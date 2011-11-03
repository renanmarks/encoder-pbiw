/* 
 * File:   PBIW.cpp
 * Author: helix
 * 
 * Created on July 20, 2011, 4:13 PM
 */

#include "PartialPBIW.h"
#include "rVex64PBIWInstruction.h"
#include "Operation.h"
#include "Operand.h"

namespace PBIW
{
  using namespace Interfaces;

  
  bool 
  PartialPBIW::hasPattern(const IPBIWPattern* other) const
  {
    PBIWPatternSet::const_iterator it;
    
    for (it = codedPatterns.begin();
         it != codedPatterns.end();
         it++)
    {
      if ( **it != *other )
        return false;
    }
    
    return true;
  }
  
  void
  PartialPBIW::encode(const std::vector<rVex::Instruction*>& originalInstructions)
  {
    std::vector<rVex::Instruction*>::const_iterator instructionIt;
    
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
        Operation unitaryPattern;
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
              if ( !hasPattern(pattern) )
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
          
          unitaryPattern.addOperand( operandIt->first );
          
        } // ... end for each operand
        
        pattern->addOperation(unitaryPattern);
      } // ... end for each syllable
      
      // If the pattern has not already been included, include it
      if ( !hasPattern(pattern) )
        codedPatterns.insert(pattern);
      
      // Point to the new pattern and save the instruction
      instruction->pointToPattern(pattern);
      codedInstructions.push_back(instruction);
    
    } // ... end for each instruction
  }

  void
  PartialPBIW::print(IPBIWPrinter& printer)
  {
    printer.printHeader();
    
    PBIWPatternSet::const_iterator patternIt;
    
    printer.getOutputStream() << "Patterns: " << codedPatterns.size() << std::endl;
    
    for (patternIt = codedPatterns.begin();
         patternIt != codedPatterns.end();
         patternIt++)
    {
      printer.printPattern(**patternIt);
    }
    
    PBIWInstructionList::const_iterator instructionIt;
    
    printer.getOutputStream() << "Instructions: " << codedInstructions.size() << std::endl;
    
    for (instructionIt = codedInstructions.begin();
         instructionIt != codedInstructions.end();
         instructionIt++)
    {
      printer.printInstruction(**instructionIt);
    }
    
    printer.printFooter();
  }
  
  void
  PartialPBIW::decode(const std::vector<IPBIWInstruction*>& codedInstructions, 
               const std::vector<IPBIWPattern*>& codedPatterns)
  {

  }

  std::vector<IPBIWInstruction*>
  PartialPBIW::getInstructions()
  {
    return std::vector<IPBIWInstruction*>(codedInstructions.begin(), codedInstructions.end());
  }

  std::vector<IPBIWPattern*>
  PartialPBIW::getPatterns()
  {
    return std::vector<IPBIWPattern*>(codedPatterns.begin(), codedPatterns.end());
  }
}