/* 
 * File:   BaseOptimizer.cpp
 * Author: helix
 * 
 * Created on December 22, 2011, 3:37 PM
 */

#include "BaseOptimizer.h"
#include "Interfaces/IPBIWInstruction.h"
#include "algorithm"

namespace PBIW
{

  BaseOptimizer::BaseOptimizer()
  {
    // TODO
  }

  BaseOptimizer::BaseOptimizer(const BaseOptimizer& orig)
  {
    useInstructions(orig.getInstructions());
    usePatterns(orig.getPatterns());
    useLabels(orig.getLabels());
    setupOptimizer();
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

  std::vector<ILabel*> 
  BaseOptimizer::getLabels() const
  {
    std::vector<ILabel*> labelsCopy;
    LabelList::const_iterator labelIt;
      
    for (labelIt = labels.begin();
        labelIt != labels.end();
        labelIt++)
    {
      labelsCopy.push_back(const_cast<Label*>(&*labelIt));
    }
    
    return labelsCopy;
  }
  
  void
  BaseOptimizer::useLabels(const std::vector<ILabel*>& labels) // O(1)
  {
    std::vector<ILabel*>::const_iterator it;
    
    for (it = labels.begin(); it < labels.end(); it++) // O(|labels|) = O(1)
    {
      Label label = *dynamic_cast<Label*>(*it);
      this->labels.push_back(label);
    }
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
    LabelList::iterator labelIt;
    
    for (labelIt = labels.begin();
         labelIt != labels.end();
         labelIt++)
    {
      const IPBIWInstruction* destiny = labelIt->getDestiny();
      PBIWInstructionList::iterator foundInstructionIt = 
        std::find_if(instructions.begin(), instructions.end(), FindInstruction(destiny));
      
      if (foundInstructionIt != instructions.end())
      {
        labelIt->setDestiny(*foundInstructionIt);
        labelIt->setAbsoluteAddress((*foundInstructionIt)->getAddress());
      }
    }
    
    PBIWInstructionList::iterator instructionIt;
    
    // First, we setup the labels and instructions
    for (instructionIt = instructions.begin();
         instructionIt != instructions.end();
         instructionIt++)
    {
      if ((*instructionIt)->getLabel() == NULL)
        continue;
      
      std::string label = (*instructionIt)->getLabel()->getName();
      LabelList::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if (labelIt != labels.end())
        (*instructionIt)->setLabel(*labelIt);
    }
    
    // Then we setup de branching instructions
    for (instructionIt = branchingInstructions.begin();
         instructionIt != branchingInstructions.end();
         instructionIt++)
    {
      std::string label = (*instructionIt)->getLabelDestiny();
      LabelList::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));
      
      if (labelIt != labels.end())
      {
        (*instructionIt)->setBranchDestiny(*labelIt->getDestiny());
        (*instructionIt)->setImmediateValue(labelIt->getDestiny()->getAddress());
      }
    }
    
    // At last we move the pointers to the cloned patterns
    for (instructionIt = instructions.begin();
         instructionIt != instructions.end();
         instructionIt++)
    {    
      const IPBIWPattern* pattern = (*instructionIt)->getPattern();
      PBIWPatternList::iterator patternIt = std::find_if(patterns.begin(), patterns.end(), FindPattern(pattern));
      
      if (patternIt != patterns.end())
        (*instructionIt)->pointToPattern(**patternIt);
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
