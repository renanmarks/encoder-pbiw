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
    OperandIndexVector thisOperands = this->getOperandsIndexes();
    OperandIndexVector otherOperands = other.getOperandsIndexes();
    
    if (opcode != other.getOpcode())
      return false;
    
    if (thisOperands.size() != otherOperands.size())
      return false;
    
    if (thisOperands != otherOperands)
      return false;
    
    return true;
  }
  
  bool Operation::operator!=(const IOperation& other) const
  {
    return !(*this == other);
  }
}
