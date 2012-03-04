#include <iostream>

#include "LDW.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      void LDW::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
        builder.insertRegisters(readRegisters, OperandItem::GRSource);
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::NineBits);
      }
    }
  }
}
