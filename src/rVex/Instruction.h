/* 
 * File:   rVexInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 4:19 PM
 */

#ifndef RVEXINSTRUCTION_H
#define	RVEXINSTRUCTION_H

#include <memory>
#include <vector>
#include <algorithm>
#include "Syllable.h"

namespace rVex
{
  class Instruction
  {
    public:
      bool addSyllable(Syllable&);
      bool removeSyllable(const Syllable&);
      
      std::string print() const;
      
      std::vector<Syllable*> getSyllables() const;
    
    private:
      typedef std::vector<Syllable*> SyllableVec;
      SyllableVec syllables;
  };
}

#endif	/* RVEXINSTRUCTION_H */

