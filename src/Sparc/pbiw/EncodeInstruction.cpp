/* 
 * File:   EncodeInstruction.cpp
 * Author: renato
 * 
 * Created on October 24, 2012, 4:55 PM
 */

#include <iostream>
#include "EncodeInstruction.h"
#include "Encode.h"

using namespace std;

namespace Sparc
{

namespace PBIW
{

EncodeInstruction::EncodeInstruction() {
}

EncodeInstruction::EncodeInstruction(const EncodeInstruction& orig) {
}

EncodeInstruction::~EncodeInstruction() {
}

void
EncodeInstruction::setEncodeInstruction(string instruction) {
    this->encodedInstruction = instruction;
}

string
EncodeInstruction::getEncodeInstruction() {
    return this->encodedInstruction;
}

void
EncodeInstruction::fmt1EncodeInstruction(OriginalInstruction instruction) {
    string temp = instruction.getBinInstruction().substr(16,16);
    std::cout << "Teste " << instruction.getBinInstruction() << std::endl;
    std::cout << "patt " << temp << std::endl;
    
}

void
EncodeInstruction::fmt2EncodeInstruction(OriginalInstruction instruction) {
    
}

void
EncodeInstruction::fmt3EncodeInstruction(OriginalInstruction instruction) {
    
}

}

}
