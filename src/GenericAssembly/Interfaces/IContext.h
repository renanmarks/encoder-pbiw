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
 * File:   IContext.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:59 PM
 */

#ifndef GENERICASSEMBLY_ICONTEXT_H
#define	GENERICASSEMBLY_ICONTEXT_H

#include "GenericAssembly/Interfaces/IInstruction.h"
#include "GenericAssembly/Interfaces/IOperation.h"
#include "ILabel.h"

namespace GenericAssembly
{
  namespace Interfaces
  {
    class IContext
    {
    public:
      typedef std::deque<GenericAssembly::Interfaces::IOperation*> OperationDeque;
      typedef std::deque<GenericAssembly::Interfaces::IInstruction*> InstructionDeque;
      typedef std::deque<GenericAssembly::Interfaces::ILabel*> LabelDeque;
      
      virtual ~IContext() { }

      /**
       * Switch the debug mode (i.e. verbose output)
       */
      virtual void enableDebugging(bool) = 0;
      
      /**
       * Return the debug status of this context.
       */
      virtual bool isDebuggingEnabled() const = 0;
      
      /**
       * Return the instructions stored in this context.
       */
      virtual InstructionDeque getInstructions() const = 0;
      
      /**
       * Return the operations stored in this context.
       */
      virtual OperationDeque getOperations() const = 0;
      
      /**
       * Return the labels stored in this context.
       */
      virtual LabelDeque getLabels() const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_ICONTEXT_H */

