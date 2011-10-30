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
    virtual ~rVex64PBIWInstruction() { }
    
    virtual void pointToPattern(IPBIWPattern* pattern);
    
    virtual bool containsOperand(const IOperand&) const;
    
    virtual void addReadOperand(IOperand* operand);
    
    virtual void addWriteOperand(IOperand* operand);
    
    virtual bool hasOperandSlot() const;
    virtual bool hasReadOperandSlot() const;
    virtual bool hasWriteOperandSlot() const;
    
  private:

    rVex96PBIWPattern* pattern;

    /* The readRegs organization is as follows:
         
      ,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,__5b__,
      ---------------------------------------------------------
      | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 | 0-31 |
      ---------------------------------------------------------
                                                       \      /
                                                        Br src
     */
    
    typedef std::vector<IOperand*> OperandVector;
    OperandVector readOperands; // Max 8

    /* The writeRegs/imm organization is as follows:
         
      ,__5b__,__5b__,__5b__,__3b__,
      -----------------------------
      | 0-31 | 0-31 | 0-31 | 0-7  |
      -----------------------------
             '----9b imm---'
             '-------12b imm------'
     */
    
    bool has9BitImm;
    bool has12BitImm;
    OperandVector writeOperands; // Max 4 (9 and 12 bit immediates inclusive)
    
    /**
     * Keeps track of what syllables were packed in this instruction
     */
    std::vector<rVex::Syllable*> syllablesPacked;
  };
}

#endif	/* RVEX64PBIWINSTRUCTION_H */

