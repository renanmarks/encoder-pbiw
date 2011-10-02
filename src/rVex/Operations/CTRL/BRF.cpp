#include "BRF.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      std::string
      BRF::print(bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::BRANCH_IMM;
        
        final <<= 18;
        final |= this->shortImmediate;

        final <<= 12;
        final |= this->brSource;

        final <<= 2;

        return this->printBinary(final, first, last); 
      }
    }
  }
}
