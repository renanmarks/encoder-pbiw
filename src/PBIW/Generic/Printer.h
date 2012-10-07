/* 
 * File:   Printer.h
 * Author: helix
 *
 * Created on July 23, 2012, 9:37 PM
 */

#ifndef PBIW_GENERIC_PRINTER_H
#define	PBIW_GENERIC_PRINTER_H

#include "src/PBIW/Interfaces/IPBIWPrinter.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {

    class Printer : public IPBIWPrinter
    {
    public:
      Printer(std::ostream& output);
      Printer(const Printer& orig);
      virtual ~Printer();
      
      virtual void printInstructionsHeader();
      virtual void printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&);
      virtual void printInstructionsFooter(unsigned int);
      
      virtual void printPatternsHeader();
      virtual void printPattern(const IPBIWPattern&, const std::vector<unsigned int>&);
      virtual void printPatternsFooter(unsigned int);
      
      virtual std::ostream& getOutputStream();
      
    private:
      std::ostream& output;
    };
  }
}

#endif	/* PRINTER_H */

