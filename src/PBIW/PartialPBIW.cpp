/* 
 * File:   PBIW.cpp
 * Author: helix
 * 
 * Created on July 20, 2011, 4:13 PM
 */

#include <iostream>
#include <stdexcept>

#include "PartialPBIW.h"
#include "rVex64PBIWInstruction.h"
#include "Operation.h"
#include "Operand.h"
#include "PartialPBIWPrinter.h"

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
      const IPBIWPattern& pattern = **it;
      
      if ( pattern == other )
        return pattern;
    }
    
    return other;
  }
  
  void PartialPBIW::createNewPBIWElements(IPBIWInstruction*& finalInstruction, IPBIWPattern*& newPattern)
  {
    newPattern->reorganize();
    
    const IPBIWPattern& foundPattern = hasPattern(*newPattern);
    IPBIWPattern& notConstFoundPattern = const_cast<IPBIWPattern&>(foundPattern);
    
    // If not found in the patterns set
    if ( &notConstFoundPattern == newPattern )
      codedPatterns.push_back(newPattern); // If the pattern has not already been included, include it
    else
      delete newPattern; // if found, we are not using the newPattern, so free the memory allocated

    finalInstruction->pointToPattern(notConstFoundPattern);
    codedInstructions.push_back(finalInstruction);
    notConstFoundPattern.incrementUsageCounter();
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
      IPBIWInstruction* finalInstruction = new rVex64PBIWInstruction();
      IPBIWPattern* newPattern = new rVex96PBIWPattern();
      
      // For each syllable...
      VexSyllableVector syllables = (*instructionIt)->getSyllables();
      VexSyllableVector::const_iterator syllableIt;
      
      for (syllableIt = syllables.begin();
           syllableIt < syllables.end();
           syllableIt++)
      {
        IOperation* finalOperation = new Operation();
        
        finalOperation->setOpcode( (*syllableIt)->getOpcode() );
        finalOperation->setType( (*syllableIt)->getSyllableType() );
        
        // For each operand...
        VexSyllableOperandVector::const_iterator operandIt;
        VexSyllableOperandVector operands = (*syllableIt)->getOperandVector();
        
        for (operandIt = operands.begin();
             operandIt < operands.end();
             operandIt++)
        {
          const IPBIWInstruction* firstInstruction = finalInstruction;
          
          // Search for the operand (only its value and type(imm, for example))
          const IOperand& foundOperand = finalInstruction->containsOperand( *(operandIt->first) );
          
          // If not found in the instruction (i.e. the operand returned is the same searched)...
          if ( &foundOperand == operandIt->first )
          {
            // TODO: Check the read AND write slots separately!
            if ( !finalInstruction->hasOperandSlot( *operandIt ) )
            {
              createNewPBIWElements(finalInstruction, newPattern);
              
              finalInstruction = new rVex64PBIWInstruction();
              newPattern = new rVex96PBIWPattern();
              
              operandIt = operands.begin();
              delete finalOperation;
              finalOperation = new Operation();
              finalOperation->setOpcode( (*syllableIt)->getOpcode() );
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
                finalInstruction->addWriteOperand(operand);
                break;

              case rVex::Syllable::OperandType::BRSource :
              case rVex::Syllable::OperandType::GRSource :
                if (operand.getValue() != 0)
                  finalInstruction->addReadOperand(operand);
                
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
            
            // Fixes for write operands
            if (foundOperand.getIndex() > 7)
            {
              if ( !finalInstruction->hasReadOperandSlot() )
              {
                createNewPBIWElements(finalInstruction, newPattern);
                
                finalInstruction = new rVex64PBIWInstruction();
                newPattern = new rVex96PBIWPattern();
                
                operandIt = operands.begin();
                delete finalOperation;
                finalOperation = new Operation();
                finalOperation->setOpcode( (*syllableIt)->getOpcode() );
              }

              IOperand& operand = *(operandIt->first);
              
              // TODO: Check the read AND write slots separately!
              switch ( operandIt->second )
              {
                case rVex::Syllable::OperandType::BRSource :
                case rVex::Syllable::OperandType::GRSource :
                  finalInstruction->addReadOperand(operand);
                  finalOperation->addOperand(operand);
                  //delete operandIt->first; // Free memory
                  continue;
                default:
                  break;
              }
            }
            else if (foundOperand.getIndex() < 8)// Fixes for read operands
            {
              if ( (*syllableIt)->getOpcode() != rVex::Syllable::opNOP )
              {
                if ( !finalInstruction->hasWriteOperandSlot() )
                {
                  createNewPBIWElements(finalInstruction, newPattern);

                  finalInstruction = new rVex64PBIWInstruction();
                  newPattern = new rVex96PBIWPattern();
                  
                  operandIt = operands.begin();
                  delete finalOperation;
                  finalOperation = new Operation();
                  finalOperation->setOpcode( (*syllableIt)->getOpcode() );
                }

                IOperand& operand = *(operandIt->first);
                
                // TODO: Check the read AND write slots separately!
                switch ( operandIt->second )
                {
                  case rVex::Syllable::OperandType::BRDestiny :
                  case rVex::Syllable::OperandType::GRDestiny :
                    finalInstruction->addWriteOperand(operand);
                    finalOperation->addOperand(operand);
                    //delete operandIt->first; // Free memory
                    continue;
                  default:
                    break;
                }
              }
            }
          } // end if (not) found operands
          
          // or if contains operand, so... USE IT!
          if (firstInstruction != finalInstruction)
          {
            const IOperand& foundOperand = finalInstruction->containsOperand( *(operandIt->first) );
            finalOperation->addOperand( foundOperand );
          }
          else
          {
            finalOperation->addOperand( foundOperand );
            //delete operandIt->first; // Free memory
          }
         
        } // ... end for each operand
        
        newPattern->addOperation(finalOperation);
      } // ... end for each syllable
      
      createNewPBIWElements(finalInstruction, newPattern);
    } // ... end for each instruction
  }

  void PartialPBIW::registerOptimizer(const IPBIWOptimizer& optimizer)
  {
    return;
  }
  
  void PartialPBIW::runOptimizers()
  {
    return;
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