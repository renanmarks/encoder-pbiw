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
    switch (layoutType)
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
  SyllableMUL::printRTYPE(bool first, bool last) const 
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
  SyllableMUL::printISTYPE(bool first, bool last) const 
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
  SyllableMUL::operator==(const Syllable& other) const 
  { 
    Syllable& notConstOther = const_cast<Syllable&>(other);
    const SyllableMUL* syllableMUL = static_cast<SyllableMUL*>(&notConstOther);

    if (this->getOpcode() == syllableMUL->getOpcode())
    {
      return (this->getLayoutType() == syllableMUL->getLayoutType()) &&
        (this->getSyllableType() == syllableMUL->getSyllableType()) &&
        (this->getReadRegisters() == syllableMUL->getReadRegisters() &&
        (this->getShortImmediate() == syllableMUL->getShortImmediate()));
    }

    return false;
  }

  bool 
  SyllableMUL::operator!=(const Syllable& other) const 
  { 
    return !(*this == other); 
  }
}