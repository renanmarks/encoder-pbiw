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
        
//        typedef struct annulBit{
//            bool modified;
//            bool original[4];
//            bool current[4];
//            int addressPattern;
//        } AnnulBit;
        
        // To control patterns with one and/or three operations
        enum {
            CTRL = 0, MEM, MUL, ALU
        };
       
        // To control patterns with two operations
        enum {
            MUL_MUL = 0, CTRL_MUL, MEM_MUL, CTRL_MEM, CTRL_ALU, MEM_ALU, MUL_ALU, ALU_ALU
        };
        
        PBIWOptimizerJoinPatterns();
        PBIWOptimizerJoinPatterns(const PBIWOptimizerJoinPatterns& orig);
        virtual ~PBIWOptimizerJoinPatterns();
        
        virtual void printDeque(std::deque<std::deque<int> >* opDeque);
        
        virtual void preprocessPatterns();
        
        virtual void processJoinPatterns();
        
        virtual void joinPatterns(IPBIWPattern* pattern1, IPBIWPattern* pattern2);
        
        virtual void joiningPatterns(IPBIWPattern* pattern1, IPBIWPattern* pattern2);
        
        virtual void updateAnnulBits(IPBIWPattern* pattern, int index, bool bit);
        
        virtual void updateAddressInstruction(IPBIWPattern* pattern1, IPBIWPattern* pattern2);
        
        virtual void getPatternsToJoin(int index1, int index2);
        
        virtual void getPatternsToJoinOneTwo(int index);
        
        virtual void updateInstructions(IPBIWPattern* pattern1, IPBIWPattern* pattern2,
                                        std::deque<bool>* annulBitsOps1, std::deque<bool>* annulBitsOps2);
        
        virtual void addTempOperation(IOperation* operation);
        
        virtual void run();
    
        typedef std::vector<IPBIWPattern*> AllPatterns;
        typedef std::deque<IPBIWInstruction*> AllInstructions;
        typedef std::vector<IOperation*> AllOperations;
        typedef std::deque<std::deque<int> > BaseDeque;
        typedef std::deque<int> InnerDeque;        
        typedef std::deque<bool> AnnulationBits;
//        typedef std::deque<AnnulBit> AnnulationBits2;
                
        
    private:
        std::deque<std::deque<int> > oneOperation;
        std::deque<std::deque<int> > twoOperation;
        std::deque<std::deque<int> > threeOperation;
        AllOperations tempOps;
//        AnnulationBits2 annulBits;
        
        virtual int countTrueBits(AnnulationBits index);
        
//        AllPatterns patterns;
//        AllInstructions instructions;
    };

}

#endif	/* PBIWOPTIMIZERJOINPATTERNS_H */

