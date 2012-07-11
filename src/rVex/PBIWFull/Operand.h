/* 
 * File:   Operand.h
 * Author: helix
 *
 * Created on October 20, 2011, 2:00 PM
 */

#ifndef PBIWFULL_OPERAND_H
#define	PBIWFULL_OPERAND_H

#include "src/PBIW/Interfaces/IOperand.h"
#include "src/rVex/Syllable.h"

namespace PBIWFull
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
    explicit Operand(int, rVex::Syllable::ImmediateSwitch::Type);
    Operand(const Operand&);
    virtual ~Operand() { }
  
    virtual IOperand* clone() const
    { return new Operand(*this); }
    
    virtual void setIndex(unsigned int index) 
    { this->index = index; }
    
    virtual unsigned int getIndex() const
    { return this->index; }
    
    virtual bool isImmediate9Bits() const
    { return this->immType == rVex::Syllable::ImmediateSwitch::SHORT_IMM; }
    
    virtual void isImmediate9Bits(bool valid) 
    { this->immType = rVex::Syllable::ImmediateSwitch::SHORT_IMM; }
    
    virtual bool isImmediate12Bits() const
    { return this->immType == rVex::Syllable::ImmediateSwitch::BRANCH_IMM; }
    
    virtual void isImmediate12Bits(bool valid) 
    { this->immType = rVex::Syllable::ImmediateSwitch::BRANCH_IMM; }
    
    virtual bool isImmediate() const
    { return isImmediate12Bits() || isImmediate9Bits(); }
    
    virtual rVex::Syllable::ImmediateSwitch::Type getImmediateType() const
    { return immType; }
    
    virtual void setValue(int value)
    { this->value = value; }
    
    virtual int getValue() const
    { return value; }
    
    virtual rVex::Syllable::BranchOperand::Type getBanchType() const
    { return branchType; }
    
    virtual bool isBRSource() const
    { return branchType == rVex::Syllable::BranchOperand::SOURCE; }
    
    virtual void setBRSource(const bool value)
    { if (value) branchType = rVex::Syllable::BranchOperand::SOURCE; }
    
    virtual bool isBRDestiny() const
    { return branchType == rVex::Syllable::BranchOperand::DESTINY; }
    
    virtual void setBRDestiny(const bool value)
    { if (value) branchType = rVex::Syllable::BranchOperand::DESTINY; }

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
    rVex::Syllable::ImmediateSwitch::Type immType;
    
    // Type of this operand
    rVex::Syllable::BranchOperand::Type branchType;
    
    // The value of this operand (register number or immediate number)
    int value;
  };
}



#endif	/* OPERAND_H */

