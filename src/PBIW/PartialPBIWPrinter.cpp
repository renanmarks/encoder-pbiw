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
    
    printer << "Pattern Addr: " << pattern.getAddress() << std::endl;
    
    for (unsigned int i = 0; i < operationCount; i++)
    {
      printer << "Opcode: " << pattern[i]->getOpcode() << " - ";
      
      IOperation::OperandIndexVector::const_iterator it;
      IOperation::OperandIndexVector operands = pattern[i]->getOperandsIndexes();
      
      printer << "Operands indexes (" << operands.size() << " total): ";
      
      for (it = operands.begin();
           it < operands.end();
           it++)
      {
        printer << *it << ", ";
      }
      
      printer << std::endl;
    }
  }

  void
  PartialPBIWPrinter::printInstruction(const IPBIWInstruction& instruction)
  {
    IPBIWInstruction::OperandVector operands = instruction.getOperands();
    IPBIWInstruction::OperandVector::const_iterator it;
    
    std::list<rVex::Syllable*>::const_iterator sIt;
    std::list<rVex::Syllable*> references = instruction.getSyllableReferences();
    
    printer << "Instruction Addr: " << instruction.getAddress() << std::endl;
    
    printer << "References : " << std::endl;
    
    for (sIt = references.begin();
         sIt != references.end();
         sIt++)
    {
      printer << (*sIt)->getOpcode() << "(" << (*sIt) << ")" << std::endl;
    }
    
    printer << "Read : ";
    
    for (it = operands.begin();
         it < operands.end()-4; //&& it->getIndex() < 8;
         it++)
    {
      printer << "[" << it->getIndex() <<  "] = "<< it->getValue();
      
      if ( it->isImmediate() )
        printer << "(Imm)";
      
      printer << ", ";
    }
    
    printer << std::endl;
    
    printer << "Write: ";
    
    for (it = operands.begin() + 8;
         it < operands.end() ;
         it++)
    {
//      if (it->getIndex() >= 8)
      {
        printer << "[" << it->getIndex() <<  "] = "<< it->getValue();

        if ( it->isImmediate() )
          printer << "(Imm)";

        printer << ", ";
      }
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
