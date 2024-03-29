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

#include "FullPBIWDebugPrinter.h"
#include "PBIW/Interfaces/IPBIWPattern.h"
#include "PBIW/Interfaces/IPBIWInstruction.h"
#include "PBIW/Interfaces/IOperation.h"
#include "PBIW/Interfaces/IPBIW.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;
  
  void
  FullPBIWDebugPrinter::printPattern(const IPBIWPattern& pattern, const std::vector<unsigned int>& binary) // O(|operationCount|)
  {
    unsigned int operationCount = pattern.getOperationCount(); // O(1)
    
    printer << "\tPattern Addr: " << pattern.getAddress() << std::endl;
    printer << "\tReuse count: " << pattern.getUsageCounter() << std::endl;
    printer << "\tInstr. use it: ";
    
    typedef std::deque<IPBIWInstruction*> AddrInstruction;
    AddrInstruction addrInstruction = const_cast<IPBIWPattern&>(pattern).getInstructionsThatUseIt();
    AddrInstruction::const_iterator it;
    
    for(it = addrInstruction.begin(); it < addrInstruction.end(); it++)
    {
        if(it != addrInstruction.begin())
            printer  << ", ";
        
        printer << (*it)->getAddress();        
    }
    
    printer << std::endl;
    
    for (unsigned int i = 0; i < operationCount; i++) // O(|operationCount|)
    {
      unsigned short opcode = pattern[i]->getOpcode();
      short brSrc = pattern[i]->getBrReadOperand();
      
      printer << "\tOpcode: " << opcode << " ";
      
      if (brSrc != -1)
        printer << "(old: " << pattern[i]->getOriginalOpcode() << ")";
      
      printer << " - ";
      
      IOperation::OperandIndexVector::const_iterator it;
      IOperation::OperandIndexVector operands = pattern[i]->getOperandsIndexes(); // O(1)
      
      printer << "Operands indexes (" << operands.size() << " total): ";
      
      if (brSrc != -1)
        printer << brSrc << " (BRSrc), ";
      
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
  FullPBIWDebugPrinter::printInstruction(const IPBIWInstruction& instruction, const std::vector<unsigned int>& binary)  // O(1)
  {
    PBIW::Utils::OperandVector operands = instruction.getOperands(); // O(1)
    PBIW::Utils::OperandVector::Collection::const_iterator it;
    IPBIWInstruction::AnnulationBits::const_iterator aBit;
    
    std::list<GenericAssembly::Interfaces::IOperation*>::const_iterator sIt;
    std::list<GenericAssembly::Interfaces::IOperation*> references = instruction.getOperationReferences(); // O(1)
    std::vector<bool> annulBits = instruction.getAnnulBits();
    
    printer << "\tInstruction Addr: " << instruction.getAddress() << std::endl;
    printer << "\tPoints to pattern at addr: " << instruction.getPattern()->getAddress() << std::endl;
    printer << "\tAnnul Bits: ";
            
    for(aBit = annulBits.begin();
        aBit < annulBits.end();
        aBit++)
    {
        printer << *aBit;
    }
    printer << std::endl;
    
    printer << "\tReferences : " << std::endl;
    
    for (sIt = references.begin(); // O(|references|) = O(12) = O(1)
         sIt != references.end();
         sIt++)
    {
      printer << "\t" <<(*sIt)->getOpcode() << " - " << (*sIt)->getTextRepresentation() << std::endl;
    }
    
    printer << "\tOperands : ";
    
    for (it = operands.begin(); // O(|operands|) = O(8) = O(1)
         it < operands.end(); //&& it->getIndex() < 8;
         it++)
    {
      printer << "[" << (*it)->getIndex() <<  "] = "<< (*it)->getValue();
      
      if ( (*it)->isImmediate() )
        printer << "(Imm)";
      
      printer << ", ";
    }
    
    printer << std::endl;
  }

  void
  FullPBIWDebugPrinter::printInstructionsHeader()  // O(1)
  {
    printer << "--- Start of PBIW Instructions Debug Printing --- " << std::endl;
  }

  void
  FullPBIWDebugPrinter::printInstructionsFooter(unsigned int instructionsCount) // O(1)
  {
    if (instructionsCount >= 255)
      printer << "### WARNING: More than 256 instructions generated.\nCheck your VHDL entity to accomplish the new address size." << std::endl;
    
    printer << "Instruction count = " << instructionsCount << std::endl;
    
    printer << "--- End of PBIW Instructions Debug Printing --- " << std::endl;
  }
  
  void
  FullPBIWDebugPrinter::printPatternsHeader()  // O(1)
  {
    printer << "--- Start of PBIW Patterns Debug Printing --- " << std::endl;
  }

  void
  FullPBIWDebugPrinter::printPatternsFooter(unsigned int patternsCount) // O(1)
  {
    if (patternsCount >= 63)
      printer << "### WARNING: More than 64 patterns generated.\nCheck your VHDL entity to accomplish the new address size." << std::endl;
    
    printer << "Pattern count = " << patternsCount << std::endl;
    
    printer << "--- End of PBIW Patterns Debug Printing --- " << std::endl;
  }

}
