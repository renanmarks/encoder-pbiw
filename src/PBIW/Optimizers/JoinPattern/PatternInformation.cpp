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
#include "src/rVex/rVex.h"

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
          
          std::cout << "---\nBefore Annul"<<std::endl;
          IPBIWInstruction::AnnulationBits::iterator it;
          for(it = annulationBits.begin(); it < annulationBits.end(); it++ )
          {
              std::cout << *it << std::endl;
          }
          
          for (opIt = slots.begin(); opIt != slots.end(); opIt++, operationIndex++)
          {
            if (opIt->getOperation() != NULL)
            {
              annulationBits[opIt->getOriginalPosition()] = false;
              annulationBits[operationIndex] = true;
            }
          }

          std::cout << "\nAfter Annul" << std::endl;
          
          for(it = annulationBits.begin(); it < annulationBits.end(); it++ )
          {
              std::cout << *it << std::endl;
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

            IPBIWPattern::OperationVector::iterator opIt = 
              std::find_if(operations.begin(), operations.end(), finderFunctor);

            // If found the operation, set it's new position!
            if (opIt != operations.end())
            {
              newSlots[finderFunctor.GetPosition()].setOperation(*opIt);
              newSlots[finderFunctor.GetPosition()].setOriginalPosition(it->getOriginalPosition());
            }
          }
        }
        
        // Update the old tracking slots
        slots = newSlots;
      }

    }
  }
}