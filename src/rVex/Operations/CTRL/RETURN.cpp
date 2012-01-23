#include "RETURN.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void
      RETURN::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Operand;
        using PBIW::Utils::OperandItem;
        
//        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
//        builder.insertRegister(this->readRegisters.at(0), OperandItem::GRSource);
        builder.insertRegister(this->readRegisters.at(1), OperandItem::GRSource);
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits);
      }
      
      void 
      RETURN::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 6;
        final |= this->grDestiny;

        final <<= 12;
        final |= this->shortImmediate;

        final <<= 5;

        output.printSyllable(this, final, first, last);
      }
    }
  }
}

