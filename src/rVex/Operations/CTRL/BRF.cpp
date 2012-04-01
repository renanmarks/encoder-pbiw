#include "../../Instruction.h"
#include "BRF.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void
      BRF::exportOperandVector(Utils::OperandVectorBuilder& builder) const // O(1)
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->brSource, OperandItem::BRSource, this); // O(1)
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits, this); // O(1)
      }
      
      void 
      BRF::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      { 
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 18;
        final |= (this->branchDestiny->getBelongedInstruction()->getAddress() & 0x00000FFF);

        final <<= 3;
        final |= this->brSource;

        final <<= 2;

        output.printSyllable(this, final, first, last);
      }
    }
  }
}
