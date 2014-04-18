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
 * File:   PBIWOptimizerJoinPatterns.h
 * Author: renato
 *
 * Created on April 13, 2012, 1:54 AM
 */

#ifndef PBIWOPTIMIZERJOINPATTERNS_H
#define	PBIWOPTIMIZERJOINPATTERNS_H

#include <deque>
#include <vector>
#include "Interfaces/IPBIWFactory.h"
#include "BaseOptimizer.h"

namespace PBIW
{
    using namespace Interfaces;
    
    class PBIWOptimizerJoinPatterns : public BaseOptimizer
    {
    public:
        
        // To control patterns with one and/or three operations
        enum {
            CTRL = 0, MEM, MUL, ALU
        };
       
        // To control patterns with two operations
        enum {
            MUL_MUL = 0, CTRL_MUL, MEM_MUL, CTRL_MEM, CTRL_ALU, MEM_ALU, MUL_ALU, ALU_ALU
        };
        
        virtual void printDeque(std::deque<std::deque<IPBIWPattern*> >& opDeque);
        
        virtual void preprocessPatterns();
        
        virtual void processJoinPatterns(IPBIWFactory& factory);
        
        virtual void updatePatterns();
        
        virtual void updateAddressInstruction(IPBIWPattern* pattern1, IPBIWPattern* pattern2);
        
        virtual void getPatternsToJoin(int index1, int index2, IPBIWFactory& factory);
        
        virtual void run(IPBIWFactory& factory);
    
        typedef std::vector<IPBIWPattern*> AllPatterns;
        typedef std::deque<IPBIWInstruction*> AllInstructions;
        typedef std::deque<IOperation*> AllOperations;
        typedef std::deque<std::deque<IPBIWPattern*> > BaseDeque;
        typedef std::deque<IPBIWPattern*> InnerDeque;        
                
        
    private:
        std::deque<std::deque<IPBIWPattern*> > oneOperation;
        std::deque<std::deque<IPBIWPattern*> > twoOperation;
        std::deque<std::deque<IPBIWPattern*> > threeOperation;
        PBIWPatternList joinedPattern;
    };

}

#endif	/* PBIWOPTIMIZERJOINPATTERNS_H */

