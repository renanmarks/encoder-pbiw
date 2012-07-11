/* 
 * File:   OperandVectorBuilder.cpp
 * Author: helix
 * 
 * Created on December 18, 2011, 5:33 PM
 */

#include "OperandVectorBuilder.h"
#include "src/rVex/Instruction.h"


namespace rVex
{
  namespace Utils
  {

    OperandVectorBuilder::OperandVectorBuilder(const PBIW::Interfaces::IPBIWFactory& factory)
    : factory(factory)
    {

    }

    void
    OperandVectorBuilder::insertRegister(int value, OperandItemDTO::Type type, const GenericAssembly::Interfaces::IOperation* operation) // O(1)
    {
      IOperand* operand=factory.createOperand();

      operand->setValue(value);
      operand->setBRSource(type == OperandItemDTO::BRSource);
      operand->setBRDestiny(type == OperandItemDTO::BRDestiny);

      OperandItemDTO* item=new OperandItemDTO(operand, type, operation);

      items.push_back(item);
    }

    void
    OperandVectorBuilder::insertImmediate(int value, rVex::Syllable::ImmediateSwitch::Type immType, const GenericAssembly::Interfaces::IOperation* operation) // O(1)
    {
      IOperand* operand=factory.createOperand();

      if (immType == rVex::Syllable::ImmediateSwitch::SHORT_IMM)
        operand->isImmediate9Bits(true);
      else if (immType == rVex::Syllable::ImmediateSwitch::BRANCH_IMM)
        operand->isImmediate12Bits(true);

      operand->setValue(value);
      OperandItemDTO* item=new OperandItemDTO(operand, OperandItemDTO::Imm, operation);

      items.push_back(item);
    }

    void
    OperandVectorBuilder::insertRegisters(const std::vector<unsigned int>& values, OperandItemDTO::Type type, const GenericAssembly::Interfaces::IOperation* operation) // O(1)
    {
      std::vector<unsigned int>::const_iterator it;

      for (it=values.begin(); it < values.end(); it++) // O(1)
        insertRegister(*it, type, operation);
    }

    const OperandVectorDTO&
    OperandVectorBuilder::getOperandVector()
    {
      return items;
    }
  }
}