/* 
 * File:   IPrinter.h
 * Author: helix
 *
 * Created on May 27, 2012, 5:35 PM
 */

#ifndef GENERICASSEMBLY_IPRINTER_H
#define	GENERICASSEMBLY_IPRINTER_H

#include <ostream>

namespace GenericAssembly
{
  namespace Interfaces
  {
    /**
     * Printer interface
     * Used by the printing mechanisms to output the bytecode.
     */
    template <class TInstruction, class TOperation>
    class IPrinter
    {
    public:
      virtual ~IPrinter() { }
      
      /**
       * Print the operation.
       */
      virtual void printOperation(const TOperation&, const std::vector<unsigned int>&) = 0;
      
      /**
       * Print the instruction.
       */
      virtual void printInstruction(const TInstruction&) = 0;
      
      /**
       * Print the file header.
       */
      virtual void printHeader() = 0;
      
      /**
       * Print the file footer.
       */
      virtual void printFooter() = 0;
      
      /**
       * Returns the output stream being used by this printer.
       */
      virtual std::ostream& getOutputStream() = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IPRINTER_H */

