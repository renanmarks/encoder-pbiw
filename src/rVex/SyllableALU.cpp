/* 
 * File:   SyllableALU.cpp
 * Author: helix
 * 
 * Created on August 21, 2011, 7:43 PM
 */

#include <vector>
#include "SyllableALU.h"
#include "Printers/IPrinter.h"

namespace rVex
{
  void
  SyllableALU::print(rVex::Printers::IPrinter& output, bool first, bool last) const
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