#include "../../Instruction.h"
#include "BRF.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void 
      BRF::print(rVex::Printers::IPrinter& output, bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 18;
        final |= (this->labelDestiny->getBelongedInstruction()->getAddress() & 0x00000FFF);

        final <<= 3;
        final |= this->brSource;

        final <<= 2;

        output.printSyllable(this, final, first, last);
      }
    }
  }
}
