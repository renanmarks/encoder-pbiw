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
 * File:   PatternBuilder.h
 * Author: helix
 *
 * Created on May 3, 2012, 4:54 PM
 */

#ifndef PATTERNBUILDER_H
#define	PATTERNBUILDER_H

#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "PBIW/Interfaces/IOperation.h"
#include "PBIW/Interfaces/IPBIWFactory.h"

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
        PatternBuilder(IPBIWFactory& factory)
        : factory(factory)
        { }
        
        PatternBuilder(const PatternBuilder& orig)
        : 
        factory(orig.factory),
        patternInformations(orig.patternInformations)
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
        IPBIWFactory& factory;
        void reorganizeOperations(IPBIWPattern* returnedPattern);
        
        typedef std::deque<PatternInformation> PatternInformationList;
        PatternInformationList patternInformations;
      };
      
    }
  }
}

#endif	/* PATTERNBUILDER_H */
