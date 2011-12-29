/* 
 * File:   OperandVector.h
 * Author: helix
 *
 * Created on December 9, 2011, 8:45 PM
 */

#ifndef OPERANDITEM_H
#define	OPERANDITEM_H

#include "src/PBIW/Operand.h"

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
      class OperandItem
      {
      public:
        typedef enum {
          GRSource, GRDestiny, BRSource, BRDestiny, Imm
        } Type;
        
        explicit OperandItem(PBIW::Operand* operand, Type type)
          : operand( operand ), type(type)
        {}
        
        OperandItem(const OperandItem& other)
          : operand( new PBIW::Operand( *(other.getOperand()) ) ), type(other.getType())
        {}
        
        ~OperandItem()
        { delete operand;  }

        OperandItem& operator=(const OperandItem& other)
        {
          if (this != &other)
          {
            delete this->operand;
            this->operand = new PBIW::Operand( *(other.getOperand()) );
            this->type = other.getType();
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
        setOperand(PBIW::Operand* operand)
        { this->operand = operand; }

        PBIW::Operand*
        getOperand() const
        { return operand; }

      private:
        PBIW::Operand* operand;
        Type type;
      };
  }
}

#endif	/* OPERANDITEM_H */

