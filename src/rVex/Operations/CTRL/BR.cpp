#include "BR.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      
      GenericAssembly::Utils::OperandVector
      BR::exportOperandVector() const  // O(1)
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(brSource);
        builder.insertOperand(shortImmediate);
        
        return builder.getOperandVector();
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
        final |= getBrSourceValue();

        final <<= 1;
        final |= first;
        final <<= 1;
        final |= last;
        
        output.printOperation(*this, std::vector<unsigned int>(1,final));
      }
    }
  }
}
