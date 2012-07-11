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
      void MTB::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Utils::OperandItemDTO;
        
        builder.insertRegister(0, OperandItemDTO::GRDestiny, this);
        builder.insertRegister(readRegisters[0], OperandItemDTO::GRSource, this);
        builder.insertRegister(0, OperandItemDTO::GRSource, this);
        builder.insertRegister(this->brDestiny, OperandItemDTO::BRDestiny, this);
      }
    }
  }
}
