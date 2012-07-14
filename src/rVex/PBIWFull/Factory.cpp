/* 
 * File:   Factory.cpp
 * Author: helix
 * 
 * Created on July 9, 2012, 9:43 PM
 */

#include "Factory.h"

#include "src/rVex/PBIWFull/rVex64PBIWInstruction.h"
#include "src/rVex/PBIWFull/rVex96PBIWPattern.h"
#include "src/rVex/PBIWFull/Operation.h"
#include "src/rVex/PBIWFull/Operand.h"
#include "src/rVex/PBIWFull/Label.h"

namespace PBIWFull
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
}