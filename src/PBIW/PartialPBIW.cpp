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
  
  PartialPBIW::~PartialPBIW() 
  { 
    PBIWPatternList::iterator patternIt;
    PBIWInstructionList::iterator instructionIt;
    
    for (instructionIt = codedInstructions.begin();
         instructionIt != codedInstructions.end();
         instructionIt++)
    {
      delete *instructionIt;
    }
    
    for (patternIt = codedPatterns.begin();
         patternIt != codedPatterns.end();
         patternIt++)
    {
      delete *patternIt;
    }
  }
  
  const IPBIWPattern&
  PartialPBIW::hasPattern(const IPBIWPattern& other) const
  {
    if (codedPatterns.size() == 0)
      return other;
    
    PBIWPatternList::const_iterator it;
    
    // O(|codedPatterns|)
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
  
  // O(|codedPatterns|) + O(1) = O(|codedPatterns|)
  void PartialPBIW::savePBIWElements(IPBIWInstruction*& finalInstruction, IPBIWPattern*& newPattern)
  {
    newPattern->reorganize(finalInstruction); // O(1)
    
    const IPBIWPattern& foundPattern = hasPattern(*newPattern); // O(|codedPatterns|)
    IPBIWPattern& notConstFoundPattern = const_cast<IPBIWPattern&>(foundPattern);
    
    // If not found in the patterns set
    if ( &notConstFoundPattern == newPattern )
      codedPatterns.push_back(newPattern); // If the pattern has not already been included, include it
    else
      delete newPattern; // if found, we are not using the newPattern, so free the memory allocated

    finalInstruction->pointToPattern(notConstFoundPattern);
    finalInstruction->setSyllableReferences(syllablesBuffer);
    
    syllablesBuffer.clear(); // Clear the buffer to get new references
    
    codedInstructions.push_back(finalInstruction);
    notConstFoundPattern.incrementUsageCounter();
  }
  
  // O(|codedPatterns|)
  void PartialPBIW::saveAndCreateNewPBIWElements(IPBIWInstruction*& finalInstruction, IPBIWPattern*& newPattern)
  {
    savePBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)

    finalInstruction = new rVex64PBIWInstruction();
    newPattern = new rVex96PBIWPattern();
  }
  
  void PartialPBIW::resetFinalOperation(VexSyllableOperandVector::Collection::const_iterator& operandIt, 
                                        IOperation*& finalOperation, 
                                        rVex::Syllable* const& syllable,
                                        const VexSyllableOperandVector& operands)
  {
    operandIt = operands.begin();
    delete finalOperation;
    finalOperation = new Operation();
    finalOperation->setOpcode( syllable->getOpcode() );
    finalOperation->setType( syllable->getSyllableType() );
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
      
      // Copy the original labels to the data structure used in PBIW
      if ( (*instructionIt)->haveLabel() )
      {
        rVex::Label* instructionLabel = (*instructionIt)->getLabel();
        PBIW::Label label = *instructionLabel;
        
        labels.push_back(label);
        
        finalInstruction->setLabel(labels.back());
      }
      
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
        rVex::Utils::OperandVectorBuilder operandVectorBuilder;
        (*syllableIt)->exportOperandVector(operandVectorBuilder);
        
        VexSyllableOperandVector::Collection::const_iterator operandIt;
        VexSyllableOperandVector operands = operandVectorBuilder.getOperandVector();
        
        for (operandIt = operands.begin();
             operandIt < operands.end();
             operandIt++)
        {
          const IPBIWInstruction* firstInstruction = finalInstruction;
          IOperand* operand = (*operandIt)->getOperand();
          
          // Search for the operand (only its value and type(imm, for example))
          const IOperand& foundOperand = finalInstruction->containsOperand( *operand );
          
          // If not found in the instruction (i.e. the operand returned is the same searched)...
          if ( &foundOperand == operand )
          {
            if ( !finalInstruction->hasOperandSlot( **operandIt ) )
            {
              saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
              resetFinalOperation(operandIt, finalOperation, *syllableIt, operands);
            }
          
            operand = (*operandIt)->getOperand();
            
            switch ( (*operandIt)->getType() )
            {
              case Utils::OperandItem::BRDestiny :
              case Utils::OperandItem::GRDestiny :
                if (operand->getValue() == 0)
                  break;

              case Utils::OperandItem::Imm :
                finalInstruction->addWriteOperand(*operand);
                break;

              case Utils::OperandItem::BRSource :
              case Utils::OperandItem::GRSource :
                if (operand->getValue() != 0)
                  finalInstruction->addReadOperand(*operand);
                
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
                saveAndCreateNewPBIWElements(finalInstruction, newPattern);// O(|codedPatterns|)
                resetFinalOperation(operandIt, finalOperation, *syllableIt, operands);
              }

              operand = (*operandIt)->getOperand();
              
              switch ( (*operandIt)->getType() )
              {
                case Utils::OperandItem::BRSource :
                case Utils::OperandItem::GRSource :
                  finalInstruction->addReadOperand(*operand);
                  finalOperation->addOperand(*operand);
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
                  saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
                  resetFinalOperation(operandIt, finalOperation, *syllableIt, operands);
                }

                operand = (*operandIt)->getOperand();
                
                switch ( (*operandIt)->getType() )
                {
                  case Utils::OperandItem::BRDestiny :
                  case Utils::OperandItem::GRDestiny :
                    finalInstruction->addWriteOperand(*operand);
                    finalOperation->addOperand(*operand);
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
            IOperand* tempOperand = (*operandIt)->getOperand();
            const IOperand& foundOperand = finalInstruction->containsOperand( *tempOperand ); 
            finalOperation->addOperand( foundOperand );
          }
          else
          {
            finalOperation->addOperand( foundOperand );
          }
         
        } // ... end for each operand
        
        syllablesBuffer.push_back(*syllableIt);
        newPattern->addOperation(finalOperation);
      } // ... end for each syllable
      
      savePBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
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
    
//    for (patternIt = codedPatterns.begin();
//         patternIt != codedPatterns.end();
//         patternIt++)
//    {
//      printer.getOutputStream() << "Usage count: " << (*patternIt)->getUsageCounter() << std::endl;
//      printer.printPattern(**patternIt);
//      printer.getOutputStream() << "---" << std::endl;
//    }
    
    PBIWInstructionList::const_iterator instructionIt;
    
    printer.getOutputStream() << "Instructions: " << codedInstructions.size() << std::endl;
    
    for (instructionIt = codedInstructions.begin();
         instructionIt != codedInstructions.end();
         instructionIt++)
    {
//      const IPBIWPattern* pattern = (*instructionIt)->getPattern();
//      
//      printer.getOutputStream() << "Pattern Addr: " << pattern << " - " << std::endl;
      printer.printInstruction(**instructionIt);
//      printer.printPattern(*pattern);
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