/* 
 * File:   SyllableALU.cpp
 * Author: helix
 * 
 * Created on August 21, 2011, 7:43 PM
 */

#include <vector>
#include <iostream>
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
        output.printSyllable(this, printRTYPE(), first, last);
        break;
      case Syllable::ISTYPE:
        output.printSyllable(this, printISTYPE(), first, last);
        break;
      default:
        throw new LayoutNotSupportedException("This syllable only supports R or IS layouts.");
    }
  }
  
  
}