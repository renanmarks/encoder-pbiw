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
  : index(0), immType(Immediate::None), branchType(Branch::None), value(0)
  {
  }
  
  Operand::Operand(int value)
  : index(0), immType(Immediate::None), branchType(Branch::None), value(value)
  {
  }
  
  Operand::Operand(int value, Immediate::Type immediateType)
  : index(0), immType(immediateType), branchType(Branch::None), value(value)
  {
  }
  
  Operand::Operand(const Operand& other)
  : index(other.getIndex()), immType(other.getImmediateType()), branchType(other.getBanchType()), value(other.getValue())
  {
  }
  
  bool 
  Operand::operator<(const IOperand& operand) const  // O(1)
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      return (this->index < otherOperand.getIndex());
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator>(const IOperand& operand) const // O(1)
  {
    try
    {
      IOperand& tempOperand = const_cast<IOperand&>(operand);
      Operand& otherOperand = dynamic_cast<Operand&>(tempOperand);
      
      return (this->index > otherOperand.getIndex());
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }
  
  bool 
  Operand::operator<=(const IOperand& operand) const  // O(1)
  {
    return !(*this > operand);
  }
  
  bool 
  Operand::operator>=(const IOperand& operand) const  // O(1)
  {
    return !(*this < operand);
  }
  
  bool 
  Operand::operator==(const IOperand& operand) const  // O(1)
  {
    IOperand& tempOperand = const_cast<IOperand&>(operand);
    Operand& otherOperand = static_cast<Operand&>(tempOperand);

    bool isEqual = 
      (this->value == otherOperand.getValue()) &&
      //(this->index == otherOperand.index) &&
      (this->isImmediate12Bits() == otherOperand.isImmediate12Bits()) &&
      (this->isImmediate9Bits() == otherOperand.isImmediate9Bits());

    return isEqual;
  }
  
  bool 
  Operand::operator!=(const IOperand& operand) const  // O(1)
  {
    return !(*this == operand);
  }
}
