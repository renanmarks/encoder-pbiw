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
 * File:   Printer.h
 * Author: helix
 *
 * Created on July 23, 2012, 9:37 PM
 */

#ifndef PBIW_GENERIC_PRINTER_H
#define	PBIW_GENERIC_PRINTER_H

#include "PBIW/Interfaces/IPBIWPrinter.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {

    class Printer : public IPBIWPrinter
    {
    public:
      Printer(std::ostream& output);
      Printer(const Printer& orig);
      virtual ~Printer();
      
      virtual void printInstructionsHeader();
      virtual void printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&);
      virtual void printInstructionsFooter(unsigned int);
      
      virtual void printPatternsHeader();
      virtual void printPattern(const IPBIWPattern&, const std::vector<unsigned int>&);
      virtual void printPatternsFooter(unsigned int);
      
      virtual std::ostream& getOutputStream();
      
    private:
      std::ostream& output;
    };
  }
}

#endif	/* PRINTER_H */

