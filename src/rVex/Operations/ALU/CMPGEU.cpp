#include <iostream>

#include "CMPGEU.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      GenericAssembly::Utils::OperandVector CMPGEU::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        if (this->haveBRDestiny)
          builder.insertOperand(Operand(Operand::GRDestiny));
        else
          builder.insertOperand(grDestiny);
        
        builder.insertOperands(readRegisters);
        
        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertOperand(shortImmediate);
        
        if (this->haveBRDestiny)
          builder.insertOperand(brDestiny);
        
        return builder.getOperandVector();
      }
    }
  }
}
