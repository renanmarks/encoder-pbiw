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
 * File:   IPBIWFactory.h
 * Author: helix
 *
 * Created on July 9, 2012, 5:53 PM
 */

#ifndef IPBIWFACTORY_H
#define	IPBIWFACTORY_H

namespace GenericAssembly
{
  namespace Interfaces
  {
    class IInstruction;
    class IOperation;
    class IOperand;
    class ILabel;
  }
}

namespace PBIW
{
  namespace Interfaces
  {
    class IPBIWInstruction;
    class IPBIWPattern;
    class IOperation;
    class IOperand;
    class ILabel;
    
    /**
     * PBIW Factory to build the minimum parts used in the algorithm.
     */
    class IPBIWFactory
    {
    public:
      virtual ~IPBIWFactory() { }
      
      virtual IPBIWInstruction* createInstruction() const = 0;
      virtual IPBIWPattern* createPattern() const = 0;
      virtual IOperation* createOperation() const = 0;
      virtual IOperand* createOperand() const = 0;
      virtual ILabel* createLabel() const = 0;
      
      virtual IOperation* createOperation(const GenericAssembly::Interfaces::IOperation&) const = 0;
      virtual IOperand* createOperand(const GenericAssembly::Interfaces::IOperand&) const = 0;
      virtual ILabel* createLabel(const GenericAssembly::Interfaces::ILabel&) const = 0;
    };
  }
}

#endif	/* IPBIWFACTORY_H */

