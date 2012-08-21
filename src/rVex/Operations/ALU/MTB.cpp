#include <iostream>

#include "MTB.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      Syllable::OperandConstPtrDeque MTB::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(Operand(Operand::GRDestiny));
        builder.insertOperand(readRegisters[0]);
        builder.insertOperand(Operand(Operand::GRSource));
        builder.insertOperand(brDestiny);
        
        return builder.getOperandVector();
      }
    }
  }
}
