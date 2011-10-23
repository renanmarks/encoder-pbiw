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
      typedef std::vector<Syllable*> SyllableVector;
      
      Instruction() : address(0) {}
      
      bool addSyllable(Syllable&);
      bool removeSyllable(const Syllable&);
      
      unsigned int getAddress() const
      { return this->address; }
      
      void setAddress(unsigned int address)
      { this->address = address; }
      
      void print(rVex::Printers::IPrinter&) const;
      
      SyllableVector getSyllables() const;
    
    private:
      SyllableVector syllables;
      unsigned int address;
  };
}

#endif	/* RVEXINSTRUCTION_H */

