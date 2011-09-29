#include <endian.h>
#include "Syllable.h"

namespace rVex
{
  std::string Syllable::printBinary(unsigned int number, bool first, bool last) const
  {
    std::string resultBinary;
    unsigned int temp = number;
    
    for (unsigned char counter=0; counter < 30; temp <<= 1, counter++)
    {
      if (temp & 0x80000000)
        resultBinary.append("1");
      else
        resultBinary.append("0");
    }
    
    if (last)
      resultBinary.append("1");
    else
      resultBinary.append("0");
    
    if (first)
      resultBinary.append("1");
    else
      resultBinary.append("0");
    
    return resultBinary;
  }
  
  void
  Syllable::addReadRegister( unsigned int readRegister )
  {
    if ( this->readRegisters.size() > 2 )
      return;

    this->readRegisters.push_back(readRegister);
  }
  
  void Syllable::fillTypeI(VexParser::SyllableArguments* arguments)
  {
    this->fillTypeII(arguments);
  }
  
  void Syllable::fillTypeII(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin1 = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin2 = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();

    this->addReadRegister(static_cast<unsigned int>(origin1.value));

    if (origin2.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::ISTYPE);
      this->setShortImmediate(static_cast<unsigned short>(origin2.value));
    }
    else
    {
      this->setLayoutType(rVex::Syllable::RTYPE);
      this->addReadRegister(static_cast<unsigned int>(origin2.value));
    }

    if (destiny.isBranchRegister)
      this->setBrDestiny(static_cast<unsigned char>(destiny.value));
    else
      this->setGrDestiny(static_cast<unsigned char>(destiny.value));
  }
  
  void Syllable::fillTypeIII(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    std::vector<VexParser::Expression*> sourceArgs = arguments->getSourceArguments()->getArguments();
    VexParser::Expression::ParseInfo origin1 = sourceArgs[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin2 = sourceArgs[1]->getParsedValue();
    VexParser::Expression::ParseInfo origin3 = sourceArgs[2]->getParsedValue();

    this->setBrSource(static_cast<unsigned char>(origin1.value));
    this->addReadRegister(static_cast<unsigned int>(origin2.value));

    if (origin3.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::ISTYPE);
      this->setShortImmediate(static_cast<unsigned short>(origin3.value));
    }
    else
    {
      this->setLayoutType(rVex::Syllable::RTYPE);
      this->addReadRegister(static_cast<unsigned int>(origin3.value));
    }

    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
  }
  
  void Syllable::fillTypeIV(VexParser::SyllableArguments* arguments)
  {
    std::vector<VexParser::Expression*> destinyArgs = arguments->getDestinyArguments()->getArguments();
    VexParser::Expression::ParseInfo destiny1 = destinyArgs[0]->getParsedValue();
    VexParser::Expression::ParseInfo destiny2 = destinyArgs[1]->getParsedValue();
    
    std::vector<VexParser::Expression*> sourceArgs = arguments->getSourceArguments()->getArguments();
    VexParser::Expression::ParseInfo origin1 = sourceArgs[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin2 = sourceArgs[1]->getParsedValue();
    VexParser::Expression::ParseInfo origin3 = sourceArgs[2]->getParsedValue();

    this->setGrDestiny    (static_cast<unsigned char>(destiny1.value));
    this->setBrDestiny    (static_cast<unsigned char>(destiny2.value));
    this->setBrSource     (static_cast<unsigned char>(origin1.value));
    this->addReadRegister (static_cast<unsigned int>(origin2.value));
    this->addReadRegister (static_cast<unsigned int>(origin3.value));
  }
  
  void Syllable::fillTypeV(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();

    this->setBrDestiny    (static_cast<unsigned char>(destiny.value));
    this->addReadRegister (static_cast<unsigned int>(origin.value));
  }
  
  void Syllable::fillTypeVI(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin1 = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin2 = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();

    this->setGrDestiny    (static_cast<unsigned char>(destiny.value));
    
    if (origin1.isImmediate)
      this->setShortImmediate (static_cast<unsigned short>(origin1.value));
    else
      this->addReadRegister (static_cast<unsigned int>(origin1.value));
    
    this->addReadRegister (static_cast<unsigned int>(origin2.value));
  }
  
  void Syllable::fillTypeVII(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();

    
    this->setLayoutType(Syllable::RTYPE);
    this->setGrDestiny    (static_cast<unsigned char>(destiny.value));
    this->addReadRegister (static_cast<unsigned int>(origin.value));
  }
  
  void Syllable::fillTypeVIII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    std::string address = arguments->getSourceArguments()->getArguments()[1]->getString();

    this->setBrSource (static_cast<unsigned char>(source.value));
    this->setLabel    (address);
  }
  
  void Syllable::fillTypeIX(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    std::string path = arguments->getSourceArguments()->getArguments()[1]->getString();

    this->addReadRegister (static_cast<unsigned int>(source.value));
    this->setLabel        (path);
  }
  
  void Syllable::fillTypeX(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source1 = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source2 = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();

    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
    this->setShortImmediate(static_cast<unsigned short>(source1.value));
    this->addReadRegister (static_cast<unsigned int>(source2.value));
  }
  
  void Syllable::fillTypeXI(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo offset = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo destiny = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();

    this->setShortImmediate(static_cast<unsigned short>(offset.value));
    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
    this->addReadRegister (static_cast<unsigned int>(source.value));
  }
  
  void Syllable::fillTypeXII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo offset = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();

    this->setShortImmediate(static_cast<unsigned short>(offset.value));
    this->addReadRegister (static_cast<unsigned int>(source.value));
  }
  
  void Syllable::fillTypeXIII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    
    if (source.isLabel)
      this->setLabel(source.label);
    
    this->addReadRegister(static_cast<unsigned int>(source.value));
  }

  // Only opcode
  void Syllable::fillTypeXIV(VexParser::SyllableArguments* arguments) { }
  
  void Syllable::fillTypeXV(VexParser::SyllableArguments* arguments) 
  { 
    int value = arguments->getSourceArguments()->getArguments()[0]->getValue();
    
    this->setShortImmediate(static_cast<unsigned short>(value));
  }
  
  void Syllable::fillTypeXVI(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    
    if (source.isLabel)
      this->setLabel(source.label);
    else
      this->addReadRegister(static_cast<unsigned int>(source.value));
    
    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
  }

  void Syllable::fillTypeXVII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source1 = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source2 = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();
    VexParser::Expression::ParseInfo source3 = arguments->getSourceArguments()->getArguments()[2]->getParsedValue();
    
    if (source1.isLabel)
      this->setLabel(source1.label);
    else
      this->addReadRegister(static_cast<unsigned int>(source1.value));
    
    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
  }
  
  void Syllable::fillTypeXVIII(VexParser::SyllableArguments* arguments) 
  { 
  
  }
  
  void Syllable::fillTypeXIX(VexParser::SyllableArguments* arguments) 
  { 
  
  }
  
  void Syllable::fillTypeXX(VexParser::SyllableArguments* arguments) 
  { 
  
  }
}