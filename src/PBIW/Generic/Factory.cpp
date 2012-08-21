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
