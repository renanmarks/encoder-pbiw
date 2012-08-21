/* 
 * File:   Operand.h
 * Author: helix
 *
 * Created on August 18, 2012, 10:57 PM
 */

#ifndef RVEX_OPERAND_H
#define	RVEX_OPERAND_H

#include "src/GenericAssembly/Interfaces/IOperand.h"

namespace rVex
{
  class Syllable;
  /**
   * The rVEX operand class.
   */
  class Operand : public GenericAssembly::Interfaces::IOperand
  {
  public:
    typedef enum {
      GRSource = 1, GRDestiny, BRSource, BRDestiny, Imm9, Imm12
    } Type;
    
    Operand();
    Operand(int);
    Operand(Type);
    Operand(Type, int);
    Operand(const Operand&);
    
    virtual GenericAssembly::Interfaces::IOperand* clone();
    
    virtual void setType(Type);
    virtual Type getType() const;
    
    virtual void setTypeCode(int);
    virtual int getTypeCode() const;

    virtual bool isImmediate(Type) const;
    virtual bool isRegister(Type) const;
    
    virtual bool isImmediate() const;
    virtual bool isRegister() const;

    virtual void setValue(int);
    virtual int getValue() const;
  
    virtual void setOperationBelonged(GenericAssembly::Interfaces::IOperation*);
    virtual GenericAssembly::Interfaces::IOperation* getOperationBelonged() const;
    
    bool operator==(const IOperand&) const;
    bool operator!=(const IOperand&) const;
    
  private:
    Type type;
    int value;
    Syllable* syllableBelonged;
  };
}

#endif	/* OPERAND_H */

