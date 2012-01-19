
#include <string>
#include "SyllableMISC.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  void
  SyllableMISC::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
  {
    output.printSyllable(this, printRTYPE(), first, last);
  }
}
