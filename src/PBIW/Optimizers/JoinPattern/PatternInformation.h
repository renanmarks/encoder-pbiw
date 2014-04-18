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
 * File:   PatternInformation.h
 * Author: helix
 *
 * Created on May 3, 2012, 4:11 PM
 */

#ifndef PATTERNINFORMATION_H
#define	PATTERNINFORMATION_H

#include <deque>
#include <vector>

#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "PBIW/Interfaces/IOperation.h"
#include "OperationInformation.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Optimizers
  {
    namespace JoinPattern
    {
      /**
       * Pattern informations
       */
      class PatternInformation
      {
      public:
        typedef std::deque<IPBIWInstruction*> InstructionCollection;
        typedef std::vector<OperationInformation> OperationsCollections;
        
        PatternInformation()
        : pattern(NULL),
          slots(4, OperationInformation())
        {}
        
        PatternInformation(const PatternInformation& orig)
        : pattern(orig.pattern),
          instructions(orig.instructions),
          slots(orig.slots)
        { }
        
        virtual ~PatternInformation()
        { }
        
        void
        addOperation(IOperation*, int);

        void
        setPattern(IPBIWPattern*);

        void
        updateInstructionsAnnulationBits();
        
        void
        updateInstructionsPointers(IPBIWPattern*);
        
        IPBIWPattern*
        getPattern() const
        { return pattern; }

        OperationsCollections
        getSlots() const
        { return slots; }
        
        void 
        updateSlots(IPBIWPattern*);
      
      private:
        /**
         * Functor used to find a operation in the collection
         */
        class FindOperation : public std::unary_function<IOperation, bool>
        {
        public:
            FindOperation(const IOperation* operation) 
              : operation(operation)
            { }

            bool operator()(IOperation* const& t) 
            { return (*t == *operation); }

        private:
            const IOperation* operation;
        };
        
        IPBIWPattern* pattern;
        InstructionCollection instructions;
        OperationsCollections slots; // ctrl, mul1, mul2, mem
      };
    }
  }
}

#endif	/* PATTERNINFORMATION_H */

