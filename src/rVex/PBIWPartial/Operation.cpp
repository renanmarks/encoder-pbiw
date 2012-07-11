/* 
 * File:   Operation.cpp
 * Author: helix
 * 
 * Created on October 20, 2011, 3:38 PM
 */

#include <cstddef>
#include <iostream>
#include "Operation.h"
#include "src/PBIW/Interfaces/IPBIWInstruction.h"
#include "src/rVex/Syllable.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;
  
  Operation::OperandIndexVector
  Operation::getOperandsIndexes() const  // O(1)
  {
    OperandIndexVector returnVector;
    returnVector.reserve(readOperands.size() + 2);
    
    returnVector.push_back(writeOperand);
    returnVector.insert(returnVector.end(), readOperands.begin(), readOperands.end());
    returnVector.push_back(writeBrOperand);
    returnVector.resize(4, -1);

    return returnVector;
  }
  
  void 
  Operation::updateIndexes(int oldIndex, int newIndex)
  {
    if (this->writeOperand == oldIndex)
      this->writeOperand = newIndex;

    if (this->writeBrOperand == oldIndex)
      this->writeBrOperand = newIndex;
    
    //if (this->readBrOperand == oldIndex)
    //  this->readBrOperand = newIndex;
    
    OperandIndexVector::iterator it;
    
    for(it = readOperands.begin(); 
        it < readOperands.end(); 
        it++)
    {
      if (*it == oldIndex)
        *it = newIndex;
    }
  }
  
  void
  Operation::addOperand(const IOperand& operand)  // O(1)
  {
    switch(this->getOpcode())
    {
      case rVex::Syllable::opGOTO:
      case rVex::Syllable::opIGOTO:
        if (writeOperand == -1)
        {
          writeOperand = 0;
          
          if (operand.isImmediate())
            readOperands.push_back(0);
        }
        break;
      
      case rVex::Syllable::opCALL:
        if (operand.isImmediate())
          readOperands.push_back(0);
        break;
        
      case rVex::Syllable::opBR:
      case rVex::Syllable::opBRF:
        if (writeOperand == -1)
          writeOperand = 0;
        break;
      
      case rVex::Syllable::opRETURN: // TODO
      case rVex::Syllable::opRFI:
          break;
    }
    
    if (this->writeOperand == -1)
    {
      this->writeOperand = operand.getIndex();
      return;
    }

    if (this->readOperands.size() < 2)
    {
      this->readOperands.push_back(operand.getIndex());
      return;
    }

    if (this->writeBrOperand == -1)
    {
      this->writeBrOperand = operand.getIndex();
      return;
    }
  }
  
  bool Operation::operator==(const IOperation& other) const  // O(1)
  {
    OperandIndexVector thisOperands = this->getOperandsIndexes();
    OperandIndexVector otherOperands = other.getOperandsIndexes();
    
    if (opcode != other.getOpcode())
      return false;
    
    if ( immediateSwitch != other.getImmediateSwitch() )
      return false;
    
    if (thisOperands.size() != otherOperands.size())
      return false;
    
    OperandIndexVector::const_iterator thisIt;
    OperandIndexVector::const_iterator otherIt;
    
    for(thisIt = thisOperands.begin(), otherIt = otherOperands.begin(); // O(|thisOperands|) =  O(4) = O(1)
        thisIt < thisOperands.end() && otherIt < otherOperands.end();
        thisIt++, otherIt++)
    {
      if (*thisIt != *otherIt)
        return false;
    }
    
    return true;
  }
  
  bool Operation::operator!=(const IOperation& other) const  // O(1)
  {
    return !(*this == other);
  }
}