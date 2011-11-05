/* 
 * File:   PartialPBIWPrinter.cpp
 * Author: helix
 * 
 * Created on October 30, 2011, 4:28 PM
 */

#include "PartialPBIWPrinter.h"
#include "Interfaces/IPBIWPattern.h"
#include "Interfaces/IPBIWInstruction.h"

namespace PBIW
{
  using namespace Interfaces;
  
  void
  PartialPBIWPrinter::printPattern(const IPBIWPattern& pattern)
  {
    unsigned int operationCount = pattern.getOperationCount();
    
    for (unsigned int i = 0; i < operationCount; i++)
    {
      printer << "Opcode: " << pattern[i]->getOpcode() << " - ";
      
      IOperation::OperandVector::const_iterator it;
      IOperation::OperandVector operands = pattern[i]->getOperands();
      
      printer << "Operands pointers ( " << operands.size() << " total): ";
      
      for (it = operands.begin();
           it < operands.end();
           it++)
      {
        printer << (*it)->getValue() << ", ";
      }
      
      printer << std::endl;
    }
  }

  void
  PartialPBIWPrinter::printInstruction(const IPBIWInstruction& instruction)
  {
    IPBIWInstruction::OperandVector operands = instruction.getOperands();
    IPBIWInstruction::OperandVector::const_iterator it;
    
    printer << "Operands: ";
    
    for (it = operands.begin();
         it < operands.end();
         it++)
    {
      printer << (*it)->getValue() << "(Imm? ";
      
      if ( (*it)->isImmediate() )
        printer << "Yes";
      else
        printer << "No";
      
      printer << "), ";
    }
    
    printer << std::endl;
  }

  void
  PartialPBIWPrinter::printHeader()
  {
    printer << "--- Start of PBIW Debug Printing --- " << std::endl;
  }

  void
  PartialPBIWPrinter::printFooter()
  {
    printer << "--- End of PBIW Debug Printing --- " << std::endl;
  }

  std::ostream&
  PartialPBIWPrinter::getOutputStream()
  {
    return printer;
  }
}
