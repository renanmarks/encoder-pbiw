/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/* 
 * File:   DependencyChains.cpp
 * Author: helix
 * 
 * Created on April 5, 2012, 3:55 PM
 */

#include <iostream>
#include <functional>
#include "DependencyChains.h"
#include "rVex/rVex.h"

namespace rVex
{
  namespace Utils
  {
    DependencyChains::Dependency 
    DependencyChains::getDependencies(Syllable* const& operation, const std::deque<Syllable*>& operations)
    {
      Dependency dependency;

      rVex::Syllable::OperandVector readRegs = operation->getReadOperands();
      std::deque<Syllable*>::const_iterator otherSyllableIt;

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
            dependency.antiDepends.insert(*otherSyllableIt);
          else
            dependency.depends.insert(*otherSyllableIt);
        }
      }

      return dependency;
    }
    
  }
}
