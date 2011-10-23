/* 
 * File:   PBIW.cpp
 * Author: helix
 * 
 * Created on July 20, 2011, 4:13 PM
 */

#include "PBIW.h"
#include "rVex64PBIWInstruction.h"
#include "UnitaryPattern.h"

namespace PBIW
{

  void
  PBIW::encode()
  {
    VexInstructionVector::const_iterator instructionIt;
    
    // For each group of 4 syllables...
    for(instructionIt = originalInstructions.begin();
        instructionIt < originalInstructions.end();
        instructionIt++)
    {
      // Create a new PBIW instruction and PBIW pattern
      rVex64PBIWInstruction* instruction = new rVex64PBIWInstruction();
      rVex96PBIWPattern* pattern = new rVex96PBIWPattern();
      
      // For each syllable...
      VexSyllableVector syllables = (*instructionIt)->getSyllables();
      VexSyllableVector::const_iterator syllableIt;
      
      for (syllableIt = syllables.begin();
           syllableIt < syllables.end();
           syllableIt++)
      {
        UnitaryPattern unitaryPattern;
        unitaryPattern.opcode = (*syllableIt)->getOpcode();
        
        //pattern->addOpcode()
        
        // For each operand...
        VexSyllableOperandVector::const_iterator operandIt;
        VexSyllableOperandVector operands = (*syllableIt)->getOperandVector();
        
        for (operandIt = operands.begin();
             operandIt < operands.end();
             operandIt++)
        {
          
        }
      }
      
    }
  }

  void
  PBIW::decode(const std::vector<IPBIWInstruction*>& codedInstructions, 
               const std::vector<IPBIWPattern*>& codedPatterns)
  {

  }

  std::vector<IPBIWInstruction*>
  PBIW::getInstructions()
  {

  }

  std::vector<IPBIWPattern*>
  PBIW::getPatterns()
  {

  }
}