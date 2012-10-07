/* 
 * File:   AssemblyPrinter.h
 * Author: helix
 *
 * Created on October 11, 2011, 3:04 PM
 */

#ifndef RVEX_PRINTERS_DINEROTOOL_ASSEMBLYPRINTER_H
#define	RVEX_PRINTERS_DINEROTOOL_ASSEMBLYPRINTER_H

#include <ostream>
#include "src/rVex/rVex.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  namespace Printers
  {
    namespace DineroTool
    {
      /**
      * Printer that outputs instruction data used to generate Dinero Traces
      */
      class AssemblyPrinter : public IPrinter
      {
      public:
        AssemblyPrinter( std::ostream& );
        virtual ~AssemblyPrinter( ) { }

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
}

#endif	/* ASSEMBLYPRINTER_H */

