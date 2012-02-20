#include <iostream>

#include "CMPGE.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      void CMPGE::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        if (this->haveBRDestiny)
          builder.insertRegister(0, OperandItem::GRDestiny);
        else
          builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
        
        builder.insertRegisters(readRegisters, OperandItem::GRSource);
        
        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertImmediate(this->shortImmediate, Operand::Immediate::NineBits);
        
        if (this->haveBRDestiny)
          builder.insertRegister(this->brDestiny, OperandItem::BRDestiny);
      }
    }
  }
}
