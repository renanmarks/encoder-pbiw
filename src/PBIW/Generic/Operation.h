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
 * File:   Operation.h
 * Author: helix
 *
 * Created on July 23, 2012, 4:12 PM
 */

#ifndef PBIW_GENERIC_OPERATION_H
#define	PBIW_GENERIC_OPERATION_H

#include "PBIW/Interfaces/IOperation.h"

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

