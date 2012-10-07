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
    
//    PBIWOptimizerDataSet::PBIWOptimizerDataSet() {   
//    }
//
//    PBIWOptimizerDataSet::PBIWOptimizerDataSet(const PBIWOptimizerDataSet& orig) {
//    }
//
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
    PBIWPatternSetOptimizer::addPatternSet(const std::deque<IPBIWPattern*>& set)
    {
        std::deque<IPBIWPattern*>::const_iterator it;
        std::deque<IPBIWPattern*> clonedPatterns;
        
        for (it = set.begin(); it != set.end(); it++)
        {
          clonedPatterns.push_back( (*it)->clone() );
        }
      
        sets.push_back(clonedPatterns);
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
      PatternsSets::const_iterator optIt;
      int i = 0;
      int total = 0;
      
      std::cout << "-------- Results: Patterns Minimum Set ---------" << std::endl;
      std::cout << "Programs: " << sets.size() << std::endl;
      
      for(optIt = sets.begin(); optIt != sets.end(); optIt++)
      {
          std::cout << "Program " << i++ << ": " << optIt->size() << " patterns " << std::endl;
          total += optIt->size();
      }
      
      std::cout << "Patterns: " << total << std::endl;
      std::cout << "Unique Patterns: " << uniquePatterns.size() << std::endl;
      std::cout << "Reduction Patters: " << total - uniquePatterns.size() << std::endl;
      std::cout << "Compression Rate: " << uniquePatterns.size()/(double)total*100 << " %" << std::endl;
      std::cout << "---------- End Patterns Minimum Set -----------" << std::endl;
      std::cout << std::endl;
    }

}