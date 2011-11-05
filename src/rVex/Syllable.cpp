#include <utility>
#include <iostream>
#include "Syllable.h"

namespace rVex
{
  Syllable::OperandVector 
  Syllable::getOperandVector() const
  {
    using PBIW::Operand;
    
    Syllable::OperandVector returnVector;
    ReadRegVector::const_iterator it;
    
    switch( getLayoutType() )
    {
      case LayoutType::RTYPE:
        returnVector.push_back(
          std::make_pair(
            new Operand(this->grDestiny),
            OperandType::GRDestiny
          )
        );
        
        for(it = readRegisters.begin();
            it < readRegisters.end();
            it++)
        {
          returnVector.push_back(
            std::make_pair(new Operand(*it), OperandType::GRSource)
          );
        }
        break;
        
      case LayoutType::ISTYPE:
        returnVector.push_back(
            std::make_pair(
              new Operand(this->grDestiny), 
              OperandType::GRDestiny
            )
          );
        
        for(it = readRegisters.begin();
            it < readRegisters.end();
            it++)
        {
          returnVector.push_back(
            std::make_pair(new Operand(*it), OperandType::GRSource)
          );
        }
        
        returnVector.push_back(
          std::make_pair(
            new Operand(this->shortImmediate, Operand::Immediate::NineBits),
            OperandType::Imm
          )
        );
        break;
        
      case LayoutType::BRANCH:
        break;
        
      case LayoutType::RTYPE_BS:
        break;
        
      case LayoutType::MEMTYPE:
        break;
      
      case LayoutType::ILTYPE:
      default:
        break;
    }
    
    return returnVector;
  }
  
  unsigned int 
  Syllable::printRTYPE() const 
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    final <<= 2;
    final |= Syllable::ImmediateSwitch::NO_IMM;
    final <<= 6;
    final |= grDestiny;

    ReadRegVector::const_iterator it;

    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
    {
      final <<= 6;
      final |= *it;
    }

    final <<= 3;
    final |= this->brDestiny;

    final <<= 2;

    return final; 
  }
  
  unsigned int 
  Syllable::printISTYPE() const 
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    final <<= 2;

    final |= Syllable::ImmediateSwitch::SHORT_IMM;
    final <<= 6;
    
    final |= grDestiny;

    ReadRegVector::const_iterator it;

    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
    {
      final <<= 6;
      final |= *it;
    }

    final <<= 9;
    final |= this->shortImmediate;

    final <<= 2;

    return final;
  }
  
  unsigned int 
  Syllable::printILTYPE() const
  {
    // TODO
  }
  
  unsigned int 
  Syllable::printBRANCH() const
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    final <<= 2;

    final |= Syllable::ImmediateSwitch::BRANCH_IMM;
    final <<= 6;
    
    final |= grDestiny;

    final <<= 12;
    final |= this->shortImmediate;
    
    final <<= 3;
    final |= this->brDestiny;

    final <<= 2;

    return final;
  }
  
  unsigned int 
  Syllable::printRTYPE_BS() const
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    final |= this->brSource;
    
    final <<= 2;
    final |= Syllable::ImmediateSwitch::NO_IMM;
    
    final <<= 6;
    final |= grDestiny;
    
    ReadRegVector::const_iterator it;

    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
    {
      final <<= 6;
      final |= *it;
    }
    
    final <<= 3;
    final |= this->brDestiny;

    final <<= 2;

    return final;
  }
  
  unsigned int 
  Syllable::printMEMLOADTYPE() const
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    
    final <<= 2;
    final |= Syllable::ImmediateSwitch::NO_IMM;
    
    final <<= 6;
    final |= grDestiny;
    
    ReadRegVector::const_iterator it;

    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
    {
      final <<= 6;
      final |= *it;
    }
    
    final <<= 9;
    final |= this->shortImmediate;

    final <<= 2;

    return final;
  }
  
  unsigned int 
  Syllable::printMEMSTORETYPE() const
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    
    final <<= 2;
    final |= Syllable::ImmediateSwitch::NO_IMM;
    
    final <<= 6;
    final |= grDestiny;
    
    ReadRegVector::const_iterator it;

    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
    {
      final <<= 6;
      final |= *it;
    }
    
    final <<= 9;
    final |= this->shortImmediate;

    final <<= 2;

    return final;
  }
  
  bool 
  Syllable::operator==(const Syllable& other) const 
  { 
    if (this->getOpcode() == other.getOpcode())
    {
      return (this->getLayoutType() == other.getLayoutType()) &&
        (this->getSyllableType() == other.getSyllableType()) &&
        (this->getReadRegisters() == other.getReadRegisters() &&
        (this->getShortImmediate() == other.getShortImmediate()));
    }

    return false;
  }

  bool 
  Syllable::operator!=(const Syllable& other) const 
  { 
    return !(*this == other); 
  }
  
  void
  Syllable::addReadRegister( unsigned int readRegister )
  {
    if ( this->readRegisters.size() > 2 )
      return;

    this->readRegisters.push_back(readRegister);
  }
  
  void 
  Syllable::fillTypeI(VexParser::SyllableArguments* arguments)
  {
    this->fillTypeII(arguments);
  }
  
  void 
  Syllable::fillTypeII(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin1 = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin2 = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();

    this->addReadRegister(static_cast<unsigned int>(origin1.value));

    if (origin2.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediate(static_cast<unsigned short>(origin2.value));
    }
    else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int>(origin2.value));
    }

    if (destiny.isBranchRegister)
      this->setBrDestiny(static_cast<unsigned char>(destiny.value));
    else
      this->setGrDestiny(static_cast<unsigned char>(destiny.value));
  }
  
  void 
  Syllable::fillTypeIII(VexParser::SyllableArguments* arguments)
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
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediate(static_cast<unsigned short>(origin3.value));
    }
    else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int>(origin3.value));
    }

    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
  }
  
  void 
  Syllable::fillTypeIV(VexParser::SyllableArguments* arguments)
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
  
  void 
  Syllable::fillTypeV(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();

    this->setBrDestiny    (static_cast<unsigned char>(destiny.value));
    this->addReadRegister (static_cast<unsigned int>(origin.value));
  }
  
  void 
  Syllable::fillTypeVI(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin1 = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin2 = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();

    this->setGrDestiny    (static_cast<unsigned char>(destiny.value));
    
    if (origin1.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediate (static_cast<unsigned short>(origin1.value));
    }
    else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister (static_cast<unsigned int>(origin1.value));
    }
    
    this->addReadRegister (static_cast<unsigned int>(origin2.value));
  }
  
  void 
  Syllable::fillTypeVII(VexParser::SyllableArguments* arguments)
  {
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo origin = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();

    
    this->setLayoutType(Syllable::LayoutType::RTYPE);
    this->setGrDestiny    (static_cast<unsigned char>(destiny.value));
    this->addReadRegister (static_cast<unsigned int>(origin.value));
  }
  
  void 
  Syllable::fillTypeVIII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    std::string address = arguments->getSourceArguments()->getArguments()[1]->getString();

    this->setBrSource (static_cast<unsigned char>(source.value));
    this->setLabel    (address);
  }
  
  void 
  Syllable::fillTypeIX(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    std::string path = arguments->getSourceArguments()->getArguments()[1]->getString();

    this->addReadRegister (static_cast<unsigned int>(source.value));
    this->setLabel        (path);
  }
  
  void 
  Syllable::fillTypeX(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo offset = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[1]->getParsedValue();

    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
    this->setShortImmediate(static_cast<unsigned short>(offset.value));
    this->addReadRegister (static_cast<unsigned int>(source.value));
  }
  
  void 
  Syllable::fillTypeXI(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo offset = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[1]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();

    this->setShortImmediate(static_cast<unsigned short>(offset.value));
    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
    this->addReadRegister (static_cast<unsigned int>(source.value));
  }
  
  void 
  Syllable::fillTypeXII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo offset = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();

    this->setShortImmediate(static_cast<unsigned short>(offset.value));
    this->addReadRegister (static_cast<unsigned int>(source.value));
  }
  
  void 
  Syllable::fillTypeXIII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    
    if (source.isLabel)
      this->setLabel(source.label);
    
    this->addReadRegister(static_cast<unsigned int>(source.value));
  }

  // Only opcode
  void 
  Syllable::fillTypeXIV(VexParser::SyllableArguments* arguments) { }
  
  void 
  Syllable::fillTypeXV(VexParser::SyllableArguments* arguments) 
  { 
    int value = arguments->getSourceArguments()->getArguments()[0]->getValue();
    
    this->setShortImmediate(static_cast<unsigned short>(value));
  }
  
  void 
  Syllable::fillTypeXVI(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    
    if (source.isLabel)
      this->setLabel(source.label);
    else
      this->addReadRegister(static_cast<unsigned int>(source.value));
    
    this->setGrDestiny(static_cast<unsigned char>(destiny.value));
  }

  void 
  Syllable::fillTypeXVII(VexParser::SyllableArguments* arguments) 
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
  
  void 
  Syllable::fillTypeXVIII(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    
    this->setGrDestiny(destiny.value);
    this->setPath(source.label);
  }
  
  void 
  Syllable::fillTypeXIX(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    
    this->setGrDestiny(source.value);
  }
  
  void 
  Syllable::fillTypeXX(VexParser::SyllableArguments* arguments) 
  { 
    VexParser::Expression::ParseInfo destiny = arguments->getDestinyArguments()->getArguments()[0]->getParsedValue();
    VexParser::Expression::ParseInfo source = arguments->getSourceArguments()->getArguments()[0]->getParsedValue();
    
    this->setGrDestiny(destiny.value);
    this->addReadRegister(source.value);
  }
}