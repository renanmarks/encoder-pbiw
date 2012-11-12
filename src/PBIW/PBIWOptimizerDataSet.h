/* 
 * File:   PBIWOptimizerDataSet.h
 * Author: renato
 *
 * Created on May 11, 2012, 5:20 PM
 */

#ifndef PBIWPATTERNSETOPTIMIZER_H
#define	PBIWPATTERNSETOPTIMIZER_H

#include <deque>
#include <iostream>
#include "PBIWOptimizerJoinPatterns.h"
#include "Interfaces/IPBIWPrinter.h"
#include "Interfaces/IPBIWSet.h"

namespace PBIW
{
    using namespace Interfaces;
    
    class PBIWPatternSetOptimizer {
    public:
        PBIWPatternSetOptimizer(unsigned int, unsigned int, unsigned int);
        virtual ~PBIWPatternSetOptimizer();
        
        typedef std::deque<IPBIWPattern*> Patterns;
        typedef std::deque<Patterns> PatternsSets;
        
        virtual void minimumPatterns();
        
        virtual void printPatterns(IPBIWPrinter&) const;
        virtual void printStatistics() const;
        
        virtual PatternsSets getPBIWSets() const
        { return sets; }
        
        virtual void addPatternSet(const std::deque<IPBIWPattern*>&, unsigned int, unsigned int);
        
    private:
        PBIWPatternSetOptimizer(const PBIWPatternSetOptimizer&);
      
        std::deque<unsigned int> instructionsPerProgram;
        std::deque<unsigned int> originalInstructionsPerProgram;
        PatternsSets sets;
        Patterns uniquePatterns;
        const unsigned int instructionByteSize;
        const unsigned int patternByteSize;
        const unsigned int originalInstructionByteSize;
    };
}

#endif	/* PBIWPATTERNSETOPTIMIZER_H */

