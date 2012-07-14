/* 
 * File:   SyllableMUL.cpp
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 23:38
 */

#include <vector>
#include "SyllableMUL.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  void
  SyllableMUL::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
  {
    switch (this->layoutType)
    {
      case LayoutType::RTYPE:
        output.printOperation(*this, std::vector<unsigned int>(1, printRTYPE(first, last))); // O(1)
        break;
      case LayoutType::ISTYPE:
        output.printOperation(*this, std::vector<unsigned int>(1, printISTYPE(first, last))); // O(1)
        break;
      default:
        throw new LayoutNotSupportedException("This instruction only supports R or IS layouts.");
    }
  }
 
}