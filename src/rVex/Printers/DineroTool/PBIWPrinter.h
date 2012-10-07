/* 
 * File:   PBIWPrinter.h
 * Author: helix
 *
 * Created on October 30, 2011, 4:28 PM
 */

#ifndef RVEX_PRINTERS_DINEROTOOL_PBIWPRINTER_H
#define	RVEX_PRINTERS_DINEROTOOL_PBIWPRINTER_H

#include "src/PBIW/Interfaces/IPBIWPrinter.h"

namespace rVex
{
  namespace Printers
  {
    namespace DineroTool
    {
      using namespace PBIW::Interfaces;

      class PBIWPrinter : public IPBIWPrinter
      {
      public:
        PBIWPrinter(std::ostream& printer) 
        : printer(printer)
        { }

        PBIWPrinter(const PBIWPrinter& orig) 
        : printer( const_cast<PBIWPrinter&>(orig).getOutputStream() )
        { }

        virtual ~PBIWPrinter()
        { }

        virtual void printPatternsHeader();
        virtual void printPattern(const IPBIWPattern&, const std::vector<unsigned int>&);
        virtual void printPatternsFooter(unsigned int);

        virtual void printInstructionsHeader();
        virtual void printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&);
        virtual void printInstructionsFooter(unsigned int);

        virtual std::ostream& getOutputStream()
        { return printer; }

      private:
        std::ostream& printer;
      };
    }
  }
}

#endif	/* RVEX_PRINTERS_DINEROTOOL_PARTIALPBIWPRINTER_H */

