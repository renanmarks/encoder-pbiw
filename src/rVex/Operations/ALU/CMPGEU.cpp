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
      void CMPGEU::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Utils::OperandItemDTO;
        
        if (this->haveBRDestiny)
          builder.insertRegister(0, OperandItemDTO::GRDestiny, this);
        else
          builder.insertRegister(this->grDestiny, OperandItemDTO::GRDestiny, this);
        
        builder.insertRegisters(readRegisters, OperandItemDTO::GRSource, this);
        
        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertImmediate(this->shortImmediate, rVex::Syllable::ImmediateSwitch::SHORT_IMM, this);
        
        if (this->haveBRDestiny)
          builder.insertRegister(this->brDestiny, OperandItemDTO::BRDestiny, this);
      }
    }
  }
}
