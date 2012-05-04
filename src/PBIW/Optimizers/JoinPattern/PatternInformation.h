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

#include "src/PBIW/Interfaces/IPBIWInstruction.h"
#include "src/PBIW/Interfaces/IPBIWPattern.h"
#include "src/PBIW/Interfaces/IOperation.h"
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
              : operation(operation), position(0) 
            { }

            bool operator()(IOperation* const& t) 
            { position++; return (*t == *operation); }

            int
            GetPosition() const
            { return position; }
            
        private:
            const IOperation* operation;
            int position;
        };
        
        IPBIWPattern* pattern;
        InstructionCollection instructions;
        OperationsCollections slots; // ctrl, mul1, mul2, mem
      };
    }
  }
}

#endif	/* PATTERNINFORMATION_H */

