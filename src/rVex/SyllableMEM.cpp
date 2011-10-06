#include <vector>
#include "SyllableMEM.h"

namespace rVex
{
  void
  SyllableMEM::print(rVex::Printers::IPrinter& output, bool first, bool last) const
  {
    switch (layoutType)
    {
      case Syllable::MEMTYPE:
        output.printSyllable(printMEMLOADTYPE(), first, last);
      default:
        throw new LayoutNotSupportedException("This instruction only supports R or IS layouts.");
    }
  }
}
