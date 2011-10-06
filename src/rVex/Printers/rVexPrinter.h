/* 
 * File:   rVexPrinter.h
 * Author: helix
 *
 * Created on October 6, 2011, 3:41 PM
 */

#ifndef RVEXPRINTER_H
#define	RVEXPRINTER_H

#include <ostream>
#include "../rVex.h"
#include "IPrinter.h"

namespace rVex
{
  namespace Printers
  {
    /**
     * Printer that outputs binary code in a VHDL file.
     */
    class rVexPrinter : public IPrinter
    {
    public:
      rVexPrinter( std::ostream& output ) : output(output) { }
      virtual ~rVexPrinter( ) { }
      
      /**
       * Print the syllable.
       */
      virtual void printSyllable(unsigned int, bool, bool);
      
      /**
       * Print the instruction.
       */
      virtual void printInstruction(const rVex::Instruction&);
      
      /**
       * Print the file header.
       */
      virtual void printHeader();
      
      /**
       * Print the file footer.
       */
      virtual void printFooter();
      
    private:
      std::ostream& output;
      
    };
  }
}

#endif	/* RVEXPRINTER_H */

