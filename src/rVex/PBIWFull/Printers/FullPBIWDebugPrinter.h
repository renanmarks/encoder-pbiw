/* 
 * File:   PartialPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef PBIWFULL_DEBUGPRINTER_H
#define	PBIWFULL_DEBUGPRINTER_H

#include "src/PBIW/Interfaces/IPBIWPrinter.h"

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

