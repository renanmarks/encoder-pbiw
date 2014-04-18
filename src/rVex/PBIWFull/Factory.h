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
 * File:   Factory.h
 * Author: helix
 *
 * Created on July 9, 2012, 9:43 PM
 */

#ifndef PBIWFULL_FACTORY_H
#define	PBIWFULL_FACTORY_H

#include "PBIW/Interfaces/IPBIWFactory.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;
  
  class Factory : public IPBIWFactory
  {
  public:
    virtual ~Factory() { }
    
    IPBIWInstruction* createInstruction() const;
    IPBIWPattern* createPattern() const;
    IOperation* createOperation() const;
    IOperand* createOperand() const;
    ILabel* createLabel() const;
    
    IOperation* createOperation(const GenericAssembly::Interfaces::IOperation&) const;
    IOperand* createOperand(const GenericAssembly::Interfaces::IOperand&) const;
    ILabel* createLabel(const GenericAssembly::Interfaces::ILabel&) const;
  };
}

#endif	/* FACTORY_H */

