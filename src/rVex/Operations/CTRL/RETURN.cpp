#include "RETURN.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      std::string
      RETURN::print(bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::BRANCH_IMM;
        
        final <<= 6;
        final |= this->grDestiny;

        final <<= 12;
        final |= this->shortImmediate;

        final <<= 2;

        return this->printBinary(final, first, last); 
      }
    }
  }
}

