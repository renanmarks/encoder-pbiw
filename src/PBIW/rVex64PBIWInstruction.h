/* 
 * File:   PBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef RVEX64PBIWINSTRUCTION_H
#define	RVEX64PBIWINSTRUCTION_H

#include <vector>
#include "Label.h"
#include "Interfaces/IPBIWInstruction.h"
#include "Interfaces/IOperand.h"
#include "rVex96PBIWPattern.h"
#include "src/rVex/Syllable.h"

namespace PBIW
{
  using namespace Interfaces;

  /**
   * r-VEX 64 bits length instruction 
   */
  class rVex64PBIWInstruction : public IPBIWInstruction
  {
  public:
    rVex64PBIWInstruction() : address(0), label(NULL), branchDestiny(NULL), pattern(NULL), hasBRSrc(false)//readOperands(0, Operand(0)), writeOperands()
    {
      Operand operand(0);
      operand.setIndex(0);
      readOperands.push_back(operand); // Zero register
      readOperands.push_back(operand); // Space for (possible) future BRSRC
    }
    
    virtual ~rVex64PBIWInstruction();
    
    virtual void setAddress(unsigned int addr)
    { address = addr; }
        
    virtual unsigned int getAddress() const
    { return address; }
    
    virtual void setLabel(const ILabel&);
    virtual ILabel* getLabel() const
    { return label; }
    
    virtual void pointToPattern(const IPBIWPattern& pattern);
    
    virtual const rVex96PBIWPattern* getPattern() const
    { return this->pattern; }
    
    virtual bool containsImmediate() const
    { return immediate.isImmediate9Bits() || immediate.isImmediate12Bits(); }
     
    virtual const IOperand& containsOperand(const IOperand&) const;
    
    virtual void addReadOperand(IOperand& operand);
    
    virtual void setBranchSourceOperand(IOperand&);
    virtual bool hasBranchSourceOperand() const;
    
    virtual void addWriteOperand(IOperand& operand);
    
    virtual bool hasOperandSlot(const Utils::OperandItem&);
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
    
    virtual OperandVector getOperands() const;
    
    virtual void setSyllableReferences(const std::list<rVex::Syllable*>& list);
    
    virtual std::list<rVex::Syllable*> getSyllableReferences() const
    { return syllablesPacked; }

    virtual void setBranchDestiny(const IPBIWInstruction& branchDestiny);

    virtual rVex64PBIWInstruction* getBranchDestiny() const
    { return branchDestiny; }
    
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
    
    ILabel* label;
    std::string destinyLabel;
    rVex64PBIWInstruction* branchDestiny;
    
    const rVex96PBIWPattern* pattern;

    /* The readRegs organization is as follows:
         
      ,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,
      ---------------------------------------------------------
      | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 |
      ---------------------------------------------------------
             \      /
              Br src
     */
    OperandVector readOperands; // Max 8
    bool hasBRSrc;

    /* The writeRegs/imm organization is as follows:
         
      ,__5b__,__5b__,__5b__,__3b__,
      -----------------------------
      | 0-31 | 0-31 | 0-31 | 0-7  |
      -----------------------------
             '----9b imm---'
             '-------12b imm------'
     */
    OperandVector writeOperands; // Max 4
    
    Operand immediate; // (9 or 12 bit immediates)
    
    /**
     * Keeps track of what syllables were packed in this instruction
     */
    typedef std::list<rVex::Syllable*> SyllableList;
    SyllableList syllablesPacked;
  };
}

#endif	/* RVEX64PBIWINSTRUCTION_H */

