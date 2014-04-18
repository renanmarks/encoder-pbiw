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
 * Created on July 23, 2012, 5:02 PM
 */

#include "Operand.h"

namespace PBIW
{
  namespace Generic
  {

    Operand::Operand()
    {
    }

    Operand::Operand(const Operand& orig)
    {
    }

    Operand::~Operand()
    {
    }

    IOperand*
    Operand::clone() const
    {
    }

    void
    Operand::setIndex(unsigned int)
    {
    }

    unsigned int
    Operand::getIndex() const
    {
    }

    bool
    Operand::isImmediate() const
    {
    }

    bool
    Operand::isImmediate9Bits() const
    {
    }

    void
    Operand::isImmediate9Bits(bool)
    {
    }

    bool
    Operand::isImmediate12Bits() const
    {
    }

    void
    Operand::isImmediate12Bits(bool)
    {
    }

    void
    Operand::setValue(int)
    {
    }

    int
    Operand::getValue() const
    {
    }

    bool
    Operand::isBRSource() const
    {
    }

    void
    Operand::setBRSource(const bool)
    {
    }

    bool
    Operand::isBRDestiny() const
    {
    }

    void
    Operand::setBRDestiny(const bool)
    {
    }

    bool Operand::operator<(const IOperand&) const
    {
    }

    bool Operand::operator>(const IOperand&) const
    {
    }

    bool Operand::operator<=(const IOperand&) const
    {
    }

    bool Operand::operator>=(const IOperand&) const
    {
    }

    bool Operand::operator==(const IOperand&) const
    {
    }

    bool Operand::operator!=(const IOperand&) const
    {
    }
  }
}
