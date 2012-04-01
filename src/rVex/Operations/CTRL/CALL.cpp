#include "CALL.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void
      CALL::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
        builder.insertRegister(this->grDestiny, OperandItem::GRSource, this);
        
        if (readRegisters.size() == 0)
          builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits, this);
        else
          builder.insertRegister(this->readRegisters[0], OperandItem::GRSource, this);
      }
      
      void
      CALL::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 6;
        final |= this->grDestiny;

        final <<= 15;

        output.printSyllable(this, final, first, last);
      }
    }
  }
}


