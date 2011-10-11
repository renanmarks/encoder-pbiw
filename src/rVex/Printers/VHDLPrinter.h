/* 
 * File:   VHDLPrinter.h
 * Author: helix
 *
 * Created on October 11, 2011, 3:04 PM
 */

#ifndef VHDLPRINTER_H
#define	VHDLPRINTER_H

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
    class VHDLPrinter : public IPrinter
    {
    public:
      VHDLPrinter( std::ostream& );
      virtual ~VHDLPrinter( ) { }
      
      /**
       * Print the syllable.
       */
      virtual void printSyllable(const rVex::Syllable*,unsigned int, bool, bool);
      
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
      
      void setFileName(std::string& filename)
      { this->filename = filename; }
      
      void setAssemblerFlags(std::string& flags)
      { this->flags = flags; }
      
    private:
      std::ostream& output;
      std::string filename;
      std::string flags;
      std::string date;
      
    };
  }
}

#endif	/* VHDLPRINTER_H */

