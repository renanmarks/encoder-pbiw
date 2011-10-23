/* 
 * File:   Operand.cpp
 * Author: helix
 * 
 * Created on October 20, 2011, 2:00 PM
 */

#include <ios>
#include <typeinfo>
#include "Operand.h"

namespace PBIW
{

  Operand::Operand(unsigned char value, bool isImmediate)
  : value(value), isImmediate(isImmediate)
  {}
  
  bool 
  Operand::operator==(const IOperand& operand) const
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      bool isEqual = (this->value == otherOperand.value) &&
                     (this->index == otherOperand.index) &&
                     (this->isImmediate == otherOperand.isImmediate);
      
      return isEqual;
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator!=(const IOperand& operand) const
  {
    return !(*this == operand);
  }
}
