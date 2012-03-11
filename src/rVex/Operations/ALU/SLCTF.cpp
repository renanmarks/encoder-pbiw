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
        
        builder.insertRegister(this->brSource, OperandItem::BRSource);
        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
        builder.insertRegisters(readRegisters, OperandItem::GRSource);

        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertImmediate(this->shortImmediate, Operand::Immediate::NineBits);
      }
    }
  }
}
