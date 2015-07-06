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

namespace Tools {

    OriginalInstruction::OriginalInstruction() {
    }

    OriginalInstruction::OriginalInstruction(string bin)
            :binInstruction(bin)
    {
    }

    OriginalInstruction::OriginalInstruction(string hexStr, string bin, string hex)
            :hexStrInstruction(hexStr),
            binInstruction(bin),
            hexInstruction(hex)
    {
    }

    OriginalInstruction::~OriginalInstruction() {
    }

    string
    OriginalInstruction::getBinInstruction() {
        return this->binInstruction;
    }

    string
    OriginalInstruction::getHexStrInstruction() {
        return this->hexStrInstruction;
    }

    void
    OriginalInstruction::setBinInstruction(string binInstruction) {
        this->binInstruction = binInstruction;
    }

    string
    OriginalInstruction::getHexInstruction() {
        return this->hexInstruction;
    }

}

}

}
