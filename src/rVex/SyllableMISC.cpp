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

#include <string>
#include "SyllableMISC.h"
#include "rVex/Printers/IPrinter.h"

namespace rVex
{
  void
  SyllableMISC::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
  {
    output.printOperation(*this, std::vector<unsigned int>(1, printRTYPE(first, last)));
  }
}
