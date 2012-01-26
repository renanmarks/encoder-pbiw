/* 
 * File:   PBIWInstruction.cpp
 * Author: helix
 * 
 * Created on July 21, 2011, 3:18 PM
 */

#include <deque>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include "rVex64PBIWInstruction.h"
#include "Interfaces/IOperand.h"

namespace PBIW
{
  using namespace Interfaces;

  rVex64PBIWInstruction::~rVex64PBIWInstruction()
  {

  }

  rVex64PBIWInstruction::OperandVector
  rVex64PBIWInstruction::getOperands() const // O(1)
  {
    std::deque<Operand> temp(readOperands.begin(), readOperands.end()); // O(|readOperands|) = O(8) = O(1)

    temp.resize(8, Operand(-1)); // O(8) = O(1)

    if (writeOperands.size() > 0)
      temp.push_back(writeOperands[0]);
    else
      temp.push_back(Operand(-1));
    
    if (immediate.isImmediate())
    {
      temp.push_back(Operand(-1));

      if (immediate.isImmediate9Bits())
      {
        temp.push_back(immediate);

        if (writeOperands.size() > 1)
          temp.push_back(writeOperands[1]);
      } else
      {
        temp.push_back(Operand(-1));
        temp.push_back(immediate);
      }
    } else
    {
      if (writeOperands.size() > 1)
        temp.insert(temp.end(), writeOperands.begin() + 1, writeOperands.end());
    }

    if (temp.size() < 12)
      temp.resize(12, Operand(-1));

    rVex64PBIWInstruction::OperandVector returnVector(temp.begin(), temp.end());

    return returnVector;
  }

  void
  rVex64PBIWInstruction::print(IPBIWPrinter& printer) const
  {

  }

  void
  rVex64PBIWInstruction::setLabel(const ILabel& label) // O(1)
  {
    const Label& temp = dynamic_cast<const Label&> (label);

    this->label= &const_cast<Label&> (temp);
  }

  void
  rVex64PBIWInstruction::setBranchDestiny(const IPBIWInstruction& branchDestiny)
  {
    const rVex64PBIWInstruction& temp = dynamic_cast<const rVex64PBIWInstruction&> (branchDestiny);

    this->branchDestiny = &const_cast<rVex64PBIWInstruction&> (temp);
  }

  bool
  rVex64PBIWInstruction::hasControlOperationWithLabelDestiny()
  {
    using rVex::Syllable;
    SyllableList::const_iterator it;

    for (it=syllablesPacked.begin();
         it != syllablesPacked.end();
         it++)
    {
      if ((*it)->getOpcode() == Syllable::opBR ||
          (*it)->getOpcode() == Syllable::opBRF ||
          (*it)->getOpcode() == Syllable::opCALL ||
          (*it)->getOpcode() == Syllable::opGOTO ||
          (*it)->getOpcode() == Syllable::opRETURN)
      {
        if ((*it)->getBranchDestiny() != NULL)
        {
          destinyLabel = (*it)->getLabelDestiny();
          break;
        }
      }
    }

    if (!destinyLabel.empty())
    {
      if (!pattern->hasControlOperation())
      {
        //this->branchDestiny = NULL;
        throw new CodingMismatchException("Mismatch: pattern does not have a control syllable referenced by PBIW instruction.");
      }

      return true;
    }

    return false;
  }

  void
  rVex64PBIWInstruction::pointToPattern(const IPBIWPattern& pattern) // O(1)
  {
    const rVex96PBIWPattern& temp=dynamic_cast<const rVex96PBIWPattern&> (pattern);

    this->pattern= &temp;
  }

  const IOperand&
  rVex64PBIWInstruction::containsOperand(const IOperand& operand) const // O(1)
  {
    //    bool foundInReadOperands = std::find(readOperands.begin(), readOperands.end(), operand);
    //    bool foundInWriteOperands = std::find(writeOperands.begin(), writeOperands.end(), operand);
    //    return (foundInReadOperands || foundInWriteOperands);

    OperandVector::const_iterator it;

    for (it=readOperands.begin(); // O(|readOperands|) = O(8) = O(1)
         it < readOperands.end();
         it++)
    {
      if (*it == operand)
        return *it;
    }

    for (it=writeOperands.begin(); //O(|writeOperands|) = O(4) = O(1)
         it < writeOperands.end();
         it++)
    {
      if (*it == operand)
        return *it;
    }

    return operand;
  }

  void
  rVex64PBIWInstruction::addReadOperand(IOperand& operand) // O(1)
  {
    unsigned int index=this->readOperands.size();
    operand.setIndex(index);
    this->readOperands.push_back(dynamic_cast<Operand&> (operand));
  }

  void
  rVex64PBIWInstruction::addWriteOperand(IOperand& operand) // O(1)
  {
    if (operand.isImmediate())
    {
      if (operand.isImmediate9Bits())
        operand.setIndex(10);
      else if (operand.isImmediate12Bits())
        operand.setIndex(11);

      immediate=dynamic_cast<Operand&> (operand);

      return;
    }

    // If we not have the immediate yet, do the normal indexing
    unsigned int index; // = 8 + this->writeOperands.size();

    if (immediate.isImmediate())
    {
      // If we have immediate, do the absolute indexing
      if (immediate.isImmediate9Bits())
      {
        switch (writeOperands.size()) {
          case 0:
            index=8; // before the 9 and 10 positions occupied by the imm
            break;
          case 1:
            index=11; // after the 9 and 10 positions occupied by the imm
            break;
          default: // more than 2
            index=666; // error!
            break;
        }
      } else if (immediate.isImmediate12Bits())
      {
        switch (writeOperands.size()) {
          case 0:
            index=8; // before the 9, 10 and 11 positions occupied by the imm
            break;
          default: // more than 1
            index=666; // error!
            break;
        }
      }
    } else
    {
      index=8 + this->writeOperands.size();
    }

    operand.setIndex(index);
    this->writeOperands.push_back(dynamic_cast<Operand&> (operand));
  }

  bool
  rVex64PBIWInstruction::hasOperandSlot(const Utils::OperandItem& operand) // O(1)
  {
    switch (operand.getType()) {
      case Utils::OperandItem::BRDestiny:
      case Utils::OperandItem::GRDestiny:
        return this->hasWriteOperandSlot();
        break;

      case Utils::OperandItem::Imm:
        if (this->containsImmediate())
          return false;

        if (operand.getOperand()->isImmediate9Bits() && writeOperands.size() == 2)
        {
          writeOperands.back().setIndex(11);
          return false;
        }

        if (operand.getOperand()->isImmediate9Bits() && writeOperands.size() > 2)
          return false;

        if (operand.getOperand()->isImmediate12Bits() && writeOperands.size() > 1)
          return false;
        break;

      case Utils::OperandItem::BRSource:
      case Utils::OperandItem::GRSource:
        return this->hasReadOperandSlot();
        break;
    }

    return true;
    //    return hasReadOperandSlot() || hasWriteOperandSlot();
  }

  bool
  rVex64PBIWInstruction::hasReadOperandSlot() const // O(1)
  {
    return readOperands.size() < 8;
  }

  bool
  rVex64PBIWInstruction::hasWriteOperandSlot() const // O(1)
  {
    bool hasWriteSlots=
      (immediate.isImmediate12Bits() && (writeOperands.size() < 1)) ||
      (immediate.isImmediate9Bits() && (writeOperands.size() < 2)) ||
      (!immediate.isImmediate12Bits() && !immediate.isImmediate9Bits() && writeOperands.size() < 4);

    return hasWriteSlots;
  }
}
