/* 
 * File:   rVexPrinter.h
 * Author: helix
 *
 * Created on October 6, 2011, 3:41 PM
 */

#ifndef RVEX_PRINTERS_RVEXPRINTER_H
#define	RVEX_PRINTERS_RVEXPRINTER_H

#include <ostream>
#include "../rVex.h"
#include "src/rVex/Printers/IPrinter.h"

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
      rVexPrinter( std::ostream&);
      virtual ~rVexPrinter( ) { }
      
      /**
       * Print the operation.
       */
      virtual void printOperation(const rVex::Syllable&, const std::vector<unsigned int>&);
      
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
      
      /**
       * Return output print stream.
       */
      virtual std::ostream& getOutputStream()
      { return output; }
      
    private:
      std::ostream& output;
      
    };
  }
}

#endif	/* RVEX_PRINTERS_RVEXPRINTER_H */

