/* 
 * File:   PartialPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef PARTIALPBIWDEBUGPRINTER_H
#define	PARTIALPBIWDEBUGPRINTER_H

#include "src/PBIW/Interfaces/IPBIWPrinter.h"

namespace PBIW
{
  using namespace Interfaces;

  class PartialPBIWDebugPrinter : public IPBIWPrinter
  {
  public:
    PartialPBIWDebugPrinter(std::ostream& printer) 
    : printer(printer)
    { }
    
    PartialPBIWDebugPrinter(const PartialPBIWDebugPrinter& orig) 
    : printer( const_cast<PartialPBIWDebugPrinter&>(orig).getOutputStream() )
    { }
    
    virtual ~PartialPBIWDebugPrinter()
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

