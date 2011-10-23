#include "RFI.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void 
      RFI::print(rVex::Printers::IPrinter& output, bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 6;
        final |= this->grDestiny;

        final <<= 12;
        final |= this->shortImmediate;

        final <<= 2;
        
        output.printSyllable(this, final, first, last);
      }
    }
  }
}


