#include <vector>
#include "RETURN.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      GenericAssembly::Utils::OperandVector
      RETURN::exportOperandVector() const
      {
        Utils::OperandVectorBuilder builder;
        
//        builder.insertRegister(this->grDestiny, OperandItem::GRDestiny);
//        builder.insertRegister(this->readRegisters.at(0), OperandItem::GRSource);
        builder.insertOperand(this->readRegisters.at(1));
        builder.insertOperand(this->shortImmediate);
        
        return builder.getOperandVector();
      }
      
      void 
      RETURN::print(rVex::Printers::IPrinter& output, bool first, bool last) const // O(1)
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 6;
        final |= getGrDestinyValue();

        final <<= 12;
        final |= getShortImmediateValue();

        final <<= 5;

        final|=last;
        final<<=1;
        final|=first;

        output.printOperation(*this, std::vector<unsigned int>(1, final));
      }
    }
  }
}

