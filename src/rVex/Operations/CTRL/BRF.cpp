#include "../../Instruction.h"
#include "BRF.h"

namespace rVex
{
  namespace Operations
  {
    namespace CTRL
    {
      Syllable::OperandVector
      BRF::getOperandVector() const
      {
        using PBIW::Operand;

        Syllable::OperandVector returnVector;
        ReadRegVector::const_iterator it;

        returnVector.push_back( std::make_pair( new Operand(this->brSource), OperandType::GRDestiny ) );
        returnVector.push_back( std::make_pair( new Operand(this->shortImmediate, Operand::Immediate::TwelveBits), OperandType::Imm ) );

        return returnVector;
      }
      
      void 
      BRF::print(rVex::Printers::IPrinter& output, bool first, bool last) const
      {
        unsigned int final = 0;

        final |= this->getOpcode();
        
        final <<= 2;
        final |= Syllable::ImmediateSwitch::BRANCH_IMM;
        
        final <<= 18;
        final |= (this->labelDestiny->getBelongedInstruction()->getAddress() & 0x00000FFF);

        final <<= 3;
        final |= this->brSource;

        final <<= 2;

        output.printSyllable(this, final, first, last);
      }
    }
  }
}
