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
 * File:   Factory.cpp
 * Author: helix
 * 
 * Created on July 22, 2012, 7:06 PM
 */

#include "Factory.h"
namespace PBIW
{
  namespace Generic
  {

    Factory::Factory(const Configuration& config)
    : configuration(config)
    {
    }

    Factory::Factory(const Factory& orig)
    : configuration(orig.configuration)
    {
    }

    Factory::~Factory()
    {
    }

    IPBIWInstruction*
    Factory::createInstruction() const
    {
    }

    IPBIWPattern*
    Factory::createPattern() const
    {
    }

    IOperation*
    Factory::createOperation() const
    {
    }

    IOperand*
    Factory::createOperand() const
    {
    }

    ILabel*
    Factory::createLabel() const
    {
    }

    IOperation*
    Factory::createOperation(const GenericAssembly::Interfaces::IOperation& operation) const
    {
    }

    IOperand*
    Factory::createOperand(const GenericAssembly::Interfaces::IOperand& operand) const
    {
    }

    ILabel*
    Factory::createLabel(const GenericAssembly::Interfaces::ILabel& label) const
    {
    }
  }
}
