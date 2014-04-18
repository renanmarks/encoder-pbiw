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
 * File:   IPrinter.h
 * Author: helix
 *
 * Created on September 17, 2011, 8:51 PM
 */

#ifndef IPRINTER_H
#define	IPRINTER_H

#include <ostream>
#include "GenericAssembly/Interfaces/IPrinter.h"

namespace rVex
{
  class Instruction;
  class Syllable;
  
  namespace Printers
  {
    /**
     * Printer interface
     * Used by the printing mechanisms to output the bytecode.
     */
    class IPrinter : public GenericAssembly::Interfaces::IPrinter<Instruction, Syllable>
    {
    public:
      virtual ~IPrinter() { }
    };
  }
}

#endif	/* IPRINTER_H */

