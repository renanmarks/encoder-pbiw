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
  Operand::Operand()
  : index(0), immType(Immediate::None), value(0)
  {
  }
  
  Operand::Operand(unsigned char value)
  : index(0), immType(Immediate::None), value(value)
  {
  }
  
  Operand::Operand(unsigned char value, Immediate::Type immediateType)
  : index(0), immType(immediateType), value(value)
  {
  }
  
  Operand::Operand(const Operand& other)
  : index(other.getIndex()), immType(other.getImmediateType()), value(other.getValue())
  {
  }
  
  bool 
  Operand::operator<(const IOperand& operand) const
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      return (this->index < otherOperand.index);
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
      
      return (this->index > otherOperand.index);
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator<=(const IOperand& operand) const
  {
    return !(*this > operand);
  }
  
  bool 
  Operand::operator>=(const IOperand& operand) const
  {
    return !(*this < operand);
  }
  
  bool 
  Operand::operator==(const IOperand& operand) const
  {
//    try
//    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = static_cast<Operand&>(tempOperand);
      
      bool isEqual = 
        (this->value == otherOperand.value) &&
        //(this->index == otherOperand.index) &&
        (this->isImmediate12Bits() == otherOperand.isImmediate12Bits()) &&
        (this->isImmediate9Bits() == otherOperand.isImmediate9Bits());
      
      return isEqual;
//    }
//    catch (std::bad_cast ex)
//    {
//      return false;
//    }
  }
  
  bool 
  Operand::operator!=(const IOperand& operand) const
  {
    return !(*this == operand);
  }
}
