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
#include "Printers/PartialPBIWPrinter.h"

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
  PartialPBIW::hasPattern(const IPBIWPattern& other) const  // O(|codedPatterns|)
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
    IPBIWPattern& notConstFoundPattern = const_cast<IPBIWPattern&>(foundPattern); // O(1)
    
    // If not found in the patterns set
    if ( &notConstFoundPattern == newPattern )
    {
      newPattern->setAddress(codedPatterns.size()); // Set the pattern address
      codedPatterns.push_back(newPattern); // If the pattern has not already been included, include it
    }
    else
    {
      delete newPattern; // if found, we are not using the newPattern, so free the memory allocated
    }

    finalInstruction->pointToPattern(notConstFoundPattern);
    finalInstruction->setSyllableReferences(syllablesBuffer);
    
    syllablesBuffer.clear(); // Clear the buffer to get new references
    
    finalInstruction->setAddress(codedInstructions.size()); // Set the instruction address
    codedInstructions.push_back(finalInstruction);
    notConstFoundPattern.incrementUsageCounter();
    
    if (finalInstruction->hasControlOperationWithLabelDestiny())
      branchingInstructions.push_back(finalInstruction);
  }
  
  // O(|codedPatterns|)
  void PartialPBIW::saveAndCreateNewPBIWElements(IPBIWInstruction*& finalInstruction, IPBIWPattern*& newPattern)
  {
    savePBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)

    finalInstruction = new rVex64PBIWInstruction();
    newPattern = new rVex96PBIWPattern();
  }
  
  void PartialPBIW::resetFinalOperation(VexSyllableOperandVector::Collection::const_iterator& operandIt, // O(1)
                                        IOperation*& finalOperation, 
                                        rVex::Syllable* const& syllable,
                                        const VexSyllableOperandVector& operands)
  {
    operandIt = operands.begin();
    delete finalOperation;
    finalOperation = new Operation();
    finalOperation->setOpcode( syllable->getOpcode() );
    finalOperation->setImmediateSwitch( syllable->getImmediateSwitch() );
    finalOperation->setType( syllable->getSyllableType() );
  }
  
  void                                                                                 
  PartialPBIW::encode(const std::vector<rVex::Instruction*>& originalInstructions) // O(|codedPatterns|^2)
  {
    std::vector<rVex::Instruction*>::const_iterator instructionIt;
    
    // For each group of 4 syllables...
    for(instructionIt = originalInstructions.begin();   // O((|originalInstructions| + |codedPatterns|) * (16 + 16|codedPatterns|)) =
        instructionIt < originalInstructions.end();     // O((|originalInstructions| + |codedPatterns|) * 16|codedPatterns|) =                 
        instructionIt++)                                // O(16|codedPatterns||originalInstructions| + 16|codedPatterns|^2) =                 
    {                                                   // O(|codedPatterns||originalInstructions| * |codedPatterns|^2) =                
      // Create a new PBIW instruction and PBIW pattern                  // O(|codedPatterns|^3)
      IPBIWInstruction* finalInstruction = new rVex64PBIWInstruction();
      IPBIWPattern* newPattern = new rVex96PBIWPattern();
      
      // Copy the original labels to the data structure used in PBIW
      if ( (*instructionIt)->haveLabel() )
      {
        rVex::Label* instructionLabel = (*instructionIt)->getLabel();
        PBIW::Label label = *instructionLabel;
        label.setDestiny(finalInstruction);
        
        labels.push_back(label);
        
        finalInstruction->setLabel(labels.back());
      }
      
      // For each syllable...
      VexSyllableVector syllables = (*instructionIt)->getSyllables();
      VexSyllableVector::const_iterator syllableIt;
      
      for (syllableIt = syllables.begin();  // O(|syllables| * (4 + |codedPatterns|)) = O(4 * (4 + |codedPatterns|)) = 
           syllableIt < syllables.end();    // O(16 + 16|codedPatterns|)
           syllableIt++)
      {
        IOperation* finalOperation = new Operation();
        
        finalOperation->setOpcode( (*syllableIt)->getOpcode() );
        finalOperation->setImmediateSwitch( (*syllableIt)->getImmediateSwitch() );
        finalOperation->setType( (*syllableIt)->getSyllableType() );
        
        bool syllableHasBrDestiny = (*syllableIt)->hasBrDestiny();
        
        // For each operand...
        rVex::Utils::OperandVectorBuilder operandVectorBuilder;
        (*syllableIt)->exportOperandVector(operandVectorBuilder);
        
        VexSyllableOperandVector::Collection::const_iterator operandIt;
        VexSyllableOperandVector operands = operandVectorBuilder.getOperandVector();
        
        for (operandIt = operands.begin(); // O(|operands| + |codedPatterns|) = O(4 + |codedPatterns|) = O(|codedPatterns|)
             operandIt < operands.end();
             operandIt++)
        {
          const IPBIWInstruction* firstInstruction = finalInstruction;
          IOperand* operand = (*operandIt)->getOperand();
          
          // Search for the operand (only its value and type(imm, for example))
          const IOperand& foundOperand = finalInstruction->containsOperand( *operand ); // O(|operands|) = O(12) = O(1)
          
          // If not found in the instruction (i.e. the operand returned is the same searched)...
          if ( &foundOperand == operand )
          {
            if ( !finalInstruction->hasOperandSlot( **operandIt ) )
            {
              saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
              resetFinalOperation(operandIt, finalOperation, *syllableIt, operands); // O(1)
            }

            operand = (*operandIt)->getOperand(); // O(1)

            switch ( (*operandIt)->getType() )
            {
              case Utils::OperandItem::GRDestiny :
                if (operand->getValue() == 0)
                  break;

              case Utils::OperandItem::Imm :
                finalInstruction->addWriteOperand(*operand); // O(1)
                break;

              case Utils::OperandItem::BRSource :
                finalInstruction->setBranchSourceOperand(*operand); // O(1)
                break;
              
              case Utils::OperandItem::BRDestiny :
                finalInstruction->addReadOperand(*operand); // O(1)
                break;
                
              case Utils::OperandItem::GRSource :
                if (operand->getValue() != 0)
                  finalInstruction->addReadOperand(*operand); // O(1)

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
            
            bool isZeroReadRegister = foundOperand.getIndex() == 0 && foundOperand.getValue() == 0 && 
                 (  (*operandIt)->getType() == Utils::OperandItem::GRSource 
                    /*|| (*operandIt)->getType() == Utils::OperandItem::BRSource*/ );
            
            if (syllableHasBrDestiny)
            {
              if ((*operandIt)->getType() == Utils::OperandItem::GRDestiny && (*operandIt)->getOperand()->getValue() == 0 )
              {
                // If it's a syllable that uses an Branch register as destiny (The General Register destiny and it has value zero (must!))
                // we don't do any copy or "error recovery" strategy.
              }
              else if ( (*operandIt)->getType() == Utils::OperandItem::BRDestiny )
              {
                // If it's a syllable that uses an Branch register as destiny
                // we don't do any copy or "error recovery" strategy.
              }
            }
            else
            if (!isZeroReadRegister && foundOperand.getIndex() > 7) // Fixes for write operands
            {
              if ( !finalInstruction->hasReadOperandSlot() )  // // O(|readOperands|) = O(8) = O(1)
              {
                saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
                resetFinalOperation(operandIt, finalOperation, *syllableIt, operands); // O(1)
              }

              operand = (*operandIt)->getOperand();
              
              switch ( (*operandIt)->getType() )
              {
                case Utils::OperandItem::BRSource :
                  finalInstruction->setBranchSourceOperand(*operand); // O(1)
                  continue;
                  break;
                  
                case Utils::OperandItem::GRSource :
                  finalInstruction->addReadOperand(*operand); // O(1)
                  finalOperation->addOperand(*operand); // O(1)
                  continue;
                default:
                  break;
              }
            }
            else if (!isZeroReadRegister && foundOperand.getIndex() < 8)// Fixes for read operands
            {
              if ( (*syllableIt)->getOpcode() != rVex::Syllable::opNOP )
              {
//                if (syllableHasBrDestiny && (*operandIt)->getType() == Utils::OperandItem::BRDestiny && (*operandIt)->getOperand()->getValue() == 0)
//                  continue;
                
                if ( !finalInstruction->hasWriteOperandSlot() )
                {
                  saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
                  resetFinalOperation(operandIt, finalOperation, *syllableIt, operands); // O(1)
                }

                operand = (*operandIt)->getOperand();
                
                switch ( (*operandIt)->getType() )
                {
                  case Utils::OperandItem::BRDestiny :
                    break;
                  case Utils::OperandItem::GRDestiny :
                    finalInstruction->addWriteOperand(*operand); // O(1)
                    finalOperation->addOperand(*operand); // O(1)
                    continue;
                  default:
                    break;
                }
              }
            }
          } // end if (not) found operands
          
          // If the PBIW instruction has been splitted
          if (firstInstruction != finalInstruction)
          {
            IOperand* tempOperand = (*operandIt)->getOperand(); // O(1)
            const IOperand& foundOperand = finalInstruction->containsOperand( *tempOperand ); // O(1)
            finalOperation->addOperand( foundOperand ); // O(1)
          }
          else
          {
            finalOperation->addOperand( foundOperand ); // O(1)
          }
         
        } // ... end for each operand
        
        syllablesBuffer.push_back(*syllableIt);
        newPattern->addOperation(finalOperation);
      } // ... end for each syllable
      
      savePBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
    } // ... end for each instruction
    
    processLabels();
  }

  void PartialPBIW::processLabels()
  {
    if (debug)
    {
      std::cout << "Translating to PBIW labels" << std::endl;
      std::cout << branchingInstructions.size() << " branching instructions" << std::endl;
    }
    
    PBIWInstructionList::iterator it;
    
    for (it = branchingInstructions.begin();
         it != branchingInstructions.end();
         it++)
    {
      std::string label = (*it)->getLabelDestiny();
      LabelVector::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if (labelIt != labels.end())
      {
        (*it)->setBranchDestiny(*labelIt->getDestiny());
        (*it)->setImmediateValue(labelIt->getDestiny()->getAddress());
      }
      
      if (debug)
      {
        std::cout << "PBIW Instr" << " addr[" << (*it)->getAddress() << "]"
          << " branching label " << (*it)->getLabelDestiny()
          << " now points to addr[" << (*it)->getBranchDestiny()->getAddress() << "]"
          << std::endl;      
      }
    }
    
    return;
  }
  
  void PartialPBIW::registerOptimizer(IPBIWOptimizer& optimizer)
  {
    optimizers.push_back(&optimizer);
    
    return;
  }
  
  void PartialPBIW::runOptimizers()
  {
    PBIWOptimizerList::iterator it;
    
    for (it = optimizers.begin();
         it != optimizers.end();
         it++)
    {
      std::vector<IPBIWInstruction*> codedInstructionsCopy(codedInstructions.begin(), codedInstructions.end());
      std::vector<IPBIWPattern*> codedPatternsCopy(codedPatterns.begin(), codedPatterns.end());
      std::vector<PBIW::Label> labelsCopy(labels.begin(), labels.end());
      
      (*it)->useInstructions(codedInstructionsCopy);
      (*it)->usePatterns(codedPatternsCopy);
      (*it)->useLabels(labelsCopy);
      (*it)->run();
    }
    
    return;
  }
  
  void
  PartialPBIW::printInstructions(IPBIWPrinter& printer)
  {
    PBIWInstructionList::const_iterator instructionIt;
    
    printer.printInstructionsHeader();
    
    for (instructionIt = codedInstructions.begin();
         instructionIt != codedInstructions.end();
         instructionIt++)
    {
      (*instructionIt)->print(printer);
    }
    
    printer.printInstructionsFooter(codedInstructions.size());
  }
  
  void
  PartialPBIW::printPatterns(IPBIWPrinter& printer)
  {
    PBIWPatternList::const_iterator patternIt;
    
    printer.printPatternsHeader();
    
    for (patternIt = codedPatterns.begin();
         patternIt != codedPatterns.end();
         patternIt++)
    {
      (*patternIt)->print(printer);
    }
    
    printer.printPatternsFooter(codedPatterns.size());
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