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

#ifndef PBIWFULL_PBIWLABEL_H
#define	PBIWFULL_PBIWLABEL_H

#include <string>
#include "PBIW/Interfaces/ILabel.h"
#include "rVex/Label.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;
  
  /**
   * Structure used to save the label definition information.
   */
  class Label : public ILabel
  {
  public:
    Label()
      : name(""), 
        scope(GenericAssembly::Utils::LabelScope::GLOBAL), 
        destiny(NULL), 
        absoluteAddress(0)
    { }
    
    Label(const Label& other)
      : name(other.name), 
      scope(other.getScope()), 
      destiny(other.getDestiny()), 
      absoluteAddress(other.getAbsoluteAddress())
    { }
    
    Label(const rVex::Label& rVexLabel)
      : name(rVexLabel.getName()), 
      scope(rVexLabel.getScope()), 
      destiny(NULL), 
      absoluteAddress(0)
    { }
    
    virtual ~Label() 
    { }

    virtual ILabel* clone() const
    { return new Label(*this); }
    
    void
    setAbsoluteAddress(unsigned int absoluteAddress)
    { this->absoluteAddress=absoluteAddress; }

    unsigned int
    getAbsoluteAddress() const
    { return absoluteAddress; }

    void
    setDestiny(IPBIWInstruction* destiny)
    { this->destiny=destiny; }

    IPBIWInstruction*
    getDestiny() const
    { return destiny; }

    void
    setScope(GenericAssembly::Utils::LabelScope::Type scope)
    { this->scope=scope; }

    GenericAssembly::Utils::LabelScope::Type
    getScope() const
    { return scope; }

    void
    setName(const std::string& name)
    { this->name=name; }

    std::string
    getName() const
    { return name; }
    
  private:
    std::string name;
    GenericAssembly::Utils::LabelScope::Type scope;
    IPBIWInstruction* destiny;
    unsigned int absoluteAddress;
  };
}

#endif	/* PBIWLABEL_H */

