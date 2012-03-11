/* 
 * File:   PBIWInstruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */

#include <deque>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include "rVex64PBIWInstruction.h"
#include "Interfaces/IOperand.h"

namespace PBIW
{
    using namespace Interfaces;

    rVex64PBIWInstruction::~rVex64PBIWInstruction()
    {

    }

    rVex64PBIWInstruction::OperandVector
    rVex64PBIWInstruction::getOperands() const // O(1)
    {
      std::deque<Operand> temp(operands.begin(), operands.end()); // O(|operands|) = O(8) = O(1)

      if (immediate.isImmediate9Bits())
      {
        if (operands.size() < 10)
          temp.resize(10, Operand(-1));

        temp.push_back(immediate);
        temp.push_back(Operand(-1));
      }
      else if (immediate.isImmediate12Bits())
      {
        if (operands.size() < 11)
          temp.resize(11, Operand(-1));

        temp.push_back(immediate);
      }

      if (temp.size() < 12)
        temp.resize(12, Operand(-1));

      rVex64PBIWInstruction::OperandVector returnVector(temp.begin(), temp.end());

      return returnVector;
    }

    void
    rVex64PBIWInstruction::print(IPBIWPrinter& printer) const
    {
      OperandVector operands=getOperands(); // O(1)
      OperandVector::iterator it;

      union OutputBinary
      {
        unsigned int word[2];
        unsigned long long int longWord;
      };

      OutputBinary output;
      output.longWord=0;

      output.longWord|=pattern->getAddress();

      // Get rid of the -1 values
      for (it=operands.begin();
           it < operands.end();
           it++)
      {
        if ((it->getValue() < 0) && (!it->isImmediate()))
          it->setValue(0);
      }

      // Read operands
      for (it=operands.begin(); // O(|operands|) = O(8) = O(1)
           it < operands.end() - 4; //&& it->getIndex() < 8;
           it++)
      {
        output.longWord<<=5;
        output.longWord|=it->getValue();
      }

      bool hasImm9Bits=operands[10].isImmediate9Bits();
      bool hasImm12Bits=operands[11].isImmediate12Bits();
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
            output.longWord|=it->getValue();
            continue;
          }

          output.longWord<<=5;
          output.longWord|=it->getValue();
        }
      } else
      {
        output.longWord<<=5;
        output.longWord|=operands[8].getValue();

        if (hasImm9Bits)
        {
          output.longWord<<=10;
          output.longWord|=(0x000001FF & operands[10].getValue());

          output.longWord<<=3;
          output.longWord|=operands[11].getValue();
        }

        if (hasImm12Bits)
        {
          output.longWord<<=13;
          output.longWord|=(0x00000FFF & operands[11].getValue());
        }
      }

      std::vector<unsigned int> binary;
      binary.push_back(output.word[1]);
      binary.push_back(output.word[0]);

      printer.printInstruction(*this, binary);
    }

    void
    rVex64PBIWInstruction::setLabel(const ILabel& label) // O(1)
    {
      const Label& temp=dynamic_cast<const Label&> (label);

      this->label= &const_cast<Label&> (temp);
    }

    void
    rVex64PBIWInstruction::setBranchDestiny(const IPBIWInstruction& branchDestiny)
    {
      const rVex64PBIWInstruction& temp=dynamic_cast<const rVex64PBIWInstruction&> (branchDestiny);

      this->branchDestiny= &const_cast<rVex64PBIWInstruction&> (temp);
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
    rVex64PBIWInstruction::pointToPattern(const IPBIWPattern& pattern) // O(1)
    {
      const rVex96PBIWPattern& temp=dynamic_cast<const rVex96PBIWPattern&> (pattern);

      this->pattern= &temp;
    }

    const IOperand&
    rVex64PBIWInstruction::containsOperand(const IOperand& operand) const // O(1)
    {
      if (operand.getValue() == 0 && !operand.isBRSource())
        return zeroOperand;
      
      OperandVector::const_iterator it;

      for (it = operands.begin(); // O(|operands|) = O(8) = O(1)
           it < operands.end();
           it++)
      {
        if (*it == operand)
          return *it;
      }

      return operand;
    }

    void
    rVex64PBIWInstruction::addWriteOperand(IOperand& operand) // O(1)
    {
      addReadOperand(operand);
    }
    
    void
    rVex64PBIWInstruction::addReadOperand(IOperand& operand) // O(1)
    {
      if (operand.isImmediate())
      {
        if (operand.isImmediate9Bits())
          operand.setIndex(10);
        else if (operand.isImmediate12Bits())
          operand.setIndex(11);

        immediate=dynamic_cast<Operand&> (operand);

        return;
      }

      if (operand.getValue() == 0 && !operand.isBRSource())
      {
        operand.setIndex(15);
        return;
      }
      
      // If we not have the immediate yet, do the normal indexing
      unsigned int index = operands.size();

      if (immediate.isImmediate())
      {
        // If we have immediate, do the absolute indexing
        if (immediate.isImmediate9Bits())
        {
          if (operands.size() == 9)
            index = 11;
          else if (operands.size() < 9)
            index = operands.size();
        }
        else if (immediate.isImmediate12Bits())
        {
          if (operands.size() < 9)
            index = operands.size();
        }
      }
      
      operand.setIndex(index);
      operands.push_back(dynamic_cast<Operand&> (operand));
      
//      unsigned int index=this->operands.size();
//      operand.setIndex(index);
//      this->operands.push_back(dynamic_cast<Operand&> (operand));
    }

    void
    rVex64PBIWInstruction::addBranchSourceOperand(IOperand& operand)
    {
      int emptySlotIndex = giveEmptyBranchSourceSlot();
      
      if (emptySlotIndex > -1)
      {
        operand.setIndex(emptySlotIndex);
        
        if (emptySlotIndex == 0)
          operands.push_back(dynamic_cast<Operand&> (operand));
        else
          operands.at(emptySlotIndex) = dynamic_cast<Operand&> (operand);
      }
      
      return;
    }

    int
    rVex64PBIWInstruction::giveEmptyBranchSourceSlot()
    {
      // Check if there is space in the 0-7 slot range;
      if (operands.size() < 8)
      {
        if (operands.size() == 0)
          return 0;
        
        return operands.size() - 1;
      }
      // If not, check if we can "move" some operands to open space so
      // we can put the BRsrc registers in them;
      else if (hasReadOperandSlot())
      {
        OperandVector::iterator it;
        int index = 0;
        
        for(it = operands.begin(); it < operands.begin()+8; it++, index++)
        {
          // Change the operand position and inform the new space opened
          if (!it->isBRSource())
          {
            addReadOperand(*it);
            return index;
          }
        }
      }
      
      // If we cant do any of above, desist: there is no free space left.
      return -1;
    }
    
    bool
    rVex64PBIWInstruction::hasBranchSourceOperand() const
    {
      return false; // TODO
    }

    

    bool
    rVex64PBIWInstruction::hasOperandSlot(const Utils::OperandItem& operand) // O(1)
    {
      // TODO

      switch (operand.getType()) 
      {
        case Utils::OperandItem::Imm:
          if (this->containsImmediate())
            return false;

          if (operand.getOperand()->isImmediate9Bits() && operands.size() == 10)
          {
            if (operands.back().getValue() < 8)
            {
              operands.back().setIndex(11);
              return true;
            }

            return false;
          }

          if (operand.getOperand()->isImmediate9Bits() && operands.size() > 10)
            return false;

          if (operand.getOperand()->isImmediate12Bits() && operands.size() > 10)
            return false;
          break;

        case Utils::OperandItem::BRSource:
          // Check if there is space in the 0-7 slot range;
          if (operands.size() < 8)
          {
            return true;
          }
          // If not, check if we can "move" some operands to open space so
          // we can put the BRsrc registers in them;
          else if (hasReadOperandSlot())
          {
            return true;
          }
          else // If we cant do any of above, desist: there is no free space left.
            return false;

        default:
          // Default empty slot checking
          return hasReadOperandSlot();
      }

      return true;
    }

    bool
    rVex64PBIWInstruction::hasReadOperandSlot() const // O(1)
    {
      return hasWriteOperandSlot();
    }

    bool
    rVex64PBIWInstruction::hasWriteOperandSlot() const // O(1)
    {
      bool hasWriteSlots=
        (immediate.isImmediate12Bits() && (operands.size() < 10)) ||
        (immediate.isImmediate9Bits() && (operands.size() < 11)) ||
        (!immediate.isImmediate12Bits() && !immediate.isImmediate9Bits() && operands.size() < 12);

      return hasWriteSlots;
    }
}
