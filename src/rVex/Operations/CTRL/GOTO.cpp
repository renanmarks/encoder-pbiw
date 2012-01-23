#include "../../Instruction.h"
#include "GOTO.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void
      GOTO::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        if (this->labelDestiny != NULL)
          builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits);
        else
          builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
      }
      
      void 
      GOTO::print(rVex::Printers::IPrinter& output, bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 18;
        final |= (this->labelDestiny->getBelongedInstruction()->getAddress() & 0x00000FFF);

        final <<= 5;
        
        output.printSyllable(this, final, first, last);
      }
    }
  }
}

