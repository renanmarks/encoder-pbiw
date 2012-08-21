#include <iostream>

#include "SLCTF.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      Syllable::OperandConstPtrDeque SLCTF::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(brSource);
        builder.insertOperand(grDestiny);
        builder.insertOperands(readRegisters);

        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertOperand(shortImmediate);
        
        return builder.getOperandVector();
      }
    }
  }
}
