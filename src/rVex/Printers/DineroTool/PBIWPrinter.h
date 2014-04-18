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
 * File:   PBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef RVEX_PRINTERS_DINEROTOOL_PBIWPRINTER_H
#define	RVEX_PRINTERS_DINEROTOOL_PBIWPRINTER_H

#include "PBIW/Interfaces/IPBIWPrinter.h"

namespace rVex
{
  namespace Printers
  {
    namespace DineroTool
    {
      using namespace PBIW::Interfaces;

      class PBIWPrinter : public IPBIWPrinter
      {
      public:
        PBIWPrinter(std::ostream& printer) 
        : printer(printer)
        { }

        PBIWPrinter(const PBIWPrinter& orig) 
        : printer( const_cast<PBIWPrinter&>(orig).getOutputStream() )
        { }

        virtual ~PBIWPrinter()
        { }

        virtual void printPatternsHeader();
        virtual void printPattern(const IPBIWPattern&, const std::vector<unsigned int>&);
        virtual void printPatternsFooter(unsigned int);

        virtual void printInstructionsHeader();
        virtual void printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&);
        virtual void printInstructionsFooter(unsigned int);

        virtual std::ostream& getOutputStream()
        { return printer; }

      private:
        std::ostream& printer;
      };
    }
  }
}

#endif	/* RVEX_PRINTERS_DINEROTOOL_PARTIALPBIWPRINTER_H */

