/* 
 * File:   Operation.cpp
 * Author: helix
 * 
 * Created on October 20, 2011, 3:38 PM
 */

#include <cstddef>
#include "Operation.h"

namespace PBIW
{
  using namespace Interfaces;
  
  Operation::OperandVector
  Operation::getOperands() const
  {
    OperandVector returnVector;
    
    returnVector.push_back(writeOperand);
    returnVector.insert(returnVector.end(), readOperands.begin(), readOperands.end());
    returnVector.push_back(writeBrOperand);

    return returnVector;
  }

  void
  Operation::addOperand(IOperand* operand)
  {
    if (this->writeOperand == NULL)
    {
      this->writeOperand=operand;
      return;
    }

    if (this->readOperands.size() <= 2)
    {
      this->readOperands.push_back(operand);
      return;
    }

    if (this->writeBrOperand == NULL)
    {
      this->writeBrOperand=operand;
      return;
    }
  }
  
  bool Operation::operator==(const IOperation& other) const
  {
    OperandVector::const_iterator it1, it2;
    OperandVector thisOperands = this->getOperands();
    OperandVector otherOperands = this->getOperands();
    
    // Optimization? :)
    if (thisOperands.size() != otherOperands.size())
      return false;
    
    for (it1 = thisOperands.begin(),
         it2 = otherOperands.begin();
         it1 < thisOperands.end(),
         it2 < otherOperands.end();
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
