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
  PartialPBIWPrinter::printPattern(const IPBIWPattern& pattern) // O(|operationCount|)
  {
    unsigned int operationCount = pattern.getOperationCount(); // O(1)
    
    for (unsigned int i = 0; i < operationCount; i++) // O(|operationCount|)
    {
      printer << "Opcode: " << pattern[i]->getOpcode() << " - ";
      
      IOperation::OperandIndexVector::const_iterator it;
      IOperation::OperandIndexVector operands = pattern[i]->getOperandsIndexes(); // O(1)
      
      printer << "Operands indexes (" << operands.size() << " total): ";
      
      for (it = operands.begin(); // O(|operands|) = O(4) = O(1)
           it < operands.end();
           it++)
      {
        printer << *it << ", ";
      }
      
      printer << std::endl;
    }
  }

  void
  PartialPBIWPrinter::printInstruction(const IPBIWInstruction& instruction)  // O(1)
  {
    IPBIWInstruction::OperandVector operands = instruction.getOperands(); // O(1)
    IPBIWInstruction::OperandVector::const_iterator it;
    
    std::list<rVex::Syllable*>::const_iterator sIt;
    std::list<rVex::Syllable*> references = instruction.getSyllableReferences(); // O(1)
    
    for (sIt = references.begin(); // O(|references|) = O(12) = O(1)
         sIt != references.end();
         sIt++)
    {
      printer << (*sIt)->getOpcode() << "(" << (*sIt) << ")" << std::endl;
    }
    
    printer << "Read : ";
    
    for (it = operands.begin(); // O(|operands|) = O(8) = O(1)
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
    
    for (it = operands.begin() + 8; // O(|operands|) = O(4) = O(1)
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
  PartialPBIWPrinter::printHeader()  // O(1)
  {
    printer << "--- Start of PBIW Debug Printing --- " << std::endl;
  }

  void
  PartialPBIWPrinter::printFooter() // O(1)
  {
    printer << "--- End of PBIW Debug Printing --- " << std::endl;
  }

  std::ostream&
  PartialPBIWPrinter::getOutputStream() // O(1)
  {
    return printer;
  }
}
