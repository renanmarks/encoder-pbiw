/* 
 * File:   EncodeInstruction.cpp
 * Author: renato
 * 
 * Created on October 24, 2012, 4:55 PM
 */

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <math.h>
#include "Encode.h"
#include "EncodePattern.h"
#include "ParseFile.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    using namespace std;

    EncodeInstruction::EncodeInstruction() {
    }

    EncodeInstruction::~EncodeInstruction() {
    }

    void
    EncodeInstruction::setHexEncodeInstruction(string instruction) {
        this->hexEncodedInstruction = instruction;
    }

    string
    EncodeInstruction::getHexEncodeInstruction() {
        return this->hexEncodedInstruction;
    }
    
    void
    EncodeInstruction::setStrHexEncInstruction(string hex) {
        this->strHexEncInstruction = hex;
    }
    
    string
    EncodeInstruction::getStrHexEncInstruction() {
        return this->strHexEncInstruction;
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
    EncodeInstruction::setIndexSize(int indexSize) {
        this->indexSize = indexSize;
    }
    
    int
    EncodeInstruction::getIndexSize() {
        return this->indexSize;
    }
    
    void
    EncodeInstruction::setAddress(int address) {
        this->address = address;
        if(this->encodedInstruction.size() < 16 ) {
            bitset<16> pointToPatternBin = address;
            string indexPattern = pointToPatternBin.to_string();
            this->encodedInstruction = indexPattern.substr((pointToPatternBin.size()-indexSize), indexSize) + encodedInstruction;
            if(address > pow(2, this->getIndexSize())) {
                cout << "WARNING: Index Pattern overflowed. Execution stopped to avoid that program encoding has semantic errors." << endl;
                cout << "note: Use an alternative layout to encode this program." << endl;
                exit(0);
            }
        }
        this->setHexEncodeInstruction(ParseFile().binToHex(this->encodedInstruction));
        this->setStrHexEncInstruction(ParseFile().binToStrHex(this->encodedInstruction));
    }

    int
    EncodeInstruction::getAddress() {
        return address;
    }

    void
    EncodeInstruction::setAddress_Seq(int address) {
        this->address_seq = address;
    }
    
    int
    EncodeInstruction::getAddress_Seq() {
        return this->address_seq;
    }

    void 
    EncodeInstruction::setPointToPattern(IPBIWEncodePattern& pattern) {
        EncodePattern& temp = dynamic_cast<EncodePattern&> (pattern);
        this->pointToPattern = &temp;
        this->pointToPattern->includeInstructionUseIt(this);
    }
    
    IPBIWEncodePattern&
    EncodeInstruction::getPointToPattern() {
        return *(this->pointToPattern);
    }
    
    void
    EncodeInstruction::fmtAllEncodeInstruction(OriginalInstruction instruction, FieldInstruction instrLayout) {
        FieldInstruction::iterator it; 
        FieldInstruction frmDeque;
        
        frmDeque.assign(instrLayout.begin(), instrLayout.end());
        
        for(it = frmDeque.begin(); it < frmDeque.end(); it++){
            this->encodedInstruction += instruction.getBinInstruction().substr(it->getFirstField(), it->getSizeField());            
        }
        
    }

    void
    EncodeInstruction::printInstruction() {
        printInstruction(this);
    }
    
    void
    EncodeInstruction::printInstruction(IPBIWEncodeInstruction* printInstruction) const {
        cout << "\n---------------------------------------------" << endl;
        cout << "Instruction Address: " << printInstruction->getAddress_Seq() << endl;
        cout << "Encoded Instruction: " << printInstruction->getEncodeInstruction() << endl;
        cout << "Encoded HexInstruction: 0x" << printInstruction->getStrHexEncInstruction() << endl;
        cout << "Point to Pattern: " << printInstruction->getPointToPattern().getAddress();
    }        
}

}

}
