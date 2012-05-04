/* 
 * File:   OperationInformation.h
 * Author: helix
 *
 * Created on May 3, 2012, 4:11 PM
 */

#ifndef OPERATIONINFORMATION_H
#define	OPERATIONINFORMATION_H

#include "src/PBIW/Interfaces/IOperation.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Optimizers
  {
    namespace JoinPattern
    {
      /**
       * Class that tracks the pattern's operations for future reference
       * when building the joined patterns.
       */
      class OperationInformation
      {
      public:
        OperationInformation()
        : operation(NULL),
          originalPosition(-1)
        { }
        OperationInformation(const OperationInformation& orig)
        : operation(orig.operation),
          originalPosition(orig.originalPosition)
        { }
        
        virtual ~OperationInformation()
        { }

        void
        setOriginalPosition(int originalPosition)
        { this->originalPosition=originalPosition; }

        int
        getOriginalPosition() const
        { return originalPosition; }

        void
        setOperation(IOperation* operation)
        { this->operation=operation; }

        IOperation*
        getOperation() const
        { return operation; }

        void
        reset()
        { *this = OperationInformation(); }
        
      private:
        IOperation* operation;
        int originalPosition;
      };
    }
  }
}

#endif	/* OPERATIONINFORMATION_H */

