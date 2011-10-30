/* 
 * File:   UnitaryPattern.h
 * Author: helix
 *
 * Created on October 20, 2011, 3:38 PM
 */

#ifndef UNITARYPATTERN_H
#define	UNITARYPATTERN_H

#include "Interfaces/IPattern.h"

namespace PBIW
{
  using namespace Interfaces;

/*  Class(or struct :P) used to store the individual pattern data.
 
    ,___9b___,__4b___,__4b__,__4b__,__3b__,
    ---------------------------------------
    |        |  0-15 | 0-15 | 0-15 | 0-7  |
    ---------------------------------------
    ' Opcode ' Write ' Read ' Read '  wBr '
 */
  class UnitaryPattern : public IPattern
  {
  public:
    virtual void setOpcode(unsigned short opcode)
    { this->opcode = opcode; }
    
    virtual unsigned short getOpcode() const
    { return this->opcode; }
    
    virtual void addReadOperand(IOperand* operand)
    { this->readOperands.push_back(operand); }
    
    virtual OperandVector getOperands() const
    { return this->readOperands; }
    
    virtual void pointToWriteOperand(IOperand* operand)
    { this->writeOperand = operand; }
    
    virtual void pointToWriteBrOperand(IOperand* operand)
    { this->writeBrOperand = operand; }
    
  private:
    /**
     * Syllable opcode
     */ 
    unsigned short opcode; // 9b
    
    /**
     * Pointer to the write GR operand
     */
    IOperand* writeOperand; // 4b
    
    /**
     * Vector of pointers to read operands
     */
    OperandVector readOperands; // 2 x 4b
    
    /**
     * Pointer to the write BR operand
     */
    IOperand* writeBrOperand; // 3b
  };
}

#endif	/* UNITARYPATTERN_H */

