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
  
  const IPBIWPattern&
  PartialPBIW::hasPattern(const IPBIWPattern& other) const
  {
    if (codedPatterns.size() == 0)
      return other;
    
    PBIWPatternList::const_iterator it;
    
    for (it = codedPatterns.begin();
         it != codedPatterns.end();
         it++)
    {
      if ( **it == other )
        return **it;
    }
    
    return other;
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
      rVex64PBIWInstruction tempInstruction;
      
      // Create a new PBIW instruction and PBIW pattern
      IPBIWInstruction* finalInstruction = new rVex64PBIWInstruction();
      IPBIWPattern* newPattern = new rVex96PBIWPattern();
      
      // For each syllable...
      VexSyllableVector syllables = (*instructionIt)->getSyllables();
      VexSyllableVector::const_iterator syllableIt;
      
      for (syllableIt = syllables.begin();
           syllableIt < syllables.end();
           syllableIt++)
      {
        Operation tempOperation;
        IOperation* finalOperation = new Operation();
        
        tempOperation.setOpcode( (*syllableIt)->getOpcode() );
        
        // For each operand...
        VexSyllableOperandVector::const_iterator operandIt;
        VexSyllableOperandVector operands = (*syllableIt)->getOperandVector();
        
        for (operandIt = operands.begin();
             operandIt < operands.end();
             operandIt++)
        {
          // Search for the operand (only its value and type(imm, for example))
          const IOperand& foundOperand = tempInstruction.containsOperand( *(operandIt->first) );
          
          // If not found in the instruction (i.e. the operand returned is the same searched)...
          if ( &foundOperand == operandIt->first )
          {
            // TODO: Check the read AND write slots separately!
            if ( !tempInstruction.hasOperandSlot( *operandIt ) )
            {
              const IPBIWPattern& foundPattern = hasPattern(*newPattern);
              
              // If not found in the patterns set
              if ( &foundPattern == newPattern )
                codedPatterns.push_back(newPattern); // If the pattern has not already been included, include it
              else
                delete newPattern; // if found, we are not using the newPattern, so free the memory allocated
              
              tempInstruction.pointToPattern(foundPattern);
              
              *finalInstruction = tempInstruction;
              codedInstructions.push_back(finalInstruction);
              
              finalInstruction = new rVex64PBIWInstruction();
              newPattern = new rVex96PBIWPattern();
            }
            
            IOperand& operand = *(operandIt->first);
            
            // TODO: Check the read AND write slots separately!
            switch ( operandIt->second )
            {
              case rVex::Syllable::OperandType::BRDestiny :
              case rVex::Syllable::OperandType::GRDestiny :
                if (operand.getValue() == 0)
                  break;

              case rVex::Syllable::OperandType::Imm :
                tempInstruction.addWriteOperand(operand);
                break;

              case rVex::Syllable::OperandType::BRSource :
              case rVex::Syllable::OperandType::GRSource :
                tempInstruction.addReadOperand(operand);
                break;
            }
            
          }
          else // if found...
          {
            /* Fix the bug when the read operands reference an write operand in
             * a PBIW instruction.
             * Simply check this condition and, if true, "copy"
             * the operand in the write section to a field in the read section
             * and uses this new index as a reference.
             **/
            
            if (foundOperand.getIndex() > 7)
            {
              if ( !tempInstruction.hasReadOperandSlot() )
              {
                const IPBIWPattern& foundPattern = hasPattern(*newPattern);

                // If not found in the patterns set
                if ( &foundPattern == newPattern )
                  codedPatterns.push_back(newPattern); // If the pattern has not already been included, include it
                else
                  delete newPattern; // if found, we are not using the newPattern, so free the memory allocated

                tempInstruction.pointToPattern(foundPattern);
                
                *finalInstruction = tempInstruction;
                codedInstructions.push_back(finalInstruction);

                finalInstruction = new rVex64PBIWInstruction();
                newPattern = new rVex96PBIWPattern();
              }

              IOperand& operand = *(operandIt->first);
              
              // TODO: Check the read AND write slots separately!
              switch ( operandIt->second )
              {
                case rVex::Syllable::OperandType::BRSource :
                case rVex::Syllable::OperandType::GRSource :
                  tempInstruction.addReadOperand(operand);
                  
                  tempOperation.addOperand(operand);
                  delete operandIt->first; // Free memory
                  continue;
              }
            }
          }
          
          // or if contains operand, so... USE IT!
          tempOperation.addOperand( foundOperand );
          delete operandIt->first; // Free memory
        } // ... end for each operand
        
        *finalOperation = tempOperation;
        
        newPattern->addOperation(finalOperation);
      } // ... end for each syllable
      
      const IPBIWPattern& foundPattern = hasPattern(*newPattern);
              
      // If not found in the patterns set
      if ( &foundPattern == newPattern )
        codedPatterns.push_back(newPattern); // If the pattern has not already been included, include it
      else
        delete newPattern;  // if found, we are not using the newPattern, so free the memory allocated

      // Point to the new pattern and save the instruction
      finalInstruction->pointToPattern(foundPattern);
      codedInstructions.push_back(finalInstruction);
    } // ... end for each instruction
  }

  void
  PartialPBIW::print(IPBIWPrinter& printer)
  {
    printer.printHeader();
    
    PBIWPatternList::const_iterator patternIt;
    
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
      const IPBIWPattern* pattern = (*instructionIt)->getPattern();
      
      printer.getOutputStream() << "Pattern Addr: " << pattern << " - " << std::endl;
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