/* 
 * File:   IContext.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:59 PM
 */

#ifndef ICONTEXT_H
#define	ICONTEXT_H

#include "src/GenericAssembly/Interfaces/IInstruction.h"
#include "src/GenericAssembly/Interfaces/IOperation.h"
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

#endif	/* ICONTEXT_H */

