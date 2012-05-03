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
        setInstructionsAnnulationBits();
        
        IPBIWPattern*
        getPattern() const
        { return pattern; }
        
      private:
        IPBIWPattern* pattern;
        
        typedef std::deque<IPBIWInstruction*> InstructionCollection;
        InstructionCollection instructions;
        
        typedef std::vector<OperationInformation> OperationsCollections;
        OperationsCollections slots; // ctrl, mul1, mul2, mem
      };
    }
  }
}

#endif	/* PATTERNINFORMATION_H */

