/* 
 * File:   OperandVector.h
 * Author: helix
 *
 * Created on December 9, 2011, 8:45 PM
 */

#ifndef OPERANDITEMDTO_H
#define	OPERANDITEMDTO_H

#include "src/PBIW/Interfaces/IOperand.h"
#include "src/GenericAssembly/Interfaces/IOperation.h"
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

