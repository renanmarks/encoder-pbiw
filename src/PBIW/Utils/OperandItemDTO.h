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
     * Encapsulates the DTO (Data Transfer Object) used by the PBIW encoder
     * Provides an vector with all the operands (destiny, source and immediate) 
     * inside.
     */
    
      /**
       * An item of the OperandVector.
       */
      class OperandItemDTO
      {
      public:
        typedef enum {
          GRSource, GRDestiny, BRSource, BRDestiny, Imm
        } Type;
        
        explicit OperandItemDTO(PBIW::Interfaces::IOperand* operand, Type type, const GenericAssembly::Interfaces::IOperation* operation)
          : operand( operand ), type(type), operationBelonged(operation)
        {}
        
        OperandItemDTO(const OperandItemDTO& other)
          : operand( other.getOperand()->clone() ), type(other.getType()), operationBelonged(other.getOperationBelonged())
        {}
        
        ~OperandItemDTO()
        { delete operand; }

        OperandItemDTO& operator=(const OperandItemDTO& other)
        {
          if (this != &other)
          {
            delete this->operand;
            this->operand = other.getOperand()->clone();
            this->type = other.getType();
            this->operationBelonged = other.getOperationBelonged();
          }
          
          return *this;
        }
        
        void
        setType(Type type)
        { this->type=type; }

        Type
        getType() const
        { return type; }

        void
        setOperand(PBIW::Interfaces::IOperand* operand)
        { this->operand = operand; }

        PBIW::Interfaces::IOperand*
        getOperand() const
        { return operand; }

        void
        setOperationBelonged(GenericAssembly::Interfaces::IOperation* syllableBelonged)
        { this->operationBelonged=syllableBelonged; }

        const GenericAssembly::Interfaces::IOperation*
        getOperationBelonged() const
        { return operationBelonged; }
      
      private:
        PBIW::Interfaces::IOperand* operand;
        Type type;
        const GenericAssembly::Interfaces::IOperation* operationBelonged;
      };
  }
}

#endif	/* OPERANDITEM_H */

