/* 
 * File:   VHDLPrinter.h
 * Author: helix
 *
 * Created on October 11, 2011, 3:04 PM
 */

#ifndef RVEX_PRINTERS_VHDLPRINTER_H
#define	RVEX_PRINTERS_VHDLPRINTER_H

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
    class VHDLPrinter : public IPrinter
    {
    public:
      VHDLPrinter( std::ostream& );
      virtual ~VHDLPrinter( ) { }
      
      /**
       * Print the syllable.
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
      
      void setFileName(const std::string& filename)
      { this->filename = filename; }
      
      void setAssemblerFlags(const std::string& flags)
      { this->flags = flags; }
      
    private:
      std::ostream& output;
      std::string filename;
      std::string flags;
      std::string date;
      
    };
  }
}

#endif	/* RVEX_PRINTERS_VHDLPRINTER_H */

