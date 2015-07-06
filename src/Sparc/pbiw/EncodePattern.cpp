/* 
 * File:   EncodePattern.cpp
 * Author: renato
 * 
 * Created on October 24, 2012, 4:55 PM
 */

#include "EncodePattern.h"
#include "Encode.h"

namespace Sparc
{

namespace PBIW
{

EncodePattern::EncodePattern() {
}

//EncodePattern::EncodePattern(const EncodePattern& orig) {
//}

EncodePattern::~EncodePattern() {
}

void
EncodePattern::setEncodePattern(string pattern) {
    this->encodedPattern = pattern;
}

string
EncodePattern::getEncodePattern() {
    return this->encodedPattern;
}

void
EncodePattern::fmt1EncodePattern(OriginalInstruction instruction) {
    encodedPattern = instruction.getBinInstruction().substr(0, 16);    
}

void
EncodePattern::fmt2EncodePattern(OriginalInstruction instruction) {
    
}

void
EncodePattern::fmt3EncodePattern(OriginalInstruction instruction) {
    
}

}

}
