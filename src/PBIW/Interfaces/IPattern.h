/* 
 * File:   IPattern.h
 * Author: helix
 *
 * Created on October 20, 2011, 4:49 PM
 */

#ifndef IPATTERN_H
#define	IPATTERN_H

#include <vector>
#include "IOperand.h"

namespace PBIW
{
  namespace Interfaces
  {
    class IPattern
    {
    public:
      typedef std::vector<IOperand*> OperandVector;
      
      virtual void setOpcode(unsigned short opcode) = 0;
    
      virtual unsigned short getOpcode() const = 0;

      virtual void addReadOperand(IOperand* operand) = 0;

      virtual OperandVector getOperands() const = 0;

      virtual void pointToWriteOperand(IOperand* operand) = 0;

      virtual void pointToWriteBrOperand(IOperand* operand) = 0;
    };
  }
}

#endif	/* IPATTERN_H */

