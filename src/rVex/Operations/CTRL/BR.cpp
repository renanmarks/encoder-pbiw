#include "BR.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      
      void
      BR::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->brSource, OperandItem::GRSource);
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits);
      }
      
      void 
      BR::print(rVex::Printers::IPrinter& output, bool first, bool last) const
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
