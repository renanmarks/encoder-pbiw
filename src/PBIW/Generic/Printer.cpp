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
 * File:   Printer.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 9:37 PM
 */

#include "Printer.h"

namespace PBIW
{
  namespace Generic
  {

    Printer::Printer(std::ostream& output)
    : output(output)
    {
    }

    Printer::Printer(const Printer& orig)
    : output(orig.output)
    {
    }

    Printer::~Printer()
    {
    }

    void
    Printer::printInstructionsHeader()
    {
    }

    void
    Printer::printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&)
    {
    }

    void
    Printer::printInstructionsFooter(unsigned int)
    {
    }

    void
    Printer::printPatternsHeader()
    {
    }

    void
    Printer::printPattern(const IPBIWPattern&, const std::vector<unsigned int>&)
    {
    }

    void
    Printer::printPatternsFooter(unsigned int)
    {
    }

    std::ostream&
    Printer::getOutputStream()
    {
    }
  }
}
