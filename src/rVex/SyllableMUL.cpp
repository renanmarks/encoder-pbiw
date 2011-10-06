/* 
 * File:   SyllableMUL.cpp
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 23:38
 */

#include <vector>
#include "SyllableMUL.h"
#include "Printers/IPrinter.h"

namespace rVex
{
  void
  SyllableMUL::print(rVex::Printers::IPrinter& output, bool first, bool last) const
  {
    switch (this->layoutType)
    {
      case Syllable::RTYPE:
        output.printSyllable(printRTYPE(), first, last);
      case Syllable::ISTYPE:
        output.printSyllable(printISTYPE(), first, last);
      default:
        throw new LayoutNotSupportedException("This instruction only supports R or IS layouts.");
    }
  }
 
}