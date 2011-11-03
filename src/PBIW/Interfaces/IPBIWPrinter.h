/* 
 * File:   IPBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:05 PM
 */

#ifndef IPBIWPRINTER_H
#define	IPBIWPRINTER_H

#include <ostream>

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
       * Print the pattern.
       */
      virtual void printPattern(const IPBIWPattern&) = 0;
      
      /**
       * Print the instruction.
       */
      virtual void printInstruction(const IPBIWInstruction&) = 0;
      
      /**
       * Print the file header.
       */
      virtual void printHeader() = 0;
      
      /**
       * Print the file footer.
       */
      virtual void printFooter() = 0;
      
      virtual std::ostream& getOutputStream() = 0;
    };
  }
}


#endif	/* IPBIWPRINTER_H */
