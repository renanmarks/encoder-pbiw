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
#include "src/PBIW/Interfaces/IOperation.h"
#include "Interfaces/IPBIWInstruction.h"
#include "src/rVex/Operations/MISC/NOP.h"
#include "src/rVex/Operations/ALU/NANDL.h"
#include "Optimizers/JoinPattern/PatternBuilder.h"

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
                        
//            std::cout << "PATTERNS " << pat++ << std::endl;
            // Operations
            for(int i = 0; i < SIZE; i++)
            {
//                std::cout << "OPCODE " << (*it)->getOperation(i)->getOpcode() << std::endl;
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
                    if(ops[0]) // if has a CTRL operation
                        half1 = 0;
                    
                    if(ops[3])  // if has a MEM operation
                    { 
                        if(half1 == -1) // if is MEM_...
                            half1 = 1;
                        else            // else is ..._MEM
                            half2 = 1;
                    }
                    
                    if(ops[1]) // if has MUL operation in the position one
                    {
                        if(half1 == -1) // if is MUL_...
                            half1 = 2;
                        else            // else is ..._MUL
                            half2 = 2;
                    }
                    
                    if(ops[2])  // if has MUL operation in the position two
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
        
//        printDeque(oneOperation);
//        printDeque(twoOperation);
//        printDeque(threeOperation);    
//        
//        std::cout << "COUNT 1..3 ops: " << count2[0] << std::endl;
//        std::cout << "COUNT 4 ops: " << count2[1] << std::endl;
//        std::cout << "COUNT others: " << count2[2] << std::endl;
//        std::cout << "Totals: " << (count2[0] + count2[1] + count2[2]) << std::endl;
    }
    
    void
    PBIWOptimizerJoinPatterns::processJoinPatterns(IPBIWFactory& factory)
    {
        Optimizers::JoinPattern::PatternBuilder patternBuilder(factory);        
            
        int start = 0;
        int finish = 0;
        
        do{
            threeOperation.clear();
            twoOperation.clear();
            oneOperation.clear();
            
        preprocessPatterns();

        start = patterns.size();
        
        IPBIWPattern* temp = patterns.back();
        patterns.pop_back();

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
                IPBIWPattern* first = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                IPBIWPattern* second = *(std::find(patterns.begin(), patterns.end(), *itInner2));

                patterns.push_back(patternBuilder.startWithPattern(first).joinWithPattern(second).buildPattern());

                patterns.erase(std::find(patterns.begin(), patterns.end(), first));
                patterns.erase(std::find(patterns.begin(), patterns.end(), second));

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
                            getPatternsToJoin(MUL_MUL, CTRL_MEM, factory); 

                            if(!twoOperation.at(CTRL_ALU).empty())
                            getPatternsToJoin(MUL_MUL, CTRL_ALU, factory);

                            if(!twoOperation.at(MEM_ALU).empty())
                                getPatternsToJoin(MUL_MUL, MEM_ALU, factory);
                            break;

                        case CTRL_MUL:
                            if(!twoOperation.at(MEM_MUL).empty())
                                getPatternsToJoin(CTRL_MUL, MEM_MUL, factory);

                            if(!twoOperation.at(MEM_ALU).empty())
                                getPatternsToJoin(CTRL_MUL, MEM_ALU, factory);

                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(CTRL_MUL, MUL_ALU, factory);
                            break;

                        case MEM_MUL:
                            if(!twoOperation.at(CTRL_ALU).empty())
                                getPatternsToJoin(MEM_MUL, CTRL_ALU, factory);

                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(MEM_MUL, MUL_ALU, factory);
                            break;

                        case CTRL_MEM:
                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(CTRL_MEM, MUL_ALU, factory);
                            break;

                        case CTRL_ALU:
                            if(!twoOperation.at(MEM_ALU).empty())
                                getPatternsToJoin(CTRL_ALU, MEM_ALU, factory);

                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(CTRL_ALU, MUL_ALU, factory);
                            break;

                        case MEM_ALU: 
                            if(!twoOperation.at(MUL_ALU).empty())
                                getPatternsToJoin(MEM_ALU, MUL_ALU, factory);
                            break;

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
                                        getPatternsToJoin(j, ALU_ALU, factory);
                                    }                                    
                                    else if(j == 7)// if alu_alu
                                    {
                                        while(itBase2->size() > 1)
                                        {
                                            patterns.push_back(
                                            patternBuilder.startWithPattern(itBase2->front()).joinWithPattern(itBase2->back()).buildPattern());
                                            
                                            patterns.erase(std::find(patterns.begin(), patterns.end(), itBase2->front()));
                                            patterns.erase(std::find(patterns.begin(), patterns.end(), itBase2->back()));

                                            itBase2->pop_front();
                                            itBase2->pop_back();                                                
                                        }
                                    }
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
        int count = 2;
        IPBIWPattern* tempPattern = NULL;
        i = 0;

        // CTRL = 0, MEM = 1, MUL = 2, ADD = 3
        for(itBase1 = twoOperation.begin();
            itBase1 < twoOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end() && count <= 4;
                itInner1++)
            {
                if(tempPattern == NULL)
                {
                    tempPattern = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                    patternBuilder.startWithPattern(tempPattern);
                    twoOperation.at(i).erase(itInner1);                                                                        
                }

                for(int j = 0; j < 4; j++)
                {
                    if((tempPattern->getOperation(j)->getType() != syllableType[j]) ||
                    (tempPattern->getOperation(j)->getOpcode() == 0))
                    {
                        if((!oneOperation.at(types[j]).empty()) &&
                            (tempPattern->getOperation(j)->getOpcode() == 0))
                        {
                            patterns.erase(std::find(patterns.begin(), patterns.end(), tempPattern));

                            tempPattern = patternBuilder
                            .joinWithPattern(*(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front())))
                            .buildPattern();

                            patterns.erase(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front()));
                            oneOperation.at(types[j]).pop_front();

                            patterns.push_back(tempPattern);
                            count++;
                        }
                        if(j == 3)
                        {
                            for(int k = 0; (k < 4) && (!oneOperation.at(types[4]).empty()); k++)
                            {
                                if(tempPattern->getOperation(k)->getOpcode() == 0)
                                {
                                    patterns.erase(std::find(patterns.begin(), patterns.end(), tempPattern));

                                    tempPattern = patternBuilder
                                    .joinWithPattern(*(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())))
                                    .buildPattern();

                                    patterns.erase(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front()));
                                    oneOperation.at(types[4]).pop_front();

                                    patterns.push_back(tempPattern);
                                    count++;
                                }
                            }
                        }
                    }                        
                }     
            }
            tempPattern = NULL;
            i++;
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
                    patternBuilder.startWithPattern(tempPattern1);
                    threeOperation.at(i).erase(itInner1);
                }

                for(int j = 0; j < 4; j++)
                {
                    if((tempPattern1->getOperation(j)->getType() != syllableType[j]))
                    {
                        if((!oneOperation.at(types[j]).empty()) && ((syllableType[j] == j) ||
                            (tempPattern1->getOperation(j)->getOpcode() == 0)))
                        {
                            patterns.push_back(
                            patternBuilder
                            .joinWithPattern(*(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front())))
                            .buildPattern());

                            patterns.erase(std::find(patterns.begin(), patterns.end(), tempPattern1));
                            patterns.erase(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front()));
                            oneOperation.at(types[j]).pop_front();
                            j = 4;
                            tempPattern1 = NULL;
                        }
                        else if((i == 3) || (j == 3))
                        {
                            for(int k = 0; (k < 4) && (!oneOperation.at(types[4]).empty()); k++)
                            {
                                if(tempPattern1->getOperation(k)->getOpcode() == 0)
                                {
                                    patterns.push_back(
                                    patternBuilder
                                    .joinWithPattern(*(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())))
                                    .buildPattern());

                                    patterns.erase(std::find(patterns.begin(), patterns.end(), tempPattern1));
                                    patterns.erase(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front()));
                                    oneOperation.at(types[4]).pop_front(); 
                                }
                            }
                            tempPattern1 = NULL;
                            j = 4;
                        }
                    }
                }
            }
            i++;
        }

        i = 0;
        count = 1;
        tempPattern1 = NULL;

        // CTRL = 0, MEM = 1, MUL = 2, ADD = 3
        for(itBase1 = oneOperation.begin();
            itBase1 < oneOperation.end();
            itBase1++)
        {
            for(itInner1 = (*itBase1).begin();
                itInner1 < (*itBase1).end() && count <= 4;
                itInner1++)
            {
                if(tempPattern1 == NULL)
                {
                    tempPattern1 = *(std::find(patterns.begin(), patterns.end(), *itInner1));
                    patternBuilder.startWithPattern(tempPattern1);
                    oneOperation.at(i).erase(itInner1);
                }

                for(int j = 0; j < 4; j++)
                {
                    if(((tempPattern1->getOperation(j)->getType() != syllableType[j]) ||
                        (tempPattern1->getOperation(j)->getOpcode() == 0) || 
                        (!oneOperation.at(types[4]).empty())) &&
                        (tempPattern1->getOperation(0)->getOpcode() != 31))
                    {
                        if((!oneOperation.at(types[j]).empty()) && 
                        ((tempPattern1->getOperation(j)->getType() != syllableType[j]) ||
                        (tempPattern1->getOperation(j)->getOpcode() == 0)))
                        {
                            patterns.erase(std::find(patterns.begin(), patterns.end(), tempPattern1));

                            tempPattern1 = patternBuilder
                            .joinWithPattern(*(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front())))
                            .buildPattern();

                            patterns.erase(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[j]).front()));
                            oneOperation.at(types[j]).pop_front();

                            j = 4;
                            count++;
                        }
                        else if((i == 3) || (j == 3))
                        {
                            for(int k = 0; (k < 4) && (!oneOperation.at(types[4]).empty()); k++)
                            {
                                if(tempPattern1->getOperation(k)->getOpcode() == 0)
                                {
                                    patterns.erase(std::find(patterns.begin(), patterns.end(), tempPattern1));

                                    tempPattern1 = patternBuilder
                                    .joinWithPattern(*(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front())))
                                    .buildPattern();

                                    patterns.erase(std::find(patterns.begin(), patterns.end(), oneOperation.at(types[4]).front()));
                                    oneOperation.at(types[4]).pop_front();

                                    j = 4;
                                    count++;
                                    break;
                                }
                            }
                            j = 4;
                        }
                    }
                }

                if(count > 1)
                {
                    patterns.push_back(tempPattern1);
                    count = 1;
                }
            }
            i++;
        }       

        patterns.push_back(temp);
//        finish = threeOperation.size() + twoOperation.size() + oneOperation.size();        
        updatePatterns();
        finish = patterns.size();        
        
        }while(start > finish);
    }
    
    
    void
    PBIWOptimizerJoinPatterns::updatePatterns()
    {
        PBIWPatternList::iterator it1;
        PBIWPatternList::iterator it2;
        unsigned int address = 0;
        
        for(it1 = patterns.begin(); it1 < patterns.end(); it1++)
        {
            if((*it1)->getAddress() != address)
                (*it1)->setAddress(address);
            
            for(it2 = it1+1; (it2 < patterns.end()) && (it1+1 < patterns.end()); it2++)
            {
                if(**it1 == **it2)
                    updateAddressInstruction(*it1, *it2);
            }
            
            address++;
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
            (*it)->pointToPattern(*pattern1);
            pattern1->getInstructionsThatUseIt().push_back(*it);
        }
        
        patterns.erase(std::find(patterns.begin(), patterns.end(), pattern2));                
    }
    
    void
    PBIWOptimizerJoinPatterns::getPatternsToJoin(int index1, int index2, IPBIWFactory& factory)
    {
        InnerDeque::iterator itInner1, itInner2;
        
        for(itInner1 = twoOperation.at(index1).begin(), itInner2 = twoOperation.at(index2).begin();
            (itInner1 < twoOperation.at(index1).end()) && (itInner2 < twoOperation.at(index2).end());
            itInner1++, itInner2++)
        {
            IPBIWPattern* first = *(std::find(patterns.begin(), patterns.end(), *itInner1));
            IPBIWPattern* second = *(std::find(patterns.begin(), patterns.end(), *itInner2));
            
            Optimizers::JoinPattern::PatternBuilder patternBuilder(factory);
            
            patterns.push_back(
            patternBuilder.startWithPattern(first).joinWithPattern(second).buildPattern());
            
            patterns.erase(std::find(patterns.begin(), patterns.end(), first));
            patterns.erase(std::find(patterns.begin(), patterns.end(), second));
            
            twoOperation.at(index1).erase(itInner1);
            twoOperation.at(index2).erase(itInner2);
        }        
        
    }
    
    void
    PBIWOptimizerJoinPatterns::run(IPBIWFactory& factory) 
    {
        this->processJoinPatterns(factory);
    }    
}