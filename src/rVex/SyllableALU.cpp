/* 
 * File:   SyllableALU.cpp
 * Author: helix
 * 
 * Created on August 21, 2011, 7:43 PM
 */

#include <vector>
#include <iostream>
#include "SyllableALU.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  void
  SyllableALU::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
  {
    switch (this->layoutType)
    {
      case LayoutType::RTYPE:
        output.printOperation(*this, std::vector<unsigned int>(1, printRTYPE(first, last)));
        break;
      case LayoutType::ISTYPE:
        output.printOperation(*this, std::vector<unsigned int>(1, printISTYPE(first, last)));
        break;
      case LayoutType::RTYPE_BS:
        output.printOperation(*this, std::vector<unsigned int>(1, printRTYPE_BS(first, last)));
        break;
      default:
        throw LayoutNotSupportedException("This syllable only supports R or IS layouts.");
    }
  }
  
  
}