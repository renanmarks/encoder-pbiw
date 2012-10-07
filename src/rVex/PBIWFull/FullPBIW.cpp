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
#include "src/rVex/PBIWFull/Printers/FullPBIWPrinter.h"
#include "src/rVex/PBIWFull/Printers/FullPBIWDebugPrinter.h"
#include "src/rVex/Utils/OperandVectorBuilder.h"
#include "src/rVex/PBIWFull/Factory.h"

namespace PBIWFull
{
  using namespace PBIW::Interfaces;
  
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
    newPattern->reorganize(); // O(1)
    
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
    finalInstruction->setOperationReferences(syllablesBuffer);
    
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
  
  void FullPBIW::resetFinalOperation(GenericAssembly::Utils::OperandVector::const_iterator& operandIt, // O(1)
                                        IOperation*& finalOperation, 
                                        rVex::Syllable* const& syllable,
                                        const GenericAssembly::Utils::OperandVector& operands)
  {
    operandIt = operands.begin();
    delete finalOperation;
    finalOperation = factory.createOperation(*syllable);//new Operation();
  }
  
  void                                                                                 
  FullPBIW::encode(const std::deque<GenericAssembly::Interfaces::IInstruction*>& originalInstructions) // O(|codedPatterns|^2)
  {
    std::deque<rVex::Instruction*> rVexInstructions;
    std::deque<GenericAssembly::Interfaces::IInstruction*>::const_iterator it;
    
    for (it = originalInstructions.begin();
         it != originalInstructions.end();
         it++)
    {
      rVexInstructions.push_back( static_cast<rVex::Instruction*>(*it) );
    }
    
    encode(rVexInstructions);
  }
  
  void                                                                                 
  FullPBIW::encode(const std::deque<rVex::Instruction*>& originalInstructions) // O(|codedPatterns|^2)
  {
    std::deque<rVex::Instruction*>::const_iterator instructionIt;
    
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
        PBIWFull::Label label = *instructionLabel;
        label.setDestiny(finalInstruction);
        
        labels.push_back(label);
        
        finalInstruction->setLabel(&labels.back());
      }
      
      // For each syllable...
      VexSyllableVector syllables = (*instructionIt)->getSyllables();
      VexSyllableVector::const_iterator syllableIt;
      
      unsigned int index = 0;
      
      for (syllableIt = syllables.begin();  // O(|syllables| * (4 + |codedPatterns|)) = O(4 * (4 + |codedPatterns|)) = 
           syllableIt < syllables.end();    // O(16 + 16|codedPatterns|)
           syllableIt++)
      {
        IOperation* finalOperation = factory.createOperation(**syllableIt);//new Operation();
        
        finalInstruction->setCodingOperation(*finalOperation);
        
        // For each operand...
        using GenericAssembly::Interfaces::IOperation;
        
        GenericAssembly::Utils::OperandVector::const_iterator operandIt;
        GenericAssembly::Utils::OperandVector operands = (*syllableIt)->exportOperandVector();
        
        for (operandIt = operands.begin(); // O(|operands| + |codedPatterns|) = O(4 + |codedPatterns|) = O(|codedPatterns|)
             operandIt < operands.end();
             operandIt++)
        {
          const IPBIWInstruction* firstInstruction = finalInstruction;
          IOperand* operand = factory.createOperand(**operandIt);
          
          // Search for the operand (only its value and type(imm, for example))
          const IOperand& foundOperand = finalInstruction->containsOperand( *operand ); // O(|operands|) = O(12) = O(1)
          
          // If not found in the instruction (i.e. the operand returned is the same searched)...
          if ( &foundOperand == operand )
          {
            if ( !finalInstruction->hasOperandSlot( PBIW::Utils::OperandItemDTO(operand, *operandIt) ) )
            {
              if ( (*instructionIt)->canSplitInstruction(**syllableIt) )
              {
                saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
              }
              else
              {
                while ( !(*instructionIt)->canSplitInstruction(**syllableIt) )
                {
                  syllablesBuffer.remove(*syllableIt);
                  syllableIt--; // go back
                  newPattern->removeLastAddedOperation();
                  finalInstruction->setAnnulBit(index-1,false);
                } 
                
                syllablesBuffer.remove(*syllableIt);
                
                saveAndCreateNewPBIWElements(finalInstruction, newPattern); // O(|codedPatterns|)
              }

              operands = (*syllableIt)->exportOperandVector();
              
              resetFinalOperation(operandIt, finalOperation, *syllableIt, operands); // O(1)
              finalInstruction->setCodingOperation(*finalOperation);
              
              delete operand;
              operand = factory.createOperand(**operandIt); // O(1)
            }

            finalInstruction->addOperand(*operand);
          }
          else 
          {
            // If found, check if it is some operand of a BR/BRF syllable
            // and put it in its position
            rVex::Operand::Type type = static_cast<rVex::Operand::Type>(operand->getTypeCode());
            
            if (type == rVex::Operand::BRSource)
            {
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
            }
          }
          
          // If the PBIW instruction has been splitted
          if (firstInstruction != finalInstruction)
          {
            delete operand;
            IOperand* tempOperand = factory.createOperand(**operandIt); // O(1)
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
        index = newPattern->getOperations().size();
        
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
      rVex64PBIWInstruction* instruction = static_cast<rVex64PBIWInstruction*>(*it);
      
      std::string label = instruction->getLabelDestiny();
      LabelVector::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if (labelIt != labels.end())
      {
        instruction->setBranchDestiny(*(labelIt->getDestiny()));
        instruction->setImmediateValue(labelIt->getDestiny()->getAddress());
      }
      
      if (debug)
      {
        std::cout << "PBIW Instr" << " addr[" << instruction->getAddress() << "]"
          << " branching label " << instruction->getLabelDestiny()
          << " now points to addr[" << instruction->getBranchDestiny()->getAddress() << "]"
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
      (*it)->useContext(*this);
      (*it)->run(factory);
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
  FullPBIW::decode(const std::deque<IPBIWInstruction*>& codedInstructions, 
               const std::deque<IPBIWPattern*>& codedPatterns)
  {

  }

  std::deque<IPBIWInstruction*>
  FullPBIW::getInstructions() const
  {
    return std::deque<IPBIWInstruction*>(codedInstructions.begin(), codedInstructions.end());
  }

  std::deque<IPBIWPattern*>
  FullPBIW::getPatterns() const
  {
    return std::deque<IPBIWPattern*>(codedPatterns.begin(), codedPatterns.end());
  }
  
  std::deque<ILabel*> 
  FullPBIW::getLabels() const
  {
    std::deque<ILabel*> temp;
    LabelVector::const_iterator it;
    
    for(it = labels.begin(); it != labels.end(); it++)
      temp.push_back( const_cast<Label*>(&(*it)) );
    
    return std::deque<ILabel*>(temp.begin(), temp.end());
  }
}
