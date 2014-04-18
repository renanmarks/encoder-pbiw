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
 * Created on October 19, 2011, 2:03 PM
 */

#ifndef IOPERAND_H
#define	IOPERAND_H

namespace PBIW
{
  namespace Interfaces
  {

    /**
     * Class that represents an operand in a PBIW instruction
     */
    class IOperand
    {
    public:
      virtual ~IOperand() {}
      
      virtual IOperand* clone() const = 0;
      
      virtual void setIndex(unsigned int) = 0;
      virtual unsigned int getIndex() const = 0;
      
      virtual bool isImmediate() const = 0;
      
      virtual void setTypeCode(int) = 0;
      virtual int getTypeCode() const = 0;
      
      virtual void setValue(int) = 0;
      virtual int getValue() const = 0;
      
      virtual bool operator<(const IOperand&) const = 0;
      virtual bool operator>(const IOperand&) const = 0;
      virtual bool operator<=(const IOperand&) const = 0;
      virtual bool operator>=(const IOperand&) const = 0;
    
      virtual bool operator==(const IOperand&) const = 0;
      virtual bool operator!=(const IOperand&) const = 0;
    };
  }
}

#endif	/* IOPERAND_H */

