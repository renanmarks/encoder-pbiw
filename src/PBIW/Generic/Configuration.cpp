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
