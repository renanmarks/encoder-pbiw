#include <iostream>

#include "STH.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      void STH::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Utils::OperandItemDTO;
        
        builder.insertRegister(this->grDestiny, OperandItemDTO::GRSource, this);
        builder.insertRegisters(readRegisters, OperandItemDTO::GRSource, this);
        builder.insertImmediate(this->shortImmediate, rVex::Syllable::ImmediateSwitch::SHORT_IMM, this);
      }
    }
  }
}
