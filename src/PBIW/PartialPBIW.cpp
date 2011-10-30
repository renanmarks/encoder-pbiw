/* 
 * File:   PBIW.cpp
 * Author: helix
 * 
 * Created on July 20, 2011, 4:13 PM
 */

#include "PartialPBIW.h"
#include "rVex64PBIWInstruction.h"
#include "UnitaryPattern.h"
#include "Operand.h"

namespace PBIW
{

  void
  PartialPBIW::encode()
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
        unitaryPattern.setOpcode( (*syllableIt)->getOpcode() );
        
        // TODO: pattern->addOpcode()
        
        // For each operand...
        VexSyllableOperandVector::const_iterator operandIt;
        VexSyllableOperandVector operands = (*syllableIt)->getOperandVector();
        
        for (operandIt = operands.begin();
             operandIt < operands.end();
             operandIt++)
        {
          // Search for the operand (its value and type(imm, for instance))
          if ( !instruction->containsOperand( *(operandIt->first) ) )
          {
            // TODO: Check the read AND write slots separately!
            if ( !instruction->hasOperandSlot() )
            {
              if ( codedPatterns.find(pattern) != codedPatterns.end() )
                codedPatterns.insert(pattern);
              
              instruction->pointToPattern(pattern);
              codedInstructions.push_back(instruction);
              
              instruction = new rVex64PBIWInstruction();
              pattern = new rVex96PBIWPattern();
            }
            
            // TODO: Check the read AND write slots separately!
            switch ( operandIt->second )
            {
              case rVex::Syllable::OperandType::BRDestiny :
              case rVex::Syllable::OperandType::GRDestiny :
              case rVex::Syllable::OperandType::Imm :
                instruction->addWriteOperand(operandIt->first);
                break;
                
              case rVex::Syllable::OperandType::BRSource :
              case rVex::Syllable::OperandType::GRSource :
                instruction->addReadOperand(operandIt->first);
                break;
            }
          }
          
          // TODO: pattern->addOperand( (*operandIt)->first->getIndex() )
          
        } // ... end for each operand
      } // ... end for each syllable
      
      // If the pattern has not already been included, include it
      if ( codedPatterns.find(pattern) != codedPatterns.end() )
        codedPatterns.insert(pattern);
      
      // Point to the new pattern and save the instruction
      instruction->pointToPattern(pattern);
      codedInstructions.push_back(instruction);
    
    } // ... end for each instruction
  }

  void
  PartialPBIW::decode(const std::vector<IPBIWInstruction*>& codedInstructions, 
               const std::vector<IPBIWPattern*>& codedPatterns)
  {

  }

  std::vector<IPBIWInstruction*>
  PartialPBIW::getInstructions()
  {

  }

  std::vector<IPBIWPattern*>
  PartialPBIW::getPatterns()
  {

  }
}