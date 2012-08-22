/* 
 * File:   DependencyChains.cpp
 * Author: helix
 * 
 * Created on April 5, 2012, 3:55 PM
 */

#include <iostream>
#include <functional>
#include "DependencyChains.h"
#include "src/rVex/rVex.h"

namespace rVex
{
  namespace Utils
  {
    DependencyChains::Dependency 
    DependencyChains::getDependencies(Syllable* const& operation, const std::vector<Syllable*>& operations)
    {
      Dependency dependency;

      rVex::Syllable::OperandVector readRegs = operation->getReadOperands();
      rVex::Instruction::SyllableVector::const_iterator otherSyllableIt;

      for(otherSyllableIt = operations.begin(); otherSyllableIt < operations.end(); otherSyllableIt++)
      {
        if ( ((*otherSyllableIt)->getAddress() == operation->getAddress()) || ((*otherSyllableIt)->getGrDestinyValue() == 0 && !operation->hasBrSource()) )
          continue;

        bool writesInMyGrReadRegister = 
          (*otherSyllableIt)->hasGrDestiny() 
          && (std::find(readRegs.begin(), readRegs.end(), (*otherSyllableIt)->getGrDestinyOperand()) != readRegs.end());

        bool writesInMyBrReadRegister = 
          (*otherSyllableIt)->hasBrDestiny() 
          && operation->hasBrSource() 
          && ((*otherSyllableIt)->getBrDestinyValue() == operation->getBrSourceValue());

        switch ((*otherSyllableIt)->getOpcode())
        {
          case rVex::Syllable::opSTW:
          case rVex::Syllable::opSTH:
          case rVex::Syllable::opSTB:
            writesInMyGrReadRegister = false;
            writesInMyBrReadRegister = false;
            break;
        }

        bool isAfterMe = (*otherSyllableIt)->getAddress() > operation->getAddress();

        if (writesInMyGrReadRegister || writesInMyBrReadRegister)
        {
          if (isAfterMe)
            dependency.antiDepends.push_back(*otherSyllableIt);
          else
            dependency.depends.push_back(*otherSyllableIt);
        }
      }

      return dependency;
    }
    
  }
}
