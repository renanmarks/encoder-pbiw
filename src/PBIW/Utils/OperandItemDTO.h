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
 * File:   OperandVector.h
 * Author: helix
 *
 * Created on December 9, 2011, 8:45 PM
 */

#ifndef OPERANDITEMDTO_H
#define	OPERANDITEMDTO_H

#include "PBIW/Interfaces/IOperand.h"
#include "GenericAssembly/Interfaces/IOperation.h"
#include <string>

namespace PBIW
{
  namespace Utils
  {
      /**
      * The DTO (Data Transfer Object) used by the PBIW encoder that encapsulates
      * all the information necessary to the PBIW encoder: the original operand
      * and a PBIW encoded operand created by the PBIW factory. 
      */
      class OperandItemDTO
      {
      public:
        explicit OperandItemDTO(PBIW::Interfaces::IOperand* operandPBIW, 
                                const GenericAssembly::Interfaces::IOperand* operand)
          : operandPBIW( operandPBIW ), 
            operand(operand)
        {}
        
        OperandItemDTO(const OperandItemDTO& other)
          : operandPBIW( other.getPBIWOperand()->clone() ), 
            operand(operand)
        {}
        
        ~OperandItemDTO()
        {  }

        OperandItemDTO& operator=(const OperandItemDTO& other)
        {
          if (this != &other)
          {
            delete this->operandPBIW;
            this->operandPBIW = other.getPBIWOperand()->clone();
            this->operand = other.getOperand();
          }
          
          return *this;
        }
        
        void
        setPBIWOperand(PBIW::Interfaces::IOperand* operand)
        { this->operandPBIW = operand; }

        PBIW::Interfaces::IOperand*
        getPBIWOperand() const
        { return operandPBIW; }
        
        void
        setOperand(const GenericAssembly::Interfaces::IOperand* operand)
        { this->operand = operand; }

        const GenericAssembly::Interfaces::IOperand*
        getOperand() const
        { return operand; }

      private:
        PBIW::Interfaces::IOperand* operandPBIW;
        const GenericAssembly::Interfaces::IOperand* operand;
      };
  }
}

#endif	/* OPERANDITEM_H */

