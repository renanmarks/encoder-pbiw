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
#include "src/rVex/Syllable.h"

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIWInstruction;
    
    class IOperation
    {
    public:
      virtual ~IOperation() {}
      
      /**
       * Deep copy this operation.
       */
      virtual IOperation* clone() const = 0;
      
      virtual void setOpcode(unsigned short opcode) = 0;
      virtual unsigned short getOpcode() const = 0;
      
      virtual void setOriginalOpcode(unsigned short opcode) = 0;
      virtual unsigned short getOriginalOpcode() const = 0;
      
      virtual void setBrReadOperand(short opcode) = 0;
      virtual short getBrReadOperand() const = 0;
      
      virtual void setImmediateSwitch(int) = 0;
      virtual int getImmediateSwitch() const = 0;

      virtual void addOperand(const IOperand&) = 0;

      typedef std::vector<int> OperandIndexVector;
      virtual OperandIndexVector getOperandsIndexes() const = 0;
      
      virtual void updateIndexes(int oldIndex, int newIndex) = 0;
      
      virtual void setType(int) = 0;
      virtual int getType() const = 0;
      
      virtual bool operator<(const IOperation&) const = 0;
      virtual bool operator>(const IOperation&) const = 0;
      virtual bool operator<=(const IOperation&) const = 0;
      virtual bool operator>=(const IOperation&) const = 0;
      
      virtual bool operator==(const IOperation&) const = 0;
      virtual bool operator!=(const IOperation&) const = 0;        
      
    };
  }
}

#endif	/* IOPERATION_H */

