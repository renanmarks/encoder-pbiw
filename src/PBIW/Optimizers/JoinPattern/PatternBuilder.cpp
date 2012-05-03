/* 
 * File:   PatternBuilder.cpp
 * Author: helix
 * 
 * Created on May 3, 2012, 4:54 PM
 */

#include "PatternBuilder.h"
#include "src/PBIW/rVex96PBIWPattern.h"

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
        reorganizeOperations();
        
        IPBIWPattern* returnedPattern = new rVex96PBIWPattern();
        
//        returnedPattern->addOperation(ctrl.operation->clone());
//        returnedPattern->addOperation(mul1.operation->clone());
//        returnedPattern->addOperation(mul2.operation->clone());
//        returnedPattern->addOperation(mem.operation->clone());

        return returnedPattern;
      }
      
      void 
      PatternBuilder::reorganizeOperations()
      {
        PatternInformationList::iterator it;
        
        for (it = patternInformations.begin();
             it != patternInformations.end();
             it++)
        {
          
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