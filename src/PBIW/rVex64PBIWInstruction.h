/* 
 * File:   PBIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 3:18 PM
 */

#ifndef RVEX64PBIWINSTRUCTION_H
#define	RVEX64PBIWINSTRUCTION_H

#include <vector>
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
    rVex64PBIWInstruction() //: readOperands(0, Operand(0)), writeOperands()
    {
      Operand operand(0);
      operand.setIndex(0);
      readOperands.push_back(operand);
    }
    
    virtual ~rVex64PBIWInstruction() { }
    
    virtual void pointToPattern(const IPBIWPattern& pattern);
    
    virtual const rVex96PBIWPattern* getPattern() const
    { return this->pattern; }
    
    virtual bool containsImmediate() const
    { return immediate.isImmediate9Bits() || immediate.isImmediate12Bits(); }
     
    virtual const IOperand& containsOperand(const IOperand&) const;
    
    virtual void addReadOperand(IOperand& operand);
    virtual void addWriteOperand(IOperand& operand);
    
    virtual bool hasOperandSlot(const rVex::Syllable::OperandItem&);
    virtual bool hasReadOperandSlot() const;
    virtual bool hasWriteOperandSlot() const;
    
    virtual int readOperandQuantity() const
    { return readOperands.size(); }
    virtual int writeOperandQuantity() const
    { return writeOperands.size(); }
    
    virtual void print(IPBIWPrinter&) const;
    
    virtual OperandVector getOperands() const;
    
  private:

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
    std::vector<rVex::Syllable*> syllablesPacked;
  };
}

#endif	/* RVEX64PBIWINSTRUCTION_H */

