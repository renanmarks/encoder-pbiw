/* 
 * File:   Operand.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 5:02 PM
 */

#include "Operand.h"

namespace PBIW
{
  namespace Generic
  {

    Operand::Operand()
    {
    }

    Operand::Operand(const Operand& orig)
    {
    }

    Operand::~Operand()
    {
    }

    IOperand*
    Operand::clone() const
    {
    }

    void
    Operand::setIndex(unsigned int)
    {
    }

    unsigned int
    Operand::getIndex() const
    {
    }

    bool
    Operand::isImmediate() const
    {
    }

    bool
    Operand::isImmediate9Bits() const
    {
    }

    void
    Operand::isImmediate9Bits(bool)
    {
    }

    bool
    Operand::isImmediate12Bits() const
    {
    }

    void
    Operand::isImmediate12Bits(bool)
    {
    }

    void
    Operand::setValue(int)
    {
    }

    int
    Operand::getValue() const
    {
    }

    bool
    Operand::isBRSource() const
    {
    }

    void
    Operand::setBRSource(const bool)
    {
    }

    bool
    Operand::isBRDestiny() const
    {
    }

    void
    Operand::setBRDestiny(const bool)
    {
    }

    bool Operand::operator<(const IOperand&) const
    {
    }

    bool Operand::operator>(const IOperand&) const
    {
    }

    bool Operand::operator<=(const IOperand&) const
    {
    }

    bool Operand::operator>=(const IOperand&) const
    {
    }

    bool Operand::operator==(const IOperand&) const
    {
    }

    bool Operand::operator!=(const IOperand&) const
    {
    }
  }
}
