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
#include "Interfaces/IPBIWOptimizerJoinPatterns.h"
#include "BaseOptimizer.h"

namespace PBIW
{
    using namespace Interfaces;
    
    class PBIWOptimizerJoinPatterns : public BaseOptimizer
    {
    public:
        
        struct Sample{
            Sample()
            {
                annulBits.resize(4, false);
            }
            
            unsigned int addressPattern;
            std::vector<bool> annulBits;
            std::deque<IOperation*> operations;
            std::deque<IPBIWInstruction*> instructionsThatUseIt;
        };
        
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
        
        virtual void processJoinPatterns();
        
        virtual void joinPatterns(IPBIWPattern* pattern1, IPBIWPattern* pattern2);
        
        virtual void joiningPatterns(IPBIWPattern* pattern1, IPBIWPattern* pattern2);
        
        virtual void updateBits();
        
        virtual Sample& addSample(IPBIWPattern& );
        
        virtual void updateAnnulBits(IPBIWPattern* pattern, int index, bool bit);
        
        virtual void updateAddressInstruction(IPBIWPattern* pattern1, IPBIWPattern* pattern2);
        
        virtual void getPatternsToJoin(int index1, int index2);
        
        virtual void addTempOperation(IOperation* operation);
        
        virtual void run();
    
        typedef std::vector<IPBIWPattern*> AllPatterns;
        typedef std::deque<IPBIWInstruction*> AllInstructions;
        typedef std::vector<IOperation*> AllOperations;
        typedef std::deque<std::deque<IPBIWPattern*> > BaseDeque;
        typedef std::deque<IPBIWPattern*> InnerDeque;        
        typedef std::deque<bool> AnnulationBit;
        typedef std::deque<Sample> AllSamples;
                
        
    private:
        std::deque<std::deque<IPBIWPattern*> > oneOperation;
        std::deque<std::deque<IPBIWPattern*> > twoOperation;
        std::deque<std::deque<IPBIWPattern*> > threeOperation;
        
        std::deque<IPBIWPattern*> newJoinedPatterns;
        AllOperations tempOps;
        AllSamples samples;
        
        class PatternBuilder
        {
        public:
          void addOperation(IOperation&, int, IPBIWPattern*);
          void setBits(IPBIWInstruction&, IPBIWPattern&);
          IPBIWPattern* getPattern() const;
          
          struct OperationInfo 
          {
            OperationInfo()
            : operation(NULL),
              pattern(NULL),
              originalPosition(-1)
            { }
            
            IOperation* operation;
            IPBIWPattern* pattern;
            int originalPosition;
          };
        private:
          OperationInfo ctrl;
          OperationInfo mul1;
          OperationInfo mul2;
          OperationInfo mem;
        };
    };

}

#endif	/* PBIWOPTIMIZERJOINPATTERNS_H */

