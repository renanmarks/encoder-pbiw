#include "src/rVex/Instruction.h"
#include "BRF.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void
      BRF::exportOperandVector(Utils::OperandVectorBuilder& builder) const // O(1)
      {
        using PBIW::Utils::OperandItemDTO;
        
        builder.insertRegister(this->brSource, OperandItemDTO::BRSource, this); // O(1)
        builder.insertImmediate(this->shortImmediate, rVex::Syllable::ImmediateSwitch::BRANCH_IMM, this); // O(1)
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

        final<<=1;
        final|=last;
        final<<=1;
        final|=first;

        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}
