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
      BR::exportOperandVector(Utils::OperandVectorBuilder& builder) const  // O(1)
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->brSource, OperandItem::BRSource, this);
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits, this);
      }
      
      void 
      BR::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 18;
        final |= (this->branchDestiny->getBelongedInstruction()->getAddress() & 0x00000FFF);

        final <<= 3;
        final |= this->brSource;

        final <<= 1;
        final |= first;
        final <<= 1;
        final |= last;
        
        output.printOperation(*this, std::vector<unsigned int>(1,final));
      }
    }
  }
}
