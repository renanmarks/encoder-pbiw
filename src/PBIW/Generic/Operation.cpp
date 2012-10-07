/* 
 * File:   Operation.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 4:12 PM
 */

#include "Operation.h"

namespace PBIW
{
  namespace Generic
  {

    Operation::Operation()
    {
    }

    Operation::Operation(const Operation& orig)
    {
    }

    Operation::~Operation()
    {
    }

    IOperation*
    Operation::clone() const
    {
    }

    void
    Operation::setOpcode(unsigned short opcode)
    {
    }

    unsigned short
    Operation::getOpcode() const
    {
    }

    void
    Operation::setOriginalOpcode(unsigned short opcode)
    {
    }

    unsigned short
    Operation::getOriginalOpcode() const
    {
    }

    void
    Operation::setBrReadOperand(short opcode)
    {
    }

    short
    Operation::getBrReadOperand() const
    {
    }

    void
    Operation::setImmediateSwitch(int)
    {
    }

    int
    Operation::getImmediateSwitch() const
    {
    }

    void
    Operation::addOperand(const IOperand&)
    {
    }

    Operation::OperandIndexVector
    Operation::getOperandsIndexes() const
    {
    }

    void
    Operation::updateIndexes(int oldIndex, int newIndex)
    {
    }

    void
    Operation::setType(int)
    {
    }

    int
    Operation::getType() const
    {
    }

    bool Operation::operator==(const IOperation&) const
    {
    }

    bool Operation::operator!=(const IOperation&) const
    {
    }

  }
}