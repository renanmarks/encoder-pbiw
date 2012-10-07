/* 
 * File:   Operand.cpp
 * Author: helix
 * 
 * Created on October 20, 2011, 2:00 PM
 */

#include <ios>
#include <typeinfo>
#include "Operand.h"
#include "src/rVex/Operand.h"

namespace PBIWPartial
{
  Operand::Operand()
  : index(0), type(rVex::Operand::GRSource),  value(0)
  {
  }
  
  Operand::Operand(int value)
  : index(0), type(rVex::Operand::GRSource), value(value)
  {
  }
  
  Operand::Operand(int value, rVex::Operand::Type operandType)
  : index(0), type(operandType), value(value)
  {
  }
  
  Operand::Operand(const Operand& other)
  : index(other.getIndex()), type(other.type), value(other.getValue())
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
      (this->isImmediate9Bits() == otherOperand.isImmediate9Bits()) &&
      (this->isBRSource() == otherOperand.isBRSource());

    return isEqual;
  }
  
  bool 
  Operand::operator!=(const IOperand& operand) const  // O(1)
  {
    return !(*this == operand);
  }
}
