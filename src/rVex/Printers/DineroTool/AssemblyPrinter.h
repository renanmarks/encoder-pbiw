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
 * File:   AssemblyPrinter.h
 * Author: helix
 *
 * Created on October 11, 2011, 3:04 PM
 */

#ifndef RVEX_PRINTERS_DINEROTOOL_ASSEMBLYPRINTER_H
#define	RVEX_PRINTERS_DINEROTOOL_ASSEMBLYPRINTER_H

#include <ostream>
#include "rVex/Base/rVex.h"
#include "rVex/Printers/IPrinter.h"

namespace rVex
{
  namespace Printers
  {
    namespace DineroTool
    {
      /**
      * Printer that outputs instruction data used to generate Dinero Traces
      */
      class AssemblyPrinter : public IPrinter
      {
      public:
        AssemblyPrinter( std::ostream& );
        virtual ~AssemblyPrinter( ) { }

        /**
        * Print the syllable.
        */
        virtual void printOperation(const rVex::Base::Syllable&, const std::vector<unsigned int>&);

        /**
        * Print the instruction.
        */
        virtual void printInstruction(const rVex::Base::Instruction&);

        /**
        * Print the file header.
        */
        virtual void printHeader();

        /**
        * Print the file footer.
        */
        virtual void printFooter();

        /**
        * Return output print stream.
        */
        virtual std::ostream& getOutputStream()
        { return output; }

        void setFileName(const std::string& filename)
        { this->filename = filename; }

        void setAssemblerFlags(const std::string& flags)
        { this->flags = flags; }

      private:
        std::ostream& output;
        std::string filename;
        std::string flags;
        std::string date;

      };
    }
  }
}

#endif	/* ASSEMBLYPRINTER_H */

