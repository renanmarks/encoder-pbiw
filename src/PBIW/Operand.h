/* 
 * File:   Operand.h
 * Author: helix
 *
 * Created on October 20, 2011, 2:00 PM
 */

#ifndef OPERAND_H
#define	OPERAND_H

#include "Interfaces/IOperand.h"

namespace PBIW
{
  using namespace Interfaces;
  
  /**
   * The operand used in the PBIW encoding.
   */
  class Operand : public IOperand
  {
  public:
    
    typedef struct {
      typedef enum {
        None, NineBits, TwelveBits
      } Type;
    } Immediate;
    
    explicit Operand();
    explicit Operand(int);
    explicit Operand(int, Immediate::Type);
    Operand(const Operand&);
    virtual ~Operand() { }
  
    virtual void setIndex(unsigned int index) 
    { this->index = index; }
    
    virtual unsigned int getIndex() const
    { return this->index; }
    
    virtual bool isImmediate9Bits() const
    { return this->immType == Immediate::NineBits; }
    
    virtual bool isImmediate12Bits() const
    { return this->immType == Immediate::TwelveBits; }
    
    virtual bool isImmediate() const
    { return isImmediate12Bits() || isImmediate9Bits(); }
    
    virtual Immediate::Type getImmediateType() const
    { return immType; }
    
    virtual void setValue(int value)
    { this->value = value; }
    
    virtual int getValue() const
    { return value; }

    virtual bool operator<(const IOperand&) const;
    virtual bool operator>(const IOperand&) const;
    virtual bool operator<=(const IOperand&) const;
    virtual bool operator>=(const IOperand&) const;
    
    virtual bool operator==(const IOperand&) const;
    virtual bool operator!=(const IOperand&) const;
    
  private:
    // Used to know in what position we are in the PBIW instruction
    unsigned int index;
    
    // This is an immediate operand?
    Immediate::Type immType;
    
    // The value of this operand (register number or immediate number)
    int value;
  };
}



#endif	/* OPERAND_H */

