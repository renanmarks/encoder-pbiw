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
 * File:   Operation.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 4:12 PM
 */

#include "Operation.h"

namespace PBIW
{
  namespace Generic
  {

    Operation::Operation()
    {
    }

    Operation::Operation(const Operation& orig)
    {
    }

    Operation::~Operation()
    {
    }

    IOperation*
    Operation::clone() const
    {
    }

    void
    Operation::setOpcode(unsigned short opcode)
    {
    }

    unsigned short
    Operation::getOpcode() const
    {
    }

    void
    Operation::setOriginalOpcode(unsigned short opcode)
    {
    }

    unsigned short
    Operation::getOriginalOpcode() const
    {
    }

    void
    Operation::setBrReadOperand(short opcode)
    {
    }

    short
    Operation::getBrReadOperand() const
    {
    }

    void
    Operation::setImmediateSwitch(int)
    {
    }

    int
    Operation::getImmediateSwitch() const
    {
    }

    void
    Operation::addOperand(const IOperand&)
    {
    }

    Operation::OperandIndexVector
    Operation::getOperandsIndexes() const
    {
    }

    void
    Operation::updateIndexes(int oldIndex, int newIndex)
    {
    }

    void
    Operation::setType(int)
    {
    }

    int
    Operation::getType() const
    {
    }

    bool Operation::operator==(const IOperation&) const
    {
    }

    bool Operation::operator!=(const IOperation&) const
    {
    }

  }
}