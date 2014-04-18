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
 * File:   OperationInformation.h
 * Author: helix
 *
 * Created on May 3, 2012, 4:11 PM
 */

#ifndef OPERATIONINFORMATION_H
#define	OPERATIONINFORMATION_H

#include "PBIW/Interfaces/IOperation.h"

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

