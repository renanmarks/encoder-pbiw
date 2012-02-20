#include <iostream>

#include "DIVS.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      void DIVS::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
        builder.insertRegister(this->brDestiny, OperandItem::BRDestiny);
        builder.insertRegisters(readRegisters, OperandItem::GRSource);
      }
    }
  }
}
