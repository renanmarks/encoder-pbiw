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
  unsigned int
  Instruction::getQuantityNotNopOperations() const
  {
    SyllableVector::const_iterator it;
    
    unsigned int quantity = 0;
    
    for (it = syllables.begin(); it < syllables.end(); it++)
    {
      if ((*it)->getOpcode() != rVex::Syllable::opNOP)
        quantity++;
    }
    
    // All nops
    if (quantity == 0)
      return 1;

    return quantity;
  }
  
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
  Instruction::getOrderedSyllables() const
  {
    Instruction::SyllableVector orderedSyllables = this->syllables;
    
    int counterIt = 0;
    Instruction::SyllableVector::iterator it;

    // Go through all the syllables ordering them
    for(it = orderedSyllables.begin(); // O(|syllableBuffer|) = O(4) = O(1)
        it < orderedSyllables.end(); 
        it++)
    {
      rVex::Syllable* syllableIt = *it;

        // ALU = 1, MUL = 2, MEM = 3 , CTRL = 4
        if( 
            syllableIt->getOpcode() && 
            (syllableIt->getSyllableType() != rVex::Syllable::SyllableType::ALU) 
          )
        {
            if(
                (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::CTRL) && 
                (counterIt != 0)
              )
            {
                // exchange the indexes
                rVex::Syllable* syllable = orderedSyllables.at(0);
                orderedSyllables.at(0) = orderedSyllables.at(counterIt);
                orderedSyllables.at(counterIt) = syllable;

                counterIt--;
                it--;
            }
            else if(
                     (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::MEM) && 
                     (counterIt != 3)
                   )
            {
                // exchange the indexes
                rVex::Syllable* syllable = orderedSyllables.at(3);
                orderedSyllables.at(3) = orderedSyllables.at(counterIt);
                orderedSyllables.at(counterIt) = syllable;

                counterIt--;
                it--;
            }   

            else if(
                     (syllableIt->getSyllableType() == rVex::Syllable::SyllableType::MUL) && 
                     ((counterIt != 1) && (counterIt != 2))
                   )
            {
                int index;                  

                // set up the index that will receive the MUL syllable
                if (orderedSyllables.at(1)->getSyllableType() != rVex::Syllable::SyllableType::MUL)
                    index = 1;
                else
                    index = 2;

                // exchange the indexes
                rVex::Syllable* syllable = orderedSyllables.at(index);
                orderedSyllables.at(index) = orderedSyllables.at(counterIt);
                orderedSyllables.at(counterIt) = syllable;

                counterIt--;
                it--;
            }             
        }
        counterIt++;             
    }

    // Invert the ordering to MEM, ALU, ALU, CTRL to match de rVex slots
    Instruction::SyllableVector reverseOrderedSyllables(orderedSyllables.rbegin(), orderedSyllables.rend());
    
    return reverseOrderedSyllables;
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
  
  void 
  Instruction::printSyllableDependencies(rVex::Printers::IPrinter& printer) const
  {
    dependencies.print(printer);
  }
}