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
 * File:   PBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef PBIWPARTIAL_RVEX64PBIWINSTRUCTION_H
#define	PBIWPARTIAL_RVEX64PBIWINSTRUCTION_H

#include <vector>
#include "Label.h"

#include "rVex96PBIWPattern.h"
#include "Operand.h"
#include "rVex/Base/Syllable.h"
#include "PBIW/Utils/OperandVector.h"
#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "PBIW/Interfaces/IOperand.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;

  /**
   * r-VEX 64 bits length instruction 
   */
  class rVex64PBIWInstruction : public IPBIWInstruction
  {
  public:
    rVex64PBIWInstruction() 
    : address(0), 
      branchDestiny(NULL), 
      pattern(NULL), 
      codingOperation(NULL),
      hasBRSrc(false),
      immediate(),
      zeroOperand(0),
      annulBits(4,false)
      //readOperands(0, Operand(0)), writeOperands()
    {
      Operand operand(0);
      operand.setIndex(0);
      readOperands.push_back(operand); // Zero register
      readOperands.push_back(operand); // Space for (possible) future BRSRC
    }
    
    rVex64PBIWInstruction(const rVex64PBIWInstruction& other) : 
      address(other.address), 
      labels(other.labels),
      destinyLabel(other.destinyLabel),
      branchDestiny(other.branchDestiny), 
      pattern(other.pattern), 
      readOperands(other.readOperands),
      hasBRSrc(other.hasBRSrc),
      writeOperands(other.writeOperands),
      immediate(other.immediate),
      zeroOperand(other.zeroOperand),
      syllablesPacked(other.syllablesPacked),
      annulBits(other.annulBits)
    {
      zeroOperand.setIndex(0);
    }
    
    virtual ~rVex64PBIWInstruction() { }
    
    virtual IPBIWInstruction* clone() const;
    
    virtual void setAddress(unsigned int addr)
    { address = addr; }
        
    virtual unsigned int getAddress() const
    { return address; }
    
    virtual void setLabel(const ILabel*);
    virtual std::deque<ILabel*> getLabels() const
    { return labels; }
    
    virtual void pointToPattern(IPBIWPattern& pattern);
    
    virtual void setCodingOperation(IOperation& operation);
    virtual IOperation* getCodingOperation() const;
    
    virtual const rVex96PBIWPattern* getPattern() const
    { return this->pattern; }
    
    virtual bool containsImmediate() const
    { return immediate.isImmediate9Bits() || immediate.isImmediate12Bits(); }
     
    virtual const IOperand& containsOperand(const IOperand&) const;
    
    virtual void addOperand(IOperand&);
    
    virtual void addReadOperand(IOperand&);
    virtual void addWriteOperand(IOperand&);
    
    virtual void addBranchOperand(IOperand&);
    
    virtual void setBranchSourceOperand(IOperand&);
    virtual bool hasBranchSourceOperand() const;
    
    virtual bool hasOperandSlot(const PBIW::Utils::OperandItemDTO&);
    virtual bool hasReadOperandSlot() const;
    virtual bool hasWriteOperandSlot() const;
    
    virtual bool hasControlOperationWithLabelDestiny();
    
    virtual std::string getLabelDestiny() const
    { return destinyLabel; }
        
    virtual void setLabelDestiny(std::string label)
    { this->destinyLabel = label; }
    
    virtual void setImmediateValue(int value)
    { immediate.setValue(value); }
        
    virtual int readOperandQuantity() const
    { return readOperands.size(); }
    virtual int writeOperandQuantity() const
    { return writeOperands.size(); }
    
    virtual void print(IPBIWPrinter&) const;
    
    virtual PBIW::Utils::OperandVector getOperands() const;
    
    virtual void setOperationReferences(const std::list<GenericAssembly::Interfaces::IOperation*>& list);
    
    virtual std::list<GenericAssembly::Interfaces::IOperation*> getOperationReferences() const;

    virtual void setBranchDestiny(const IPBIWInstruction& branchDestiny);

    virtual rVex64PBIWInstruction* getBranchDestiny() const
    { return branchDestiny; }
    
    virtual const AnnulationBits& getAnnulBits() const
    {     return this->annulBits;    }

    virtual void setAnnulBit(int index, bool value)
    {     annulBits[index] = value;   }

    virtual void setAnnulBits(const AnnulationBits& vectorBits)
    {     annulBits = vectorBits;     }

    virtual void updateAnnulBits(int index1, int index2);
    
    /**
   * Exception thrown when the an encoding mismatch exception occurs;
   */
    class CodingMismatchException : public std::exception
    {
    public:
      CodingMismatchException( );

      explicit
      CodingMismatchException( std::string reason ) throw () : reason( reason )
      { }

      virtual
      ~CodingMismatchException( ) throw ()
      { };

      virtual const char*
      what( ) const throw ()
      { return reason.c_str(); }

    private:
      std::string reason;
    };
    
  private:
    unsigned int address;
    
    std::deque<ILabel*> labels;
    std::string destinyLabel;
    rVex64PBIWInstruction* branchDestiny;
    
    rVex96PBIWPattern* pattern;
    Operation* codingOperation;

    /* The readRegs organization is as follows:
         
      ,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,
      ---------------------------------------------------------
      | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 |
      ---------------------------------------------------------
             \      /
              Br src
     */
    
    std::deque<Operand> readOperands; // Max 8
    bool hasBRSrc;

    /* The writeRegs/imm organization is as follows:
         
      ,__5b__,__5b__,__5b__,__3b__,
      -----------------------------
      | 0-31 | 0-31 | 0-31 | 0-7  |
      -----------------------------
             '----9b imm---'
             '-------12b imm------'
     */
    std::deque<Operand> writeOperands; // Max 4
    
    Operand immediate; // (9 or 12 bit immediates)
    Operand zeroOperand;
    
    /**
     * Keeps track of what syllables were packed in this instruction
     */
    typedef std::list<rVex::Base::Syllable*> SyllableList;
    SyllableList syllablesPacked;
    
    AnnulationBits annulBits;
  };
}

#endif	/* RVEX64PBIWINSTRUCTION_H */

