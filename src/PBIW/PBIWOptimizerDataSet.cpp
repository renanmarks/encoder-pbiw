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
    
    PBIWOptimizerDataSet::PBIWOptimizerDataSet() {   
    }

    PBIWOptimizerDataSet::PBIWOptimizerDataSet(const PBIWOptimizerDataSet& orig) {
    }

    PBIWOptimizerDataSet::~PBIWOptimizerDataSet() {
    }
    
    void
    PBIWOptimizerDataSet::minimumPatterns()
    {
        
        Optimizers::iterator it1;
        Patterns::iterator it2;
        Patterns::const_iterator it3;
        Patterns patterns;
        VectorPatterns tempPatterns;
        
        for(it1 = optimizers.begin(); it1 < optimizers.end(); it1++)
        {
            tempPatterns = it1->getPatterns();
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
    PBIWOptimizerDataSet::setOptimizers(const PBIWOptimizerJoinPatterns& optimizer)
    {
        optimizers.push_back(optimizer);
    }
    
    void 
    PBIWOptimizerDataSet::printPatterns(IPBIWPrinter& printer) const
    {
        Patterns::const_iterator patternIt;
        Optimizers::const_iterator optIt;
        int i = 0;
        int total = 0;

        printer.printPatternsHeader();

        for (patternIt = uniquePatterns.begin();
                patternIt != uniquePatterns.end();
                patternIt++)
        {
            (*patternIt)->print(printer);
        }

        printer.printPatternsFooter(uniquePatterns.size());
        
        std::cout << std::endl;

        for(optIt = optimizers.begin(); optIt != optimizers.end(); optIt++)
        {
            std::cout << "Program " << i++ << ": " << optIt->getPatterns().size() << " patterns " << std::endl;
            total += optIt->getPatterns().size();
        }
        
        std::cout << "\n\n-------- Results: Patterns Minimum Set ---------\n" << std::endl;

        std::cout << "Programs: " << optimizers.size() << std::endl;
        std::cout << "Patterns: " << total << std::endl;
        std::cout << "Unique Patterns: " << uniquePatterns.size() << std::endl;
        std::cout << "Reduction Patters: " << total - uniquePatterns.size() << std::endl;
        std::cout << "Compression Rate: " << uniquePatterns.size()/(double)total*100 << " %" << std::endl;
        std::cout << "\n---------- End Patterns Minimum Set -----------" << std::endl;
        std::cout << std::endl;
        
        
    }

}