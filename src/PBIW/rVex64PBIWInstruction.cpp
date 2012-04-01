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
#include <stdexcept>
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
      std::set<Operand> temp(operands.begin(), operands.end());
      
      if (opBRslot.getValue() > -1)
        temp.insert(opBRslot);
      
      if (opBRFslot.getValue() > -1)
        temp.insert(opBRFslot);
      
      if (immediate.isImmediate())
        temp.insert(immediate);
      
      // Setup the non present indexes set
      std::set<int> allIndexes;
      
      for(int i=0; i<12; i++)
        allIndexes.insert(i);
      
      // Let remain only the indexes not presents in the temp set
      std::set<Operand>::iterator it;
      
      for(it=temp.begin(); it!=temp.end(); it++)
        allIndexes.erase(it->getIndex());
      
      // Insert the remaining positions
      std::set<int>::iterator indexIt;
      
      for(indexIt=allIndexes.begin(); indexIt!=allIndexes.end(); indexIt++)
      {
        Operand emptyOperand(-1);
        emptyOperand.setIndex(*indexIt);
        
        temp.insert(temp.end(), emptyOperand);
      }

      return rVex64PBIWInstruction::OperandVector(temp.begin(), temp.end());
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
          it->setValue(zeroOperand.getValue());
      }

      bool hasImm9Bits=operands[10].isImmediate9Bits();
      bool hasImm12Bits=operands[11].isImmediate12Bits();
      bool hasImmediate=hasImm9Bits || hasImm12Bits;

      if (!hasImmediate)
      {
        // operands
        for (it=operands.begin(); // O(|operands|) = O(4) = O(1)
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
      } 
      else
      {
        for (it=operands.begin(); // O(|operands|) = O(4) = O(1)
             it < operands.end()-3;
             it++)
        {
          output.longWord<<=5;
          output.longWord|=it->getValue();
        }
        
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
    rVex64PBIWInstruction::pointToPattern(IPBIWPattern& pattern) // O(1)
    {
      rVex96PBIWPattern& temp=dynamic_cast<rVex96PBIWPattern&> (pattern);

      this->pattern= &temp;
    }

    const IOperand&
    rVex64PBIWInstruction::containsOperand(const IOperand& operand) const // O(1)
    {
      if (operand.getValue() == 0 && !operand.isBRSource() && !operand.isBRDestiny() && !operand.isImmediate())
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

    void rVex64PBIWInstruction::setOpBRFslot(IOperand& operand)
    { 
      Operand& operandReference = dynamic_cast<Operand&>(operand);
      operandReference.setIndex(6);
      
      // The slot at index 5 is occupied
      if (operands.size() >= 7)
      {
        // If we're lucky...!
        if (operands.at(6) == operandReference)
        {
          operands.erase(operands.begin()+6);
          this->opBRslot = operandReference;
          return;
        }
        
        // ... if not so lucky, lets see if we have a empty slot to move someone
        if (hasReadOperandSlot())
        {
          if (!operands.at(6).isBRSource())
          {
            Operand operandAt6 = operands.at(6);

            unsigned int oldIndex = operandAt6.getIndex();
            addReadOperand(operandAt6);
            unsigned int newIndex = operandAt6.getIndex();

            pattern->updateIndexes(oldIndex, newIndex);
            
            operands.erase(operands.begin()+6);
          }
          else
          {
            int freeSlotIndex = giveEmptyBranchSourceSlot();
            
            if (freeSlotIndex > -1)
            {
              operands.at(freeSlotIndex) = operands.at(6);
              operands.erase(operands.begin()+6);
            }
          }
        }
        else
        {
          throw std::range_error("Not found free slot to move operation.");
        }
      }
      
      this->opBRslot = operandReference; 
    }

    void rVex64PBIWInstruction::setOpBRslot(IOperand& operand)
    { 
      Operand& operandReference = dynamic_cast<Operand&>(operand);
      
      operandReference.setIndex(5);
      
      // The slot at index 5 is occupied
      if (operands.size() >= 6)
      {
        // If we're lucky...!
        if (operands.at(5) == operandReference)
        {
          operands.erase(operands.begin()+5);
          this->opBRslot = operandReference;
          return;
        }
        
        // ... if not so lucky, lets see if we have a empty slot to move someone
        if (hasReadOperandSlot())
        {
          if (!operands.at(5).isBRSource())
          {
            Operand operandAt5 = operands.at(5);

            unsigned int oldIndex = operandAt5.getIndex();
            addReadOperand(operandAt5);
            unsigned int newIndex = operandAt5.getIndex();

            pattern->updateIndexes(oldIndex, newIndex);
            
            operands.erase(operands.begin()+5);
          }
          else
          {
            int freeSlotIndex = giveEmptyBranchSourceSlot();
            
            if (freeSlotIndex > -1)
            {
              operands.at(freeSlotIndex) = operands.at(5);
              operands.erase(operands.begin()+5);
            }
          }
        }
        else
        {
          throw std::range_error("Not found free slot to move operation.");
        }
      }
      
      this->opBRslot = operandReference; 
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
      
      if (operand.getValue() == 0 && !operand.isBRSource() && !operand.isBRDestiny())
      {
        operand.setIndex(15);
        return;
      }
      
      // If we not have the immediate yet, do the normal indexing
      unsigned int index = operands.size();

      if (opBRslot.getValue() > -1)
      {
        if (index >= opBRslot.getIndex())
          index++;
      }
      
      if (opBRFslot.getValue() > -1)
      {
        if (index >= opBRFslot.getIndex())
          index++;
      }
      
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
    }

    void
    rVex64PBIWInstruction::addBranchOperand(IOperand& operand)
    {
      int emptySlotIndex = giveEmptyBranchSourceSlot();
      
      if (emptySlotIndex > -1)
      {
        operand.setIndex(emptySlotIndex);
        
        // if the empty slot is at the end, well, put it at the end :P
        if (emptySlotIndex == static_cast<int>(operands.size()))
          operands.push_back(dynamic_cast<Operand&> (operand));
        else
          operands.at(emptySlotIndex) = dynamic_cast<Operand&> (operand);
      }
      
      if (emptySlotIndex == -2)
        operands.push_back(dynamic_cast<Operand&> (operand));
      
      if (emptySlotIndex == -1)
        throw std::range_error("Fail allocating empty slot for BRsrc operand.");
      
      return;
    }

    int
    rVex64PBIWInstruction::giveEmptyBranchSourceSlot()
    {
      // Check if there is space in the 0-7 slot range;
      if (operands.size() < 8)
      {
        if (operands.size() == 0)
          return -2;
        
        return operands.size();
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
            Operand operandIt = *it;
            
            unsigned int oldIndex = operandIt.getIndex();
            addReadOperand(operandIt);
            unsigned int newIndex = operandIt.getIndex();
            
            pattern->updateIndexes(oldIndex, newIndex);
            
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
          if (operand.getSyllableBelonged()->isOpcode(rVex::Syllable::opBR))
            return (opBRslot.getValue() == -1);
                                                      
          if (operand.getSyllableBelonged()->isOpcode(rVex::Syllable::opBRF))
            return (opBRFslot.getValue() == -1);
          
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

          break;
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
      int operandsSize = operands.size();
      
      if (immediate.isImmediate9Bits())
      {
        if (opBRslot.getValue() > -1)
        {
          if (opBRFslot.getValue() > -1)
            return (operandsSize < 8);
          
          return (operandsSize < 9);
        }
        
        return (operandsSize < 10);
      }
      else if (immediate.isImmediate12Bits())
      {
        if (opBRslot.getValue() > -1)
        {
          if (opBRFslot.getValue() > -1)
            return (operandsSize < 7);
          
          return (operandsSize < 8);
        }
        
        return (operandsSize < 9);
      }
      
      return (operandsSize < 12);
      
//      bool withImmSlot = 
//        (immediate.isImmediate9Bits() && (operandsSize < 10)) ||
//        (immediate.isImmediate12Bits() && (operandsSize < 9)) ||
//        (!immediate.isImmediate12Bits() && !immediate.isImmediate9Bits() && operandsSize < 12);
//      
//      bool withBRSlot = 
//        (opBRslot.getValue() > -1) && (operandsSize < 9) && (immediate.isImmediate9Bits()) ||
//        (opBRslot.getValue() > -1) && (operandsSize < 11) && (!immediate.isImmediate9Bits()) ||
//      
//        (opBRslot.getValue() > -1) && (operandsSize < 8) && (immediate.isImmediate12Bits()) ||
//        (opBRslot.getValue() > -1) && (operandsSize < 11) && (!immediate.isImmediate12Bits());
//      
//      bool withBRFSlot = 
//        (opBRFslot.getValue() > -1) && (operandsSize < 9) && (immediate.isImmediate9Bits()) ||
//        (opBRFslot.getValue() > -1) && (operandsSize < 11) && (!immediate.isImmediate9Bits()) ||
//      
//        (opBRFslot.getValue() > -1) && (operandsSize < 8) && (immediate.isImmediate12Bits()) ||
//        (opBRFslot.getValue() > -1) && (operandsSize < 11) && (!immediate.isImmediate12Bits());
//      
//      return withImmSlot || withBRFSlot || withBRSlot;
    }
}
