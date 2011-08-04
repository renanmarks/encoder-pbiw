/* 
 * File:   IVLIWInstruction.h
 * Author: helix
 *
 * Created on July 21, 2011, 4:34 PM
 */

#ifndef IVLIWINSTRUCTION_H
#define	IVLIWINSTRUCTION_H

#include "IVLIWOperation.h"

namespace Base
{
  /**
   * Represents an VLIW Instruction.
   * A VLIW instruction contains a defined number of operations (represented by
   * the IVLIWOperation).
   */
  class IVLIWInstruction 
  {
    public:
      virtual ~IVLIWInstruction() {};
      
      virtual bool addOperation(const IVLIWOperation&) = 0;
      virtual bool removeOperation(const IVLIWOperation&) = 0;
      
      virtual std::vector<IVLIWOperation> getOperations() const = 0;
  };
}

#endif	/* IVLIWINSTRUCTION_H */

