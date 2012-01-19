/* 
 * File:   Instruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 4:19 PM
 */

#include "Instruction.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  bool 
  Instruction::addSyllable(Syllable& syllable) // O(1)
  {
    if (this->syllables.size() < this->syllables.max_size()) // O(1)
    {
      this->syllables.push_back(&syllable); // O(1)
      return true;
    }
    
    return false;
  }
  
  bool 
  Instruction::removeSyllable(const Syllable& syllable) // O(1)
  {
    if (this->syllables.size() > 0) // O(1)
    {
      SyllableVector::iterator it;
      
      it = std::find(this->syllables.begin(), this->syllables.end(), &syllable);
      
      if (it != this->syllables.end()) 
      {
        this->syllables.erase(it);
        return true;
      }
    }
    
    return false;
  }

  Instruction::SyllableVector
  Instruction::getSyllables() const  // O(1)
  {
    return this->syllables;
  }
  
  void
  Instruction::print(rVex::Printers::IPrinter& printer) const
  {
    printer.printInstruction(*this);
  }
}