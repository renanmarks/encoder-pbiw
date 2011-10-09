/* 
 * File:   IPrinter.h
 * Author: helix
 *
 * Created on September 17, 2011, 8:51 PM
 */

#ifndef IPRINTER_H
#define	IPRINTER_H

#include <ostream>

namespace rVex
{
  class Instruction;
  class Syllable;
  
  namespace Printers
  {
    /**
     * Printer interface
     * Used by the printing mechanisms to output the bytecode.
     */
    class IPrinter
    {
    public:
      virtual ~IPrinter() { }
      
      /**
       * Print the syllable.
       */
      virtual void printSyllable(const rVex::Syllable*,unsigned int, bool, bool) = 0;
      
      /**
       * Print the instruction.
       */
      virtual void printInstruction(const Instruction&) = 0;
      
      /**
       * Print the file header.
       */
      virtual void printHeader() = 0;
      
      /**
       * Print the file footer.
       */
      virtual void printFooter() = 0;
    };
  }
}

#endif	/* IPRINTER_H */

