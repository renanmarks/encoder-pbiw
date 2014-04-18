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
 * File:   IPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:05 PM
 */

#ifndef IPBIWPRINTER_H
#define	IPBIWPRINTER_H

#include <ostream>
#include <list>
#include <vector>

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIWPattern;
    class IPBIWInstruction;
    
    class IPBIWPrinter
    {
    public:
      virtual ~IPBIWPrinter() { }
      
      /**
       * Print the instruction file header.
       */
      virtual void printInstructionsHeader() = 0;
      
      /**
       * Print the instruction.
       */
      virtual void printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&) = 0;
      
      /**
       * Print the instruction file footer.
       */
      virtual void printInstructionsFooter(unsigned int) = 0;
      
      
      /**
       * Print the Pattern file header.
       */
      virtual void printPatternsHeader() = 0;
      
      /**
       * Print the pattern.
       */
      virtual void printPattern(const IPBIWPattern&, const std::vector<unsigned int>&) = 0;
      
      /**
       * Print the Pattern file footer.
       */
      virtual void printPatternsFooter(unsigned int) = 0;
      
      
      virtual std::ostream& getOutputStream() = 0;
    };
  }
}


#endif	/* IPBIWPRINTER_H */
