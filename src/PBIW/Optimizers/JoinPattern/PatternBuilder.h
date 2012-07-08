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
        
        /**
         * Instantiates a really new Pattern object with all the instructions
         * from older patterns pointing to it and all the annulation bits
         * updated to use this new pattern;
         */
        IPBIWPattern*
        buildPattern();
        
        /**
         * Calls the clear() method and initializes this PatternBuilder instance
         * with the pattern passed as argument, gathering its information.
         */
        PatternBuilder&
        startWithPattern(IPBIWPattern*);
        
        /**
         * Adds a new pattern to the builder to gather information about it.
         */
        PatternBuilder&
        joinWithPattern(IPBIWPattern*);
        
        /**
         * Erases all the information gathered to join two patterns.
         * Simply clear the PatternInformation from this builder to
         * start another joining process.
         */
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
