#include <iostream>

#include "CMPNE.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      GenericAssembly::Utils::OperandVector CMPNE::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
        if (this->haveBRDestiny)
          builder.insertOperand(Operand(Operand::GRDestiny));
        else
          builder.insertOperand(grDestiny);
        
        builder.insertOperands(readRegisters);
        
        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertOperand(this->shortImmediate);
        
        if (this->haveBRDestiny)
          builder.insertOperand(this->brDestiny);
        
        return builder.getOperandVector();
      }
    }
  }
}
