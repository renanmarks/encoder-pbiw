/* 
 * File:   PatternBuilder.h
 * Author: helix
 *
 * Created on May 3, 2012, 4:54 PM
 */

#ifndef PATTERNBUILDER_H
#define	PATTERNBUILDER_H

#include "src/PBIW/Interfaces/IPBIWInstruction.h"
#include "src/PBIW/Interfaces/IPBIWPattern.h"
#include "src/PBIW/Interfaces/IOperation.h"

#include "PatternInformation.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Optimizers
  {
    namespace JoinPattern
    {

      class PatternBuilder
      {
      public:
        PatternBuilder()
        { }
        
        PatternBuilder(const PatternBuilder& orig)
        : patternInformations(orig.patternInformations)
        { }
        
        virtual ~PatternBuilder()
        { }
        
        IPBIWPattern*
        buildPattern();
        
        PatternBuilder&
        startWithPattern(IPBIWPattern*);
        
        PatternBuilder&
        joinWithPattern(IPBIWPattern*);
        
        void 
        clear()
        { patternInformations.clear(); }
        
      private:
        void reorganizeOperations(IPBIWPattern* returnedPattern);
        
        typedef std::deque<PatternInformation> PatternInformationList;
        PatternInformationList patternInformations;
      };
      
    }
  }
}

#endif	/* PATTERNBUILDER_H */
