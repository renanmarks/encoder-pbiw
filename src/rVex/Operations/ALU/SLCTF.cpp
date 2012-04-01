#include <iostream>

#include "SLCTF.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      void SLCTF::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->brSource, OperandItem::BRSource, this);
        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny, this);
        builder.insertRegisters(readRegisters, OperandItem::GRSource, this);

        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertImmediate(this->shortImmediate, Operand::Immediate::NineBits, this);
      }
    }
  }
}
