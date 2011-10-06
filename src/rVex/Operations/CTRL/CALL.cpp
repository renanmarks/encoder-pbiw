#include "CALL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void
      CALL::print(rVex::Printers::IPrinter& output, bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::BRANCH_IMM;
        
        final <<= 6;
        final |= this->grDestiny;

        final <<= 17;

        output.printSyllable(final, first, last);
      }
    }
  }
}


