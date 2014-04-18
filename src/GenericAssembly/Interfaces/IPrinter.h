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
 * Created on May 27, 2012, 5:35 PM
 */

#ifndef GENERICASSEMBLY_IPRINTER_H
#define	GENERICASSEMBLY_IPRINTER_H

#include <ostream>

namespace GenericAssembly
{
  namespace Interfaces
  {
    /**
     * Printer interface
     * Used by the printing mechanisms to output the bytecode.
     */
    template <class TInstruction, class TOperation>
    class IPrinter
    {
    public:
      virtual ~IPrinter() { }
      
      /**
       * Print the operation.
       */
      virtual void printOperation(const TOperation&, const std::vector<unsigned int>&) = 0;
      
      /**
       * Print the instruction.
       */
      virtual void printInstruction(const TInstruction&) = 0;
      
      /**
       * Print the file header.
       */
      virtual void printHeader() = 0;
      
      /**
       * Print the file footer.
       */
      virtual void printFooter() = 0;
      
      /**
       * Returns the output stream being used by this printer.
       */
      virtual std::ostream& getOutputStream() = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IPRINTER_H */

