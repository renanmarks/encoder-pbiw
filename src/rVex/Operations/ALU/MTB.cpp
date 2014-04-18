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
#include <iostream>

#include "MTB.h"
#include "rVex/Instruction.h"
#include "rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      GenericAssembly::Utils::OperandVector MTB::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(Operand(Operand::GRDestiny));
        builder.insertOperand(readRegisters[0]);
        builder.insertOperand(Operand(Operand::GRSource));
        builder.insertOperand(brDestiny);
        
        return builder.getOperandVector();
      }
    }
  }
}
