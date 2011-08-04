/* 
 * File:   IVLIWOperation.h
 * Author: helix
 *
 * Created on July 23, 2011, 4:30 PM
 */

#ifndef IVLIWOPERATION_H
#define	IVLIWOPERATION_H

#include <vector>

namespace Base
{
  /**
   * Represents a operation within a VLIW instruction.
   */
  class IVLIWOperation 
  {
    public:
      virtual ~IVLIWOperation() {};

      virtual bool setOpcode(int) = 0;
      virtual int getOpcode() = 0;
      
      virtual bool setReadRegisters(const std::vector<int>&) = 0;
      virtual std::vector<int> getReadRegisters() = 0;
      
      virtual bool setWriteRegisters(const std::vector<int>&) = 0;
      virtual std::vector<int> getWriteRegisters() = 0;
  };
}

#endif	/* IVLIWOPERATION_H */

