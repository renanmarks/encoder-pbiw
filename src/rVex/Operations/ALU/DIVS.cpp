#include <iostream>

#include "DIVS.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      Syllable::OperandConstPtrDeque DIVS::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(this->brSource);
        builder.insertOperand(this->grDestiny);
        builder.insertOperands(readRegisters);
        builder.insertOperand(this->brDestiny);
        
        return builder.getOperandVector();
      }
    }
  }
}
