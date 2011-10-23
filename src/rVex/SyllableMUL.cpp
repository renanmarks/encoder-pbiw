/* 
 * File:   SyllableMUL.cpp
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 23:38
 */

#include <vector>
#include "SyllableMUL.h"
#include "src/Interfaces/IPrinter.h"

namespace rVex
{
  void
  SyllableMUL::print(rVex::Printers::IPrinter& output, bool first, bool last) const
  {
    switch (this->layoutType)
    {
      case LayoutType::RTYPE:
        output.printSyllable(this, printRTYPE(), first, last);
        break;
      case LayoutType::ISTYPE:
        output.printSyllable(this, printISTYPE(), first, last);
        break;
      default:
        throw new LayoutNotSupportedException("This instruction only supports R or IS layouts.");
    }
  }
 
}