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

