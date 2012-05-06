/* 
 * File:   BaseOptimizer.cpp
 * Author: helix
 * 
 * Created on December 22, 2011, 3:37 PM
 */

#include "BaseOptimizer.h"
#include "Interfaces/IPBIWInstruction.h"
#include <algorithm>

namespace PBIW
{

  BaseOptimizer::BaseOptimizer()
  {
    // TODO
  }

  BaseOptimizer::BaseOptimizer(const BaseOptimizer& orig)
  {
    // TODO
  }

  BaseOptimizer::~BaseOptimizer()
  {  
    PBIWInstructionList::iterator instructionIt;
    
    for (instructionIt = instructions.begin(); instructionIt != instructions.end(); instructionIt++) // O(|labels|) = O(1)
      delete *instructionIt;
    
    PBIWPatternList::iterator patternIt;
    
    for (patternIt = patterns.begin(); patternIt != patterns.end(); patternIt++) // O(|labels|) = O(1)
      delete *patternIt;
  }

  void
  BaseOptimizer::useLabels(const std::vector<Label>& labels) // O(1)
  {
    std::vector<Label>::const_iterator it;
    
    for (it = labels.begin(); it < labels.end(); it++) // O(|labels|) = O(1)
      this->labels.push_back(*it);
  }

  void
  BaseOptimizer::useInstructions(const std::vector<IPBIWInstruction*>& instructions) // O(|instructions|)
  {
    std::vector<IPBIWInstruction*>::const_iterator it;
    
    for (it = instructions.begin(); it < instructions.end(); it++)
    {
      IPBIWInstruction* clonedInstruction = (*it)->clone();
      
      this->instructions.push_back(clonedInstruction);
      
      if (clonedInstruction->hasControlOperationWithLabelDestiny())
        branchingInstructions.push_back(clonedInstruction);
    }
  }

  void
  BaseOptimizer::usePatterns(const std::vector<IPBIWPattern*>& patterns) // O(|patterns|)
  {
    std::vector<IPBIWPattern*>::const_iterator it;
    
    for (it = patterns.begin(); it < patterns.end(); it++)
    {
      IPBIWPattern* clonedPattern = (*it)->clone();
      clonedPattern->resetUsageCounter();
      
      this->patterns.push_back(clonedPattern);
    }
  }

  void 
  BaseOptimizer::setupOptimizer()
  {
    PBIWInstructionList::iterator it;
    
    // First, we setup the labels and instructions
    for (it = instructions.begin();
         it != instructions.end();
         it++)
    {
      if ((*it)->getLabel() == NULL)
        continue;
      
      std::string label = (*it)->getLabel()->getName();
      LabelList::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if (labelIt != labels.end())
        (*it)->setLabel(*labelIt);
    }
    
    // Then we setup de branching instructions
    for (it = branchingInstructions.begin();
         it != branchingInstructions.end();
         it++)
    {
      std::string label = (*it)->getLabelDestiny();
      LabelList::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if (labelIt != labels.end())
      {
        (*it)->setBranchDestiny(*labelIt->getDestiny());
        (*it)->setImmediateValue(labelIt->getDestiny()->getAddress());
      }
    }
    
    // At last we move the pointers to the cloned patterns
    for (it = instructions.begin();
         it != instructions.end();
         it++)
    { 
        const IPBIWPattern* pattern = (*it)->getPattern();
        PBIWPatternList::iterator patternIt = std::find_if(patterns.begin(), patterns.end(), FindPattern(pattern));
      
      if (patternIt != patterns.end())
        (*it)->pointToPattern(**patternIt);
        
    }
  }
  
    void 
  BaseOptimizer::printStatistics(IPBIWPrinter& printer, int originalInstructionsCount, int encodedPatterns, int encodedInstructions)
  {
    unsigned int instructionsBytes = instructions.size() * 8;
    unsigned int patternsBytes = patterns.size() * 12;
    
    printer.getOutputStream()
      << "Optimizer Summary: \n\n"
      << "Instruction count = " << instructions.size() 
      << " ( " << instructionsBytes <<" bytes )" << std::endl
      
      << "Pattern count = " << patterns.size()
      << " ( " << patternsBytes <<" bytes )" << std::endl
      
      << "Reuse ratio = " 
      << (instructions.size() / (double)patterns.size()) << std::endl
      
      << "Total = " 
      << patternsBytes + instructionsBytes <<" bytes" << std::endl
      
      << "----" << std::endl
      << "PBIW Encode Summary: \n\n"
      
      << "Encoded Pattern count = " << encodedPatterns
      << " ( " << encodedPatterns * 12 << " bytes )" << std::endl
            
      << "Encoded Instructions count = " << encodedInstructions
      << " ( " << encodedInstructions * 8 << " bytes )" << std::endl
            
      << "Reuse ratio = " 
      << (encodedInstructions / (double)encodedPatterns) << std::endl
            
      << "Total = " << (encodedPatterns * 12) + (encodedInstructions * 8) << " bytes" << std::endl
      << "----" << std::endl
            
      << "rVex Summary: \n\n"
      << "Original Instructions count = " << originalInstructionsCount
      << " ( " << originalInstructionsCount * 16 <<" bytes )" << std::endl
            
      << "----" << std::endl 
            
      << "Compressions Rates: \n\n"
      << "Compression ratio (Join/PBIW) = " 
      << (((instructions.size() * 8) + (patterns.size() * 12)) / (double)((encodedInstructions * 8) + (encodedPatterns * 12))) * 100.0 << " %" << std::endl
            
      << "Compression ratio (Join/rVex) = " 
      << (((instructions.size() * 8) + (patterns.size() * 12)) / (double)(originalInstructionsCount * 16)) * 100.0 << " %" << std::endl
    
      << "Compression ratio (PBIW/rVex) = " 
      << (((encodedInstructions * 8) + (encodedPatterns * 12)) / (double)(originalInstructionsCount * 16)) * 100.0 << " %" << std::endl
    
      << "----" << std::endl;
  }
  
  void 
  BaseOptimizer::printInstructions(IPBIWPrinter& instructionPrinter)
  {
    PBIWInstructionList::const_iterator instructionIt;
    
    instructionPrinter.printInstructionsHeader();
    
    for (instructionIt = instructions.begin();
         instructionIt != instructions.end();
         instructionIt++)
    {
      (*instructionIt)->print(instructionPrinter);
    }
    
    instructionPrinter.printInstructionsFooter(instructions.size());
  }
  
  void 
  BaseOptimizer::printPatterns(IPBIWPrinter& patternPrinter)
  {
    PBIWPatternList::const_iterator patternIt;
    
    patternPrinter.printPatternsHeader();
    
    for (patternIt = patterns.begin();
         patternIt != patterns.end();
         patternIt++)
    {
      (*patternIt)->print(patternPrinter);
    }
    
    patternPrinter.printPatternsFooter(patterns.size());
  }
}
