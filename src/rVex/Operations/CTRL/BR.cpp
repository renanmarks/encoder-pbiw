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
#include "BR.h"
#include "rVex/Instruction.h"
#include "rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      
      GenericAssembly::Utils::OperandVector
      BR::exportOperandVector() const  // O(1)
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(brSource);
        builder.insertOperand(shortImmediate);
        
        return builder.getOperandVector();
      }
      
      void 
      BR::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 18;
        final |= (this->branchDestiny->getBelongedInstruction()->getAddress() & 0x00000FFF);

        final <<= 3;
        final |= getBrSourceValue();

        final <<= 1;
        final |= first;
        final <<= 1;
        final |= last;
        
        output.printOperation(*this, std::vector<unsigned int>(1,final));
      }
    }
  }
}
