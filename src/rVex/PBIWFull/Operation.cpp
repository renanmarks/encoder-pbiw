/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/* 
 * File:   Operation.cpp
 * Author: helix
 * 
 * Created on October 20, 2011, 3:38 PM
 */

#include <cstddef>
#include <iostream>
#include "Operation.h"
#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "rVex/Base/Syllable.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;

  void
  Operation::setOpcode(unsigned short opcode)
  {
    unsigned short realOpcode=opcode & 0xFFF8;

    setOriginalOpcode(opcode);

    switch (realOpcode) // Get the 4 most significant bits from op
    {
      case rVex::Base::Syllable::opADDCG:
      case rVex::Base::Syllable::opDIVS:
      case rVex::Base::Syllable::opSLCT:
      case rVex::Base::Syllable::opSLCTF:
        this->opcode=realOpcode;
        break;

      default:
        this->opcode=opcode;
        break;
    }
  }

  Operation::OperandIndexVector
  Operation::getOperandsIndexes() const // O(1)
  {
    OperandIndexVector returnVector;
    returnVector.reserve(readOperands.size() + 2);

    returnVector.push_back(writeOperand);
    returnVector.insert(returnVector.end(), readOperands.begin(), readOperands.end());
    returnVector.push_back(writeBrOperand);
    returnVector.resize(4, -1);

    return returnVector;
  }

  void
  Operation::updateIndexes(int oldIndex, int newIndex)
  {
    if (this->writeOperand == oldIndex)
      this->writeOperand=newIndex;

    if (this->writeBrOperand == oldIndex)
      this->writeBrOperand=newIndex;

    if (this->readBrOperand == oldIndex)
      this->readBrOperand=newIndex;

    OperandIndexVector::iterator it;

    for (it=readOperands.begin();
         it < readOperands.end();
         it++)
    {
      if (*it == oldIndex)
        *it=newIndex;
    }
  }

  void
  Operation::addOperand(const IOperand& operand) // O(1)
  {
    switch (this->getOpcode()) {
      case rVex::Base::Syllable::opGOTO:
      case rVex::Base::Syllable::opIGOTO:
        if (writeOperand == -1)
        {
          writeOperand=0;

          if (operand.isImmediate())
            readOperands.push_back(0);
        }
        break;

      case rVex::Base::Syllable::opCALL:
        if (operand.isImmediate())
          readOperands.push_back(0);
        break;

      case rVex::Base::Syllable::opBR:
      case rVex::Base::Syllable::opBRF:
        if (writeOperand == -1)
          writeOperand=0;
        break;

      case rVex::Base::Syllable::opRETURN: // TODO
      case rVex::Base::Syllable::opRFI:
        break;

      case rVex::Base::Syllable::opADDCG:
      case rVex::Base::Syllable::opDIVS:
      case rVex::Base::Syllable::opSLCT:
      case rVex::Base::Syllable::opSLCTF:
        if (readBrOperand == -1)
        {
          this->readBrOperand=operand.getIndex();
          return;
        }
        break;
    }

    if (this->writeOperand == -1)
    {
      this->writeOperand=operand.getIndex();
      return;
    }

    if (this->readOperands.size() < 2)
    {
      this->readOperands.push_back(operand.getIndex());
      return;
    }

    if (this->writeBrOperand == -1)
    {
      this->writeBrOperand=operand.getIndex();
      return;
    }
  }

  bool Operation::operator<(const IOperation& other) const
  {
    
  }

  bool Operation::operator>(const IOperation& other) const
  {
    
  }

  bool Operation::operator<=(const IOperation& other) const
  {
    
  }

  bool Operation::operator>=(const IOperation& other) const
  {
    
  }

  bool Operation::operator==(const IOperation& other) const // O(1)
  {
    OperandIndexVector thisOperands=this->getOperandsIndexes();
    OperandIndexVector otherOperands=other.getOperandsIndexes();

    if (opcode != other.getOpcode())
      return false;

    switch (opcode) {
      case rVex::Base::Syllable::opADDCG:
      case rVex::Base::Syllable::opDIVS:
      case rVex::Base::Syllable::opSLCT:
      case rVex::Base::Syllable::opSLCTF:
        if ((this->readBrOperand > 0 && other.getBrReadOperand() > 0) &&
            (this->readBrOperand != other.getBrReadOperand()))
          return false;
    }

    if (immediateSwitch != static_cast<rVex::Base::Syllable::ImmediateSwitch::Type> (other.getImmediateSwitch()))
      return false;

    if (thisOperands.size() != otherOperands.size())
      return false;

    OperandIndexVector::const_iterator thisIt;
    OperandIndexVector::const_iterator otherIt;

    for (thisIt=thisOperands.begin(), otherIt=otherOperands.begin(); // O(|thisOperands|) =  O(4) = O(1)
         thisIt < thisOperands.end() && otherIt < otherOperands.end();
         thisIt++, otherIt++)
    {
      if (*thisIt != *otherIt)
        return false;
    }

    return true;
  }

  bool Operation::operator!=(const IOperation& other) const // O(1)
  {
    return !(*this == other);
  }
}
