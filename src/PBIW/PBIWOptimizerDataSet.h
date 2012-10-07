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
//        PBIWOptimizerDataSet();
//        PBIWOptimizerDataSet(const PBIWOptimizerDataSet& orig);
        virtual ~PBIWPatternSetOptimizer();
        
        typedef std::deque<IPBIWPattern*> Patterns;
        typedef std::deque<Patterns> PatternsSets;
        
        virtual void minimumPatterns();
        
        virtual void printPatterns(IPBIWPrinter&) const;
        virtual void printStatistics() const;
        
        virtual PatternsSets getPBIWSets() const
        { return sets; }
        
        virtual void addPatternSet(const std::deque<IPBIWPattern*>& set);
        
    private:
        PatternsSets sets;
        Patterns uniquePatterns;
    };
}

#endif	/* PBIWPATTERNSETOPTIMIZER_H */

