#include "RFI.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void 
      RFI::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 6;
        final |= getGrDestinyValue();

        final <<= 12;
        final |= getShortImmediateValue();

        final<<=1;
        final|=last;
        final<<=1;
        final|=first;

        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}


