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
  BaseOptimizer::print(IPBIWPrinter& printer)
  {
    PBIWInstructionList::const_iterator instructionIt;
    
    printer.printInstructionsHeader();
    
    for (instructionIt = instructions.begin();
         instructionIt != instructions.end();
         instructionIt++)
    {
      (*instructionIt)->print(printer);
    }
    
    printer.printInstructionsFooter(instructions.size());
    
    PBIWPatternList::const_iterator patternIt;
    
    printer.printPatternsHeader();
    
    for (patternIt = patterns.begin();
         patternIt != patterns.end();
         patternIt++)
    {
      (*patternIt)->print(printer);
    }
    
    printer.printPatternsFooter(patterns.size());
  }
}
