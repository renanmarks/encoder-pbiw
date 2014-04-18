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
 * File:   Factory.cpp
 * Author: helix
 * 
 * Created on July 9, 2012, 9:43 PM
 */

#include "Factory.h"

#include "rVex/PBIWPartial/rVex64PBIWInstruction.h"
#include "rVex/PBIWPartial/rVex96PBIWPattern.h"
#include "rVex/PBIWPartial/Operation.h"
#include "rVex/PBIWPartial/Operand.h"
#include "rVex/PBIWPartial/Label.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;

  IPBIWInstruction*
  Factory::createInstruction() const
  {
    return new rVex64PBIWInstruction();
  }

  IPBIWPattern*
  Factory::createPattern() const
  {
    return new rVex96PBIWPattern();
  }

  IOperation*
  Factory::createOperation() const
  {
    return new Operation();
  }

  IOperand*
  Factory::createOperand() const
  {
    return new Operand();
  }

  ILabel*
  Factory::createLabel() const
  {
    return new Label();
  }
  
  IOperation*
  Factory::createOperation(const GenericAssembly::Interfaces::IOperation& operation) const
  {
    const rVex::Syllable& syllable = dynamic_cast<const rVex::Syllable&>(operation);
    Operation* finalOperation = static_cast<Operation*>(createOperation());
    
    finalOperation->setOpcode( syllable.getOpcode() );
    finalOperation->setImmediateSwitch( syllable.getImmediateSwitch() );
    finalOperation->setType( syllable.getSyllableType() );
    
    return finalOperation;
  }

  IOperand*
  Factory::createOperand(const GenericAssembly::Interfaces::IOperand& operand) const
  {
    IOperand* operandPBIW = createOperand();
    
    operandPBIW->setValue(operand.getValue());
    operandPBIW->setTypeCode(operand.getTypeCode());
    
    return operandPBIW;
  }

  ILabel*
  Factory::createLabel(const GenericAssembly::Interfaces::ILabel& label) const
  {
  }
}