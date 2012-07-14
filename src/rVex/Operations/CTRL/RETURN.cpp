#include <vector>
#include "RETURN.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      void
      RETURN::exportOperandVector(Utils::OperandVectorBuilder& builder) const
      {
        using PBIW::Utils::OperandItemDTO;
        
//        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
//        builder.insertRegister(this->readRegisters.at(0), OperandItem::GRSource);
        builder.insertRegister(this->readRegisters.at(1), OperandItemDTO::GRSource, this);
        builder.insertImmediate(this->shortImmediate, rVex::Syllable::ImmediateSwitch::BRANCH_IMM, this);
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

