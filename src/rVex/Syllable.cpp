/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
#include <utility>
#include <iostream>
#include "Syllable.h"
#include "Utils/OperandVectorBuilder.h"
#include "Operand.h"

namespace rVex
{

  Syllable::Syllable() :
  address(0),
  layoutType(LayoutType::RTYPE),
  grDestiny(Operand::GRDestiny),
  haveGRDestiny(false),
  brDestiny(Operand::BRDestiny),
  haveBRDestiny(false),
  brSource(Operand::BRSource),
  haveBRSource(false),
  shortImmediate(Operand::Imm9),
  branchDestiny(NULL)
  {
    grDestiny.setOperationBelonged(this);
    brDestiny.setOperationBelonged(this);
    brSource.setOperationBelonged(this);
    shortImmediate.setOperationBelonged(this);
  }

  Syllable::~Syllable()
  {

  }

  Operand 
  Syllable::getShortImmediateOperand() const
  {
    return shortImmediate;
  }
  
  Operand 
  Syllable::getBrDestinyOperand() const
  {
    return brDestiny;
  }
  
  Operand 
  Syllable::getBrSourceOperand() const
  {
    return brSource;
  }
  
  Operand 
  Syllable::getGrDestinyOperand() const
  {
    return grDestiny;
  }

  Syllable::OperandVector
  Syllable::getReadOperands() const
  {
    return this->readRegisters;
  }

  void
  Syllable::setShortImmediateValue(unsigned int shortImmediate)
  {
    this->shortImmediate.setValue(shortImmediate);
  }

  unsigned int
  Syllable::getShortImmediateValue() const
  {
    return shortImmediate.getValue();
  }

  bool
  Syllable::hasBrSource() const
  {
    return haveBRSource;
  }

  bool
  Syllable::hasBrDestiny() const
  {
    return haveBRDestiny;
  }

  void
  Syllable::setBrDestinyValue(unsigned char brDestiny)
  {
    haveBRDestiny=true;
    this->brDestiny.setValue(brDestiny);
  }

  unsigned char
  Syllable::getBrDestinyValue() const
  {
    return brDestiny.getValue();
  }

  void
  Syllable::setBrSourceValue(unsigned char brSource)
  {
    haveBRSource=true;
    this->brSource.setValue(brSource);
  }

  unsigned char
  Syllable::getBrSourceValue() const
  {
    return brSource.getValue();
  }

  bool
  Syllable::hasGrDestiny() const
  {
    return haveGRDestiny;
  }

  void
  Syllable::setGrDestinyValue(unsigned char grDestiny)
  {
    haveGRDestiny=true;
    this->grDestiny.setValue(grDestiny);
  }

  unsigned char
  Syllable::getGrDestinyValue() const
  {
    return grDestiny.getValue();
  }

  void
  Syllable::setLabelDestiny(std::string label)
  {
    this->labelDestiny=label;
  }

  std::string
  Syllable::getLabelDestiny() const
  {
    return this->labelDestiny;
  }

  void
  Syllable::setBranchDestiny(Syllable* syllableDestiny)
  {
    this->branchDestiny=syllableDestiny;
  }

  Syllable*
  Syllable::getBranchDestiny() const
  {
    return this->branchDestiny;
  }

  void
  Syllable::setPath(std::string path)
  {
    this->path=path;
  }

  std::string
  Syllable::getPath() const
  {
    return this->path;
  }

  void
  Syllable::setTextRepresentation(std::string textRepresentation)
  {
    this->textRepresentation=textRepresentation;
  }

  std::string
  Syllable::getTextRepresentation() const
  {
    return this->textRepresentation;
  }

  void
  Syllable::setBelongedInstruction(IInstruction* instruction)
  {
    this->belongedInstruction = static_cast<rVex::Instruction*>(instruction);
  }

  rVex::Instruction*
  Syllable::getBelongedInstruction() const
  {
    return this->belongedInstruction;
  }

  unsigned int
  Syllable::getAddress() const
  {
    return this->address;
  }

  void
  Syllable::setAddress(unsigned int address)
  {
    this->address=address;
  }

  /**
   * Get the structure/layout type of a syllable.
   * The structure type is how a syllable is built.
   * More info at: 
   * http://code.google.com/p/r-vex/source/browse/trunk/doc/syllable_layout.txt
   * 
   * @return the structure type of a syllable
   */
  Syllable::LayoutType::Type
  Syllable::getLayoutType() const
  {
    return layoutType;
  }
  
  void
  Syllable::setLayoutType(int layoutType)
  {
    this->setLayoutType(static_cast<Syllable::LayoutType::Type>(layoutType));
  }
  
  void
  Syllable::setLayoutType(Syllable::LayoutType::Type layoutType)
  {
    this->layoutType=layoutType;
  }

  bool 
  Syllable::isOpcode(unsigned int opcode) const
  {
    return isOpcode(static_cast<SyllableOpcode>(opcode));
  }
  
  bool 
  Syllable::isOpcode(SyllableOpcode opcode) const
  {
    return (getOpcode() & opcode) == opcode; 
  }
  
  GenericAssembly::Utils::OperandVector
  Syllable::exportOperandVector() const // O(1)
  {
    Utils::OperandVectorBuilder builder;

    switch (getLayoutType()) {
      case LayoutType::RTYPE:
        builder.insertOperand(grDestiny);
        builder.insertOperands(readRegisters);
        break;

      case LayoutType::ISTYPE:
        builder.insertOperand(grDestiny);
        builder.insertOperands(readRegisters);
        builder.insertOperand(shortImmediate);
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
    
    return builder.getOperandVector();
  }

  Syllable::ImmediateSwitch::Type
  Syllable::getImmediateSwitch() const
  {
    switch (this->getLayoutType()) {
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
  Syllable::printRTYPE(bool first, bool last) const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();
    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;
    final<<=6;
    final|=getGrDestinyValue();

    OperandVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= it->getValue();
    }

    if (readRegisters.size() < 2)
      final<<=6;

    final<<=3;
    final|=getBrDestinyValue();

    final<<=1;
    final|=last;
    final<<=1;
    final|=first;

    return final;
  }

  unsigned int
  Syllable::printISTYPE(bool first, bool last) const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();
    final<<=2;

    final|=Syllable::ImmediateSwitch::SHORT_IMM;
    final<<=6;

    final|=(getGrDestinyValue() != 0) ? getGrDestinyValue() : getBrDestinyValue();

    OperandVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= it->getValue();
    }

    final<<=9;
    final|=(getShortImmediateValue() & 0x1FF);

    final<<=1;
    final|=last;
    final<<=1;
    final|=first;

    return final;
  }

  unsigned int
  Syllable::printILTYPE(bool first, bool last) const // O(1)
  {
    return 0xFFFFFFFF;
  }

  unsigned int
  Syllable::printBRANCH(bool first, bool last) const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();
    final<<=2;

    final|=Syllable::ImmediateSwitch::BRANCH_IMM;
    final<<=6;

    final|=getGrDestinyValue();

    final<<=12;
    final|=(getShortImmediateValue() & 0xFFF);

    final<<=3;
    final|=getBrDestinyValue();

    final<<=1;
    final|=last;
    final<<=1;
    final|=first;

    return final;
  }

  unsigned int
  Syllable::printRTYPE_BS(bool first, bool last) const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();

    // Already comes merged with opcode
    // final|=this->brSource;

    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;

    final<<=6;
    final|=getGrDestinyValue();

    OperandVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= it->getValue();
    }

    final<<=3;
    final|=getBrDestinyValue();

    final<<=1;
    final|=last;
    final<<=1;
    final|=first;

    return final;
  }

  unsigned int
  Syllable::printMEMLOADTYPE(bool first, bool last) const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();

    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;

    final<<=6;
    final|=getGrDestinyValue();

    OperandVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= it->getValue();
    }

    final<<=9;
    final|=getShortImmediateValue();

    final<<=1;
    final|=last;
    final<<=1;
    final|=first;

    return final;
  }

  unsigned int
  Syllable::printMEMSTORETYPE(bool first, bool last) const // O(1)
  {
    unsigned int final=0;

    final|=this->getOpcode();

    final<<=2;
    final|=Syllable::ImmediateSwitch::NO_IMM;

    final<<=6;
    final|=getGrDestinyValue();

    OperandVector::const_iterator it;

    for (it=readRegisters.begin(); it < readRegisters.end(); it++) // O(1)
    {
      final<<=6;
      final|= it->getValue();
    }

    final<<=9;
    final|=getShortImmediateValue();

    final<<=1;
    final|=last;
    final<<=1;
    final|=first;

    return final;
  }

  bool
  Syllable::operator==(const Syllable& other) const // O(1)
  {
    if (this->getOpcode() == other.getOpcode())
    {
      return (this->getLayoutType() == other.getLayoutType()) &&
        (this->getSyllableType() == other.getSyllableType()) &&
        (this->getReadOperands() == other.getReadOperands() &&
        (this->getShortImmediateValue() == other.getShortImmediateValue()));
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

    Operand newOperand(readRegister);
    newOperand.setOperationBelonged(this);
      
    this->readRegisters.push_back(newOperand);
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
      this->setShortImmediateValue(static_cast<unsigned short> (origin2.value));
    } else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int> (origin2.value));
    }

    if (destiny.isBranchRegister)
      this->setBrDestinyValue(static_cast<unsigned char> (destiny.value));
    else
      this->setGrDestinyValue(static_cast<unsigned char> (destiny.value));
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

    this->setBrSourceValue(static_cast<unsigned char> (origin1.value));
    this->addReadRegister(static_cast<unsigned int> (origin2.value));

    if (origin3.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediateValue(static_cast<unsigned short> (origin3.value));
    } else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int> (origin3.value));
    }

    this->setGrDestinyValue(static_cast<unsigned char> (destiny.value));
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

    this->setGrDestinyValue(static_cast<unsigned char> (destiny1.value));
    this->setBrDestinyValue(static_cast<unsigned char> (destiny2.value));
    this->addReadRegister(static_cast<unsigned char> (origin1.value));
    this->addReadRegister(static_cast<unsigned int> (origin2.value));
    this->setBrSourceValue(static_cast<unsigned int> (origin3.value));
  }

  void
  Syllable::fillTypeV(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();

    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);

    this->setBrDestinyValue(static_cast<unsigned char> (destiny.value));
    this->addReadRegister(static_cast<unsigned int> (origin.value));
  }

  void
  Syllable::fillTypeVI(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();

    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin1=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo origin2=arguments.getSourceArguments().getArguments()[1].getParsedValue();

    this->setGrDestinyValue(static_cast<unsigned char> (destiny.value));

    if (origin1.isImmediate)
    {
      this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);
      this->setShortImmediateValue(static_cast<unsigned short> (origin1.value));
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

    this->setGrDestinyValue(static_cast<unsigned char> (destiny.value));
    this->addReadRegister(static_cast<unsigned int> (origin.value));
  }

  void
  Syllable::fillTypeVIII(VexParser::SyllableArguments& arguments) // O(1) 
  {
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();
    std::string address=arguments.getSourceArguments().getArguments()[1].getString();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);

    this->setBrSourceValue(static_cast<unsigned char> (source.value));
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

    this->setGrDestinyValue(static_cast<unsigned char> (destiny.value));
    this->addReadRegister(static_cast<unsigned int> (source.value));
    this->setShortImmediateValue(static_cast<unsigned short> (offset.value));
  }

  void
  Syllable::fillTypeXI(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();

    VexParser::Expression::ParseInfo offset=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo baseRegister=arguments.getDestinyArguments().getArguments()[1].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::MEMTYPE);

    this->setGrDestinyValue(static_cast<unsigned int> (source.value));
    this->addReadRegister(static_cast<unsigned char> (baseRegister.value));
    this->setShortImmediateValue(static_cast<unsigned short> (offset.value));
  }

  void
  Syllable::fillTypeXII(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();

    VexParser::Expression::ParseInfo offset=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::ISTYPE);

    this->setShortImmediateValue(static_cast<unsigned short> (offset.value));
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

    this->setShortImmediateValue(static_cast<unsigned short> (value));
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
    } else
    {
      this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);
      this->addReadRegister(static_cast<unsigned int> (source.value));
    }

    this->setGrDestinyValue(static_cast<unsigned char> (destiny.value));
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

    this->setGrDestinyValue(static_cast<unsigned char> (destiny.value));
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

    this->setGrDestinyValue(destiny.value);
    this->setPath(source.label);
  }

  void
  Syllable::fillTypeXIX(VexParser::SyllableArguments& arguments) // O(1)
  {
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::BRANCH);

    this->setGrDestinyValue(source.value);
  }

  void
  Syllable::fillTypeXX(VexParser::SyllableArguments& arguments) // O(1)
  {
    this->readRegisters.clear();

    VexParser::Expression::ParseInfo destiny=arguments.getDestinyArguments().getArguments()[0].getParsedValue();
    VexParser::Expression::ParseInfo source=arguments.getSourceArguments().getArguments()[0].getParsedValue();

    this->setLayoutType(rVex::Syllable::LayoutType::RTYPE);

    this->setGrDestinyValue(destiny.value);
    this->addReadRegister(source.value);
  }
}