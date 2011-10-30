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
    
    explicit Operand(unsigned char);
    explicit Operand(unsigned char, Immediate::Type);
    virtual ~Operand() { }
  
    virtual void setIndex(unsigned int index) 
    { this->index = index; }
    
    virtual unsigned int getIndex() const
    { return this->index; }
    
    virtual bool isImmediate9Bits() const
    { return immType == Immediate::NineBits; }
    
    virtual bool isImmediate12Bits() const
    { return immType == Immediate::TwelveBits; }
    
    virtual bool isImmediate() const
    { return isImmediate12Bits() || isImmediate9Bits(); }
    
    virtual void setValue(short value)
    { this->value = value; }
    
    virtual short getValue() const
    { return value; }

    virtual bool operator<(const IOperand&) const;
    virtual bool operator>(const IOperand&) const;
    virtual bool operator<=(const IOperand&) const;
    virtual bool operator>=(const IOperand&) const;
    
    virtual bool operator==(const IOperand&) const;
    virtual bool operator!=(const IOperand&) const;
    
  private:
    // Used to know in what position we are in the PBIW instruction
    unsigned char index;
    
    // This is an immediate operand?
    Immediate::Type immType;
    
    // The value of this operand (register number or immediate number)
    short value;
  };
}



#endif	/* OPERAND_H */

