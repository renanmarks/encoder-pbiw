#include <iostream>

#include "STW.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace MEM
    {
      void STW::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->grDestiny, OperandItem::GRSource, this);
        builder.insertRegisters(readRegisters, OperandItem::GRSource, this);
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::NineBits, this);
      }
    }
  }
}
