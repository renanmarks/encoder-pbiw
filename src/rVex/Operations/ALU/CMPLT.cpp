#include <iostream>

#include "CMPLT.h"
#include "../../Instruction.h"
#include "src/rVex/Instruction.h"

namespace rVex
{
  namespace Operations
  {
    namespace ALU
    {
      void CMPLT::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        if (this->haveBRDestiny)
          builder.insertRegister(0, OperandItem::GRDestiny, this);
        else
          builder.insertRegister(this->grDestiny, OperandItem::GRDestiny, this);
        
        builder.insertRegisters(readRegisters, OperandItem::GRSource, this);
        
        if (getLayoutType() == LayoutType::ISTYPE)
          builder.insertImmediate(this->shortImmediate, Operand::Immediate::NineBits, this);
        
        if (this->haveBRDestiny)
          builder.insertRegister(this->brDestiny, OperandItem::BRDestiny, this);
      }
    }
  }
}
