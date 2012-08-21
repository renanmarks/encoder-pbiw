/* 
 * File:   IOperand.h
 * Author: helix
 *
 * Created on May 27, 2012, 3:56 PM
 */

#ifndef GENERICASSEMBLY_IOPERAND_H
#define	GENERICASSEMBLY_IOPERAND_H

#include "IOperation.h"

namespace GenericAssembly
{
  namespace Interfaces
  {
    class IOperand
    {
    public:
      virtual ~IOperand() { }
      
      virtual IOperand* clone() = 0;
      
      virtual void setTypeCode(int) = 0;
      virtual int getTypeCode() const = 0;

      virtual bool isImmediate() const = 0;
      virtual bool isRegister() const = 0;
      
      virtual void setValue(int) = 0;
      virtual int getValue() const = 0;
      
      virtual void setOperationBelonged(IOperation*) = 0;
      virtual IOperation* getOperationBelonged() const = 0;
      
      virtual bool operator==(const IOperand&) const = 0;
      virtual bool operator!=(const IOperand&) const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IOPERAND_H */

