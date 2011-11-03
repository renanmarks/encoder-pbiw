/* 
 * File:   IOperation.h
 * Author: helix
 *
 * Created on October 20, 2011, 4:49 PM
 */

#ifndef IOPERATION_H
#define	IOPERATION_H

#include <vector>
#include "IOperand.h"

namespace PBIW
{
  namespace Interfaces
  {
    class IOperation
    {
    public:
      virtual void setOpcode(unsigned short opcode) = 0;
    
      virtual unsigned short getOpcode() const = 0;

      virtual void addOperand(IOperand* operand) = 0;

      typedef std::vector<IOperand*> OperandVector;
      virtual OperandVector getOperands() const = 0;
      
      virtual bool operator==(const IOperation&) const = 0;
      virtual bool operator!=(const IOperation&) const = 0;
    };
  }
}

#endif	/* IOPERATION_H */

