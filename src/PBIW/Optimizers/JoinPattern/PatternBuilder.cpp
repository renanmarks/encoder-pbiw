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
 * File:   PatternBuilder.cpp
 * Author: helix
 * 
 * Created on May 3, 2012, 4:54 PM
 */

#include "PatternBuilder.h"
#include <iostream>

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Optimizers
  {
    namespace JoinPattern
    {
      IPBIWPattern*
      PatternBuilder::buildPattern()
      {
        IPBIWPattern* returnedPattern = factory.createPattern();
        
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
        return returnedPattern;
      }
      
      void 
      PatternBuilder::reorganizeOperations(IPBIWPattern* returnedPattern)
      {
        returnedPattern->reorganize(false);
        
        PatternInformationList::iterator it;
        
        for (it = patternInformations.begin();
             it != patternInformations.end();
             it++)
        {
          it->updateSlots(returnedPattern); // Update our slots!
          it->updateInstructionsAnnulationBits(); // Update the annulation bits!
          it->updateInstructionsPointers(returnedPattern); // CHANGE ALL THE POINTERS! \o>
        }
      }
        
      PatternBuilder&
      PatternBuilder::startWithPattern(IPBIWPattern* pattern)
      {
        PatternInformation patternInfo;
        patternInfo.setPattern(pattern);
        clear();
        
        patternInformations.push_back(patternInfo);
        
        return *this;
      }
        
      PatternBuilder&
      PatternBuilder::joinWithPattern(IPBIWPattern* pattern)
      {
        PatternInformation patternInfo;
        patternInfo.setPattern(pattern);
        
        patternInformations.push_back(patternInfo);
        
        return *this;
      }
    }
  }
}