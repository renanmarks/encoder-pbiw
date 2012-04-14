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
#include <set>
#include <algorithm>
#include "Syllable.h"
#include "src/PBIW/Interfaces/IPBIWInstruction.h"

namespace rVex
{
  class Instruction
  {
    public:
      typedef std::vector<Syllable*> SyllableVector;
      typedef std::set<const PBIW::Interfaces::IPBIWInstruction*> PBIWInstructionSet;
      
      Instruction() : label(NULL), address(0) {}
      
      void addReferencePBIWInstruction(const PBIW::Interfaces::IPBIWInstruction&);
      PBIWInstructionSet getPBIWInstructions() const;
      
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
    
      SyllableVector getOrderedSyllables() const;
    private:
      rVex::Label* label;
      SyllableVector syllables;
      PBIWInstructionSet pbiwInstructions;
      unsigned int address;
      
      
  };
}

#endif	/* RVEXINSTRUCTION_H */

