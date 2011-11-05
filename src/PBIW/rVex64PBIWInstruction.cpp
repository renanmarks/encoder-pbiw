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
  using namespace Interfaces;

  rVex64PBIWInstruction::OperandVector
  rVex64PBIWInstruction::getOperands() const
  {
    rVex64PBIWInstruction::OperandVector returnVector(readOperands.begin(), readOperands.end());
    returnVector.insert(returnVector.end(), writeOperands.begin(), writeOperands.end());
    
    return returnVector;
  }

  void
  rVex64PBIWInstruction::print(IPBIWPrinter&) const
  {

  }

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
      if ( **it == operand )
        return true;
    }

    for (it=writeOperands.begin();
         it < writeOperands.end();
         it++)
    {
      if ( **it == operand )
        return true;
    }

    return false;
  }

  void
  rVex64PBIWInstruction::addReadOperand(IOperand* operand)
  {
    this->readOperands.push_back(operand);

    unsigned int index=this->readOperands.size();
    operand->setIndex(index);
  }

  void
  rVex64PBIWInstruction::addWriteOperand(IOperand* operand)
  {
    if (operand->isImmediate9Bits())
      has9BitImm=true;
    else if (operand->isImmediate12Bits())
      has12BitImm=true;

    this->writeOperands.push_back(operand);
    unsigned int index=this->writeOperands.size() - 1;
    operand->setIndex(index);
  }

  bool
  rVex64PBIWInstruction::hasOperandSlot() const
  {
    return hasWriteOperandSlot() || hasReadOperandSlot();
  }

  bool
  rVex64PBIWInstruction::hasReadOperandSlot() const
  {
    return readOperands.size() < 8;
  }

  bool
  rVex64PBIWInstruction::hasWriteOperandSlot() const
  {
    bool fullWriteSlots =
      (has12BitImm && (writeOperands.size() == 2)) ||
      (has9BitImm && (writeOperands.size() == 3)) ||
      (writeOperands.size() == 4);

    return !fullWriteSlots;
  }
}
