/* 
 * File:   PBIWInstruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */
#include <stdexcept>
#include <deque>
#include <iostream>
#include <algorithm>
#include "src/rVex/PBIWPartial/rVex64PBIWInstruction.h"
#include "src/PBIW/Interfaces/IOperand.h"
#include "src/PBIW/Interfaces/IPBIWInstruction.h"
#include "src/rVex/Instruction.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;

  IPBIWInstruction* 
  rVex64PBIWInstruction::clone() const
  {
    return new rVex64PBIWInstruction(*this);
  }
  
  void
  rVex64PBIWInstruction::addBranchOperand(IOperand& operand)
  {
    throw std::range_error("addBranchOperand() NOT IMPLEMENTED EXCEPTION");
  }
  
  void 
  rVex64PBIWInstruction::setOperationReferences(const std::list<GenericAssembly::Interfaces::IOperation*>& list)
  {
    std::list<GenericAssembly::Interfaces::IOperation*>::const_iterator it;
    
    for(it = list.begin(); it != list.end(); it++)
    {
      syllablesPacked.push_back(static_cast<rVex::Syllable*>(*it));
      (*it)->getBelongedInstruction()->addReferencePBIWInstruction(*this);
    }
  }
  
  std::list<GenericAssembly::Interfaces::IOperation*>
  rVex64PBIWInstruction::getOperationReferences() const
  {
    return std::list<GenericAssembly::Interfaces::IOperation*>(syllablesPacked.begin(), syllablesPacked.end());
  }
  
  void
  rVex64PBIWInstruction::updateAnnulBits(int index1, int index2)
  {
      bool tempBit;

      tempBit = this->annulBits[index1];
      this->setAnnulBit(index1, this->annulBits[index2]);
      this->setAnnulBit(index2, tempBit);
  }

  void
  rVex64PBIWInstruction::setCodingOperation(IOperation& operation)
  {
    codingOperation = &dynamic_cast<Operation&> (operation);
  }
  
  IOperation*
  rVex64PBIWInstruction::getCodingOperation() const
  {
    return codingOperation;
  }
  
  PBIW::Utils::OperandVector
  rVex64PBIWInstruction::getOperands() const // O(1)
  {
    std::deque<Operand> temp(readOperands.begin(), readOperands.end()); // O(|readOperands|) = O(8) = O(1)

    temp.resize(8, Operand(-1)); // O(8) = O(1)

    if (writeOperands.size() > 0)
      temp.push_back(writeOperands[0]);
    else
      temp.push_back(Operand(-1));

    if (immediate.isImmediate())
    {
      temp.push_back(Operand(-1));

      if (immediate.isImmediate9Bits())
      {
        temp.push_back(immediate);

        if (writeOperands.size() > 1)
          temp.push_back(writeOperands[1]);
      } else
      {
        temp.push_back(Operand(-1));
        temp.push_back(immediate);
      }
    } else
    {
      if (writeOperands.size() > 1)
        temp.insert(temp.end(), writeOperands.begin() + 1, writeOperands.end());
    }

    if (temp.size() < 12)
      temp.resize(12, Operand(-1));

    PBIW::Utils::OperandVector returnVector;
    
    returnVector.fill(temp);

    return returnVector;
  }

  void
  rVex64PBIWInstruction::print(IPBIWPrinter& printer) const
  {
    PBIW::Utils::OperandVector operands=getOperands(); // O(1)
    PBIW::Utils::OperandVector::Collection::iterator it;

    union OutputBinary
    {
      unsigned int word[2];
      unsigned long long int longWord;
    };

    OutputBinary output;
    output.longWord=0;

    output.longWord|=pattern->getAddress();

    for(unsigned int i = annulBits.size()-1;
            i >= 0 && i < 4;
            i--) 
    {
      output.longWord<<=1;
      output.longWord|= annulBits[i];          
    }
    
    // Get rid of the -1 values
    for (it=operands.begin();
         it < operands.end();
         it++)
    {
      if (((*it)->getValue() < 0) && (!(*it)->isImmediate()))
        (*it)->setValue(0);
    }

    // Read operands
    for (it=operands.begin()+1; // O(|operands|) = O(8) = O(1)
         it < operands.end() - 4; //&& (*it)->getIndex() < 8;
         it++)
    {
      output.longWord<<=5;
      output.longWord|=(*it)->getValue();
    }

    bool hasImm9Bits=dynamic_cast<Operand*>(operands[10])->isImmediate9Bits();
    bool hasImm12Bits=dynamic_cast<Operand*>(operands[11])->isImmediate12Bits();
    bool hasImmediate=hasImm9Bits || hasImm12Bits;

    if (!hasImmediate)
    {
      // write operands
      for (it=operands.begin() + 8; // O(|operands|) = O(4) = O(1)
           it < operands.end();
           it++)
      {
        if (it == (operands.end() - 1))
        {
          output.longWord<<=3;
          output.longWord|=(*it)->getValue();
          continue;
        }

        output.longWord<<=5;
        output.longWord|=(*it)->getValue();
      }
    } else
    {
      output.longWord<<=5;
      output.longWord|=operands[8]->getValue();

      if (hasImm9Bits)
      {
        output.longWord<<=10;
        output.longWord|=(0x000001FF & operands[10]->getValue());

        output.longWord<<=3;
        output.longWord|=operands[11]->getValue();
      }

      if (hasImm12Bits)
      {
        output.longWord<<=13;
        output.longWord|=(0x00000FFF & operands[11]->getValue());
      }
    }

    std::vector<unsigned int> binary;
    binary.push_back(output.word[1]);
    binary.push_back(output.word[0]);

    printer.printInstruction(*this, binary);
  }

  void
  rVex64PBIWInstruction::setLabel(const ILabel* label) // O(1)
  {
    this->labels.push_back(const_cast<ILabel*>(label));
  }

  void
  rVex64PBIWInstruction::setBranchDestiny(const IPBIWInstruction& branchDestiny)
  {
    const rVex64PBIWInstruction& temp = dynamic_cast<const rVex64PBIWInstruction&> (branchDestiny);

    this->branchDestiny= &const_cast<rVex64PBIWInstruction&> (temp);
    this->setImmediateValue(temp.getAddress());
  }

  bool
  rVex64PBIWInstruction::hasControlOperationWithLabelDestiny()
  {
    using rVex::Syllable;
    SyllableList::const_iterator it;

    for (it=syllablesPacked.begin();
         it != syllablesPacked.end();
         it++)
    {
      if ((*it)->getOpcode() == Syllable::opBR ||
          (*it)->getOpcode() == Syllable::opBRF ||
          (*it)->getOpcode() == Syllable::opCALL ||
          (*it)->getOpcode() == Syllable::opGOTO ||
          (*it)->getOpcode() == Syllable::opRETURN)
      {
        if ((*it)->getBranchDestiny() != NULL)
        {
          destinyLabel=(*it)->getLabelDestiny();
          break;
        }
      }
    }

    if (!destinyLabel.empty())
    {
      if (!pattern->hasControlOperation())
      {
        //this->branchDestiny = NULL;
        throw new CodingMismatchException("Mismatch: pattern does not have a control syllable referenced by PBIW instruction.");
      }

      return true;
    }

    return false;
  }

  void
  rVex64PBIWInstruction::pointToPattern(IPBIWPattern& pattern) // O(1)
  {
    rVex96PBIWPattern& temp=dynamic_cast<rVex96PBIWPattern&> (pattern);

    this->pattern = &temp;
    this->pattern->referencedByInstruction(this);
  }

  const IOperand&
  rVex64PBIWInstruction::containsOperand(const IOperand& operand) const // O(1)
  {
    //    bool foundInReadOperands = std::find(readOperands.begin(), readOperands.end(), operand);
    //    bool foundInWriteOperands = std::find(writeOperands.begin(), writeOperands.end(), operand);
    //    return (foundInReadOperands || foundInWriteOperands);

    std::deque<Operand>::const_iterator it;

    for (it=readOperands.begin(); // O(|readOperands|) = O(8) = O(1)
         it < readOperands.end();
         it++)
    {
      if (*it == dynamic_cast<const Operand&>(operand))
        return *it;
    }

    for (it=writeOperands.begin(); //O(|writeOperands|) = O(4) = O(1)
         it < writeOperands.end();
         it++)
    {
      if (*it == dynamic_cast<const Operand&>(operand))
        return *it;
    }

    return operand;
  }

  void 
  rVex64PBIWInstruction::addOperand(IOperand& operand)
  {
    switch ( static_cast<rVex::Operand::Type>(operand.getTypeCode()) )
    {
      case rVex::Operand::GRDestiny :
        if (operand.getValue() == 0)
          break;

      case rVex::Operand::Imm9:
      case rVex::Operand::Imm12:
        this->addWriteOperand(operand); // O(1)
        break;

      case rVex::Operand::BRSource :
        this->setBranchSourceOperand(operand); // O(1)
        break;

      case rVex::Operand::BRDestiny :
        this->addReadOperand(operand); // O(1)
        break;

      case rVex::Operand::GRSource :
        if (operand.getValue() != 0)
          this->addReadOperand(operand); // O(1)

        break;
    }
  }
  
  void
  rVex64PBIWInstruction::addReadOperand(IOperand& operand) // O(1)
  {
    Operand& convertedOperand = dynamic_cast<Operand&>(operand);
    
    if (convertedOperand.isBRSource())
    {
      setBranchSourceOperand(convertedOperand);
      return;
    }
    
    unsigned int index=this->readOperands.size();
    convertedOperand.setIndex(index);
    this->readOperands.push_back(convertedOperand);
  }

  void
  rVex64PBIWInstruction::setBranchSourceOperand(IOperand& operand)
  {
    operand.setIndex(1);
    
    if (!hasBranchSourceOperand())
    {
      if (readOperands.size() == 1) // 1 element (zero)
        readOperands.push_back(dynamic_cast<Operand&> (operand));
      else // 1 element (zero) and/or more element(s) after
        readOperands[1] = dynamic_cast<Operand&> (operand);
      
      hasBRSrc = true;
    }
    else
    {
      readOperands[1] = dynamic_cast<Operand&> (operand);
    }
    
    return;
  }

  bool
  rVex64PBIWInstruction::hasBranchSourceOperand() const
  {
    return hasBRSrc;
  }

  void
  rVex64PBIWInstruction::addWriteOperand(IOperand& operand) // O(1)
  {
    Operand& convertedOperand = dynamic_cast<Operand&>(operand);
    
    if (convertedOperand.isImmediate())
    {
      if (convertedOperand.isImmediate9Bits())
        operand.setIndex(10);
      else if (convertedOperand.isImmediate12Bits())
        operand.setIndex(11);

      immediate=convertedOperand;

      return;
    }

    // If we not have the immediate yet, do the normal indexing
    unsigned int index; // = 8 + this->writeOperands.size();

    if (immediate.isImmediate())
    {
      // If we have immediate, do the absolute indexing
      if (immediate.isImmediate9Bits())
      {
        switch (writeOperands.size()) {
          case 0:
            index=8; // before the 9 and 10 positions occupied by the imm
            break;
          case 1:
            index=11; // after the 9 and 10 positions occupied by the imm
            break;
          default: // more than 2
            index=666; // error!
            break;
        }
      } else if (immediate.isImmediate12Bits())
      {
        switch (writeOperands.size()) {
          case 0:
            index=8; // before the 9, 10 and 11 positions occupied by the imm
            break;
          default: // more than 1
            index=666; // error!
            break;
        }
      }
    } else
    {
      index=8 + this->writeOperands.size();
    }

    convertedOperand.setIndex(index);
    this->writeOperands.push_back(convertedOperand);
  }

  bool
  rVex64PBIWInstruction::hasOperandSlot(const PBIW::Utils::OperandItemDTO& operand) // O(1)
  {
    switch ( static_cast<rVex::Operand::Type>(operand.getOperand()->getTypeCode()) )
    {
      case rVex::Operand::GRDestiny:
      {
        bool hasWriteSlot = this->hasWriteOperandSlot();
        
        bool onlyLastWriteField = 
          (immediate.isImmediate9Bits() && (writeOperands.size() == 1)) ||
          (!immediate.isImmediate12Bits() && !immediate.isImmediate9Bits() && (writeOperands.size() == 3));
        
        bool operandFit = (operand.getOperand()->getValue() < 8);
        
        if (onlyLastWriteField)
        {
          if (operandFit)
            return true;
          
          return false;
        }
        else
          return hasWriteSlot;
      }
        break;

      case rVex::Operand::Imm12:
        {
          Operand* convertedOperand = dynamic_cast<Operand*>(operand.getPBIWOperand());

          if (this->containsImmediate())
            return false;

          if (convertedOperand->isImmediate12Bits() && writeOperands.size() > 1)
            return false;
        }
        break;
        
      case rVex::Operand::Imm9:
        {
          Operand* convertedOperand = dynamic_cast<Operand*>(operand.getPBIWOperand());

          if (this->containsImmediate())
            return false;

          if (convertedOperand->isImmediate9Bits() && writeOperands.size() == 2)
          {
            writeOperands.back().setIndex(11);
            return false;
          }

          if (convertedOperand->isImmediate9Bits() && writeOperands.size() > 2)
            return false;
        }
        break;

      case rVex::Operand::BRSource:
        return !this->hasBranchSourceOperand();
        break;
      
      case rVex::Operand::BRDestiny:
      case rVex::Operand::GRSource:
        if (operand.getOperand()->getValue() != 0)
          return this->hasReadOperandSlot();

        std::cout << "Encontrei um zero" << operand.getOperand()->getValue() << std::endl;
        break;
    }

    return true;
  }

  bool
  rVex64PBIWInstruction::hasReadOperandSlot() const // O(1)
  {
    return readOperands.size() < 8;
  }

  bool
  rVex64PBIWInstruction::hasWriteOperandSlot() const // O(1)
  {
    bool hasWriteSlots=
      (immediate.isImmediate12Bits() && (writeOperands.size() < 1)) ||
      (immediate.isImmediate9Bits() && (writeOperands.size() < 2)) ||
      (!immediate.isImmediate12Bits() && !immediate.isImmediate9Bits() && writeOperands.size() < 4);

    return hasWriteSlots;
  }
}
