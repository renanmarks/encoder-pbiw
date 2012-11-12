/* 
 * File:   PBIWOptimizerDataSet.cpp
 * Author: renato
 * 
 * Created on May 11, 2012, 5:20 PM
 */

#include "PBIWOptimizerDataSet.h"
#include "Interfaces/IPBIWPrinter.h"

namespace PBIW
{
    using namespace Interfaces;
    
    PBIWPatternSetOptimizer::PBIWPatternSetOptimizer(unsigned int _instructionByteSize, unsigned int _patternByteSize, unsigned int _originalInstructionByteSize) 
      : instructionByteSize(_instructionByteSize), patternByteSize(_patternByteSize), originalInstructionByteSize(_originalInstructionByteSize)
    {
      
    }
    
    PBIWPatternSetOptimizer::~PBIWPatternSetOptimizer() 
    {
      PatternsSets::iterator setIt;
      Patterns::iterator patternIt;

      for (setIt = sets.begin(); setIt != sets.end(); setIt++)
      {
        for (patternIt = setIt->begin(); patternIt != setIt->end(); patternIt++)
        {
          delete *patternIt;
        }
      }
    }
    
    void
    PBIWPatternSetOptimizer::minimumPatterns()
    {
        
        PatternsSets::iterator it1;
        Patterns::iterator it2;
        Patterns::const_iterator it3;
        Patterns patterns;
        Patterns tempPatterns;
        
        for(it1 = sets.begin(); it1 < sets.end(); it1++)
        {
            tempPatterns = *it1;
            patterns.assign(tempPatterns.begin(),tempPatterns.end());
            
            for(it2 = patterns.begin(); it2 < patterns.end(); it2++)
            {
                if(uniquePatterns.size() == 0)
                {
                    uniquePatterns.assign(patterns.begin(),patterns.end());
                    it2 = patterns.end();
                }
                else 
                {
                    bool notHasPattern = true;
                    for(it3 = uniquePatterns.begin(); it3 < uniquePatterns.end(); it3++)
                    {
                        if(**it3 == **it2)
                        {
                            notHasPattern = false;
                            break;
                        }
                    }

                    if(notHasPattern)
                        uniquePatterns.push_back(*it2);
                }
            }        
        }

        //printPatterns();
    }

    void
    PBIWPatternSetOptimizer::addPatternSet(const std::deque<IPBIWPattern*>& set, unsigned int instructionCount, unsigned int originalInstructionCount)
    {
        std::deque<IPBIWPattern*>::const_iterator it;
        std::deque<IPBIWPattern*> clonedPatterns;
        
        for (it = set.begin(); it != set.end(); it++)
        {
          clonedPatterns.push_back( (*it)->clone() );
        }
      
        sets.push_back(clonedPatterns);
        instructionsPerProgram.push_back(instructionCount);
        originalInstructionsPerProgram.push_back(originalInstructionCount);
    }
    
    void 
    PBIWPatternSetOptimizer::printPatterns(IPBIWPrinter& printer) const
    {
        Patterns::const_iterator patternIt;
        

        printer.printPatternsHeader();

        for (patternIt = uniquePatterns.begin();
                patternIt != uniquePatterns.end();
                patternIt++)
        {
            (*patternIt)->print(printer);
        }

        printer.printPatternsFooter(uniquePatterns.size());
    }
    
    void 
    PBIWPatternSetOptimizer::printStatistics() const
    {
      int totalPatterns = 0;
      int totalInstructions = 0;
      int totalOriginalInstructions = 0;
      
      std::cout << "-------- Results: Patterns Minimum Set ---------" << std::endl;
      std::cout << "Programs: " << sets.size() << std::endl;
      
      PatternsSets::const_iterator optIt;
      int i = 0;
      
      for(optIt = sets.begin(); optIt != sets.end(); optIt++)
      {
          std::cout << "Program " << i << ": " 
            << originalInstructionsPerProgram.at(i) << " Original Instr., " 
            << instructionsPerProgram.at(i) << " Instr., " 
            << optIt->size() << " Patterns " << std::endl;
          
          totalPatterns += optIt->size();
          totalInstructions += instructionsPerProgram.at(i);
          totalOriginalInstructions += originalInstructionsPerProgram.at(i++);
      }
      
      unsigned int instructionsSize = totalInstructions * instructionByteSize;
      unsigned int patternsSize = totalPatterns * patternByteSize;
      unsigned int originalInstructionsSize = totalOriginalInstructions * originalInstructionByteSize;
      
      std::cout << "Original Instr.:   \t" << totalOriginalInstructions << " - " << originalInstructionsSize << " bytes" << std::endl;
      std::cout << "Instructions:      \t" << totalInstructions << " - " << instructionsSize << " bytes" << std::endl;
      std::cout << "Unique Patterns:   \t" << uniquePatterns.size() << " - " << patternsSize << " bytes" << std::endl;
      std::cout << "Total size:        \t" << instructionsSize + patternsSize << " bytes" << std::endl;
      std::cout << "Compression ratio: \t" << ((instructionsSize + patternsSize) / (double)originalInstructionsSize) * 100 << " %" << std::endl << std::endl;
      
      
      std::cout << "All Patterns:      \t" << totalPatterns << " - " << patternsSize << " bytes" << std::endl;
      
      unsigned int duplicatedPatterns = totalPatterns - uniquePatterns.size();
      std::cout << "Duplicated Patters:\t " << duplicatedPatterns << " - " << duplicatedPatterns * patternByteSize << " bytes" << std::endl << std::endl;
      
      std::cout << "Patterns Reduction Rate: " << (uniquePatterns.size() / (double)totalPatterns) * 100 << " %" << std::endl;
      std::cout << "---------- End Patterns Minimum Set -----------" << std::endl;
      std::cout << std::endl;
    }

}