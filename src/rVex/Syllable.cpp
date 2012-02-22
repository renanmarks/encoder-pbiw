#include <utility>
#include <iostream>
#include "Syllable.h"
#include "Utils/OperandVectorBuilder.h"

namespace rVex
{

  void
  Syllable::exportOperandVector(Utils::OperandVectorBuilder& builder) const // O(1)
  {
    using PBIW::Operand;
    using PBIW::Utils::OperandItem;

    switch (getLayoutType()) {
      case LayoutType::RTYPE:
        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
        builder.insertRegisters(readRegisters, OperandItem::GRSource);
        break;

      case LayoutType::ISTYPE:
        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
        builder.insertRegisters(readRegisters, OperandItem::GRSource);
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::NineBits);
        break;

        //      Must implement in each specific opcode
        //        
        //      case LayoutType::BRANCH:
        //        break;
        //        
        //      case LayoutType::RTYPE_BS:
        //        break;
        //        
        //      case LayoutType::MEMTYPE:
        //        break;
        //      
        //      case LayoutType::ILTYPE:
        //      default:
        //        break;
      default:
        break;
    }
  }

  Syllable::ImmediateSwitch::Type
  Syllable::getImmediateSwitch() const
  {
    switch(this->getLayoutType())
    {
      case LayoutType::RTYPE:
      case LayoutType::RTYPE_BS:
      case LayoutType::MEMTYPE:
        return Syllable::ImmediateSwitch::NO_IMM;
        
      case LayoutType::ISTYPE:
        return Syllable::ImmediateSwitch::SHORT_IMM;
        
      case LayoutType::ILTYPE:
        return Syllable::ImmediateSwitch::LONG_IMM;
        
      case LayoutType::BRANCH:
        return Syllable::ImmediateSwitch::BRANCH_IMM;
    }
    
    return Syllable::ImmediateSwitch::NO_IMM;
  }

  unsigned int
  Syllable::printRTYPE() const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();
    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;
    final<<=6;
    final|=grDestiny;

    ReadRegVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= *it;
    }

    if (readRegisters.size() < 2)
      final<<=6;

    final<<=3;
    final|=this->brDestiny;

    final<<=2;

    return final;
  }

  unsigned int
  Syllable::printISTYPE() const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();
    final<<=2;

    final|=Syllable::ImmediateSwitch::SHORT_IMM;
    final<<=6;

    final|=(grDestiny != 0) ? grDestiny : brDestiny;

    ReadRegVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= *it;
    }

    final<<=9;
    final|=(this->shortImmediate & 0x1FF);

    final<<=2;

    return final;
  }

  unsigned int
  Syllable::printILTYPE() const // O(1)
  {
    return 0xFFFFFFFF;
  }

  unsigned int
  Syllable::printBRANCH() const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();
    final<<=2;

    final|=Syllable::ImmediateSwitch::BRANCH_IMM;
    final<<=6;

    final|=grDestiny;

    final<<=12;
    final|=(this->shortImmediate & 0xFFF);

    final<<=3;
    final|=this->brDestiny;

    final<<=2;

    return final;
  }

  unsigned int
  Syllable::printRTYPE_BS() const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();
    final|=this->brSource;

    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;

    final<<=6;
    final|=grDestiny;

    ReadRegVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= *it;
    }

    final<<=3;
    final|=this->brDestiny;

    final<<=2;

    return final;
  }

  unsigned int
  Syllable::printMEMLOADTYPE() const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();

    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;

    final<<=6;
    final|=grDestiny;

    ReadRegVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= *it;
    }

    final<<=9;
    final|=this->shortImmediate;

    final<<=2;

    return final;
  }

  unsigned int
  Syllable::printMEMSTORETYPE() const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();

    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;

    final<<=6;
    final|=grDestiny;

    ReadRegVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= *it;
    }

    final<<=9;
    final|=this->shortImmediate;

    final<<=2;

    return final;
  }

  bool
  Syllable::operator==(const Syllable& other) const // O(1)
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
  Syllable::operator!=(const Syllable& other) const // O(1)
  {
    return !(*this == other);
  }

  void
  Syllable::addReadRegister(unsigned int readRegister) // O(1)
  {
    if (this->readRegisters.size() > 2)
      return;

    this->readRegisters.push_back(readRegister);
  }

  void
  Syllable::fillTypeI(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->fillTypeII(arguments);
  }

  void
  Syllable::fillTypeII(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue(); // O(1)
    VexParser::Expression::ParseInfo origin1=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin2=arguments.getSourceArguments().getArguments()[1].getParsedValue();

    this->addReadRegister(static_cast<unsigned int> (origin1.value)); // O(1)

    if (origin2.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediate(static_cast<unsigned short> (origin2.value));
    } else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int> (origin2.value));
    }

    if (destiny.isBranchRegister)
      this->setBrDestiny(static_cast<unsigned char> (destiny.value));
    else
      this->setGrDestiny(static_cast<unsigned char> (destiny.value));
  }

  void
  Syllable::fillTypeIII(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Arguments::ArgumentVector sourceArgs=arguments.getSourceArguments().getArguments();
    VexParser::Expression::ParseInfo origin1=sourceArgs[0].getParsedValue();
    VexParser::Expression::ParseInfo origin2=sourceArgs[1].getParsedValue();
    VexParser::Expression::ParseInfo origin3=sourceArgs[2].getParsedValue();

    this->setBrSource(static_cast<unsigned char> (origin1.value));
    this->addReadRegister(static_cast<unsigned int> (origin2.value));

    if (origin3.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediate(static_cast<unsigned short> (origin3.value));
    } else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int> (origin3.value));
    }

    this->setGrDestiny(static_cast<unsigned char> (destiny.value));
  }

  void
  Syllable::fillTypeIV(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Arguments::ArgumentVector destinyArgs=arguments.getDestinyArguments().getArguments();
    VexParser::Expression::ParseInfo destiny1=destinyArgs[0].getParsedValue();
    VexParser::Expression::ParseInfo destiny2=destinyArgs[1].getParsedValue();

    VexParser::Arguments::ArgumentVector sourceArgs=arguments.getSourceArguments().getArguments();
    VexParser::Expression::ParseInfo origin1=sourceArgs[0].getParsedValue();
    VexParser::Expression::ParseInfo origin2=sourceArgs[1].getParsedValue();
    VexParser::Expression::ParseInfo origin3=sourceArgs[2].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::RTYPE_BS);

    this->setGrDestiny(static_cast<unsigned char> (destiny1.value));
    this->setBrDestiny(static_cast<unsigned char> (destiny2.value));
    this->setBrSource(static_cast<unsigned char> (origin1.value));
    this->addReadRegister(static_cast<unsigned int> (origin2.value));
    this->addReadRegister(static_cast<unsigned int> (origin3.value));
  }

  void
  Syllable::fillTypeV(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);

    this->setBrDestiny(static_cast<unsigned char> (destiny.value));
    this->addReadRegister(static_cast<unsigned int> (origin.value));
  }

  void
  Syllable::fillTypeVI(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin1=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin2=arguments.getSourceArguments().getArguments()[1].getParsedValue();

    this->setGrDestiny(static_cast<unsigned char> (destiny.value));

    if (origin1.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediate(static_cast<unsigned short> (origin1.value));
    } else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int> (origin1.value));
    }

    this->addReadRegister(static_cast<unsigned int> (origin2.value));
  }

  void
  Syllable::fillTypeVII(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);

    this->setGrDestiny(static_cast<unsigned char> (destiny.value));
    this->addReadRegister(static_cast<unsigned int> (origin.value));
  }

  void
  Syllable::fillTypeVIII(VexParser::SyllableArguments& arguments) // O(1) 
  {
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    std::string address=arguments.getSourceArguments().getArguments()[1].getString();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);

    this->setBrSource(static_cast<unsigned char> (source.value));
    this->setLabelDestiny(address);
  }

  void
  Syllable::fillTypeIX(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    std::string path=arguments.getSourceArguments().getArguments()[1].getString();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);
    
    this->addReadRegister(static_cast<unsigned int> (source.value));
    this->setLabelDestiny(path);
  }

  void
  Syllable::fillTypeX(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo offset=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[1].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::MEMTYPE);

    this->setGrDestiny(static_cast<unsigned char> (destiny.value));
    this->addReadRegister(static_cast<unsigned int> (source.value));
    this->setShortImmediate(static_cast<unsigned short> (offset.value));
  }

  void
  Syllable::fillTypeXI(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo offset=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo baseRegister=arguments.getDestinyArguments().getArguments()[1].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::MEMTYPE);

    this->setGrDestiny(static_cast<unsigned int> (source.value));
    this->addReadRegister(static_cast<unsigned char> (baseRegister.value));
    this->setShortImmediate(static_cast<unsigned short> (offset.value));
  }

  void
  Syllable::fillTypeXII(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo offset=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);

    this->setShortImmediate(static_cast<unsigned short> (offset.value));
    this->addReadRegister(static_cast<unsigned int> (source.value));
  }

  void
  Syllable::fillTypeXIII(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);
    
    if (source.isLabel)
      this->setLabelDestiny(source.label);
    else
      this->addReadRegister(static_cast<unsigned int> (source.value));
  }

  // Only opcode

  void
  Syllable::fillTypeXIV(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
    this->addReadRegister(static_cast<unsigned int> (0));
  }

  void
  Syllable::fillTypeXV(VexParser::SyllableArguments& arguments) // O(1)
  {
    int value=arguments.getSourceArguments().getArguments()[0].getValue();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);
    
    this->setShortImmediate(static_cast<unsigned short> (value));
  }

  void
  Syllable::fillTypeXVI(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    if (source.isLabel)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);
      this->setLabelDestiny(source.label);
    }
    else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int> (source.value));
    }

    this->setGrDestiny(static_cast<unsigned char> (destiny.value));
  }

  void
  Syllable::fillTypeXVII(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source1=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source2=arguments.getSourceArguments().getArguments()[1].getParsedValue();
    VexParser::Expression::ParseInfo source3=arguments.getSourceArguments().getArguments()[2].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);
    
    this->setGrDestiny(static_cast<unsigned char> (destiny.value));
    this->addReadRegister(static_cast<unsigned int> (source1.value));
    this->setLabelDestiny(source2.label);
    this->addReadRegister(static_cast<unsigned int> (source3.value));
  }

  void
  Syllable::fillTypeXVIII(VexParser::SyllableArguments& arguments) // O(1)
  {
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);
    
    this->setGrDestiny(destiny.value);
    this->setPath(source.label);
  }

  void
  Syllable::fillTypeXIX(VexParser::SyllableArguments& arguments) // O(1)
  {
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);
    
    this->setGrDestiny(source.value);
  }

  void
  Syllable::fillTypeXX(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();
    
    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
    
    this->setGrDestiny(destiny.value);
    this->addReadRegister(source.value);
  }
}