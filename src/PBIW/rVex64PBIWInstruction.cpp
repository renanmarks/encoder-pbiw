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
#include "src/PBIW/Interfaces/IOperand.h"
#include "src/GenericAssembly/Interfaces/IOperation.h"
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

  void
  rVex64PBIWInstruction::setAddress(unsigned int addr)
  {
    address=addr;
  }

  unsigned int
  rVex64PBIWInstruction::getAddress() const
  {
    return address;
  }

  ILabel*
  rVex64PBIWInstruction::getLabel() const
  {
    return label;
  }

  std::string
  rVex64PBIWInstruction::getLabelDestiny() const
  {
    return destinyLabel;
  }

  void
  rVex64PBIWInstruction::setLabelDestiny(std::string label)
  {
    this->destinyLabel=label;
  }

  void
  rVex64PBIWInstruction::setImmediateValue(int value)
  {
    immediate.setValue(value);
  }

  int
  rVex64PBIWInstruction::readOperandQuantity() const
  {
    return operands.size();
  }

  int
  rVex64PBIWInstruction::writeOperandQuantity() const
  {
    return 0;
  }

  void
  rVex64PBIWInstruction::setCodingOperation(IOperation& operation)
  {
    codingOperation= &dynamic_cast<Operation&> (operation);
  }

  IOperation*
  rVex64PBIWInstruction::getCodingOperation() const
  {
    return codingOperation;
  }

  rVex96PBIWPattern*
  rVex64PBIWInstruction::getPattern() const
  {
    return this->pattern;
  }

  bool
  rVex64PBIWInstruction::containsImmediate() const
  {
    return immediate.isImmediate9Bits() || immediate.isImmediate12Bits();
  }
  
  IPBIWInstruction* 
  rVex64PBIWInstruction::clone() const
  {
    return new rVex64PBIWInstruction(*this);
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

    void 
    rVex64PBIWInstruction::updateIndexes(int oldIndex, int newIndex)
    {
      pattern->updateIndexes(oldIndex, newIndex);
      codingOperation->updateIndexes(oldIndex, newIndex);
    }
    
    void rVex64PBIWInstruction::setBranchSlot(const Operand& operand, Operand& field)
    {
      // Spill index (to prevent cyclic dependencies at swap)
      const unsigned int spillIndex = 99;
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
        
        // First, update the indexes with the spill index...
        updateIndexes(oldIndex, spillIndex);
        
        // Re-index all the operands as consequence of the move!
        int newIndex = 0;
        for(operandIt = operandsTemp.begin(); operandIt != operandsTemp.end(); operandIt++, newIndex++)
        {
          if (newIndex == 5 && (opBRslot.getValue() > -1 || &opBRslot == &field))
            newIndex++;
          
          if (newIndex == 6 && (opBRFslot.getValue() > -1 || &opBRFslot == &field))
            newIndex++;
          
          updateIndexes(operandIt->getIndex(), newIndex);
          operandIt->setIndex(newIndex);
        }
        
        // next change the spill indexes back to the new index!
        updateIndexes(spillIndex, index);
        
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
          if (!operands.at(index).isBRSource() && !operands.at(index).isBRDestiny())
          {
            Operand operandAtIndex = operands.at(index);

            // Spill index (to prevent cyclic dependencies at swap)
            const unsigned int spillIndex = 100;
            
            updateIndexes(operandAtIndex.getIndex(), spillIndex);
            addReadOperand(operandAtIndex);
            updateIndexes(operandAtIndex.getIndex(), spillIndex);

            operands.erase(operands.begin()+index);
          }
          else
          {
            int freeSlotIndex = giveEmptyBranchSourceSlot();
            
            if (freeSlotIndex > -1)
            {
              operands.at(freeSlotIndex) = operands.at(index);
              updateIndexes(index, freeSlotIndex);
              operands.erase(operands.begin()+index);
            }
          }
        }
        else
        {
          throw std::range_error("Not found free slot to move operand.");
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
   
    void
    rVex64PBIWInstruction::addWriteOperand(IOperand& operand) // O(1)
    {
      addReadOperand(operand);
    }
    
    unsigned int 
    rVex64PBIWInstruction::giveEmptySlot() const
    {
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

      return index;
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
      unsigned int index = giveEmptySlot();
      
      if (index == 11 && operand.getValue() >= 8)
      {
        // Spill index (to prevent cyclic dependencies at swap)
        const unsigned int spillIndex = 101;
        std::list<Operand> operandsTemp(operands.begin(), operands.end());
        std::list<Operand>::iterator operandIt = std::find_if(operandsTemp.begin(), operandsTemp.end(), Find3BitsOperand());

        // If found the operand, lets move it and use it at the specified slot
        if (operandIt != operandsTemp.end())
        {
          Operand substituteOperand = *operandIt;
          
          // First, update the indexes with the spill index...
          updateIndexes(substituteOperand.getIndex(), spillIndex);
          
          *(operandIt) = dynamic_cast<const Operand&>(operand); 
          operand.setIndex(substituteOperand.getIndex()); // To return the index, maintaining the semantics of the code
          operandIt->setIndex(substituteOperand.getIndex()); // Copy 11th operand to the position
          
          substituteOperand.setIndex(index);
          operandsTemp.push_back(substituteOperand); // put the 3 bit operand into the last position

          // next change the spill indexes back to the new index!
          updateIndexes(spillIndex, index);

          // Sort them and apply to the original vector
          operandsTemp.sort();
          operands.clear();
          operands.assign(operandsTemp.begin(), operandsTemp.end());
        }
      }
      else
      {
        operand.setIndex(index);
        operands.push_back(dynamic_cast<Operand&> (operand));
      }
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
          if (!it->isBRSource() && !it->isBRDestiny() && it->getValue() != 0 && it->getIndex() != 0)
          {
            Operand operandIt = *it;
            
            // Spill index (to prevent cyclic dependencies at swap)
            const unsigned int spillIndex = 102;
            
            updateIndexes(operandIt.getIndex(), spillIndex);
            addReadOperand(operandIt);
            updateIndexes(spillIndex, operandIt.getIndex());
            
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
      switch (operand.getType()) 
      {
        case Utils::OperandItem::Imm:
          if (this->containsImmediate())
            return false;

          if (operand.getOperand()->isImmediate9Bits() && operands.size() == 10)
          {
            if (operands.back().getValue() < 8)
            {
              operands.back().setIndex(IMM12BITS);
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
          if (operand.getOperationBelonged()->isOpcode(rVex::Syllable::opBR))
            return (opBRslot.getValue() == -1);
                                                      
          if (operand.getOperationBelonged()->isOpcode(rVex::Syllable::opBRF))
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
          if (giveEmptySlot() == 11 && operand.getOperand()->getValue() >= 8)
          {
            OperandVector::iterator operandIt = std::find_if(operands.begin(), operands.end(), Find3BitsOperand());
            
            // If not found operand to change, we cannot add this operand
            return (operandIt != operands.end());
          }
          
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
      
      return (operandsSize < ALLFIELDS);
    }
}
