/* 
 * File:   Factory.cpp
 * Author: helix
 * 
 * Created on July 9, 2012, 9:43 PM
 */

#include "Factory.h"

#include "src/rVex/PBIWPartial/rVex64PBIWInstruction.h"
#include "src/rVex/PBIWPartial/rVex96PBIWPattern.h"
#include "src/rVex/PBIWPartial/Operation.h"
#include "src/rVex/PBIWPartial/Operand.h"
#include "src/rVex/PBIWPartial/Label.h"

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
}