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
 * File:   Configuration.cpp
 * Author: helix
 * 
 * Created on July 22, 2012, 7:18 PM
 */

#include "Configuration.h"

namespace PBIW
{
  namespace Generic
  {
    Configuration::Configuration()
    {
    }

    Configuration::Configuration(const Configuration& orig)
    {
    }

    Configuration::~Configuration()
    {
    }

    void
    Configuration::setWriteFieldCount(unsigned int writeFieldCount)
    {
      this->writeFieldCount=writeFieldCount;
    }

    unsigned int
    Configuration::getWriteFieldCount() const
    {
      return writeFieldCount;
    }

    void
    Configuration::setReadFieldCount(unsigned int readFieldCount)
    {
      this->readFieldCount=readFieldCount;
    }

    unsigned int
    Configuration::getReadFieldCount() const
    {
      return readFieldCount;
    }

    void
    Configuration::setInstructionFormatType(InstructionFormat::Type instructionFormatType)
    {
      this->instructionFormatType=instructionFormatType;
    }

    Configuration::InstructionFormat::Type
    Configuration::getInstructionFormatType() const
    {
      return instructionFormatType;
    }

    void
    Configuration::setOperationCount(unsigned int operationCount)
    {
      this->operationCount=operationCount;
    }

    unsigned int
    Configuration::getOperationCount() const
    {
      return operationCount;
    }

    void
    Configuration::setCancellationType(CancellationBits::Type cancellationType)
    {
      this->cancellationType=cancellationType;
    }

    Configuration::CancellationBits::Type
    Configuration::getCancellationType() const
    {
      return cancellationType;
    }
  }
}
