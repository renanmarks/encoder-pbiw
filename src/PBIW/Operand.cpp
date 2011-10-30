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
  Operand::Operand(unsigned char value)
  : value(value), immType(Immediate::None)
  {
  }
  
  Operand::Operand(unsigned char value, Immediate::Type immediateType)
  : value(value), immType(immediateType)
  {
  }
  
  bool 
  Operand::operator<(const IOperand& operand) const
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      return (this->value < otherOperand.value);
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator>(const IOperand& operand) const
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      return (this->value > otherOperand.value);
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator<=(const IOperand& operand) const
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      return (this->value <= otherOperand.value);
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator>=(const IOperand& operand) const
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      return (this->value >= otherOperand.value);
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator==(const IOperand& operand) const
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      bool isEqual = 
        (this->value == otherOperand.value) &&
        (this->index == otherOperand.index) &&
        (this->isImmediate12Bits() == otherOperand.isImmediate12Bits()) &&
        (this->isImmediate9Bits() == otherOperand.isImmediate9Bits());
      
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
