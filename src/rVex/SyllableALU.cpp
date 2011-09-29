/* 
 * File:   SyllableALU.cpp
 * Author: helix
 * 
 * Created on August 21, 2011, 7:43 PM
 */

#include <vector>
#include "SyllableALU.h"

namespace rVex
{
  std::string 
  SyllableALU::print(bool first, bool last) const
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
  
  std::string 
  SyllableALU::printRTYPE(bool first, bool last) const 
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    final <<= 2;
    final |= Syllable::NO_IMM;
    final <<= 6;
    final |= grDestiny;

    readRegVector::const_iterator it;

    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
    {
      final <<= 6;
      final |= *it;
    }

    final <<= 3;
    final |= this->brDestiny;

    final <<= 2;

    return this->printBinary(final, first, last); 
  }
  
  std::string 
  SyllableALU::printISTYPE(bool first, bool last) const 
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    final <<= 2;

    final |= Syllable::SHORT_IMM;
    final <<= 6;
    
    final |= grDestiny;

    readRegVector::const_iterator it;

    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
    {
      final <<= 6;
      final |= *it;
    }

    final <<= 9;
    final |= this->shortImmediate;

    final <<= 2;

    return this->printBinary(final, first, last); 
  }
  
  bool 
  SyllableALU::operator==(const Syllable& other) const 
  { 
    Syllable& notConstOther = const_cast<Syllable&>(other);
    const SyllableALU* syllableALU = static_cast<SyllableALU*>(&notConstOther);

    if (this->getOpcode() == syllableALU->getOpcode())
    {
      return (this->getLayoutType() == syllableALU->getLayoutType()) &&
        (this->getSyllableType() == syllableALU->getSyllableType()) &&
        (this->getReadRegisters() == syllableALU->getReadRegisters() &&
        (this->getShortImmediate() == syllableALU->getShortImmediate()));
    }

    return false;
  }

  bool 
  SyllableALU::operator!=(const Syllable& other) const 
  { 
    return !(*this == other); 
  }
}