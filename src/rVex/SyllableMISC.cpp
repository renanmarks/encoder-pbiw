
#include <string>
#include "SyllableMISC.h"
#include "src/rVex/Printers/IPrinter.h"

namespace rVex
{
  void
  SyllableMISC::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
  {
    output.printOperation(*this, std::vector<unsigned int>(1, printRTYPE(first, last)));
  }
}
