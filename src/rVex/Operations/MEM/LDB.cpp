#include <iostream>

#include "LDB.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      GenericAssembly::Utils::OperandVector
      LDB::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        builder.insertOperand(grDestiny);
        builder.insertOperands(readRegisters);
        builder.insertOperand(shortImmediate);
        
        return builder.getOperandVector();
      }
    }
  }
}
