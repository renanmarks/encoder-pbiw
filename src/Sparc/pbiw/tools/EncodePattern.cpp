/* 
 * File:   EncodePattern.cpp
 * Author: renato
 * 
 * Created on October 24, 2012, 4:55 PM
 */

#include <iostream>
#include <memory>
#include <stdlib.h>
#include "Encode.h"
#include "EncodePattern.h"
#include "EncodeInstruction.h"
#include "ParseFile.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    EncodePattern::EncodePattern():address(-1) {
    }

    EncodePattern::~EncodePattern() {        
    }

    void
    EncodePattern::setHexEncodePattern(string pattern) {
        this->hexEncodedPattern = ParseFile().binToHex(pattern);
        this->setStrHexEncPattern(pattern);
    }
    
    string
    EncodePattern::getHexEncodePattern() const {
        return this->hexEncodedPattern;
    }
    
    void
    EncodePattern::setStrHexEncPattern(string pattern) {
        this->strHexEncPattern = ParseFile().binToStrHex(pattern);
    }
    
    string
    EncodePattern::getStrHexEncPattern() {
        return this->strHexEncPattern;
    }
    
    void
    EncodePattern::setEncodePattern(string pattern) {
        this->encodedPattern = pattern;
        this->setHexEncodePattern(this->encodedPattern);        
    }

    string
    EncodePattern::getEncodePattern() const {
        return this->encodedPattern;
    }
    
    void
    EncodePattern::setAddress(int address) {
        this->address = address;
        this->setHexEncodePattern(this->encodedPattern);
    }

    int
    EncodePattern::getAddress() const {
        return address;
    }

    std::deque<IPBIWEncodeInstruction*>
    EncodePattern::getInstructionsThatUseIt() {
        return std::deque<IPBIWEncodeInstruction*>(instructionsThatUseIt.begin(), instructionsThatUseIt.end());                
    }
    
    void
    EncodePattern::includeInstructionUseIt(IPBIWEncodeInstruction* instruction) {
        this->instructionsThatUseIt.push_back(instruction);
    }

    void
    EncodePattern::fmtAllEncodePattern(OriginalInstruction instruction, FieldPattern pattLayout) {
        FieldPattern::iterator it;
        FieldPattern frmDeque;
        
        frmDeque.assign(pattLayout.begin(), pattLayout.end());
        
        for(it = frmDeque.begin(); it < frmDeque.end(); it++){
            this->encodedPattern += instruction.getBinInstruction().substr(it->getFirstField(), it->getSizeField());
        }
        
        this->setHexEncodePattern(this->encodedPattern);
    }
    
    void
    EncodePattern::printPattern() {
        printPattern(this);
    }
    
    void
    EncodePattern::printPattern(IPBIWEncodePattern* pattern) const {
        typedef std::deque<IPBIWEncodeInstruction*> Type;
        Type instruction = pattern->getInstructionsThatUseIt();
        EncInstDeque::iterator it;
        
        cout << "=============================================" << endl;
        cout << "Pattern Address: " << pattern->getAddress() << endl;
        cout << "Encoded Pattern: " << pattern->getEncodePattern() << endl;
        cout << "Encoded HexPattern: 0x" << pattern->getStrHexEncPattern() << endl;
        cout << "Amount instructions: " << instruction.size() << endl;
        cout << "---------------------------------------------" << endl;
        cout << "---------- Instructions That Use It ---------";
        
        for(it = instruction.begin(); it < instruction.end(); it++) {
            (*it)->printInstruction();
        }        
    }
    
    bool
    EncodePattern::operator ==(const IPBIWEncodePattern& other) const {
        IPBIWEncodePattern& tempPattern = const_cast<IPBIWEncodePattern&>(other);
        EncodePattern& otherTemp = static_cast<EncodePattern&> (tempPattern);
        

        if((this->encodedPattern == otherTemp.getEncodePattern()) && (this->getAddress() == other.getAddress()))
            return true;
        else
            return false;
    }
    
    bool
    EncodePattern::operator !=(const IPBIWEncodePattern& other) const {
        return !(*this == other);
    }
}

}

}
