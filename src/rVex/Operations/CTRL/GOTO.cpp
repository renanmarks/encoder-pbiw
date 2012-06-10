#include <vector>
#include "src/rVex/Instruction.h"
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
        
        if (this->branchDestiny != NULL)
          builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits, this);
        else
          builder.insertRegisters(this->readRegisters, OperandItem::GRSource, this);
      }
      
      void 
      GOTO::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 18;
        final |= (this->branchDestiny->getBelongedInstruction()->getAddress() & 0x00000FFF);

        final <<= 4;
        
        final |= last;
        final <<= 1;
        final |= first;
        
        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}

