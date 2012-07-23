/* 
 * File:   Instruction.cpp
 * Author: helix
 * 
 * Created on July 23, 2012, 3:22 PM
 */

#include "Instruction.h"

namespace PBIW
{
  namespace Generic
  {
    Instruction::Instruction()
    {
    }

    Instruction::Instruction(const Instruction& orig)
    {
    }

    Instruction::~Instruction()
    {
    }

    IPBIWInstruction*
    Instruction::clone() const
    {
    }

    void
    Instruction::setAddress(unsigned int)
    {
    }

    unsigned int
    Instruction::getAddress() const
    {
    }

    void
    Instruction::setLabel(const ILabel*)
    {
    }

    ILabel*
    Instruction::getLabel() const
    {
    }

    void
    Instruction::pointToPattern(IPBIWPattern&)
    {
    }

    void
    Instruction::setCodingOperation(IOperation& operation)
    {
    }

    IOperation*
    Instruction::getCodingOperation() const
    {
    }

    const IPBIWPattern*
    Instruction::getPattern() const
    {
    }

    const IOperand&
    Instruction::containsOperand(const IOperand&) const
    {
    }

    void
    Instruction::addReadOperand(IOperand&)
    {
    }

    void
    Instruction::addBranchOperand(IOperand&)
    {
    }

    void
    Instruction::setBranchSourceOperand(IOperand&)
    {
    }

    bool
    Instruction::hasBranchSourceOperand() const
    {
    }

    void
    Instruction::addWriteOperand(IOperand&)
    {
    }

    bool
    Instruction::hasOperandSlot(const PBIW::Utils::OperandItemDTO&)
    {
    }

    bool
    Instruction::hasReadOperandSlot() const
    {
    }

    bool
    Instruction::hasWriteOperandSlot() const
    {
    }

    bool
    Instruction::hasControlOperationWithLabelDestiny()
    {
    }

    std::string
    Instruction::getLabelDestiny() const
    {
    }

    void
    Instruction::setLabelDestiny(std::string)
    {
    }

    void
    Instruction::setBranchDestiny(const IPBIWInstruction& branchDestiny)
    {
    }

    IPBIWInstruction*
    Instruction::getBranchDestiny() const
    {
    }

    void
    Instruction::setImmediateValue(int)
    {
    }

    int
    Instruction::readOperandQuantity() const
    {
    }

    int
    Instruction::writeOperandQuantity() const
    {
    }

    void
    Instruction::print(IPBIWPrinter&) const
    {
    }

    PBIW::Utils::OperandVector
    Instruction::getOperands() const
    {
    }

    bool
    Instruction::containsImmediate() const
    {
    }

    void
    Instruction::setOperationReferences(const std::list<GenericAssembly::Interfaces::IOperation*>&)
    {
    }

    std::list<GenericAssembly::Interfaces::IOperation*>
    Instruction::getOperationReferences() const
    {
    }

    const Instruction::AnnulationBits&
    Instruction::getAnnulBits() const
    {
    }

    void
    Instruction::setAnnulBit(int, bool)
    {
    }

    void
    Instruction::setAnnulBits(const AnnulationBits& vectorBits)
    {
    }

    void
    Instruction::updateAnnulBits(int index1, int index2)
    {
    }

  }
}