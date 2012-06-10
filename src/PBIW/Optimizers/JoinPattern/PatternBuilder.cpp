/* 
 * File:   PatternBuilder.cpp
 * Author: helix
 * 
 * Created on May 3, 2012, 4:54 PM
 */

#include "PatternBuilder.h"
#include "src/PBIW/rVex96PBIWPattern.h"

#include <iostream>

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Optimizers
  {
    namespace JoinPattern
    {
      IPBIWPattern*
      PatternBuilder::buildPattern() // 2*|codedInstructions| + 2*|codedInstructions| + |codedPatterns| = 4|codedInstructions|+ |codedPatterns|
      {
        // TODO: Make this non-dependent of the croncrete rVex96Pattern
        IPBIWPattern* returnedPattern = new rVex96PBIWPattern();
        
        PatternInformationList::iterator it;

        // Using the information we have, lets build the new pattern...
        for (it = patternInformations.begin();
             it != patternInformations.end();
             it++)
        {
          PatternInformation::OperationsCollections::const_iterator opIt;
          PatternInformation::OperationsCollections operations = it->getSlots();
          
          for (opIt = operations.begin();
               opIt != operations.end();
               opIt++)
          {
            if ( opIt->getOriginalPosition() > -1 )
              returnedPattern->addOperation( opIt->getOperation()->clone() );
          }          
        }
          
        // ... reorganize it and use itself to update our operations
        // position information!
        reorganizeOperations(returnedPattern);   
        std::cout << "BuildPattern " << std::endl;
        return returnedPattern;
      }
      
      void 
      PatternBuilder::reorganizeOperations(IPBIWPattern* returnedPattern) 
      {
        returnedPattern->reorganize(false); // O(1)
        
        PatternInformationList::iterator it;
        
        for (it = patternInformations.begin();
             it != patternInformations.end();
             it++)
        {
          it->updateSlots(returnedPattern); // Update our slots!  |operations| = O(1)
          it->updateInstructionsAnnulationBits(); // Update the annulation bits!  |codedInstructions|
          it->updateInstructionsPointers(returnedPattern); // CHANGE ALL THE POINTERS! \o>  |codedInstructions|
        }
      }
        
      PatternBuilder&
      PatternBuilder::startWithPattern(IPBIWPattern* pattern) // |codedInstructions|
      {
        PatternInformation patternInfo;
        patternInfo.setPattern(pattern);
          clear();
        
        patternInformations.push_back(patternInfo);
        
        return *this;
      }
        
      PatternBuilder&
      PatternBuilder::joinWithPattern(IPBIWPattern* pattern) // |codedInstructions|
      {
        PatternInformation patternInfo;
        patternInfo.setPattern(pattern); // |codedInstructions|
        
        patternInformations.push_back(patternInfo);
        
        return *this;
      }
    }
  }
}