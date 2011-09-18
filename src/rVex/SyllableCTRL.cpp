
#include <string>
#include "SyllableCTRL.h"

namespace rVex
{
  std::string 
  SyllableCTRL::print(bool first, bool last) const
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
  SyllableCTRL::operator==(const Syllable& other) const 
  { 
    Syllable& notConstOther = const_cast<Syllable&>(other);
    const SyllableCTRL* syllableCTRL = static_cast<SyllableCTRL*>(&notConstOther);

    if (this->getOpcode() == syllableCTRL->getOpcode())
    {
      return (this->getLayoutType() == syllableCTRL->getLayoutType()) &&
        (this->getSyllableType() == syllableCTRL->getSyllableType());
    }

    return false;
  }

  bool 
  SyllableCTRL::operator!=(const Syllable& other) const 
  { 
    return !(*this == other); 
  }
}