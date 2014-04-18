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
 * Created on July 23, 2012, 5:22 PM
 */

#ifndef PBIW_GENERIC_LABEL_H
#define	PBIW_GENERIC_LABEL_H

#include "PBIW/Interfaces/ILabel.h"

namespace PBIW
{
  using namespace Interfaces;
  
  namespace Generic
  {
    class Label : public ILabel
    {
    public:
      Label();
      Label(const Label& orig);
      virtual ~Label();
      
      virtual ILabel* clone() const;
      
      virtual void setAbsoluteAddress(unsigned int absoluteAddress);
      virtual unsigned int getAbsoluteAddress() const;

      virtual void setDestiny(IPBIWInstruction* destiny);
      virtual IPBIWInstruction* getDestiny() const;

      virtual void setScope(GenericAssembly::Utils::LabelScope::Type scope);
      virtual GenericAssembly::Utils::LabelScope::Type getScope() const;

      virtual void setName(const std::string& name);
      virtual std::string getName() const;
    private:

    };
  }
}

#endif	/* LABEL_H */

