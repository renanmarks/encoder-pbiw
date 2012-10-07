/* 
 * File:   OperandVectorBuilder.h
 * Author: helix
 *
 * Created on December 18, 2011, 5:33 PM
 */

#ifndef OPERANDVECTORBUILDER_H
#define	OPERANDVECTORBUILDER_H

#include "src/GenericAssembly/Utils/OperandVector.h"
#include "src/GenericAssembly/Interfaces/IOperation.h"

namespace rVex
{
  namespace Utils
  {
    class OperandVectorBuilder
    {
    public:
//      OperandVectorBuilder(IOperation::GenericAssembly::Utils::OperandVector&);
    
      template <class TOperand>
      void
      insertOperand(const TOperand& value) // O(1)
      {
        operands.push_back(&value);
      }

      template <class TOperand> 
      void
      insertOperands(std::vector<TOperand> const& values) // O(1)
      {
        typename std::vector<TOperand>::const_iterator it;

        for (it=values.begin(); it < values.end(); it++) // O(1)
          insertOperand(*it);
      }
      
      void clearOperandVector();
      
      GenericAssembly::Utils::OperandVector getOperandVector();
      
    private:
      GenericAssembly::Utils::OperandVector operands;
    };
  }
}

#endif	/* OPERANDVECTORBUILDER_H */

