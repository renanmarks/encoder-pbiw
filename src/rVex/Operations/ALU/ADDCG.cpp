#include <iostream>

#include "ADDCG.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      void ADDCG::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Utils::OperandItemDTO;
        
        builder.insertRegister(this->brSource, OperandItemDTO::BRSource, this);
        builder.insertRegister(this->grDestiny, OperandItemDTO::GRDestiny, this);
        builder.insertRegisters(readRegisters, OperandItemDTO::GRSource, this);
        builder.insertRegister(this->brDestiny, OperandItemDTO::BRDestiny, this);
      }
    }
  }
}
