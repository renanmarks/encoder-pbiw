#include <vector>
#include "SyllableMEM.h"

namespace rVex
{
  std::string 
  SyllableMEM::print(bool first, bool last) const
  {
    switch (layoutType)
    {
      case Syllable::MEMTYPE:
        return this->printMEMLOADTYPE(first, last);
      default:
        throw new LayoutNotSupportedException("This instruction only supports R or IS layouts.");
    }
    
    return std::string("Error printing syllable");
  }
}
