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
 * File:   PartialPBIWPrinter.cpp
 * Author: helix
 * 
 * Created on October 30, 2011, 4:28 PM
 */

#include "PartialPBIWDebugPrinter.h"
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "PBIW/Interfaces/IOperation.h"

namespace PBIWPartial
{
  using namespace PBIW::Interfaces;
  
  void
  PartialPBIWDebugPrinter::printPattern(const IPBIWPattern& pattern, const std::vector<unsigned int>& binary) // O(|operationCount|)
  {
    unsigned int operationCount = pattern.getOperationCount(); // O(1)
    
    printer << "\tPattern Addr: " << pattern.getAddress() << std::endl;
    printer << "\tReuse count: " << pattern.getUsageCounter() << std::endl;
    printer << "\tInstr. use it: ";
    
    typedef std::deque<IPBIWInstruction*> AddrInstruction;
    AddrInstruction addrInstruction = const_cast<IPBIWPattern&>(pattern).getInstructionsThatUseIt();
    AddrInstruction::iterator it;
    
    for(it = addrInstruction.begin(); it < addrInstruction.end(); it++)
    {
        if(it != addrInstruction.begin())
            printer  << ", ";
        
        printer << (*it)->getAddress();        
    }
    
    printer << std::endl;
    
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
  PartialPBIWDebugPrinter::printInstruction(const IPBIWInstruction& instruction, const std::vector<unsigned int>& binary)  // O(1)
  {
    PBIW::Utils::OperandVector operands = instruction.getOperands(); // O(1)
    PBIW::Utils::OperandVector::Collection::const_iterator it;
    
    std::list<GenericAssembly::Interfaces::IOperation*>::const_iterator sIt;
    std::list<GenericAssembly::Interfaces::IOperation*> references = instruction.getOperationReferences(); // O(1)
    
    printer << "----\nInstruction Addr: " << instruction.getAddress() << std::endl;
    printer << "Points to pattern at addr: " << instruction.getPattern()->getAddress() << std::endl;
    
    printer << "References : " << std::endl;
    
    for (sIt = references.begin(); // O(|references|) = O(12) = O(1)
         sIt != references.end();
         sIt++)
    {
      printer << (*sIt)->getOpcode() << " - " << (*sIt)->getTextRepresentation() << std::endl;
    }
    
    printer << "Read : ";
    
    for (it = operands.begin(); // O(|operands|) = O(8) = O(1)
         it < operands.end()-4; //&& it->getIndex() < 8;
         it++)
    {
      printer << "[" << (*it)->getIndex() <<  "] = "<< (*it)->getValue();
      
      if ( (*it)->isImmediate() )
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
        printer << "[" << (*it)->getIndex() <<  "] = "<< (*it)->getValue();

        if ( (*it)->isImmediate() )
          printer << "(Imm)";

        printer << ", ";
      }
    }
    
    printer << std::endl;
  }

  void
  PartialPBIWDebugPrinter::printInstructionsHeader()  // O(1)
  {
    printer << "--- Start of PBIW Instructions Debug Printing --- " << std::endl;
  }

  void
  PartialPBIWDebugPrinter::printInstructionsFooter(unsigned int instructionsCount) // O(1)
  {
    if (instructionsCount >= 255)
      printer << "### WARNING: More than 256 instructions generated.\nCheck your VHDL entity to accomplish the new address size." << std::endl;
    
    printer << "--- End of PBIW Instructions Debug Printing --- " << std::endl;
  }
  
  void
  PartialPBIWDebugPrinter::printPatternsHeader()  // O(1)
  {
    printer << "--- Start of PBIW Patterns Debug Printing --- " << std::endl;
  }

  void
  PartialPBIWDebugPrinter::printPatternsFooter(unsigned int patternsCount) // O(1)
  {
    if (patternsCount >= 63)
      printer << "### WARNING: More than 64 patterns generated.\nCheck your VHDL entity to accomplish the new address size." << std::endl;
    
    printer << "--- End of PBIW Patterns Debug Printing --- " << std::endl;
  }

}
