/* 
 * File:   Operation.h
 * Author: helix
 *
 * Created on July 23, 2012, 4:12 PM
 */

#ifndef PBIW_GENERIC_OPERATION_H
#define	PBIW_GENERIC_OPERATION_H

#include "src/PBIW/Interfaces/IOperation.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {

    class Operation : public IOperation
    {
    public:
      Operation();
      Operation(const Operation& orig);
      virtual ~Operation();
      
      IOperation* clone() const;
      
      void setOpcode(unsigned short opcode);
      unsigned short getOpcode() const;
      
      void setOriginalOpcode(unsigned short opcode);
      unsigned short getOriginalOpcode() const;
      
      void setBrReadOperand(short opcode);
      short getBrReadOperand() const;
      
      void setImmediateSwitch(int);
      int getImmediateSwitch() const;

      void addOperand(const IOperand&);

      OperandIndexVector getOperandsIndexes() const;
      
      void updateIndexes(int oldIndex, int newIndex);
      
      void setType(int);
      int getType() const;
      
      bool operator==(const IOperation&) const;
      bool operator!=(const IOperation&) const;        
    private:

    };

  }
}

#endif	/* OPERATION_H */

