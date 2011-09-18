
#include <string>
#include "SyllableMISC.h"

namespace rVex
{
  std::string 
  SyllableMISC::print(bool first, bool last) const
  {
    unsigned int final = 0;

    final |= this->getOpcode();
    final <<= 2;

    final |= Syllable::BRANCH_IMM;
    final <<= 23;
    
//    final |= grDestiny;
//
//    readRegVector::const_iterator it;
//
//    for (it = readRegisters.begin(); it < readRegisters.end(); it++)
//    {
//      final <<= 6;
//      final |= *it;
//    }
//
//    final <<= 9;
//    final |= this->shortImmediate;
//
//    final <<= 2;

    return this->printBinary(final, first, last); 
  }
  
  bool 
  SyllableMISC::operator==(const Syllable& other) const 
  { 
    Syllable& notConstOther = const_cast<Syllable&>(other);
    const SyllableMISC* syllableMISC = static_cast<SyllableMISC*>(&notConstOther);

    if (this->getOpcode() == syllableMISC->getOpcode())
    {
      return (this->getLayoutType() == syllableMISC->getLayoutType()) &&
        (this->getSyllableType() == syllableMISC->getSyllableType());
    }

    return false;
  }

  bool 
  SyllableMISC::operator!=(const Syllable& other) const 
  { 
    return !(*this == other); 
  }
}
