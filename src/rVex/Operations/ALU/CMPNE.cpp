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

#include "CMPNE.h"
#include "rVex/Base/Instruction.h"
#include "rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      GenericAssembly::Utils::OperandVector CMPNE::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        if (this->haveBRDestiny)
          builder.insertOperand(Operand(Operand::GRDestiny));
        else
          builder.insertOperand(grDestiny);
        
        builder.insertOperands(readRegisters);
        
        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertOperand(this->shortImmediate);
        
        if (this->haveBRDestiny)
          builder.insertOperand(this->brDestiny);
        
        return builder.getOperandVector();
      }
    }
  }
}
