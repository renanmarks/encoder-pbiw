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
 * Created on May 27, 2012, 3:56 PM
 */

#ifndef GENERICASSEMBLY_IOPERATION_H
#define	GENERICASSEMBLY_IOPERATION_H

#include <string>
#include <deque>

//#include "GenericAssembly/Utils/OperandVector.h"

namespace GenericAssembly
{
  namespace Utils
  {
    class OperandVector;
  }
  
  namespace Interfaces
  {
    class IInstruction;
    class IOperand;
    
    class IOperation
    {
    public:
      virtual ~IOperation() { }
      
      virtual void setBelongedInstruction(IInstruction* instruction) = 0;
      virtual IInstruction* getBelongedInstruction() const = 0;
      
      virtual unsigned int getAddress() const = 0;
      virtual void setAddress(unsigned int address) = 0;
      
      virtual void setLayoutType(int layoutType) = 0;
      
      virtual unsigned int getOpcode() const = 0;
      virtual bool isOpcode(unsigned int opcode) const = 0;
      
      virtual void setTextRepresentation(std::string textRepresentation) = 0;
      virtual std::string getTextRepresentation() const = 0;
      
      /**
       * Fills up the builder passed as argument with the operands from this
       * operation to be used at the PBIW encoding process.
       */
      virtual Utils::OperandVector exportOperandVector() const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_IOPERATION_H */

