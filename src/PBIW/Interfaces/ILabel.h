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
 * File:   Label.h
 * Author: helix
 *
 * Created on October 5, 2011, 2:25 PM
 */

#ifndef PBIWILABEL_H
#define	PBIWILABEL_H

#include <string>
#include "GenericAssembly/Utils/LabelScope.h"

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIWInstruction;
    
    /**
     * Structure used to save the label definition information.
     */
    class ILabel
    {
    public:
      virtual ~ILabel() { }
      
      virtual ILabel* clone() const = 0;
      
      virtual void setAbsoluteAddress(unsigned int absoluteAddress) = 0;
      virtual unsigned int getAbsoluteAddress() const = 0;

      virtual void setDestiny(IPBIWInstruction* destiny) = 0;
      virtual IPBIWInstruction* getDestiny() const = 0;

      virtual void setScope(GenericAssembly::Utils::LabelScope::Type scope) = 0;
      virtual GenericAssembly::Utils::LabelScope::Type getScope() const = 0;

      virtual void setName(const std::string& name) = 0;
      virtual std::string getName() const = 0;
    };
  }
}

#endif	/* PBIWILABEL_H */

