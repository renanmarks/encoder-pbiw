/* 
 * File:   Operation.cpp
 * Author: helix
 * 
 * Created on October 20, 2011, 3:38 PM
 */

#include <cstddef>
#include <iostream>
#include "Operation.h"
#include "Interfaces/IPBIWInstruction.h"

namespace PBIW
{
  using namespace Interfaces;
  
  Operation::OperandIndexVector
  Operation::getOperandsIndexes() const
  {
    OperandIndexVector returnVector;
    
    returnVector.push_back(writeOperand);
    returnVector.insert(returnVector.end(), readOperands.begin(), readOperands.end());
    returnVector.push_back(writeBrOperand);

    return returnVector;
  }
  
  void
  Operation::addOperand(const IOperand& operand)
  {
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
  
  bool Operation::operator==(const IOperation& other) const
  {
    OperandIndexVector::const_iterator it1, it2;
    OperandIndexVector thisOperands = this->getOperandsIndexes();
    OperandIndexVector otherOperands = this->getOperandsIndexes();
    
    if (opcode != other.getOpcode())
      return false;
    
    // Optimization? :)
    if (thisOperands.size() != otherOperands.size())
      return false;
    
    for (it1 = thisOperands.begin(), it2 = otherOperands.begin();
         it1 < thisOperands.end(), it2 < otherOperands.end();
         it1++, it2++ )
    {
      // If anyone different, quit
      if (*it1 != *it2)
        return false;
    }
    
    return true;
  }
  
  bool Operation::operator!=(const IOperation& other) const
  {
    return !(*this == other);
  }
}
