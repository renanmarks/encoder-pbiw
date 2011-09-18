#include <vector>
#include "SyllableMEM.h"

namespace rVex
{
  SyllableMEM::SyllableMEM()
   : layoutType(RTYPE),
        grDestiny(0), brDestiny(0), shortImmediate(0)
  {
    
  }
  
  SyllableMEM::SyllableMEM
  (LayoutType layout = RTYPE, 
   unsigned char grDestiny = 0, 
   unsigned char brDestiny = 0, 
   unsigned short shortImmediate = 0)
   : layoutType(layout),
        grDestiny(grDestiny), brDestiny(brDestiny), shortImmediate(shortImmediate)
  {
    
  }
  
  std::vector<unsigned int> 
  SyllableMEM::getReadRegisters() const 
  { 
    return this->readRegisters;
  }

  void
  SyllableMEM::setShortImmediate( unsigned short shortImmediate )
  {
    this->shortImmediate=shortImmediate;
  }

  unsigned short
  SyllableMEM::getShortImmediate( ) const
  {
    return shortImmediate;
  }

  void
  SyllableMEM::addReadRegister( unsigned int readRegister )
  {
    if ( this->readRegisters.size() > 2 )
      return;

    this->readRegisters.push_back(readRegister);
  }

  void
  SyllableMEM::setBrDestiny( unsigned char brDestiny )
  {
    this->brDestiny=brDestiny;
  }

  unsigned char
  SyllableMEM::getBrDestiny( ) const
  {
    return brDestiny;
  }

  void
  SyllableMEM::setGrDestiny( unsigned char grDestiny )
  {
    this->grDestiny=grDestiny;
  }

  unsigned char
  SyllableMEM::getGrDestiny( ) const
  {
    return grDestiny;
  }

  void
  SyllableMEM::setLayoutType( Syllable::LayoutType layoutType )
  {
    this->layoutType=layoutType;
  }
  
  std::string 
  SyllableMEM::print(bool first, bool last) const
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
  SyllableMEM::printRTYPE(bool first, bool last) const 
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
  SyllableMEM::printISTYPE(bool first, bool last) const 
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
  SyllableMEM::operator==(const Syllable& other) const 
  { 
    Syllable& notConstOther = const_cast<Syllable&>(other);
    const SyllableMEM* syllableMEM = static_cast<SyllableMEM*>(&notConstOther);

    if (this->getOpcode() == syllableMEM->getOpcode())
    {
      return (this->getLayoutType() == syllableMEM->getLayoutType()) &&
        (this->getSyllableType() == syllableMEM->getSyllableType()) &&
        (this->getReadRegisters() == syllableMEM->getReadRegisters() &&
        (this->getShortImmediate() == syllableMEM->getShortImmediate()));
    }

    return false;
  }

  bool 
  SyllableMEM::operator!=(const Syllable& other) const 
  { 
    return !(*this == other); 
  }
}
