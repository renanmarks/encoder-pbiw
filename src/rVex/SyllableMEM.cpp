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
        output.printSyllable(this, printMEMLOADTYPE(), first, last);
        break;
      default:
        throw new LayoutNotSupportedException("This instruction only supports R or IS layouts.");
    }
  }
}
