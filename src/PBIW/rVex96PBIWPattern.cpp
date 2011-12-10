/* 
 * File:   PBIWPattern.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */

#include <typeinfo>
#include <iostream>
#include "rVex96PBIWPattern.h"

namespace PBIW
{
  using namespace Interfaces;
  
  rVex96PBIWPattern::rVex96PBIWPattern()
  {
  }

  rVex96PBIWPattern::rVex96PBIWPattern(const rVex96PBIWPattern& orig)
  {
  }

  rVex96PBIWPattern::~rVex96PBIWPattern()
  {
  }

  void
  rVex96PBIWPattern::addOperation(IOperation* operation)
  {
    Operation* temp = dynamic_cast<Operation*> (operation);

    this->operations.push_back(temp);
  }

  void
  rVex96PBIWPattern::print(IPBIWPrinter& printer) const
  {
    printer.printPattern(*this);
  }

  bool
  rVex96PBIWPattern::operator<(const IPBIWPattern& other) const
  {
    return operations.size() < other.getOperationCount();
  }

  bool
  rVex96PBIWPattern::operator>(const IPBIWPattern& other) const
  {
    return operations.size() > other.getOperationCount();
  }

  bool
  rVex96PBIWPattern::operator<=(const IPBIWPattern& other) const
  {
    return (*this < other) || (*this == other);
  }

  bool
  rVex96PBIWPattern::operator>=(const IPBIWPattern& other) const
  {
    return (*this > other) || (*this == other);
  }

  bool
  rVex96PBIWPattern::operator==(const IPBIWPattern& other) const
  {
    const rVex96PBIWPattern& otherTemp = dynamic_cast<const rVex96PBIWPattern&>(other);

    unsigned int count = otherTemp.getOperationCount();

    if (operations.size() != count)
      return false;

    for (unsigned int i = 0; i < count; i++)
    {
      const IOperation& thisOperation = *(operations[i]);
      const IOperation& otherOperation = *(otherTemp.getOperation(i));
      
      if ( thisOperation != otherOperation )
        return false;
    }

    return true;
  }

  bool
  rVex96PBIWPattern::operator!=(const IPBIWPattern& other) const
  {
    return !(*this == other);
  }

}