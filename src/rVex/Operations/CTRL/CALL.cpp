#include "CALL.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      Syllable::OperandConstPtrDeque
      CALL::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(this->grDestiny);
        
        if (readRegisters.size() == 0)
          builder.insertOperand(this->shortImmediate);
        else
          builder.insertOperand(this->readRegisters[0]);
        
        return builder.getOperandVector();
      }
      
      void
      CALL::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 6;
        final |= getGrDestinyValue();

        final <<= 14;
        final |= last;
        final <<= 1;
        final |= first;

        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}


