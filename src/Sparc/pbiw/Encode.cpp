/* 
 * File:   Encode.cpp
 * Author: renato
 * 
 * Created on October 24, 2012, 2:36 PM
 */

#include <stdlib.h>
#include "OriginalInstruction.h"
#include "Encode.h"
#include "ParseFile.h"

namespace Sparc
{

namespace PBIW
{

Encode::Encode() {
}

Encode::Encode(OriginalInstDeque instrDeque) {
    originalInstructions.assign(instrDeque.begin(), instrDeque.end());
}

Encode::~Encode() {
}

void
Encode::toEncode() {
    
    EncodeInstruction encInstruction;
    EncodePattern encPattern;
    
    OriginalInstDeque::iterator it;
    
    for(it = this->originalInstructions.begin(); 
            it < originalInstructions.end(); 
            it++)
    {
    
        string instruction = it->getBinInstruction();
        int twoBits = atoi(instruction.substr(0,2).c_str());

        switch(twoBits)
        {
            case 00: break;
            case 01: 
                encInstruction.fmt1EncodeInstruction(*it);
                encPattern.fmt1EncodePattern(*it);
                
                cout << "!!!!!!!!!!" << encPattern.getEncodePattern() << endl;
//                cout << encPatDeque << endl;
                
                if(!hasPattern(encPattern)) {
                    cout << "EEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << encPattern.getEncodePattern() << endl;
                    encPatDeque.push_back(encPattern);                    
                }
                
                break;

            case 10: break;
            case 11: break;
        }
    }
}



bool
Encode::hasPattern(EncodePattern pattern) {
    EncPatDeque::iterator it;
    
    if(encPatDeque.empty()) {
        return false;
    }
    else {
        for(it = encPatDeque.begin(); it != encPatDeque.end(); it++) {
            if(it->getEncodePattern().compare(pattern.getEncodePattern()) == 0) {
                cout << "Comp " << it->getEncodePattern() << " - " << pattern.getEncodePattern() << endl;
                return true; 
            }
        }
        return false;
    }
}

}

}
