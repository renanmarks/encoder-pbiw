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
#include "src/rVex/Instruction.h"

#define ZEROINDEX 0   // 15
#define IMM9BITS 10    // 10
#define IMM12BITS 11   // 11
#define ALLFIELDS 12   // 12
#define READFIELDS 8  // 8
#define WRITEFIELDS 4  // 4

namespace PBIW
{
  using namespace Interfaces;

  IPBIWInstruction* 
  rVex64PBIWInstruction::clone() const
  {
    return new rVex64PBIWInstruction(*this);
  }
    
  void 
  rVex64PBIWInstruction::setSyllableReferences(const std::list<rVex::Syllable*>& list)
  { 
    syllablesPacked = list; 
    std::list<rVex::Syllable*>::const_iterator it;
    
    for(it = list.begin(); it != list.end(); it++)
      (*it)->getBelongedInstruction()->addReferencePBIWInstruction(*this);
  }
  
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
      
      for(int i=0; i<ALLFIELDS; i++)
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
      
      // Extra bit
      //output.longWord<<=1;
            
      for(unsigned int i = 0;
              i < annulBits.size();
              i++) 
      {
          output.longWord<<=1;
          output.longWord|= annulBits[i];          
      }
      
      // Get rid of the -1 values
      for (it=operands.begin();
           it < operands.end();
           it++)
      {
        if ((it->getValue() < 0) && (!it->isImmediate()))
          it->setValue(zeroOperand.getValue());
      }

      bool hasImm9Bits=operands[IMM9BITS].isImmediate9Bits();
      bool hasImm12Bits=operands[IMM12BITS].isImmediate12Bits();
      bool hasImmediate=hasImm9Bits || hasImm12Bits;

      if (!hasImmediate)
      {
        // operands
        for (it=operands.begin()+1; // O(|operands|) = O(4) = O(1)
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
        for (it=operands.begin()+1; // O(|operands|) = O(4) = O(1)
             it < operands.end()-3;
             it++)
        {
          output.longWord<<=5;
          output.longWord|=it->getValue();
        }
        
        if (hasImm9Bits)
        {
          output.longWord<<=10;
          output.longWord|=(0x000001FF & operands[IMM9BITS].getValue());

          output.longWord<<=3;
          output.longWord|=operands[IMM12BITS].getValue();
        }

        if (hasImm12Bits)
        {
          output.longWord<<=13;
          output.longWord|=(0x00000FFF & operands[IMM12BITS].getValue());
        }
      }

      std::vector<unsigned int> binary;
      binary.push_back(output.word[1]);
      binary.push_back(output.word[0]);

      printer.printInstruction(*this, binary);
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

      this->pattern = &temp;
      this->pattern->referencedByInstruction(this);
    }

    const IOperand&
    rVex64PBIWInstruction::containsOperand(const IOperand& operand) const // O(1)
    {
      if (operand.getValue() == 0 /*&& !operand.isBRSource() && !operand.isBRDestiny()*/ && !operand.isImmediate())
        return zeroOperand;
      
      OperandVector::const_iterator it;

      for (it = operands.begin(); // O(|operands|) = O(8) = O(1)
           it < operands.end();
           it++)
      {
        if (*it == operand)
          return *it;
      }
      
      if (opBRslot == operand)
        return opBRslot;

      if (opBRFslot == operand)
        return opBRFslot;
      
      if (operand.isImmediate() && immediate == operand)
        return immediate;
      
      return operand;
    }
    
    void rVex64PBIWInstruction::setBranchSlot(const Operand& operand, Operand& field)
    {
      unsigned int index = operand.getIndex();
      unsigned int size = index+1;
      
      std::list<Operand> operandsTemp(operands.begin(), operands.end());
      std::list<Operand>::iterator operandIt = std::find(operandsTemp.begin(), operandsTemp.end(), operand);
      
      // If found the operand, lets remove it and use it at the specified slot
      if (operandIt != operandsTemp.end() && operandIt->getValue() != 0 && operandIt->getIndex() != 0)
      {
        // Save the old index, so we can update the pattern at next
        unsigned int oldIndex = operandIt->getIndex();
        operandsTemp.erase(operandIt);
        
        // Update the indexes
        pattern->updateIndexes(oldIndex, index);
        
        // Re-index all the operands as consequence of the move!
        int newIndex = 0;
        for(operandIt = operandsTemp.begin(); operandIt != operandsTemp.end(); operandIt++, newIndex++)
        {
          if (newIndex == 5 && this->opBRslot.getValue() > -1)
            newIndex++;
          
          if (newIndex == 6 && this->opBRFslot.getValue() > -1)
            newIndex++;
          
          pattern->updateIndexes(operandIt->getIndex(), newIndex);
          operandIt->setIndex(newIndex);
        }
        
        // Sort them and apply to the original vector
        operandsTemp.sort();
        operands.assign(operandsTemp.begin(), operandsTemp.end());
      }
      
      // The slot is occupied
      if (operands.size() >= size)
      {
        // If we're lucky...!
        if (operands.at(index) == operand)
        {
          operands.erase(operands.begin()+index);
          field = operand;
          return;
        }
        
        // ... if not so lucky, lets see if we have a empty slot to move someone
        if (hasReadOperandSlot())
        {
          if (!operands.at(index).isBRSource())
          {
            Operand operandAtIndex = operands.at(index);

            unsigned int oldIndex = operandAtIndex.getIndex();
            addReadOperand(operandAtIndex);
            unsigned int newIndex = operandAtIndex.getIndex();

            pattern->updateIndexes(oldIndex, newIndex);
            
            operands.erase(operands.begin()+index);
          }
          else
          {
            int freeSlotIndex = giveEmptyBranchSourceSlot();
            
            if (freeSlotIndex > -1)
            {
              operands.at(freeSlotIndex) = operands.at(index);
              operands.erase(operands.begin()+index);
            }
          }
        }
        else
        {
          throw std::range_error("Not found free slot to move operation.");
        }
      }
      
      field = operand; 
    }
    
    void rVex64PBIWInstruction::setOpBRFslot(IOperand& operand)
    { 
      Operand& operandReference = dynamic_cast<Operand&>(operand);
      operandReference.setIndex(6);
      
      setBranchSlot(operandReference, this->opBRFslot);
    }

    void rVex64PBIWInstruction::setOpBRslot(IOperand& operand)
    { 
      Operand& operandReference = dynamic_cast<Operand&>(operand);
      operandReference.setIndex(5);
      
      setBranchSlot(operandReference, this->opBRFslot);
    }
    
//    rVex64PBIWInstruction::AnnulationBits
//    rVex64PBIWInstruction::getAnnulBits()
//    {
//        AnnulationBits bits;
//        
//        for(int i = 0; i < 4; i++)
//            bits.push_back(annulBits[i]);
//        
//        return bits;
//    }
    
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
          operand.setIndex(IMM9BITS);
        else if (operand.isImmediate12Bits())
          operand.setIndex(IMM12BITS);

        immediate=dynamic_cast<Operand&> (operand);

        return;
      }
      
      if (operand.getValue() == 0 /*&& !operand.isBRSource() && !operand.isBRDestiny()*/)
      {
        operand.setIndex(zeroOperand.getIndex());
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
          if (operands.size() == 8) // 9
            index = 10;
          else if (operands.size() < 8)
            index = operands.size();
        }
        else if (immediate.isImmediate12Bits())
        {
          if (operands.size() < 8)
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
      if (operands.size() < READFIELDS)
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
        
        for(it = operands.begin(); it < operands.begin()+READFIELDS; it++, index++)
        {
          // Change the operand position and inform the new space opened
          if (!it->isBRSource() && it->getValue() != 0 && it->getIndex() != 0)
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

          if (operand.getOperand()->isImmediate9Bits() && operands.size() == 9)
          {
            if (operands.back().getValue() < READFIELDS)
            {
              operands.back().setIndex(IMM12BITS);
              return true;
            }

            return false;
          }

          if (operand.getOperand()->isImmediate9Bits() && operands.size() > 9)
            return false;

          if (operand.getOperand()->isImmediate12Bits() && operands.size() > 9)
            return false;
          break;

        case Utils::OperandItem::BRSource:
          if (operand.getSyllableBelonged()->isOpcode(rVex::Syllable::opBR))
            return (opBRslot.getValue() == -1);
                                                      
          if (operand.getSyllableBelonged()->isOpcode(rVex::Syllable::opBRF))
            return (opBRFslot.getValue() == -1);
          
          // Check if there is space in the 0-7 slot range;
          if (operands.size() < READFIELDS)
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
            return (operandsSize < READFIELDS);
          
          return (operandsSize < 8);
        }
        
        return (operandsSize < 9);
      }
      else if (immediate.isImmediate12Bits())
      {
        if (opBRslot.getValue() > -1)
        {
          if (opBRFslot.getValue() > -1)
            return (operandsSize < 6);
          
          return (operandsSize < READFIELDS);
        }
        
        return (operandsSize < 8);
      }
      
      return (operandsSize < ALLFIELDS);
    }
}