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
 * File:   Pattern.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 3:22 PM
 */

#include "Pattern.h"

namespace PBIW
{
  namespace Generic
  {

    Pattern::Pattern()
    {
    }

    Pattern::Pattern(const Pattern& orig)
    {
    }

    Pattern::~Pattern()
    {
    }

    IPBIWPattern*
    Pattern::clone() const
    {
    }

    void
    Pattern::setAddress(unsigned int)
    {
    }

    unsigned int
    Pattern::getAddress() const
    {
    }

    void
    Pattern::addOperation(IOperation*)
    {
    }

    IPBIWPattern::OperationVector
    Pattern::getOperations() const
    {
    }

    IOperation*
    Pattern::getOperation(unsigned int) const
    {
    }

    void
    Pattern::setOperation(IOperation&, int)
    {
    }

    IOperation* Pattern::operator[](const unsigned int) const
    {
    }

    bool
    Pattern::hasControlOperation() const
    {
    }

    unsigned int
    Pattern::getOperationCount() const
    {
    }

    void
    Pattern::updateIndexes(int oldIndex, int newIndex)
    {
    }

    void
    Pattern::referencedByInstruction(IPBIWInstruction*)
    {
    }

    std::deque<IPBIWInstruction*>
    Pattern::getInstructionsThatUseIt()
    {
    }

    void
    Pattern::reorganize()
    {
    }

    void
    Pattern::reorganize(bool)
    {
    }

    int
    Pattern::getUsageCounter() const
    {
    }

    void
    Pattern::resetUsageCounter()
    {
    }

    void
    Pattern::print(IPBIWPrinter&) const
    {
    }

    bool Pattern::operator<(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator>(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator<=(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator>=(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator==(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator!=(const IPBIWPattern&) const
    {
    }
  }
}