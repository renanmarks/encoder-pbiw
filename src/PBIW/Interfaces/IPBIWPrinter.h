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
