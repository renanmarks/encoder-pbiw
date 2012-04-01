#include <iostream>

#include "MTB.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      void MTB::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(0, OperandItem::GRDestiny, this);
        builder.insertRegister(this->brDestiny, OperandItem::BRDestiny, this);
        builder.insertRegisters(readRegisters, OperandItem::GRSource, this);
      }
    }
  }
}
