/* 
 * File:   Instruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 4:19 PM
 */

#include "Instruction.h"
#include "Printers/IPrinter.h"

namespace rVex
{
  bool 
  Instruction::addSyllable(Syllable& syllable)
  {
    if (this->syllables.size() < this->syllables.max_size())
    {
      this->syllables.push_back(&syllable);
      return true;
    }
    
    return false;
  }
  
  bool 
  Instruction::removeSyllable(const Syllable& syllable)
  {
    if (this->syllables.size() > 0)
    {
      SyllableVec::iterator it;
      
      it = std::find(this->syllables.begin(), this->syllables.end(), &syllable);
      
      if (it != this->syllables.end())
      {
        this->syllables.erase(it);
        return true;
      }
    }
    
    return false;
  }

  std::vector<Syllable*> 
  Instruction::getSyllables() const
  {
    return this->syllables;
  }
  
  void
  Instruction::print(rVex::Printers::IPrinter& printer) const
  {
    printer.printInstruction(*this);
  }
}