#include "RETURN.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void 
      RETURN::print(rVex::Printers::IPrinter& output, bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::BRANCH_IMM;
        
        final <<= 6;
        final |= this->grDestiny;

        final <<= 12;
        final |= this->shortImmediate;

        final <<= 5;

        output.printSyllable(this, final, first, last);
      }
    }
  }
}
