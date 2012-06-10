#include <vector>
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
        builder.insertRegister(this->readRegisters.at(1), OperandItem::GRSource, this);
        builder.insertImmediate(this->shortImmediate, Operand::Immediate::TwelveBits, this);
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

        final|=last;
        final<<=1;
        final|=first;

        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}

