/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/* 
 * File:   BaseOptimizer.cpp
 * Author: helix
 * 
 * Created on December 22, 2011, 3:37 PM
 */


#include "Interfaces/IPBIWInstruction.h"
#include <algorithm>
#include "PBIWOptimizerJoinPatterns.h"
#include "Interfaces/IPBIW.h"

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

  void 
  BaseOptimizer::useContext(const IPBIW& context)
  {
    this->contextPBIW = &context;
    
    this->useInstructions(context.getInstructions());
    this->usePatterns(context.getPatterns());
    this->useLabels(context.getLabels());
    this->setupOptimizer();
  }
  
  void
  BaseOptimizer::useLabels(const std::deque<ILabel*>& labels) // O(1)
  {
    std::deque<ILabel*>::const_iterator it;
    
    for (it = labels.begin(); it < labels.end(); it++) // O(|labels|) = O(1)
    {
      //Label label = *dynamic_cast<Label*>(*it);
      this->labels.push_back((*it)->clone());
    }
  }

  void
  BaseOptimizer::useInstructions(const std::deque<IPBIWInstruction*>& instructions) // O(|instructions|)
  {
    std::deque<IPBIWInstruction*>::const_iterator it;
    
    for (it = instructions.begin(); it < instructions.end(); it++)
    {
      IPBIWInstruction* clonedInstruction = (*it)->clone();
      
      this->instructions.push_back(clonedInstruction);
      
      if (clonedInstruction->hasControlOperationWithLabelDestiny())
        branchingInstructions.push_back(clonedInstruction);
    }
  }

  void
  BaseOptimizer::usePatterns(const std::deque<IPBIWPattern*>& patterns) // O(|patterns|)
  {
    std::deque<IPBIWPattern*>::const_iterator it;
    
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
      const IPBIWInstruction* destiny = (*labelIt)->getDestiny();
      PBIWInstructionList::iterator foundInstructionIt = 
        std::find_if(instructions.begin(), instructions.end(), FindInstruction(destiny));
      
      if (foundInstructionIt != instructions.end())
      {
        (*labelIt)->setDestiny(*foundInstructionIt);
        (*labelIt)->setAbsoluteAddress((*foundInstructionIt)->getAddress());
      }
    }
    
    PBIWInstructionList::iterator instructionIt;
    
    // First, we setup the labels and instructions
    for (instructionIt = instructions.begin();
         instructionIt != instructions.end();
         instructionIt++)
    {
      std::deque<PBIW::Interfaces::ILabel*> originalLabels = (*instructionIt)->getLabels();
      
      if (originalLabels.size() == 0)
        continue;
      
      std::deque<PBIW::Interfaces::ILabel*>::const_iterator it;
      
      for(it = originalLabels.begin(); it != originalLabels.end(); it++)
      {
        std::string label = (*it)->getName();
        LabelList::iterator labelIt = std::find_if(labels.begin(), labels.end(), FindLabel(label));

        if (labelIt != labels.end())
          (*instructionIt)->setLabel(*labelIt);
      }
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
        (*instructionIt)->setBranchDestiny(*(*labelIt)->getDestiny());
        
        // This MUST be done (if necessary) when the setBranchDestiny() is called!
        //(*instructionIt)->setImmediateValue((*labelIt)->getDestiny()->getAddress());
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
  BaseOptimizer::printStatistics(IPBIWPrinter& printer)
  {
    unsigned int originalInstructionsCount = contextPBIW->getOriginalInstructionCount();
    unsigned int originalEncodedInstructionsCount = contextPBIW->getInstructions().size();
    unsigned int originalEncodedPatternsCount = contextPBIW->getPatterns().size();
    
    unsigned int instructionsBytes = instructions.size() * 8;
    unsigned int patternsBytes = patterns.size() * 12;
    
    printer.getOutputStream()
      << "Optimizer Summary: \n\n"
      << "Pattern count = " << patterns.size()
      << " ( " << patternsBytes <<" bytes )" << std::endl
            
      << "Instruction count = " << instructions.size() 
      << " ( " << instructionsBytes <<" bytes )" << std::endl
      
      << "Reuse ratio = " 
      << (instructions.size() / (double)patterns.size()) << std::endl
      
      << "Total = " 
      << patternsBytes + instructionsBytes <<" bytes" << std::endl
      
      << "----" << std::endl
      << "PBIW Encode Summary: \n\n"
      
      << "Encoded Pattern count = " << originalEncodedPatternsCount
      << " ( " << originalEncodedPatternsCount * 12 << " bytes )" << std::endl
            
      << "Encoded Instructions count = " << originalEncodedInstructionsCount
      << " ( " << originalEncodedInstructionsCount * 8 << " bytes )" << std::endl
            
      << "Reuse ratio = " 
      << (originalEncodedInstructionsCount / (double)originalEncodedPatternsCount) << std::endl
            
      << "Total = " << (originalEncodedPatternsCount * 12) + (originalEncodedInstructionsCount * 8) << " bytes" << std::endl
      << "----" << std::endl
            
      << "rVex Summary: \n\n"
      << "Original Instructions count = " << originalInstructionsCount
      << " ( " << originalInstructionsCount * 16 <<" bytes )" << std::endl
            
      << "----" << std::endl 
            
      << "Compressions Rates: \n\n"
      << "Compression ratio (Join/PBIW) = " 
      << (((instructions.size() * 8) + (patterns.size() * 12)) / (double)((originalEncodedInstructionsCount * 8) + (originalEncodedPatternsCount * 12))) * 100.0 << " %" << std::endl
            
      << "Compression ratio (Join/rVex) = " 
      << (((instructions.size() * 8) + (patterns.size() * 12)) / (double)(originalInstructionsCount * 16)) * 100.0 << " %" << std::endl
    
      << "Compression ratio (PBIW/rVex) = " 
      << (((originalEncodedInstructionsCount * 8) + (originalEncodedPatternsCount * 12)) / (double)(originalInstructionsCount * 16)) * 100.0 << " %" << std::endl
    
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
