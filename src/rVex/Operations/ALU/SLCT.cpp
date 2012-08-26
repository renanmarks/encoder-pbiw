#include <iostream>

#include "SLCT.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      GenericAssembly::Utils::OperandVector SLCT::exportOperandVector() const
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
