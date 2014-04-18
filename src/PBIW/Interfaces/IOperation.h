/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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
#include "rVex/Syllable.h"

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

