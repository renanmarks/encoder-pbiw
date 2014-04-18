/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/* 
 * File:   Operation.h
 * Author: helix
 *
 * Created on October 20, 2011, 3:38 PM
 */

#ifndef PBIWFULL_OPERATION_H
#define	PBIWFULL_OPERATION_H

#include "PBIW/Interfaces/IOperation.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

/*  Class(or struct :P) used to store the individual pattern data.
 
    ,___9b___,__4b___,__4b__,__4b__,__3b__,
    ---------------------------------------
    |        |  0-15 | 0-15 | 0-15 | 0-7  |
    ---------------------------------------
    ' Opcode ' Write ' Read ' Read '  wBr '
                            (or imm)
 */
  class Operation : public IOperation
  {
  public:
    Operation()
    :type(rVex::Syllable::SyllableType::ALU), 
      immediateSwitch(rVex::Syllable::ImmediateSwitch::NO_IMM), 
      opcode(0),
      originalOpcode(0),
      readBrOperand(-1),
      writeOperand(-1), 
      readOperands(),  
      writeBrOperand(-1)
    { }
    
    Operation(const Operation& other)
    :type(other.type), 
      immediateSwitch(other.immediateSwitch), 
      opcode(other.opcode),
      originalOpcode(other.originalOpcode),
      readBrOperand(other.readBrOperand),
      writeOperand(other.writeOperand), 
      readOperands(other.readOperands),  
      writeBrOperand(other.writeBrOperand)
    { }
    
    ~Operation()
    { }
    
    virtual IOperation* clone() const
    { return new Operation(*this); }
    
    virtual void setOpcode(unsigned short opcode);
    
    virtual unsigned short getOpcode() const
    { return this->opcode; }
    
    virtual void setOriginalOpcode(unsigned short opcode)
    { this->originalOpcode = opcode; }
    
    virtual unsigned short getOriginalOpcode() const
    { return originalOpcode; }
    
    virtual void setBrReadOperand(short index)
    { this->readBrOperand = index; }
    
    virtual short getBrReadOperand() const
    { return readBrOperand; }
    
    virtual void setImmediateSwitch(int type)
    { immediateSwitch = static_cast<rVex::Syllable::ImmediateSwitch::Type>(type); }
    
    virtual int getImmediateSwitch() const
    { return static_cast<int>(immediateSwitch); }
    
    virtual void addOperand(const IOperand& operand);
    
    virtual OperandIndexVector getOperandsIndexes() const;
    
    virtual void pointToWriteOperand(IOperand* operand)
    { this->writeOperand = operand->getIndex(); }
    
    virtual void pointToWriteBrOperand(IOperand* operand)
    { this->writeBrOperand = operand->getIndex(); }
    
    virtual void updateIndexes(int oldIndex, int newIndex);
    
    virtual bool operator<(const IOperation&) const;
    virtual bool operator>(const IOperation&) const;
    virtual bool operator<=(const IOperation&) const;
    virtual bool operator>=(const IOperation&) const;
    
    virtual bool operator==(const IOperation&) const;
    virtual bool operator!=(const IOperation&) const;
    
    virtual void
    setType(int type)
    { this->type=static_cast<rVex::Syllable::SyllableType::Type>(type); }

    virtual int
    getType() const
    { return static_cast<int>(type); }
            
  private:
    rVex::Syllable::SyllableType::Type type;
    
    rVex::Syllable::ImmediateSwitch::Type immediateSwitch;
    
    /**
     * Syllable opcode
     */ 
    unsigned short opcode; // 9b
    unsigned short originalOpcode; // 9b
    
    short readBrOperand; // 3b , used only in ADDCG, DIVS, SLCT, SLCTF, BR and BRF
    
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

