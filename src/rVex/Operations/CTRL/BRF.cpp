#include "src/rVex/Instruction.h"
#include "BRF.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      Syllable::OperandConstPtrDeque
      BRF::exportOperandVector() const // O(1)
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(brSource); // O(1)
        builder.insertOperand(shortImmediate); // O(1)
        
        return builder.getOperandVector();
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
        final |= getBrSourceValue();

        final<<=1;
        final|=last;
        final<<=1;
        final|=first;

        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}
