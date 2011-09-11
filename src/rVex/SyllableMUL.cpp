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
  SyllableMUL::SyllableMUL()
   : layoutType(RTYPE),
        grDestiny(0), brDestiny(0), shortImmediate(0)
  {
    
  }
  
  SyllableMUL::SyllableMUL
  (LayoutType layout = RTYPE, 
   unsigned char grDestiny = 0, 
   unsigned char brDestiny = 0, 
   unsigned short shortImmediate = 0)
   : layoutType(layout),
        grDestiny(grDestiny), brDestiny(brDestiny), shortImmediate(shortImmediate)
  {
    
  }
  
  std::vector<unsigned int> 
  SyllableMUL::getReadRegisters() const 
  { 
    return this->readRegisters;
  }

  void
  SyllableMUL::setShortImmediate( unsigned short shortImmediate )
  {
    this->shortImmediate=shortImmediate;
  }

  unsigned short
  SyllableMUL::getShortImmediate( ) const
  {
    return shortImmediate;
  }

  void
  SyllableMUL::addReadRegister( unsigned int readRegister )
  {
    if ( this->readRegisters.size() > 2 )
      return;

    this->readRegisters.push_back(readRegister);
  }

  void
  SyllableMUL::setBrDestiny( unsigned char brDestiny )
  {
    this->brDestiny=brDestiny;
  }

  unsigned char
  SyllableMUL::getBrDestiny( ) const
  {
    return brDestiny;
  }

  void
  SyllableMUL::setGrDestiny( unsigned char grDestiny )
  {
    this->grDestiny=grDestiny;
  }

  unsigned char
  SyllableMUL::getGrDestiny( ) const
  {
    return grDestiny;
  }

  void
  SyllableMUL::setLayoutType( Syllable::LayoutType layoutType )
  {
    this->layoutType=layoutType;
  }
  
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