/* 
 * File:   OriginalInstruction.cpp
 * Author: renato
 * 
 * Created on October 23, 2012, 8:16 PM
 */

#include <memory>

#include "OriginalInstruction.h"

namespace Sparc
{

namespace PBIW
{

OriginalInstruction::OriginalInstruction() {
}

OriginalInstruction::OriginalInstruction(string hex, string bin)
        :hexInstruction(hex),
        binInstruction(bin)
{
}

OriginalInstruction::~OriginalInstruction() {
}

string
OriginalInstruction::getBinInstruction() {
    return this->binInstruction;
}

string
OriginalInstruction::getHexInstruction() {
    return this->hexInstruction;
}

}

}
