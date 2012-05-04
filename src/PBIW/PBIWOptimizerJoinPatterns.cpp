/* 
 * File:   PBIWOptimizerJoinPatterns.cpp
 * Author: renato
 * 
 * Created on April 13, 2012, 1:54 AM
 */

#include <iostream>
#include <algorithm>
#include <signal.h>
#include "PBIWOptimizerJoinPatterns.h"
#include "BaseOptimizer.h"
#include "Operation.h"
#include "src/rVex/Operations/MISC/NOP.h"

namespace PBIW
{
    using namespace Interfaces;
    
    static const int SIZE = 4;
    
    void
    PBIWOptimizerJoinPatterns::printDeque(std::deque<std::deque<IPBIWPattern*> >& opDeque)
    {
        std::string type1[SIZE] = {"CTRL", "MEM", "MUL", "ALU"};
        std::string type2[8] = {"MUL_MUL", "CTRL_MUL", "MEM_MUL", "CTRL_MEM", "CTRL_ALU", "MEM_ALU", "MUL_ALU", "ALU_ALU"};
        
        for(unsigned int i = 0; i < opDeque.size(); i++)
        {
            if(opDeque.size() <= 4)
                std::cout << "Addr at " << type1[i] << ": ";
            else
                std::cout << "Addr at " << type2[i] << ": ";
            
            for(unsigned int j = 0; j < opDeque.at(i).size(); j++)
            {
                std::cout << opDeque.at(i).at(j)->getAddress() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "\n" << std::endl;
    }
    
    void
    PBIWOptimizerJoinPatterns::preprocessPatterns()
    {
        PBIWOptimizerJoinPatterns::PBIWPatternList::iterator it;
        
        oneOperation.resize(SIZE);
        twoOperation.resize(8);
        threeOperation.resize(SIZE);
        
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
                }
            }
            
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
        
        printDeque(oneOperation);
        printDeque(twoOperation);
        printDeque(threeOperation);    
        
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
                samples.clear();
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
            samples.clear();
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
            samples.clear();
        }
               
        IPBIWPattern* tempPattern1 = NULL;
        i = 0;
        
        for(itBase1 = threeOperation.begin();
            itBase1 < threeOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end();
                itInner1++)
            {
                if(tempPattern1 == NULL)
                {
                    tempPattern1 = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                    threeOperation.at(i).erase(itInner1);
                }
                
                for(int j = 0; j < 4; j++)
                {
                    if((tempPattern1->getOperation(j)->getType() != syllableType[j]))
                    {
                        if((!oneOperation.at(types[j]).empty()) && ((syllableType[j] == j) ||
                            (tempPattern1->getOperation(j)->getOpcode() == 0)))
                        {
                            joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front())));
                            oneOperation.at(types[j]).erase(oneOperation.at(types[j]).begin());
                            samples.clear();
                        }
//                        else if(!oneOperation.at(types[4]).empty())
//                        {
//                            joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())));
//                            oneOperation.at(types[4]).erase(oneOperation.at(types[4]).begin());
//                            samples.clear();
//                        }
                        else if(i == 3)
                        {
                            for(int k = 0; (k < 4) && (!oneOperation.at(types[4]).empty()); k++)
                            {
                                if(tempPattern1->getOperation(k)->getOpcode() == 0)
                                {
                                    joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())));
                                    oneOperation.at(types[4]).erase(oneOperation.at(types[4]).begin());                                
                                }
                            }
                            if(!oneOperation.at(types[4]).empty())
                            {
                                tempPattern1 = NULL;
                                j = 4;
                            }
                            
                            samples.clear();                            
                        }
                    }
                }
            }
            i++;
        }
        
        
        i = 0;
        tempPattern1 = NULL;
        // CTRL = 0, MEM = 1, MUL = 2, ADD = 3
        for(itBase1 = oneOperation.begin();
            itBase1 < oneOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end();
                itInner1++)
            {
                if(tempPattern1 == NULL)
                {
                    tempPattern1 = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                    oneOperation.at(i).erase(itInner1);
                }
                
                for(int j = 0; j < 4; j++)
                {
                    if((tempPattern1->getOperation(j)->getType() != syllableType[j]) ||
                       (tempPattern1->getOperation(j)->getOpcode() == 0))
                    {
                        if((!oneOperation.at(types[j]).empty()) && ((syllableType[j]) ||
                            (tempPattern1->getOperation(j)->getOpcode() == 0)))
                        {
                            joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front())));
                            oneOperation.at(types[j]).erase(oneOperation.at(types[j]).begin());                            
                        }
                        else if(i == 3)
                        {
                            for(int k = 0; (k < 4) && (!oneOperation.at(types[4]).empty()); k++)
                            {
                                if(tempPattern1->getOperation(k)->getOpcode() == 0)
                                {
                                    joinPatterns(tempPattern1, *(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())));
                                    oneOperation.at(types[4]).erase(oneOperation.at(types[4]).begin());                                
                                }
                            }
                            if(!oneOperation.at(types[4]).empty())
                            {
                                tempPattern1 = NULL;
                                j = 4;
                            }
                            
                            samples.clear();                            
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
        AllSamples::iterator it;
      
        Sample& sampleP1 = addSample(*pattern1);
        Sample& sampleP2 = addSample(*pattern2);
        
//        std::cout << "OP : " << samples.at(0).annulBits.at(0) << std::endl;
//        std::cout << "OP : " << samples.at(0).annulBits.at(1) << std::endl;
//        std::cout << "OP : " << samples.at(0).annulBits.at(2) << std::endl;
//        std::cout << "OP : " << samples.at(0).annulBits.at(3) << std::endl;
//        
//        std::cout << "\nOP : " << samples.at(1).annulBits.at(0) << std::endl;
//        std::cout << "OP : " << samples.at(1).annulBits.at(1) << std::endl;
//        std::cout << "OP : " << samples.at(1).annulBits.at(2) << std::endl;
//        std::cout << "OP : " << samples.at(1).annulBits.at(3) << std::endl;

        int syllableType[4] = {4, 2, 2, 3}; // Based on the rVex syllables types: ALU = 1, MUL, MEM, CTRL
        std::cout << "ADDR : " << sampleP1.addressPattern << std::endl;
        std::cout << "ADDR : " << sampleP2.addressPattern << std::endl;
        for(int i = 0; i < 4; i++)
        {
            if(pattern1->getOperation(i)->getOpcode() != 0)
            {
                std::cout << "TYPE1 : " << pattern1->getOperation(i)->getType() << " "<<pattern1->getOperation(i)->getOpcode() << std::endl;
                std::cout << "TYPE2 : " << pattern2->getOperation(i)->getType() << " "<<pattern2->getOperation(i)->getOpcode() << std::endl;
                
//                annulBitsOps1[i] = 1;
                
                if((pattern1->getOperation(i)->getType() != syllableType[i]))
                {
                    if((pattern2->getOperation(i)->getOpcode() != 0))
                    {
//                        annulBitsOps2[i] = 1;
                        
                        if(pattern2->getOperation(i)->getType() != syllableType[i])
                        {
                            addTempOperation(pattern2->getOperation(i));
//                            annulBitsOps2[i] = 0;
                            sampleP2.annulBits.at(i) = 0;
                        }
                        else
                        {
                            
                            addTempOperation(pattern1->getOperation(i));
                            sampleP1.annulBits.at(i) = 0;
                            annulBitsOps1[i] = 0;
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
                        
                        sampleP2.annulBits.at(i) = 0;
                    }                    
                }
            }
            else 
            {
                if(pattern2->getOperation(i)->getOpcode() != 0)
                {
                    pattern1->setOperation(*pattern2->getOperation(i), i);                    
                }
            }
            
            while(!tempOps.empty())
            {
                if((pattern1->getOperation(i)->getType() == syllableType[2]) &&
                    (pattern2->getOperation(i)->getType() == syllableType[2]))
                {
                    int j = 3;
                    while(j >= 0)
                    {
                        if((sampleP1.operations.at(j)->getType() != syllableType[2]) &&
                           (sampleP2.operations.at(j)->getType() != syllableType[2]))
                        {
                            if(sampleP1.operations.at(2)->getOpcode() != 0)
                            {
                                if(sampleP1.operations.at(3)->getOpcode() == 0)
                                {
                                    sampleP1.operations.at(3) = sampleP2.operations.at(1);
                                    sampleP1.annulBits.at(2) = 0;
                                    sampleP1.annulBits.at(3) = 1;
                                    pattern1->setOperation(*pattern1->getOperation(2), 3); // assign one operation to the pattern
                                }
                                else if(sampleP1.operations.at(0)->getOpcode() == 0)
                                {
                                    sampleP1.operations.at(0) = sampleP2.operations.at(1);
                                    sampleP1.annulBits.at(2) = 0;
                                    sampleP1.annulBits.at(0) = 1;
                                    pattern1->setOperation(*pattern1->getOperation(2), 0); // assign one operation to the pattern
                                }
                            }                                
                                
                            sampleP2.annulBits.at(j) = 0;
                            sampleP2.annulBits.at(2) = 1;
                                                        
                            sampleP1.operations.at(2) = tempOps.front();
                            sampleP2.operations.at(1) = 0;
                            sampleP2.operations.at(2) = tempOps.front();
                            
                            pattern1->setOperation(*tempOps.front(), 2); // assign one operation to the pattern
                            
                            tempOps.pop_front();
                            j = -1;
                        }
                    }
                }
                if((pattern1->getOperation(i)->getType() == syllableType[i]))
                {
                    int j = 3;
                    while(j >= 0)
                    {
                        if(sampleP1.operations.at(j)->getOpcode() == 0)
                        {
                            
                            sampleP2.operations.at(i) = 0;
                            sampleP1.operations.at(j) = tempOps.front();
                            sampleP2.annulBits.at(j) = 1;

                            pattern1->setOperation(*tempOps.front(), j); // assign one operation to the pattern
//                            pattern1->setOperation(*pattern2->getOperation(i), i); 

                            tempOps.erase(tempOps.begin()); // Erase the operation after assign to the pattern
                            j = -1;
                        }
                        j--;                        
                    }                        
                }
                else if((pattern1->getOperation(i)->getType() != syllableType[i]))
                {
                    int j = 3;
                    while(j >= 0)
                    {
                        
                        
                        if(sampleP1.operations.at(j)->getOpcode() == 0)
                        {
                            std::cout<< "BIT " << sampleP1.annulBits.at(i) << std::endl;
                            if(!sampleP1.annulBits.at(j))
                            {
                                for(it = samples.begin(); ((it < samples.end()) && (!tempOps.empty())); it++)
                                {
                                    if((it->addressPattern != sampleP1.addressPattern) &&
                                       (it->addressPattern != sampleP2.addressPattern) &&
                                       (*(it->operations.at(i)) == *tempOps.front()))
                                    {                                       
                                       it->annulBits.at(i) = 0;
                                       it->annulBits.at(j) = 1;
                                       it->operations.at(i) = 0;
                                       it->operations.at(j) = tempOps.front();
                                       
                                       pattern1->setOperation(*tempOps.front(), j); // assign one operation to the pattern
                                       pattern1->setOperation(*pattern2->getOperation(i), i);
                                    }
                                    else
                                    {
                                       sampleP2.annulBits.at(j) = 1;
                                       sampleP2.operations.at(i) = 0;
                                       sampleP1.annulBits.at(i) = 0;
                                       sampleP1.operations.at(j) = tempOps.front();
                                       sampleP2.operations.at(j) = tempOps.front();
                                       
                                       pattern1->setOperation(*tempOps.front(), j); // assign one operation to the pattern
                                       pattern1->setOperation(*pattern2->getOperation(i), i);
                                    }
                                    
                                    tempOps.erase(tempOps.begin()); // Erase the operation after assign to the pattern
                                }
                            }
                            else if((j == 2) && (tempOps.front()->getOpcode() == syllableType[2]))
                            {
                                if(!sampleP1.annulBits.at(j))
                                {
                                    for(it = samples.begin(); ((it < samples.end()) && (!tempOps.empty())); it++)
                                    {
                                        if((it->addressPattern != sampleP1.addressPattern) &&
                                        (it->addressPattern != sampleP2.addressPattern) &&
                                        (*(it->operations.at(i)) == *tempOps.front()))
                                        {                                       
                                            it->annulBits.at(i) = 0;
                                            it->annulBits.at(j) = 1;
                                            it->operations.at(i) = 0;
                                            it->operations.at(j) = tempOps.front();

                                            pattern1->setOperation(*tempOps.front(), j); // assign one operation to the pattern
                                            pattern1->setOperation(*pattern2->getOperation(i), i);
                                        }
                                        
                                        tempOps.erase(tempOps.begin()); // Erase the operation after assign to the pattern
                                    }
                                }
                                else if(sampleP1.annulBits.at(j)) 
                                {
                                    sampleP2.annulBits.at(i) = 0;
                                    sampleP2.annulBits.at(j) = 1;
                                    sampleP1.annulBits.at(j) = 0;
                                    sampleP1.operations.at(j) = tempOps.front();
                                    sampleP2.operations.at(j) = tempOps.front();

                                    pattern1->setOperation(*tempOps.front(), j); // assign one operation to the pattern
//                                    pattern1->setOperation(*pattern2->getOperation(i), i);
                                }
                            }
                            else
                            {
                                sampleP1.annulBits.at(j) = 1;
                                pattern1->setOperation(*tempOps.front(), j); // assign one operation to the pattern
                                pattern1->setOperation(*pattern2->getOperation(i), i);                                       
                                tempOps.erase(tempOps.begin()); // Erase the operation after assign to the pattern
                            }
                          
                            j = -1;
                        }                  
                        j--;
                    }                        
                }                    
            }
        }
        
//        std::cout << "OP : " << samples.at(0).annulBits.at(0) << std::endl;
//        std::cout << "OP : " << samples.at(0).annulBits.at(1) << std::endl;
//        std::cout << "OP : " << samples.at(0).annulBits.at(2) << std::endl;
//        std::cout << "OP : " << samples.at(0).annulBits.at(3) << std::endl;
//        
//        std::cout << "\nOP : " << samples.at(1).annulBits.at(0) << std::endl;
//        std::cout << "OP : " << samples.at(1).annulBits.at(1) << std::endl;
//        std::cout << "OP : " << samples.at(1).annulBits.at(2) << std::endl;
//        std::cout << "OP : " << samples.at(1).annulBits.at(3) << std::endl;
//        
//        if(samples.size()>2)
//        {
//            std::cout << "\nOP : " << samples.at(2).annulBits.at(0) << std::endl;
//        std::cout << "OP : " << samples.at(2).annulBits.at(1) << std::endl;
//        std::cout << "OP : " << samples.at(2).annulBits.at(2) << std::endl;
//        std::cout << "OP : " << samples.at(2).annulBits.at(3) << std::endl;
//        }
        
        updateAddressInstruction(pattern1, pattern2);
        updateBits();
    }
    
    void
    PBIWOptimizerJoinPatterns::updateBits()
    {
        AllSamples::iterator it1;
        AllInstructions::iterator it2;
        
        for(it1 = samples.begin(); it1 < samples.end(); it1++)
        {
            for(it2 = (*it1).instructionsThatUseIt.begin(); it2 < (*it1).instructionsThatUseIt.end(); it2++)
            {
                std::cout << "u OP : " << it1->annulBits.at(0) << std::endl;
                std::cout << "u OP : " << it1->annulBits.at(1) << std::endl;
                std::cout << "u OP : " << it1->annulBits.at(2) << std::endl;
                std::cout << "u OP : " << it1->annulBits.at(3) << std::endl;
                
                (*it2)->setAnnulBits(it1->annulBits);
            }
        }
    }
    
    PBIWOptimizerJoinPatterns::Sample&
    PBIWOptimizerJoinPatterns::addSample(IPBIWPattern& pattern)
    {
        AllSamples::iterator itSample;
        struct Sample samplePattern;
        bool find = false;
        
        for(itSample = samples.begin(); itSample < samples.end(); itSample++)
        {
            if((*itSample).addressPattern == pattern.getAddress())
            {
                return (*itSample);                
            }
        }
        
        if(!find)
        {
            samplePattern.addressPattern = pattern.getAddress();

            samplePattern.instructionsThatUseIt = pattern.getInstructionsThatUseIt2();

            samplePattern.annulBits = samplePattern.instructionsThatUseIt.at(0)->getAnnulBits();
            
            std::vector<IOperation*> operation = pattern.getOperations();
            std::copy(operation.begin(),operation.end(),std::back_inserter(samplePattern.operations));

            samples.push_back(samplePattern);
            
            return samples.back();
        }
         
        
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
        AllInstructions instructions = pattern2->getInstructionsThatUseIt();
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
    PBIWOptimizerJoinPatterns::addTempOperation(IOperation* operation)
    {
        tempOps.push_back(operation);
    }
    
    void
    PBIWOptimizerJoinPatterns::run() 
    {
        this->processJoinPatterns();
    }    
}