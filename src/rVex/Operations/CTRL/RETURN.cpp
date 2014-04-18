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
#include <vector>
#include "RETURN.h"
#include "rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      GenericAssembly::Utils::OperandVector
      RETURN::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
//        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
//        builder.insertRegister(this->readRegisters.at(0), OperandItem::GRSource);
        builder.insertOperand(this->readRegisters.at(1));
        builder.insertOperand(this->shortImmediate);
        
        return builder.getOperandVector();
      }
      
      void 
      RETURN::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 6;
        final |= getGrDestinyValue();

        final <<= 12;
        final |= getShortImmediateValue();

        final <<= 5;

        final|=last;
        final<<=1;
        final|=first;

        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}

