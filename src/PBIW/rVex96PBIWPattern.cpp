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
    try
    {
      rVex96PBIWPattern& otherTemp = static_cast<rVex96PBIWPattern&>(const_cast<IPBIWPattern&>(other));
      unsigned int count = otherTemp.getOperationCount();
      
      if (operations.size() != count)
        return false;
      
      for (unsigned int i = 0; i < count; i++)
      {
        if ( *(operations[i]) != *(otherTemp.getOperation(i)) )
          return false;
      }

      return true;
    }
    catch (std::bad_cast ex)
    {
      return false;
    }
  }

  bool
  rVex96PBIWPattern::operator!=(const IPBIWPattern& other) const
  {
    return !(*this == other);
  }

}