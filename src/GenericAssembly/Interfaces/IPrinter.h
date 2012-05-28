/* 
 * File:   IPrinter.h
 * Author: helix
 *
 * Created on May 27, 2012, 5:35 PM
 */

#ifndef IPRINTER_H
#define	IPRINTER_H

#include <ostream>

namespace GenericAssembly
{
  namespace Interfaces
  {
    class IInstruction;
    class IOperation;
    
    /**
     * Printer interface
     * Used by the printing mechanisms to output the bytecode.
     */
    class IPrinter
    {
    public:
      virtual ~IPrinter() { }
      
      /**
       * Print the operation.
       */
      virtual void printOperation(const IOperation&) = 0;
      
      /**
       * Print the instruction.
       */
      virtual void printInstruction(const IInstruction&) = 0;
      
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

#endif	/* IPRINTER_H */

