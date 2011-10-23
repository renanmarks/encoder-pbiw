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

namespace PBIW
{
  using namespace Interfaces;

  /**
   * r-VEX 64 bits length instruction 
   */
  class rVex64PBIWInstruction : public IPBIWInstruction
  {
  public:
    rVex64PBIWInstruction();
    rVex64PBIWInstruction(const rVex64PBIWInstruction& orig);
    virtual ~rVex64PBIWInstruction();
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
    std::vector<IOperand*> readRegs; // Max 8

    /* The writeRegs/imm organization is as follows:
         
      ,__5b__,__5b__,__5b__,__3b__,
      -----------------------------
      | 0-31 | 0-31 | 0-31 | 0-7  |
      -----------------------------
             '----9b imm---'
             '-------12b imm------'
     */
    unsigned short immediate; // For the 9 and 12 bit immediates
    std::vector<IOperand*> writeRegs; // Max 4 regs
  };
}

#endif	/* RVEX64PBIWINSTRUCTION_H */

