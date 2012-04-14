/* 
 * File:   FullPBIW.cpp
 * Author: helix
 * 
 * Created on July 20, 2011, 4:13 PM
 */

#include <iostream>
#include <stdexcept>

#include "FullPBIW.h"
#include "rVex64PBIWInstruction.h"
#include "Operation.h"
#include "Operand.h"
#include "Printers/PartialPBIWPrinter.h"
#include "Printers/PartialPBIWDebugPrinter.h"

namespace PBIW
{
  using namespace Interfaces;
  
  FullPBIW::~FullPBIW() 
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
  FullPBIW::hasPattern(const IPBIWPattern& other) const  // O(|codedPatterns|)
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
  void FullPBIW::savePBIWElements(rVex64PBIWInstruction*& finalInstruction, rVex96PBIWPattern*& newPattern)
  {
    newPattern->reorganize(finalInstruction); // O(1)
    
    const IPBIWPattern& foundPattern = hasPattern(*newPattern); // O(|codedPatterns|)
    IPBIWPattern& notConstFoundPattern = const_cast<IPBIWPattern&>(foundPattern); // O(1)
    
    // If not found in the patterns set
    if ( &notConstFoundPattern == newPattern )
    {
      newPattern->setAddress(codedPatterns.size()); // Set the pattern address
      newPattern->pointToInstructionThatUseIt(finalInstruction); // Ser the instruction that use it
      codedPatterns.push_back(newPattern); // If the pattern has not already been included, include it
    }
    else
    {
      notConstFoundPattern.pointToInstructionThatUseIt(finalInstruction);
      delete newPattern; // if found, we are not using the newPattern, so free the memory allocated
    }

    finalInstruction->pointToPattern(notConstFoundPattern);
    finalInstruction->setSyllableReferences(syllablesBuffer);
    
    syllablesBuffer.clear(); // Clear the buffer to get new references
    
    finalInstruction->setAddress(codedInstructions.size()); // Set the instruction address
    codedInstructions.push_back(finalInstruction);
    
    if (finalInstruction->hasControlOperationWithLabelDestiny())
      branchingInstructions.push_back(finalInstruction);
  }
  
  // O(|codedPatterns|)
  void FullPBIW::saveAndCreateNewPBIWElements(rVex64PBIWInstruction*& finalInstruction, rVex96PBIWPattern*& newPattern)
  {
    savePBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
    createNewPBIWElements(finalInstruction, newPattern);
  }
  
  void FullPBIW::createNewPBIWElements(rVex64PBIWInstruction*& finalInstruction, rVex96PBIWPattern*& newPattern)
  {
    finalInstruction = new rVex64PBIWInstruction();
    newPattern = new rVex96PBIWPattern();
    
    finalInstruction->pointToPattern(*newPattern);
  }
  
  void FullPBIW::resetFinalOperation(VexSyllableOperandVector::Collection::const_iterator& operandIt, // O(1)
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
  FullPBIW::encode(const std::vector<rVex::Instruction*>& originalInstructions) // O(|codedPatterns|^2)
  {
    std::vector<rVex::Instruction*>::const_iterator instructionIt;
    
    originalInstructionsCount = originalInstructions.size();
    
    // For each group of 4 syllables...
    for(instructionIt = originalInstructions.begin();   // O((|originalInstructions| + |codedPatterns|) * (16 + 16|codedPatterns|)) =
        instructionIt < originalInstructions.end();     // O((|originalInstructions| + |codedPatterns|) * 16|codedPatterns|) =                 
        instructionIt++)                                // O(16|codedPatterns||originalInstructions| + 16|codedPatterns|^2) =                 
    {                                                   // O(|codedPatterns||originalInstructions| * |codedPatterns|^2) =                
      // Create a new PBIW instruction and PBIW pattern                  // O(|codedPatterns|^3)
      rVex64PBIWInstruction* finalInstruction;
      rVex96PBIWPattern* newPattern;
      
      createNewPBIWElements(finalInstruction, newPattern);
      
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
              if ( (*instructionIt)->canSplitSyllable(*syllableIt) )
              {
                saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
                resetFinalOperation(operandIt, finalOperation, *syllableIt, operands); // O(1)
              }
              else
              {
                while ( !(*instructionIt)->canSplitSyllable(*syllableIt) )
                {
                  syllablesBuffer.remove(*syllableIt);
                  syllableIt--; // go back
                  newPattern->removeLastAddedOperation();
                } 
                
                syllablesBuffer.remove(*syllableIt);
                
                saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
                
                operandVectorBuilder.clearOperandVector();
                (*syllableIt)->exportOperandVector(operandVectorBuilder);
                operands = operandVectorBuilder.getOperandVector();
                
                resetFinalOperation(operandIt, finalOperation, *syllableIt, operands); // O(1)
              }
            }

            operand = (*operandIt)->getOperand(); // O(1)

            switch ( (*operandIt)->getType() )
            {
              case Utils::OperandItem::BRSource :
                if (finalOperation->getOpcode() == rVex::Syllable::opBR)
                {
                  finalInstruction->setOpBRslot(*operand); // O(1)
                  break;
                }
                else if (finalOperation->getOpcode() == rVex::Syllable::opBRF)
                {
                  finalInstruction->setOpBRFslot(*operand); // O(1)
                  break;
                }
                
              case Utils::OperandItem::BRDestiny :
                finalInstruction->addBranchOperand(*operand); // O(1)
                break;
              case Utils::OperandItem::GRSource :
              case Utils::OperandItem::GRDestiny :
              case Utils::OperandItem::Imm :
                finalInstruction->addReadOperand(*operand); // O(1)
                break;
            }
          }
          else 
          {
            // If found, check if it is some operand of a BR/BRF syllable
            // and put it in its position
            switch ( (*operandIt)->getType() )
            {
              case Utils::OperandItem::BRSource :
                if (finalOperation->getOpcode() == rVex::Syllable::opBR)
                {
                  finalInstruction->setOpBRslot(*operand); // O(1)
                  finalOperation->addOperand( *operand ); // O(1)
                  continue;
                }
                else if (finalOperation->getOpcode() == rVex::Syllable::opBRF)
                {
                  finalInstruction->setOpBRFslot(*operand); // O(1)
                  finalOperation->addOperand( *operand ); // O(1)
                  continue;
                }
              default:
                break;
            }
          }
          
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
        
        // Set annul bit referent this operation is used by the pattern (pointed by the instruction)
        unsigned int index = newPattern->getOperations().size();
        
        if(newPattern->getOperation(index-1)->getOpcode() != 0)
        {
          finalInstruction->setAnnulBit(index-1,true);          
        }
      } // ... end for each syllable
      
      savePBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
    } // ... end for each instruction
    
    processLabels();
  }

  void FullPBIW::processLabels()
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
  
  void FullPBIW::registerOptimizer(IPBIWOptimizer& optimizer)
  {
    optimizers.push_back(&optimizer);
    
    return;
  }
  
  void FullPBIW::runOptimizers()
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
  FullPBIW::printStatistics(IPBIWPrinter& printer)
  {
    unsigned int instructionsBytes = codedInstructions.size() * 8;
    unsigned int patternsBytes = codedPatterns.size() * 12;
    unsigned int originalInstructionsBytes = originalInstructionsCount * 16;
    
    printer.getOutputStream()
      << "Summary: \n\n"
      << "Instruction count = " << codedInstructions.size() 
      << " ( " << instructionsBytes <<" bytes )" << std::endl
      
      << "Pattern count = " << codedPatterns.size()
      << " ( " << patternsBytes <<" bytes )" << std::endl
      
      << "Reuse ratio = " 
      << (codedInstructions.size() / (double)codedPatterns.size())  << std::endl
      
      << "Total = " 
      << patternsBytes + instructionsBytes <<" bytes" << std::endl
      
      << "----" << std::endl
      
      << "Original Instructions count = " << originalInstructionsCount
      << " ( " << originalInstructionsBytes <<" bytes )" << std::endl
      
      << "Compression ratio = " 
      << ((instructionsBytes + patternsBytes) / (double)originalInstructionsBytes) * 100.0 << " %" << std::endl;
  }
  
  void
  FullPBIW::printInstructions(IPBIWPrinter& printer)
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
  FullPBIW::printPatterns(IPBIWPrinter& printer)
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
  FullPBIW::decode(const std::vector<IPBIWInstruction*>& codedInstructions, 
               const std::vector<IPBIWPattern*>& codedPatterns)
  {

  }

  std::vector<IPBIWInstruction*>
  FullPBIW::getInstructions()
  {
    return std::vector<IPBIWInstruction*>(codedInstructions.begin(), codedInstructions.end());
  }

  std::vector<IPBIWPattern*>
  FullPBIW::getPatterns()
  {
    return std::vector<IPBIWPattern*>(codedPatterns.begin(), codedPatterns.end());
  }
}
