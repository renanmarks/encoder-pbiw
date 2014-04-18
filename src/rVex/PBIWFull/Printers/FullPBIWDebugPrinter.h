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
 * File:   PartialPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef PBIWFULL_DEBUGPRINTER_H
#define	PBIWFULL_DEBUGPRINTER_H

#include "PBIW/Interfaces/IPBIWPrinter.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

  class FullPBIWDebugPrinter : public IPBIWPrinter
  {
  public:
    FullPBIWDebugPrinter(std::ostream& printer) 
    : printer(printer)
    { }
    
    FullPBIWDebugPrinter(const FullPBIWDebugPrinter& orig) 
    : printer( const_cast<FullPBIWDebugPrinter&>(orig).getOutputStream() )
    { }
    
    virtual ~FullPBIWDebugPrinter()
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

#endif	/* PARTIALPBIWPRINTER_H */

