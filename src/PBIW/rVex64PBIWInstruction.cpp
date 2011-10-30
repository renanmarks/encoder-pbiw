/* 
 * File:   PBIWInstruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */

#include <algorithm>
#include "rVex64PBIWInstruction.h"
#include "Interfaces/IOperand.h"

namespace PBIW
{
  using Interfaces::IOperand;

  void
  rVex64PBIWInstruction::pointToPattern(IPBIWPattern* pattern)
  {
    rVex96PBIWPattern* temp=dynamic_cast<rVex96PBIWPattern*> (pattern);

    if (temp != NULL)
      this->pattern=temp;
  }

  bool
  rVex64PBIWInstruction::containsOperand(const IOperand& operand) const
  {
    //    bool foundInReadOperands = std::find(readOperands.begin(), readOperands.end(), operand);
    //    bool foundInWriteOperands = std::find(writeOperands.begin(), writeOperands.end(), operand);
    //    return (foundInReadOperands || foundInWriteOperands);

    OperandVector::const_iterator it;

    for (it=readOperands.begin();
         it < readOperands.end();
         it++)
    {
      if ( (*it)->getValue() == operand.getValue() && 
           (*it)->isImmediate() == operand.isImmediate() )
        return true;
    }

    for (it=writeOperands.begin();
         it < writeOperands.end();
         it++)
    {
      if ( (*it)->getValue() == operand.getValue() && 
           (*it)->isImmediate() == operand.isImmediate() )
        return true;
    }
    
    return false;
  }

  void
  rVex64PBIWInstruction::addReadOperand(IOperand* operand)
  {
    this->readOperands.push_back(operand);
    
    unsigned int index = this->readOperands.size();
    operand->setIndex(index);
  }

  void
  rVex64PBIWInstruction::addWriteOperand(IOperand* operand)
  {
    this->writeOperands.push_back(operand);
    
    if (operand->isImmediate9Bits())
      has9BitImm = true;
    else if (operand->isImmediate12Bits())
      has12BitImm = true;
    
    unsigned int index = this->writeOperands.size();
    operand->setIndex(index);
  }

  bool
  rVex64PBIWInstruction::hasOperandSlot() const
  {
    return hasReadOperandSlot() || hasWriteOperandSlot();
  }

  bool
  rVex64PBIWInstruction::hasReadOperandSlot() const
  {
    return readOperands.size() < 8;
  }

  bool
  rVex64PBIWInstruction::hasWriteOperandSlot() const
  {
    return readOperands.size() < 4;
  }
}
