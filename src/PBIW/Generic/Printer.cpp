/* 
 * File:   Printer.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 9:37 PM
 */

#include "Printer.h"

namespace PBIW
{
  namespace Generic
  {

    Printer::Printer(std::ostream& output)
    : output(output)
    {
    }

    Printer::Printer(const Printer& orig)
    : output(orig.output)
    {
    }

    Printer::~Printer()
    {
    }

    void
    Printer::printInstructionsHeader()
    {
    }

    void
    Printer::printInstruction(const IPBIWInstruction&, const std::vector<unsigned int>&)
    {
    }

    void
    Printer::printInstructionsFooter(unsigned int)
    {
    }

    void
    Printer::printPatternsHeader()
    {
    }

    void
    Printer::printPattern(const IPBIWPattern&, const std::vector<unsigned int>&)
    {
    }

    void
    Printer::printPatternsFooter(unsigned int)
    {
    }

    std::ostream&
    Printer::getOutputStream()
    {
    }
  }
}
