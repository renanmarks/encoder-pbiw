/* 
 * File:   PartialPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef PARTIALPBIWPRINTER_H
#define	PARTIALPBIWPRINTER_H

#include "Interfaces/IPBIWPrinter.h"

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

    virtual void printPattern(const IPBIWPattern&);

    virtual void printInstruction(const IPBIWInstruction&);

    virtual void printHeader();

    virtual void printFooter();

    virtual std::ostream& getOutputStream();

  private:
    std::ostream& printer;
  };

}

#endif	/* PARTIALPBIWPRINTER_H */

