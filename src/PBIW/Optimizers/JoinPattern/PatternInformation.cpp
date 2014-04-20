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
 * File:   PatternInformation.cpp
 * Author: helix
 * 
 * Created on May 3, 2012, 4:11 PM
 */

#include <algorithm>
#include <iostream>

#include "OperationInformation.h"
#include "PatternInformation.h"
#include "rVex/Base/rVex.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Optimizers
  {
    namespace JoinPattern
    {

      void
      PatternInformation::addOperation(IOperation* operation, int originalPosition)
      {
        if (operation->getOpcode() != rVex::Syllable::opNOP)
        {
          slots[originalPosition].setOperation(operation);
          slots[originalPosition].setOriginalPosition(originalPosition);
        }
      }

      void
      PatternInformation::setPattern(IPBIWPattern* pattern)
      {
        this->pattern = pattern;
        this->instructions = pattern->getInstructionsThatUseIt();
        
        IPBIWPattern::OperationVector::const_iterator it;
        IPBIWPattern::OperationVector operations = pattern->getOperations();
        int originalIndex = 0;
        
        for(it = operations.begin();
            it != operations.end();
            it++, originalIndex++)
        {
          if ( (*it)->getOpcode() != rVex::Syllable::opNOP )
            addOperation(*it, originalIndex);
        }
      }
      
      void
      PatternInformation::updateInstructionsPointers(IPBIWPattern* pattern)
      {
        InstructionCollection::iterator instructionIt;

        for (instructionIt = instructions.begin(); 
            instructionIt != instructions.end();
            instructionIt++)
        {
          (*instructionIt)->pointToPattern(*pattern);
        }
      }
      
      void
      PatternInformation::updateInstructionsAnnulationBits()
      {
        InstructionCollection::iterator instructionIt;
        
        for (instructionIt = instructions.begin();
            instructionIt != instructions.end();
            instructionIt++)
        {
          IPBIWInstruction::AnnulationBits annulationBits = (*instructionIt)->getAnnulBits();

          OperationsCollections::iterator opIt;
          int operationIndex = 0;
          
          for (opIt = slots.begin(); opIt != slots.end(); opIt++, operationIndex++)
          {
            if (opIt->getOperation() != NULL)
            {
              annulationBits[opIt->getOriginalPosition()] = false;
              annulationBits[operationIndex] = true;
            }
          }
          
          (*instructionIt)->setAnnulBits(annulationBits);
        }
      }
      
      /**
       * Using a new and reordered pattern, update the operation slots to
       * accomplish the new operation organization. This is done to make
       * easy the generation of annulation bits for the instructions that
       * reference the original pattern registered in this PatternInformation
       * object.
       */
      void 
      PatternInformation::updateSlots(IPBIWPattern* newPattern)
      {
        OperationsCollections newSlots(4, OperationInformation());
        OperationsCollections::iterator it;
        
        for (it = slots.begin(); it != slots.end(); it++)
        {
          // Pick up only the slots that have meaningfull operations (i.e. not NOPS)
          if (it->getOriginalPosition() > -1)
          {
            IPBIWPattern::OperationVector operations = newPattern->getOperations();
            FindOperation finderFunctor(it->getOperation());

            int finderIndex = 0;
            IPBIWPattern::OperationVector::iterator opIt = operations.begin();
            
            // Search for the operation in the new pattern
            for (; opIt!=operations.end() ; opIt++, finderIndex++ )
              if ( finderFunctor(*opIt) )                  
                break;

            // If found the operation, set it's new position!
            if (opIt != operations.end())
            {
              newSlots[finderIndex].setOperation(*opIt);
              newSlots[finderIndex].setOriginalPosition(it->getOriginalPosition());
            }
          }
        }
        
        // Update the old tracking slots
        slots = newSlots;
      }

    }
  }
}
