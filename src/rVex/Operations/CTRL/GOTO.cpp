#include "GOTO.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void 
      GOTO::print(rVex::Printers::IPrinter& output, bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::BRANCH_IMM;
        
        final <<= 18;
        final |= this->shortImmediate;

        final <<= 5;
        
        output.printSyllable(this, final, first, last);
      }
    }
  }
}

