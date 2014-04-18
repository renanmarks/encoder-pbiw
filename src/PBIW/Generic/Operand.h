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
 * File:   Operand.h
 * Author: helix
 *
 * Created on July 23, 2012, 5:02 PM
 */

#ifndef PBIW_GENERIC_OPERAND_H
#define	PBIW_GENERIC_OPERAND_H

#include "PBIW/Interfaces/IOperand.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    class Operand : public IOperand
    {
    public:
      Operand();
      Operand(const Operand& orig);
      virtual ~Operand();
      
      virtual IOperand* clone() const;
      
      virtual void setIndex(unsigned int);
      virtual unsigned int getIndex() const;
      
      virtual bool isImmediate() const;
      
      virtual bool isImmediate9Bits() const;
      virtual void isImmediate9Bits(bool);
      
      virtual bool isImmediate12Bits() const;
      virtual void isImmediate12Bits(bool);
      
      virtual void setValue(int);
      virtual int getValue() const;
      
      virtual bool isBRSource() const;
      virtual void setBRSource(const bool);
      
      virtual bool isBRDestiny() const;
      virtual void setBRDestiny(const bool);

      virtual bool operator<(const IOperand&) const;
      virtual bool operator>(const IOperand&) const;
      virtual bool operator<=(const IOperand&) const;
      virtual bool operator>=(const IOperand&) const;
    
      virtual bool operator==(const IOperand&) const;
      virtual bool operator!=(const IOperand&) const;
    private:

    };
  }
}

#endif	/* OPERAND_H */

