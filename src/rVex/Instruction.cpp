/* 
 * File:   Instruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 4:19 PM
 */

#include "Instruction.h"

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
  
  std::string
  Instruction::print() const
  {
    std::string returnStr;
    SyllableVec::const_iterator it;
    
    for ( it = this->syllables.begin(); it < this->syllables.end(); it++)
    {
      std::string syllableStr; 
      
      // If the current is the first put 01 in LF...
      if (it == this->syllables.begin()) 
        syllableStr = (*it)->print(true, false);
      // ... if the current is the last put 10 in LF ...
      else if (it+1 == this->syllables.end()) 
        syllableStr = (*it)->print(false, true);
      // ... if is in the middle, put 00 in LF bits
      else 
        syllableStr = (*it)->print(false, false);
      
      returnStr.append( syllableStr ) += ", ";
    }
    
    return returnStr;
  }
}