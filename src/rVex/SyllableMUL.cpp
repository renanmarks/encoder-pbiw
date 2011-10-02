/* 
 * File:   SyllableMUL.cpp
 * Author: renato
 *
 * Created on 6 de Setembro de 2011, 23:38
 */

#include <vector>
#include "SyllableMUL.h"

namespace rVex
{
  std::string 
  SyllableMUL::print(bool first, bool last) const
  {
    switch (this->layoutType)
    {
      case Syllable::RTYPE:
        return this->printRTYPE(first, last);
      case Syllable::ISTYPE:
        return this->printISTYPE(first, last);
      default:
        throw new LayoutNotSupportedException("This instruction only supports R or IS layouts.");
    }
    
    return std::string("Error printing syllable");
  }
 
}