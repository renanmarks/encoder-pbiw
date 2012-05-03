/* 
 * File:   PatternInformation.cpp
 * Author: helix
 * 
 * Created on May 3, 2012, 4:11 PM
 */

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
        slots[originalPosition].setOperation(operation);
        slots[originalPosition].setOriginalPosition(originalPosition);
      }

      void
      PatternInformation::setPattern(IPBIWPattern* pattern)
      {
        this->pattern = pattern;
        
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
      PatternInformation::setInstructionsAnnulationBits()
      {
        std::deque<IPBIWInstruction*>::iterator instructionIt;

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

    }
  }
}