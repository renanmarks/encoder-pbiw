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
      
      Instruction() : label(NULL), address(0) {}
      
      bool addSyllable(Syllable&);
      bool removeSyllable(const Syllable&);
      
      unsigned int getAddress() const
      { return this->address; }
      
      void setAddress(unsigned int address)
      { this->address = address; }
      
      void setLabel(rVex::Label& label)
      { this->label = &label; }
      
      bool haveLabel() const
      { return this->label != NULL; }
      
      rVex::Label* getLabel() const
      { return this->label; }
      
      void print(rVex::Printers::IPrinter&) const;
      
      SyllableVector getSyllables() const;
    
    private:
      rVex::Label* label;
      SyllableVector syllables;
      unsigned int address;
  };
}

#endif	/* RVEXINSTRUCTION_H */

