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
 * File:   ILabel.h
 * Author: helix
 *
 * Created on May 27, 2012, 4:00 PM
 */

#ifndef GENERICASSEMBLY_ILABEL_H
#define	GENERICASSEMBLY_ILABEL_H

#include "IOperation.h"
#include "IOperand.h"
#include "GenericAssembly/Utils/LabelScope.h"

namespace GenericAssembly
{
  namespace Interfaces
  {
    /**
     * A label in the assembly 
     */
    class ILabel
    {
    public:
      virtual ~ILabel() { }

      virtual void setAbsoluteAddress(unsigned int) = 0;
      virtual unsigned int getAbsoluteAddress() const = 0;
      
      virtual void setDestiny(IOperation* destiny) = 0;
      virtual IOperation* getDestiny() const = 0;
      
      virtual void setScope(Utils::LabelScope::Type scope) = 0;
      virtual Utils::LabelScope::Type getScope() const = 0;
      
      virtual void setName(const std::string& name) = 0;
      virtual std::string getName() const = 0;
    };
  }
}

#endif	/* GENERICASSEMBLY_ILABEL_H */

