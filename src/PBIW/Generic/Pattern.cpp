/* 
 * File:   Pattern.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 3:22 PM
 */

#include "Pattern.h"

namespace PBIW
{
  namespace Generic
  {

    Pattern::Pattern()
    {
    }

    Pattern::Pattern(const Pattern& orig)
    {
    }

    Pattern::~Pattern()
    {
    }

    IPBIWPattern*
    Pattern::clone() const
    {
    }

    void
    Pattern::setAddress(unsigned int)
    {
    }

    unsigned int
    Pattern::getAddress() const
    {
    }

    void
    Pattern::addOperation(IOperation*)
    {
    }

    IPBIWPattern::OperationVector
    Pattern::getOperations() const
    {
    }

    IOperation*
    Pattern::getOperation(unsigned int) const
    {
    }

    void
    Pattern::setOperation(IOperation&, int)
    {
    }

    IOperation* Pattern::operator[](const unsigned int) const
    {
    }

    bool
    Pattern::hasControlOperation() const
    {
    }

    unsigned int
    Pattern::getOperationCount() const
    {
    }

    void
    Pattern::updateIndexes(int oldIndex, int newIndex)
    {
    }

    void
    Pattern::referencedByInstruction(IPBIWInstruction*)
    {
    }

    std::deque<IPBIWInstruction*>
    Pattern::getInstructionsThatUseIt()
    {
    }

    void
    Pattern::reorganize()
    {
    }

    void
    Pattern::reorganize(bool)
    {
    }

    int
    Pattern::getUsageCounter() const
    {
    }

    void
    Pattern::resetUsageCounter()
    {
    }

    void
    Pattern::print(IPBIWPrinter&) const
    {
    }

    bool Pattern::operator<(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator>(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator<=(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator>=(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator==(const IPBIWPattern&) const
    {
    }

    bool Pattern::operator!=(const IPBIWPattern&) const
    {
    }
  }
}