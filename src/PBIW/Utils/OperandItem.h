/* 
 * File:   OperandVector.h
 * Author: helix
 *
 * Created on December 9, 2011, 8:45 PM
 */

#ifndef OPERANDITEM_H
#define	OPERANDITEM_H

#include "src/PBIW/Operand.h"
#include <string>

namespace rVex
{
  class Syllable;
}

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
        
        explicit OperandItem(PBIW::Operand* operand, Type type, const rVex::Syllable* syllable)
          : operand( operand ), type(type), syllableBelonged(syllable)
        {}
        
        OperandItem(const OperandItem& other)
          : operand( new PBIW::Operand( *(other.getOperand()) ) ), type(other.getType()), syllableBelonged(other.getSyllableBelonged())
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
            this->syllableBelonged = other.getSyllableBelonged();
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

        void
        setSyllableBelonged(rVex::Syllable* syllableBelonged)
        { this->syllableBelonged=syllableBelonged; }

        const rVex::Syllable*
        getSyllableBelonged() const
        { return syllableBelonged; }
      
      private:
        PBIW::Operand* operand;
        Type type;
        const rVex::Syllable* syllableBelonged;
      };
  }
}

#endif	/* OPERANDITEM_H */

