/* 
 * File:   PartialPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef PARTIALPBIWPRINTER_H
#define	PARTIALPBIWPRINTER_H

#include "src/PBIW/Interfaces/IPBIWPrinter.h"

namespace PBIW
{
  using namespace Interfaces;

  class PartialPBIWPrinter : public IPBIWPrinter
  {
  public:
    PartialPBIWPrinter(std::ostream& printer) 
    : printer(printer)
    { }
    
    PartialPBIWPrinter(const PartialPBIWPrinter& orig) 
    : printer( const_cast<PartialPBIWPrinter&>(orig).getOutputStream() )
    { }
    
    virtual ~PartialPBIWPrinter()
    { }

    virtual void printPatternsHeader();
    virtual void printPattern(const IPBIWPattern&, const std::vector<unsigned int>&);
    virtual void printPatternsFooter();

    virtual void printInstructionsHeader();
    virtual void printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&);
    virtual void printInstructionsFooter();
    
    virtual std::ostream& getOutputStream()
    { return printer; }

  private:
    std::ostream& printer;
  };

}

#endif	/* PARTIALPBIWPRINTER_H */

