/* 
 * File:   PBIW.cpp
 * Author: helix
 * 
 * Created on July 20, 2011, 4:13 PM
 */

#include <iostream>

#include "PartialPBIW.h"
#include "rVex64PBIWInstruction.h"
#include "Operation.h"
#include "Operand.h"

namespace PBIW
{
  using namespace Interfaces;
  
  IPBIWPattern*
  PartialPBIW::hasPattern(IPBIWPattern* other) const
  {
    if (codedPatterns.size() == 0)
      return false;
    
    PBIWPatternSet::const_iterator it;
    
    for (it = codedPatterns.begin();
         it != codedPatterns.end();
         it++)
    {
      if ( **it == *other )
      {
        delete other;
        return *it;
      }
    }
    
    return NULL;
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
      IPBIWInstruction* instruction = new rVex64PBIWInstruction();
      IPBIWPattern* pattern = new rVex96PBIWPattern();
      
      // For each syllable...
      VexSyllableVector syllables = (*instructionIt)->getSyllables();
      VexSyllableVector::const_iterator syllableIt;
      
      for (syllableIt = syllables.begin();
           syllableIt < syllables.end();
           syllableIt++)
      {
        Operation* operation = new Operation();
        operation->setOpcode( (*syllableIt)->getOpcode() );
        
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
            if ( !instruction->hasOperandSlot() || instruction->containsImmediate() && operandIt->second == rVex::Syllable::OperandType::Imm)
            {
              IPBIWPattern* foundPattern = hasPattern(pattern);
              
              if ( foundPattern == NULL )
                codedPatterns.insert(pattern);
              else
                pattern = foundPattern;
              
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
          
          operation->addOperand( operandIt->first );
        } // ... end for each operand
        
        pattern->addOperation(operation);
      } // ... end for each syllable
      
      // If the pattern has not already been included, include it
      IPBIWPattern* foundPattern = hasPattern(pattern);
              
      if ( foundPattern == NULL )
        codedPatterns.insert(pattern);
      else
        pattern = foundPattern;
      
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
      printer.getOutputStream() << "---" << std::endl;
    }
    
    PBIWInstructionList::const_iterator instructionIt;
    
    printer.getOutputStream() << "Instructions: " << codedInstructions.size() << std::endl;
    
    for (instructionIt = codedInstructions.begin();
         instructionIt != codedInstructions.end();
         instructionIt++)
    {
      IPBIWPattern* pattern = (*instructionIt)->getPattern();
      
      printer.getOutputStream() << "Pattern Addr: " << pattern << " - ";
      printer.printInstruction(**instructionIt);
      printer.printPattern(*pattern);
      printer.getOutputStream() << "---" << std::endl;
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