/* 
 * File:   Operand.h
 * Author: helix
 *
 * Created on October 20, 2011, 2:00 PM
 */

#ifndef PBIWPARTIAL_OPERAND_H
#define	PBIWPARTIAL_OPERAND_H

#include "src/PBIW/Interfaces/IOperand.h"
#include "src/rVex/Operand.h"
#include "src/rVex/Syllable.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;
  
  /**
   * The operand used in the PBIW encoding.
   */
  class Operand : public IOperand
  {
  public:
    explicit Operand();
    explicit Operand(int);
    explicit Operand(int, rVex::Operand::Type);
    Operand(const Operand&);
    virtual ~Operand() { }
  
    virtual IOperand* clone() const
    { return new Operand(*this); }
    
    virtual void setIndex(unsigned int index) 
    { this->index = index; }
    
    virtual unsigned int getIndex() const
    { return this->index; }
    
    virtual void setTypeCode(int type) 
    { this->type = static_cast<rVex::Operand::Type>(type); }
    
    virtual int getTypeCode() const
    { return static_cast<int>(this->type); }
    
    virtual bool isImmediate9Bits() const
    { return this->type == rVex::Operand::Imm9; }
    
    virtual void isImmediate9Bits(bool valid) 
    { this->type = valid ? rVex::Operand::Imm9 : rVex::Operand::GRSource; }
    
    virtual bool isImmediate12Bits() const
    { return this->type == rVex::Operand::Imm12; }
    
    virtual void isImmediate12Bits(bool valid) 
    { this->type = valid ? rVex::Operand::Imm12 : rVex::Operand::GRSource; }
    
    virtual bool isImmediate() const
    { return isImmediate12Bits() || isImmediate9Bits(); }
    
    virtual void setValue(int value)
    { this->value = value; }
    
    virtual int getValue() const
    { return value; }
    
    virtual bool isBRSource() const
    { return type == rVex::Operand::BRSource; }
    
    virtual void setBRSource(const bool value)
    { type = value ? rVex::Operand::BRSource : rVex::Operand::GRSource; }
    
    virtual bool isBRDestiny() const
    { return type == rVex::Operand::BRDestiny; }
    
    virtual void setBRDestiny(const bool value)
    { type = value ? rVex::Operand::BRDestiny : rVex::Operand::GRSource; }

    virtual bool operator<(const IOperand&) const;
    virtual bool operator>(const IOperand&) const;
    virtual bool operator<=(const IOperand&) const;
    virtual bool operator>=(const IOperand&) const;
    
    virtual bool operator==(const IOperand&) const;
    virtual bool operator!=(const IOperand&) const;
    
  private:
    // Used to know in what position we are in the PBIW instruction
    unsigned int index;
    
    rVex::Operand::Type type;
    
    // The value of this operand (register number or immediate number)
    int value;
  };
}



#endif	/* OPERAND_H */

