/* 
 * File:   Operation.h
 * Author: helix
 *
 * Created on October 20, 2011, 3:38 PM
 */

#ifndef OPERATION_H
#define	OPERATION_H

#include "Interfaces/IOperation.h"

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
  class Operation : public IOperation
  {
  public:
    Operation()
    :opcode(0), writeOperand(-1), writeBrOperand(-1)
    {}
    
    virtual void setOpcode(unsigned short opcode)
    { this->opcode = opcode; }
    
    virtual unsigned short getOpcode() const
    { return this->opcode; }
    
    virtual void addOperand(const IOperand& operand);
    
    virtual OperandIndexVector getOperandsIndexes() const;
    
    virtual void pointToWriteOperand(IOperand* operand)
    { this->writeOperand = operand->getIndex(); }
    
    virtual void pointToWriteBrOperand(IOperand* operand)
    { this->writeBrOperand = operand->getIndex(); }
    
    virtual bool operator==(const IOperation&) const;
    virtual bool operator!=(const IOperation&) const;
    
  private:
    /**
     * Syllable opcode
     */ 
    unsigned short opcode; // 9b
    
    /**
     * Pointer to the write GR operand
     */
    int writeOperand; // 4b
    
    /**
     * Vector of pointers to read operands
     */
    OperandIndexVector readOperands; // 2 x 4b
    
    /**
     * Pointer to the write BR operand
     */
    int writeBrOperand; // 3b
  };
}

#endif	/* OPERATION_H */

