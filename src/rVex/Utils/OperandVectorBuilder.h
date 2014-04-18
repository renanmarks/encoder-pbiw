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
 * File:   OperandVectorBuilder.h
 * Author: helix
 *
 * Created on December 18, 2011, 5:33 PM
 */

#ifndef OPERANDVECTORBUILDER_H
#define	OPERANDVECTORBUILDER_H

#include "GenericAssembly/Utils/OperandVector.h"
#include "GenericAssembly/Interfaces/IOperation.h"

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

