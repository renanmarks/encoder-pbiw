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
      
      virtual IOperand* clone() const = 0;
      
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

