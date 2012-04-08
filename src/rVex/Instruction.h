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
#include "Utils/DependencyChains.h"

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
      void printSyllableDependencies(rVex::Printers::IPrinter&) const;
      
      SyllableVector getSyllables() const;
    
      SyllableVector getOrderedSyllables() const;

      unsigned int
      getQuantityNotNopOperations() const;

      void
      setWordAddress(unsigned int wordAddress)
      { this->wordAddress=wordAddress; }

      unsigned int
      getWordAddress() const
      { return wordAddress; }
      
      void buildSyllableDependencies()
      { dependencies.buildDependenciesChains(*this); }
      
      bool canSplitSyllable(Syllable* syllable) const
      { return dependencies.canSplitSyllable(syllable); }
      
    private:
      rVex::Label* label;
      SyllableVector syllables;
      
      Utils::DependencyChains dependencies;
      
      unsigned int address; // instruction address, aligned by 16 bytes
      unsigned int wordAddress; // word address, aligned by 4 bytes
  };
}

#endif	/* RVEXINSTRUCTION_H */

