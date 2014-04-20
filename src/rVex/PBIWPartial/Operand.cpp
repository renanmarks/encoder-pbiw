/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/* 
 * File:   Operand.cpp
 * Author: helix
 * 
 * Created on October 20, 2011, 2:00 PM
 */

#include <ios>
#include <typeinfo>
#include "Operand.h"
#include "rVex/Base/Operand.h"

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
