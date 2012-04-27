/* 
 * File:   PBIWOptimizerJoinPatterns.cpp
 * Author: renato
 * 
 * Created on April 13, 2012, 1:54 AM
 */

#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <algorithm>
#include "PBIWOptimizerJoinPatterns.h"
//#include "Interfaces/IPBIWOptimizer.h"
#include "BaseOptimizer.h"
#include "Operation.h"

namespace PBIW
{
    using namespace Interfaces;
    
    const int SIZE = 4;
    
    PBIWOptimizerJoinPatterns::PBIWOptimizerJoinPatterns()
    : BaseOptimizer()
    {
    }

    PBIWOptimizerJoinPatterns::PBIWOptimizerJoinPatterns(const PBIWOptimizerJoinPatterns& orig) {
    }

    PBIWOptimizerJoinPatterns::~PBIWOptimizerJoinPatterns() {
    }
    
    void
    PBIWOptimizerJoinPatterns::printDeque(std::deque<std::deque<IPBIWPattern*> >* opDeque)
    {
        std::string type1[SIZE] = {"CTRL", "MEM", "MUL", "ALU"};
        std::string type2[8] = {"MUL_MUL", "CTRL_MUL", "MEM_MUL", "CTRL_MEM", "CTRL_ALU", "MEM_ALU", "MUL_ALU", "ALU_ALU"};
        
        for(unsigned int i = 0; i < opDeque->size(); i++)
        {
            if(opDeque->size() <= 4)
                std::cout << "Addr at " << type1[i] << ": ";
            else
                std::cout << "Addr at " << type2[i] << ": ";
            
            for(unsigned int j = 0; j < opDeque->at(i).size(); j++)
            {
                std::cout << opDeque->at(i).at(j)->getAddress() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "\n" << std::endl;
    }
    
    void
    PBIWOptimizerJoinPatterns::preprocessPatterns()
    {
        AllPatterns patterns = this->getPatterns();
        AllPatterns::iterator it;
        
        oneOperation.resize(SIZE);
        twoOperation.resize(8);
        threeOperation.resize(SIZE);
        
//        AnnulBit annulBit;
        
        int count2[3] = {0, 0, 0};
        
        // Patterns
        for(it = patterns.begin();
            it < patterns.end();
            it++)
        {
            int count = 0;
            int countALU = 0;
            bool ops[SIZE] = {0, 0, 0, 0};
            bool threeOps[SIZE] = {0, 0, 0, 0};
                        
            std::cout << "PATTERNS " << patterns.size() << std::endl;
            // Operations
            for(int i = 0; i < SIZE; i++)
            {
                std::cout << "OPCODE " << (*it)->getOperation(i)->getOpcode() << std::endl;
                if(((*it)->getOperation(i)->getOpcode() != 0) && ((*it)->getOperation(i)->getOpcode() != 31))
                {
                    if((*it)->getOperation(i)->getType() == rVex::Syllable::SyllableType::MEM)
                    {
                        ops[i] = threeOps[i] = true;
                    }
                    else if((*it)->getOperation(i)->getType() == rVex::Syllable::SyllableType::CTRL)
                    {
                        ops[i] = threeOps[i] = true;                        
                    }
                    else if((*it)->getOperation(i)->getType() == rVex::Syllable::SyllableType::MUL)
                    {
                        ops[i] = threeOps[i] = true;
                    }
                    else if((*it)->getOperation(i)->getType() == rVex::Syllable::SyllableType::ALU)
                    {
                        threeOps[ALU] = true; countALU++;
                    }
                    count++;
                    
//                    annulBit.original[i] = true;
//                    annulBit.current[i] = true;
                }
//                else
//                {
//                    annulBit.original[i] = false;
//                    annulBit.current[i] = false;
//                }               
            }
            
//            annulBit.addressPattern = (*it)->getAddress();
//            annulBit.modified = false;
//            annulBits.push_back(annulBit);
//            //std::cout << "COUNT " << count << std::endl;
            if(count == 4)
                count2[1]++;
            else if(count > 0 && count < 4)
                count2[0]++;
            else
                count2[2]++;
            
            int half1 = -1;
            int half2 = -1;
            
            switch(count)
            {
                case 1: // Has one operation
                    if(countALU)
                            oneOperation.at(ALU).push_back((*it));
                    else {
                        for(int i = 0; i < SIZE; i++)
                        {
                            if(ops[i]){
                                switch(i)
                                {
                                    case 0: oneOperation.at(CTRL).push_back((*it));
                                            break;
                                    case 1: 
                                    case 2: oneOperation.at(MUL).push_back((*it));
                                            break;
                                    case 3: oneOperation.at(MEM).push_back((*it));
                                            break;
                                }
                            }                    
                        }
                    }
                    break;
                    
                case 2:
                    if(ops[0] && (countALU == 0)) // if has a CTRL operation
                        half1 = 0;
                    
                    if(ops[3] && (countALU == 0))  // if has a MEM operation
                    { 
                        if(half1 == -1) // if is MEM_...
                            half1 = 1;
                        else            // else is ..._MEM
                            half2 = 1;
                    }
                    
                    if(ops[1] && (countALU == 0)) // if has MUL operation in the position one
                    {
                        if(half1 == -1) // if is MUL_...
                            half1 = 2;
                        else            // else is ..._MUL
                            half2 = 2;
                    }
                    
                    if(ops[2] && (countALU == 0))  // if has MUL operation in the position two
                    {
                        if(half1 == -1) // if is MUL_...
                            half1 = 2;
                        else            // else is ..._MUL
                            half2 = 2;
                    }
                    
                    if(half1 == -1)  // if half1 is -1 then is ALU operation
                        half1 = 3;
                    
                    if(half2 == -1)  // if half2 is -1 then is ALU operation
                        half2 = 3;
                    
                    
                    switch(half1)
                    {
                        // CTRL = 0, MEM, MUL, ALU
                        // MUL_MUL = 0, CTRL_MUL, MEM_MUL, CTRL_MEM, CTRL_ALU, MEM_ALU, MUL_ALU, ALU_ALU
                        
                        case 0: //CTRL
                            if(half2 == MEM) // CTRL_MEM
                                twoOperation.at(CTRL_MEM).push_back((*it));
                            
                            else if(half2 == MUL) // CTRL_MUL
                                twoOperation.at(CTRL_MUL).push_back((*it));
                            
                            else if(half2 == ALU) // CTRL_ALU
                                twoOperation.at(CTRL_ALU).push_back((*it));
                            break;
                            
                        case 1: // MEM
                            if(half2 == MUL) // MEM_MUL
                                twoOperation.at(MEM_MUL).push_back((*it));
                            
                            else if(half2 == ALU) // MEM_ALU
                                twoOperation.at(MEM_ALU).push_back((*it));
                            break;
                            
                        case 2: // MUL
                            if(half2 == MUL) // MUL_MUL
                                twoOperation.at(MUL_MUL).push_back((*it));
                            
                            else if(half2 == ALU) // MUL_ALU
                                twoOperation.at(MUL_ALU).push_back((*it));
                            break;
                            
                        case 3: // ALU
                            twoOperation.at(ALU_ALU).push_back((*it));
                            break;
                    }
                    break;
                    
                case 3:
                    if(countALU == 3)
                            threeOperation.at(ALU).push_back((*it));
                    else 
                    {
                        for(int i = 0; i < SIZE; i++)
                        {
                            if(!threeOps[i])
                            {
                                switch(i)
                                {
                                    case 0: threeOperation.at(CTRL).push_back((*it));
                                            break;
                                    case 1: 
                                    case 2: threeOperation.at(MUL).push_back((*it));
                                            break;
                                    case 3: threeOperation.at(MEM).push_back((*it));
                                            break;
                                    
                                }
                                break;
                            }                    
                        }
                    }
                    break;
            }
            
        }
        
        printDeque(&oneOperation);
        printDeque(&twoOperation);
        printDeque(&threeOperation);    
        
        std::cout << "COUNT 1..3 ops: " << count2[0] << std::endl;
        std::cout << "COUNT 4 ops: " << count2[1] << std::endl;
        std::cout << "COUNT others: " << count2[2] << std::endl;
        std::cout << "Totals: " << (count2[0] + count2[1] + count2[2]) << std::endl;
    }
    
    void
    PBIWOptimizerJoinPatterns::processJoinPatterns()
    {
      
        preprocessPatterns();
        
        //AllPatterns patterns = this->getPatterns();
            std::cout << "HHHHHH<< " << patterns.at(0)->getOperation(0)->getOpcode() << std::endl;
                std::cout << "HHHHHH<< " << patterns.at(0)->getOperation(0)->getType() << std::endl;
        //InnerDeque* general;
        BaseDeque::iterator itBase1, itBase2;
        InnerDeque::iterator itInner1, itInner2;
        
        // CTRL = 0, MEM = 1, MUL = 2, ADD = 3
        for(itBase1 = threeOperation.begin(), itBase2 = oneOperation.begin();
            (itBase1 < threeOperation.end()-1) && (itBase2 < oneOperation.end()-1);
            itBase1++, itBase2++)
        {
            for(itInner1 = (*itBase1).begin(), itInner2 = (*itBase2).begin();
                (itInner1 < (*itBase1).end()) && (itInner2 < (*itBase2).end());
                itInner1++, itInner2++)
            {
//                std::cout << "ADD Patt: " << patterns.at(*itInner1)->getAddress() << " " << *itInner2._M_cur << std::endl;
//                std::cout << "Addr at " << (*itInner1) << " : " << (*itInner2) << " " << std::endl;
                
                IPBIWPattern* first = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                IPBIWPattern* second = *(std::find(patterns.begin(), patterns.end(), *itInner2));
                
                
                joinPatterns(first, second);
                
                (*itBase1).erase((*itBase1).begin());
                (*itBase2).erase((*itBase2).begin());
            }            
        }
        
        int i = 0;
        // MUL_MUL = 0, CTRL_MUL, MEM_MUL, CTRL_MEM, CTRL_ALU, MEM_ALU, MUL_ALU, ALU_ALU
        for(itBase1 = twoOperation.begin();
            itBase1 < twoOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end();
                itInner1++)
            {
                if(!(*itBase1).empty())
                {                
                    switch(i)
                    {
                        case MUL_MUL:
                            if(!twoOperation.at(CTRL_MEM).empty())
                            getPatternsToJoin(MUL_MUL, CTRL_MEM); 

                            if(!twoOperation.at(CTRL_ALU).empty())
                            getPatternsToJoin(MUL_MUL, CTRL_ALU);

                            if(!twoOperation.at(MEM_ALU).empty())
                                getPatternsToJoin(MUL_MUL, MEM_ALU);

                            break;

                        case CTRL_MUL: // ok
                            if(!twoOperation.at(MEM_MUL).empty())
                                getPatternsToJoin(CTRL_MUL, MEM_MUL);

                            if(!twoOperation.at(MEM_ALU).empty())
                                getPatternsToJoin(CTRL_MUL, MEM_ALU);

                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(CTRL_MUL, MUL_ALU);

                            break;

                        case MEM_MUL: // ok
    //                        if(!twoOperation.at(CTRL_MUL).empty()) //*
    //                            getPatternsToJoin(MEM_MUL, CTRL_MUL);

                            if(!twoOperation.at(CTRL_ALU).empty()) //*
                                getPatternsToJoin(MEM_MUL, CTRL_ALU);

                            if(!twoOperation.at(MUL_ALU).empty()) //
                                getPatternsToJoin(MEM_MUL, MUL_ALU);

                            break;

                        case CTRL_MEM: // 0k
    //                        if(!twoOperation.at(MUL_MUL).empty())
    //                            getPatternsToJoin(CTRL_MEM, MUL_MUL);

                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(CTRL_MEM, MUL_ALU);

                            break;

                        case CTRL_ALU: 
    //                        if(!twoOperation.at(MEM_MUL).empty())
    //                            getPatternsToJoin(CTRL_ALU, MEM_MUL);

    //                        if(!twoOperation.at(MUL_MUL).empty())
    //                            getPatternsToJoin(CTRL_ALU, MUL_MUL);

                            if(!twoOperation.at(MEM_ALU).empty())
                                getPatternsToJoin(CTRL_ALU, MEM_ALU);

                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(CTRL_ALU, MUL_ALU);

                            break;

                        case MEM_ALU: 
    //                        if(!twoOperation.at(CTRL_MUL).empty())
    //                            getPatternsToJoin(MEM_ALU, CTRL_MUL);
    //                            
    //                        if(!twoOperation.at(CTRL_ALU).empty())
    //                            getPatternsToJoin(MEM_ALU, CTRL_ALU);
    //                            
    //                        if(!twoOperation.at(MUL_MUL).empty())
    //                            getPatternsToJoin(MEM_ALU, MUL_MUL);

                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(MEM_ALU, MUL_ALU);

                            break;

    //                    case MUL_ALU: 
    //                        if(!twoOperation.at(CTRL_MEM).empty())
    //                            getPatternsToJoin(MUL_ALU, CTRL_MEM);
    //                            
    //                        if(!twoOperation.at(CTRL_MUL).empty())
    //                            getPatternsToJoin(MUL_ALU, CTRL_MUL);
    //                        
    //                        if(!twoOperation.at(CTRL_ALU).empty())
    //                            getPatternsToJoin(MUL_ALU, CTRL_ALU);
    //                            
    //                        if(!twoOperation.at(MEM_MUL).empty())
    //                            getPatternsToJoin(MUL_ALU, MEM_MUL);
    //                            
    //                        if(!twoOperation.at(MEM_ALU).empty())
    //                            getPatternsToJoin(MUL_ALU, MEM_ALU);
    //                            
    //                        break;

                        case ALU_ALU:
                            int j = 0;
                            for(itBase2 = twoOperation.begin(); 
                                itBase2 < twoOperation.end();
                                itBase2++)
                            {
                                for(itInner2 = (*itBase1).begin();
                                    itInner2 < (*itBase1).end();
                                    itInner2++)
                                {
                                    if((!(*itBase2).empty()) && (!twoOperation.at(ALU_ALU).empty()) && (j != 7))
                                    {
                                        getPatternsToJoin(j, ALU_ALU);
                                    }                                    
//                                    else
//                                    {
//                                        if((!(*itBase2).empty()) && (!twoOperation.at(ALU_ALU).size() > 1) && (j != 7))
//                                        {
//                                            getPatternsToJoin(j, ALU_ALU);
//                                        }
//                                    }
                                }
                                j++;
                            }

                            break;
                    }        
                }
            }
            
            i++;
        }
        
        // CTRL = 0, MEM, MUL, ALU
        int types[5] = {0, 2, 2, 1, 3};
        int syllableType[4] = {4, 2, 2, 3};
        int count;
        IPBIWPattern* tempPattern;
        
        for(itBase1 = twoOperation.begin();
            itBase1 < twoOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end();
                itInner1++)
            {
                tempPattern = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                count = 0;
                                                
                for(int k = 0; (k < 4) && (count <= 2); k++)
                {
                    if(((tempPattern->getOperation(k)->getType() != syllableType[k]) || 
                        (tempPattern->getOperation(k)->getOpcode() == 0)) &&
                        (!oneOperation.at(types[k]).empty()))
                    {
                         joinPatterns(tempPattern, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[k]).front())));
                         oneOperation.at(types[k]).erase(oneOperation.at(types[k]).begin());
                         count++;
                    }
                    else if(((tempPattern->getOperation(k)->getType() != syllableType[k]) || 
                            (tempPattern->getOperation(k)->getOpcode() == 0)) &&
                            (!(oneOperation.at(types[4]).empty())) && (count <= 2))
                    {
                        joinPatterns(tempPattern, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())));
                        
                        std::cout << "TMANHO " << oneOperation.at(types[4]).size() << std::endl;
                            
                        oneOperation.at(types[4]).erase(oneOperation.at(types[4]).begin());
                        std::cout << "TMANHO " << oneOperation.at(types[4]).size() << std::endl;
                        count++;
                    }
                }
            }                
        }
        itBase1 = oneOperation.begin()+3;
        itInner1 = (*itBase1).begin();
        
        std::cout << "HHHHHH " << (*itInner1) << std::endl;
//        for(itBase1 = threeOperation.begin()+3;
//            itBase1 < threeOperation.end();
//            itBase1++)
//        {
//            for(itBase2 = oneOperation.begin();
//                itBase2 < oneOperation.end();
//                itBase2++)
//            {
//                for(itInner1 = (*itBase1).begin(), itInner2 = (*itBase2).begin();
//                    (itInner1 < (*itBase1).end()) && (itInner2 < (*itBase2).end());
//                    itInner1++, itInner2++)
//                {
//                    std::cout << "ADD Patt: " << patterns.at(*itInner1)->getAddress() << " " << *itInner2._M_cur << std::endl;
//                    std::cout << "Addr at " << (*itInner1) << " : " << (*itInner2) << " " << std::endl;
//                    joinPatterns(patterns.at(*itInner1), patterns.at(*itInner2));
//                    threeOperation.at(3).erase(threeOperation.at(3).begin());
//                    (*itBase2).erase((*itBase2).begin());
//                } 
//            }
//        }
        IPBIWPattern* tempPattern1;
        i = 0;
        
        for(itBase1 = threeOperation.begin();
            itBase1 < threeOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end();
                itInner1++)
            {
                tempPattern1 = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                threeOperation.at(i).erase(itInner1);
                
                for(int j = 0; j < 4; j++)
                {
                    if(tempPattern1->getOperation(j)->getType() != syllableType[j])
                    {
                        if((!oneOperation.at(types[j]).empty()) && ((syllableType[j] == j) ||
                            (tempPattern1->getOperation(j)->getOpcode() == 0)))
                        {
                            joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front())));
                            oneOperation.at(types[j]).erase(oneOperation.at(types[j]).begin());
                        }
                        else if(!oneOperation.at(types[4]).empty())
                        {
                            joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())));
                            oneOperation.at(types[4]).erase(oneOperation.at(types[4]).begin());
                        }
                    }
                }
            }
            i++;
        }
        
        i = 0;
        
        // CTRL = 0, MEM = 1, MUL = 2, ADD = 3
        for(itBase1 = oneOperation.begin();
            itBase1 < oneOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end();
                itInner1++)
            {
                tempPattern1 = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                oneOperation.at(i).erase(itInner1);
                
                for(int j = 0; j < 4; j++)
                {
                    if(tempPattern1->getOperation(j)->getType() != syllableType[j])
                    {
                        if((!oneOperation.at(types[j]).empty()) && ((syllableType[j]) ||
                            (tempPattern1->getOperation(j)->getOpcode() == 0)))
                        {
                            joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front())));
                            oneOperation.at(types[j]).erase(oneOperation.at(types[j]).begin());
                        }
                        else if(!oneOperation.at(types[4]).empty())
                        {
                            joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())));
                            oneOperation.at(types[4]).erase(oneOperation.at(types[4]).begin());
                        }
                    }
                }
            }
            i++;
        }                                
    }
    
    void
    PBIWOptimizerJoinPatterns::joinPatterns(IPBIWPattern* pattern1, IPBIWPattern* pattern2)
    {
        if(pattern1->getInstructionsThatUseIt().size() > pattern2->getInstructionsThatUseIt().size())
            joiningPatterns(pattern1, pattern2);
        
        else if(pattern1->getInstructionsThatUseIt().size() < pattern2->getInstructionsThatUseIt().size())
            joiningPatterns(pattern2, pattern1);
        
        else
        {
            if(pattern1->getOperationCount() >= pattern2->getOperationCount())
                joiningPatterns(pattern1, pattern2);
            
            else
                joiningPatterns(pattern2, pattern1);
        }        
    }
    
    void
    PBIWOptimizerJoinPatterns::joiningPatterns(IPBIWPattern* pattern1, IPBIWPattern* pattern2)
    {
        AnnulationBit annulBitsOps1;
        AnnulationBit annulBitsOps2;
        annulBitsOps1.resize(4);
        annulBitsOps2.resize(4);
//        int index1 = pattern1->getAddress();
//        int index2 = pattern2->getAddress();
        Sample sampleP1 = addSample(*pattern1);
        Sample sampleP2 = addSample(*pattern2);
        
        std::cout << "SAMPLE : " << samples.at(0).annulBits.size() << std::endl;
        
//        std::cout << "OP : " << samples.at(0).operations.at(3) << std::endl;
        std::cout << "OP : " << samples.at(0).annulBits.at(1) << std::endl;
        std::cout << "OP : " << samples.at(0).annulBits.at(2) << std::endl;
        std::cout << "OP : " << samples.at(0).annulBits.at(3) << std::endl;
        
        int syllableType[4] = {4, 2, 2, 3}; // Based on the rVex syllables types: ALU = 1, MUL, MEM, CTRL
        std::cout << "ADDR : " << pattern1->getAddress() << std::endl;
        std::cout << "ADDR : " << pattern2->getAddress() << std::endl;
        for(int i = 0; i < 4; i++)
        {
            if(pattern1->getOperation(i)->getOpcode() != 0)
            {
                std::cout << "TYPE1 : " << pattern1->getOperation(i)->getType() << " "<<pattern1->getOperation(i)->getOpcode() << std::endl;
                std::cout << "TYPE2 : " << pattern2->getOperation(i)->getType() << " "<<pattern2->getOperation(i)->getOpcode() << std::endl;
                
                annulBitsOps1[i] = 1;
                
                if((pattern1->getOperation(i)->getType() != syllableType[i]))
                {
                    if((pattern2->getOperation(i)->getOpcode() != 0))
                    {
                        annulBitsOps2[i] = 1;
                        
                        if(pattern2->getOperation(i)->getType() != syllableType[i])
                        {
                            addTempOperation(pattern2->getOperation(i));
                            annulBitsOps2[i] = 0;
                            sampleP2.annulBits.at(i) = 0;
//                            annulBits.at(index2).current[i] = 0;
//                            
//                            if(!annulBits.at(index2).modified)
//                                annulBits.at(index2).original[i] = 0;
                            
                            updateAnnulBits(pattern2, i, 0);
                        }
                        else
                        {
                            addTempOperation(pattern1->getOperation(i));
                            pattern1->setOperation(*pattern2->getOperation(i), i);
                            annulBitsOps1[i] = 0;
                            
                            sampleP1.annulBits.at(i) = 0;
//                            
//                            annulBits.at(index1).current[i] = 0;
//                            
//                            if(!annulBits.at(index1).modified)
//                                annulBits.at(index1).original[i] = 0;
//                            
                            updateAnnulBits(pattern1, i, 0);
                        }
                    }
                }
                else
                {
                    if((pattern2->getOperation(i)->getOpcode() != 0))
                    {
                        addTempOperation(pattern2->getOperation(i));
                        annulBitsOps1[i] = 1;
                        annulBitsOps2[i] = 0;       
                        
//                        sampleP2->annulBits.at(i) = 0;
//                        
//                        annulBits.at(index2).current[i] = 0;
//                            
//                        if(!annulBits.at(index2).modified)
//                            annulBits.at(index2).original[i] = 0;
                        
                        updateAnnulBits(pattern2, i, 0);
                    }                    
                }
            }
            else 
            {
                if(pattern2->getOperation(i)->getOpcode() != 0)
                {
                    pattern1->setOperation(*pattern2->getOperation(i), i);
                    //annulBitsOps1[i] = 1;
                    //annulBitsOps2[i] = 0;
//                    
//                    annulBits.at(index1).current[i] = 1;
//                            
//                    if(!annulBits.at(index1).modified)
//                        annulBits.at(index1).original[i] = 1;
//                    
//                    annulBits.at(index2).current[i] = 0;
//                            
//                    if(!annulBits.at(index2).modified)
//                        annulBits.at(index2).original[i] = 0;
                    
//                    updateAnnulBits(pattern1, i, 1);
//                    updateAnnulBits(pattern2, i, 0);
                }
                if((pattern2->getOperation(i)->getOpcode() == 0) || (!(annulBitsOps1[0] || annulBitsOps2[0])))
                {
                    if(!tempOps.empty())
                    {
                        if((!(annulBitsOps1[0] || annulBitsOps2[0])) && (i == 3))
                        {
                            pattern1->setOperation(*tempOps.front(), 0); // assign one operation to the pattern
                            annulBitsOps1[0] = 1;
//                            
//                            annulBits.at(index1).current[0] = 1;
//                            
//                            if(!annulBits.at(index1).modified)
//                                annulBits.at(index1).original[0] = 1;
                            
                            updateAnnulBits(pattern1, 0, 1);
                        }                            
                        else
                        {
                            pattern1->setOperation(*tempOps.front(), i); // assign one operation to the pattern
                            annulBitsOps1[i] = 1;
//                            
//                            annulBits.at(index1).current[i] = 1;
//                            
//                            if(!annulBits.at(index1).modified)
//                                annulBits.at(index1).original[i] = 1;
                            
                            updateAnnulBits(pattern1, i, 1);
                        }
                            
                        tempOps.erase(tempOps.begin()); // Erase the operation after assign to the pattern                                                 
                    }
                }
            }
            
            if(!tempOps.empty())
            {
                if((pattern1->getOperation(i)->getType() == syllableType[i]) && (i == 3))
                {
                    int j = 3;
                    while(j >= 0)
                    {
                        if(!annulBitsOps1[j])
                        {
                            pattern1->setOperation(*tempOps.front(), 0); // assign one operation to the pattern
                            
                            if(j != 3)
                            {
                                annulBitsOps1[j] = 1;
                                updateAnnulBits(pattern1, j, 1);
                            } 
                            else
                                updateAnnulBits(pattern1, 0, 1);
//
//                            annulBits.at(index1).current[j] = 1;
//
//                            if(!annulBits.at(index1).modified)
//                                annulBits.at(index1).original[j] = 1;

                            
                            
                            tempOps.erase(tempOps.begin()); // Erase the operation after assign to the pattern
                            j = -1;
                        }
                        j--;
                    }                        
                }                            
                else if((pattern1->getOperation(i)->getType() != syllableType[i]) && (i == 3))
                {
                    int j = 3;
                    while(j >= 0)
                    {
                        if(!annulBitsOps1[j])
                        {
                            pattern1->setOperation(*tempOps.front(), j); // assign one operation to the pattern
                            annulBitsOps2[j] = 1;
//
//                            annulBits.at(index2).current[j] = 1;
//
//                            if(!annulBits.at(index2).modified)
//                                annulBits.at(index2).original[j] = 1;

                            updateAnnulBits(pattern2, j, 1);
                            
                            tempOps.erase(tempOps.begin()); // Erase the operation after assign to the pattern
                            j = -1;
                        }                  
                        j--;
                    }                        
                }                    
            }
        }
        
//        annulBits.at(index1).modified = true;
//        annulBits.at(index2).modified = true;                    
        
        updateAddressInstruction(pattern1, pattern2);
        
//        updateInstructions(pattern1, pattern2, &annulBitsOps1, &annulBitsOps2);
//        updateInstructions(pattern1, pattern2, &annulBits.at(index1), &annulBits.at(index));
    }
       
    PBIWOptimizerJoinPatterns::Sample
    PBIWOptimizerJoinPatterns::addSample(IPBIWPattern& pattern)
    {
        AllInstructions::iterator it;
        Sample samplePattern;
        std::vector<IOperation*> operations = pattern.getOperations();
        std::vector<IOperation*>::iterator op;
        
        samplePattern.addressPattern = pattern.getAddress();
        samplePattern.instructionsThatUseIt = pattern.getInstructionsThatUseIt2();
        
        std::vector<bool> bits = pattern.getInstructionsThatUseIt2().at(0)->getAnnulBits();
        
        samplePattern.annulBits = bits;
        
//        std::cout << "BITBITBIT " << samplePattern.annulBits.at(0) << std::endl;
        
        for(op = operations.begin(); op < operations.end(); op++)
        {
            samplePattern.operations.push_back(*op);
        }
        
        samples.push_back(samplePattern);
        
        return samplePattern;
    }
    
    void
    PBIWOptimizerJoinPatterns::updateAnnulBits(IPBIWPattern* pattern, int index, bool bit)
    {
        AllInstructions instructions = pattern->getInstructionsThatUseIt2();
        AllInstructions::iterator it;
        
        for(it = instructions.begin();
            it < instructions.end();
            it++)
        {
            (*it)->setAnnulBit(index, bit);
        }        
    }
    
    void
    PBIWOptimizerJoinPatterns::updateAddressInstruction(IPBIWPattern* pattern1, IPBIWPattern* pattern2)
    {
        AllInstructions instructions = pattern2->getInstructionsThatUseIt2();
        AllInstructions::iterator it;
        
        for(it = instructions.begin();
            it < instructions.end();
            it++)
        {
//            (*it)->setAddress(pattern1->getAddress());
            (*it)->pointToPattern(*pattern1);
            pattern1->getInstructionsThatUseIt2().push_back(*it);
        }
        
        patterns.erase(std::find(patterns.begin(), patterns.end(), pattern2));                
    }
    
    void
    PBIWOptimizerJoinPatterns::getPatternsToJoin(int index1, int index2)
    {
        AllPatterns patterns = getPatterns();
        BaseDeque::iterator itBase1;
        InnerDeque::iterator itInner1, itInner2;
        
        for(itInner1 = twoOperation.at(index1).begin(), itInner2 = twoOperation.at(index2).begin();
            (itInner1 < twoOperation.at(index1).end()) && (itInner2 < twoOperation.at(index2).end());
            itInner1++, itInner2++)
        {
            IPBIWPattern* first = *(std::find(patterns.begin(), patterns.end(), *itInner1));
            IPBIWPattern* second = *(std::find(patterns.begin(), patterns.end(), *itInner2));
            
            joinPatterns(first, second);
            twoOperation.at(index1).erase(itInner1);
            twoOperation.at(index2).erase(itInner2);
        }        
        
    }
    
    void
    PBIWOptimizerJoinPatterns::getPatternsToJoinOneTwo(int index)
    {
        AllPatterns patterns = getPatterns();
        BaseDeque::iterator itBase1;
        InnerDeque::iterator itInner1, itInner2;
        
        int types[4] = {rVex::Syllable::SyllableType::CTRL,
                        rVex::Syllable::SyllableType::MUL,
                        rVex::Syllable::SyllableType::MUL,
                        rVex::Syllable::SyllableType::MEM};
        int count = 0;
        
        for(itBase1 = oneOperation.begin();
            itBase1 < oneOperation.end();
            itBase1++)
        {
//            for(itInner1 = (*itBase1).begin();
//                itInner1 < (*itBase1).end();
//                itInner1++)
//            {
                std::cout << "TYPES: " << types[count++] << std::endl;
//                if((*itBase1._M_cur == 0) && (count <= 2))
//                {
//                    if((patterns.at(index)->getOperation(0)->getOpcode() == 0) ||
//                        (patterns.at(index)->getOperation(0)->getType() != types[0]))
//                    {
//                        joinPatterns(patterns.at(index), patterns.at(*itInner1));
//                        count++;
//                    }                   
//                }
//            }   
                    
        }
        
    }
    
    void
    PBIWOptimizerJoinPatterns::updateInstructions(IPBIWPattern* pattern1, IPBIWPattern* pattern2, 
                                                  std::deque<bool>* annulBitsOps1, std::deque<bool>* annulBitsOps2)
    {
        AllInstructions instructions1 = pattern1->getInstructionsThatUseIt2();
        AllInstructions instructions2 = pattern2->getInstructionsThatUseIt2();
        AllInstructions::iterator it;
        AnnulationBit::iterator itAnnul;
        
        for(it = instructions1.begin();
            it < instructions1.end();
            it++)
        {
            int i = 0;
            for(itAnnul = annulBitsOps1->begin();
                itAnnul < annulBitsOps1->end();
                itAnnul++)
            {
                //(*it)->setAnnulBits(annulBitsOps1);
                (*it)->setAnnulBit(i++, (*itAnnul));
            }
        }
        
        for(it = instructions2.begin();
            it < instructions2.end();
            it++)
        {
            int i = 0;
            for(itAnnul = annulBitsOps2->begin();
                itAnnul < annulBitsOps2->end();
                itAnnul++)
            {                
//              (*it)->setAnnulBits(annulBitsOps2);
               (*it)->setAnnulBit(i++, (*itAnnul));               
            }
            
            (*it)->pointToPattern(*pattern1);
            pattern1->getInstructionsThatUseIt2().push_back((*it));
            
            patterns.erase(std::find(patterns.begin(), patterns.end(), pattern2));
        }        
    }
    
  void
  PBIWOptimizerJoinPatterns::addTempOperation(IOperation* operation)
  {
    Operation* temp = dynamic_cast<Operation*> (operation);

    tempOps.push_back(temp);
  }
    
    int
    PBIWOptimizerJoinPatterns::countTrueBits(AnnulationBit annulBits)
    {
        int count = 0;
        AnnulationBit::iterator it;

        for(it = annulBits.begin();
            it < annulBits.end();
            it++)
        {
            if(*it)
                count++;
        }
        
        return count;
    }

    void
    PBIWOptimizerJoinPatterns::run() 
    {
        this->processJoinPatterns();
    }
    
    
    
//    void
//    PBIWOptimizerJoinPatterns::processJoinPatterns()
//    {
//        
//        AllInstructions instructions = this->getInstructions();
//        AllInstructions copyInstructions = instructions;
//        AllPatterns patterns = this->getPatterns();
//        AllInstructions::iterator it1;
//        AllInstructions::iterator it2;
//        
//        for(it1 = instructions.begin();
//            it1 < instructions.end();
//            it1++)
//        {
//            AnnulationBit annulBits1 = (*it1)->getAnnulBits();
//            AnnulationBit::iterator bit1;
//            IPBIWPattern* pattern1 = patterns.at((*it1)->getPattern()->getAddress());
//            int quantityBitsInstruction1 = countTrueBits(annulBits1);
//            
//            for(it2 = it1+1;
//            it2 < instructions.end();
//            it2++)
//            {
//                AnnulationBit annulBits2 = (*it2)->getAnnulBits();
//                AnnulationBit::iterator bit2;
//                IPBIWPattern* pattern2 = patterns.at((*it2)->getPattern()->getAddress());
//                int quantityBitsInstruction2 = countTrueBits(annulBits2);
//                
//                if((quantityBitsInstruction1 + quantityBitsInstruction2) <=
//                        annulBits1.size())
//                {
//                    
//                    if((*it1)->getPattern()->getUsageCounter() <
//                        (*it2)->getPattern()->getUsageCounter())
//                    {
//                        
//                        for(bit1 = annulBits1.begin();
//                        bit1 < annulBits1.end();
//                        bit1++)
//                    {
//                        std::cout << "ADDRESS " << (*it1)->getAddress() << " ANNUL " << *bit1 << std::endl;
//                    }
//                        std::cout << "\nUSAGE " << annulBits1.size() << std::endl;
//                    }
//                    else if ((*it1)->getPattern()->getUsageCounter() >=
//                        (*it2)->getPattern()->getUsageCounter())
//                    {
//                        if(quantityBitsInstruction1 < quantityBitsInstruction2){
//                            
//                        }
//                        else {
//                            for(bit2 = annulBits2.begin();
//                            bit2 < annulBits2.end();
//                            bit2++)
//                            {
//                                if(*bit2){
//                                    
//                                    IOperation* operation = pattern2->getOperation(bit2._M_offset);
//                                    IOperation* operation2 = pattern1->getOperation(bit2._M_offset);
//                                    
//                                    if(operation->getType() == rVex::Syllable::SyllableType::CTRL)
//                                    {
//                                        
//                                    }
//                                    if(operation->getType() == rVex::Syllable::SyllableType::MEM)
//                                    {
//                                        std::cout << "MEM " << annulBits1.size() << std::endl;
//                                    }
//                                    if(operation->getType() == rVex::Syllable::SyllableType::MUL)
//                                    {
//                                        std::cout << "MUL " << annulBits1.size() << std::endl;
//                                    }
//                                    if(operation->getType() == rVex::Syllable::SyllableType::ALU)
//                                    {
//                                        
//                                    }
//                                }
//                            }
//                        }
//                        
//                        
//                    }
//                    else {
//                        if(quantityBitsInstruction1 < quantityBitsInstruction2)
//                        {
//                            
//                        }
//                    }
//                    
//                    for(bit1 = (*it1)->getAnnulBits().begin();
//                        bit1 < (*it1)->getAnnulBits().end();
//                        bit1++)
//                    {
//
//                    }
//                }
//                
//            }
//        }
//                
//    }
    
    
}


