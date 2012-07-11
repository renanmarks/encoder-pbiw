/* 
 * File:   PartialPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef PBIWFULL_PBIWPRINTER_H
#define	PBIWFULL_PBIWPRINTER_H

#include "src/PBIW/Interfaces/IPBIWPrinter.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

  class FullPBIWPrinter : public IPBIWPrinter
  {
  public:
    FullPBIWPrinter(std::ostream& printer) 
    : printer(printer)
    { }
    
    FullPBIWPrinter(const FullPBIWPrinter& orig) 
    : printer( const_cast<FullPBIWPrinter&>(orig).getOutputStream() )
    { }
    
    virtual ~FullPBIWPrinter()
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

