/* 
 * File:   PBIWPattern.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */

#include "rVex96PBIWPattern.h"

namespace PBIW
{

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
  rVex96PBIWPattern::addPattern(IPattern& operation)
  {
    UnitaryPattern& temp = dynamic_cast<UnitaryPattern&>(operation);
    
    this->patterns.push_back( UnitaryPattern(temp) );
  }
  
  UnitaryPattern&
  rVex96PBIWPattern::getPattern(unsigned int index)
  {
    return this->patterns[index];
  }

  bool
  rVex96PBIWPattern::operator<(const IPBIWPattern& other) const
  {
    return true;
  }

  bool
  rVex96PBIWPattern::operator>(const IPBIWPattern& other) const
  {
    return true;
  }

  bool
  rVex96PBIWPattern::operator<=(const IPBIWPattern& other) const
  {
    return true;
  }

  bool
  rVex96PBIWPattern::operator>=(const IPBIWPattern& other) const
  {
    return true;
  }

  bool
  rVex96PBIWPattern::operator==(const IPBIWPattern& other) const
  {
    return true;
  }

  bool
  rVex96PBIWPattern::operator!=(const IPBIWPattern& other) const
  {
    return true;
  }

}