#include <iostream>

#include "LDBU.h"
#include "src/rVex/Instruction.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      void LDBU::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Utils::OperandItemDTO;
        
        builder.insertRegister(this->grDestiny, OperandItemDTO::GRDestiny, this);
        builder.insertRegisters(readRegisters, OperandItemDTO::GRSource, this);
        builder.insertImmediate(this->shortImmediate, rVex::Syllable::ImmediateSwitch::SHORT_IMM, this);
      }
    }
  }
}
