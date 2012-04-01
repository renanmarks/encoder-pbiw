#include <iostream>

#include "ADDCG.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      void ADDCG::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->brSource, OperandItem::BRSource, this);
        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny, this);
        builder.insertRegister(this->brDestiny, OperandItem::BRDestiny, this);
        builder.insertRegisters(readRegisters, OperandItem::GRSource, this);
      }
    }
  }
}
