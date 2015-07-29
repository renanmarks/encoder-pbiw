/* 
 * File:   Encode.cpp
 * Author: renato
 * 
 * Created on October 24, 2012, 2:36 PM
 */

#include <stdlib.h>
#include <fstream>
#include "OriginalInstruction.h"
#include "ParseFile.h"
#include "Encode.h"
#include "InstructionLayout.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    Encode::Encode() {
    }

    Encode::Encode(OriginalInstDeque instrDeque) {
        this->instructionLayout = InstructionLayout();
        this->patternLayout = PatternLayout();
        originalInstructions.assign(instrDeque.begin(), instrDeque.end());
    }
    
    Encode::Encode(OriginalInstDeque instrDeque, InstructionLayout instrLayout, PatternLayout pattLayout) {
        originalInstructions.assign(instrDeque.begin(), instrDeque.end());
        this->instructionLayout = instrLayout;
        this->patternLayout = pattLayout;
    }

    Encode::~Encode() {
        for(EncInstDeque::iterator it = encodedInstructions.begin(); it != encodedInstructions.end(); it++)
        {
            delete *it;
        }

        for(EncPatDeque::iterator it = encodedPatterns.begin(); it != encodedPatterns.end(); it++)
        {
            delete *it;
        }

        for(EncInstDeque::iterator it = hexInstructions.begin(); it != hexInstructions.end(); it++)
        {
            delete *it;
        }
    }

    void
    Encode::toEncode() {

        EncodeInstruction* newInstruction;
        EncodePattern* newPattern;
        
        OriginalInstDeque::iterator it;
        
        for(it = this->originalInstructions.begin(); 
                it < originalInstructions.end(); 
                it++)
        {
            createNewElements(newPattern, newInstruction);

            newInstruction->setIndexSize(this->instructionLayout.getIndexSize());
            
            string instruction = it->getBinInstruction();
            int twoBits = atoi(instruction.substr(0,2).c_str());
            int op2;
            int op3;
            int i;

            switch(twoBits)
            {
                case 00: 
                    op2 = atoi(instruction.substr(7,3).c_str());

                    switch(op2) 
                    {
                        case 0:
                        case 100:
                            newInstruction->fmtAllEncodeInstruction(*it, this->instructionLayout.getFieldInstFmt0_100());
                            newPattern->fmtAllEncodePattern(*it, this->patternLayout.getFieldPattFmt0_100());                            
                            break;
                        case 10:
                        case 110:
                        case 111: 
                            newInstruction->fmtAllEncodeInstruction(*it, this->instructionLayout.getFieldInstFmt0_10());
                            newPattern->fmtAllEncodePattern(*it, this->patternLayout.getFieldPattFmt0_10());
                            break;
                    }
                    break;
                case 01: 
                    newInstruction->fmtAllEncodeInstruction(*it, this->instructionLayout.getFieldInstFmt1());
                    newPattern->fmtAllEncodePattern(*it, this->patternLayout.getFieldPattFmt1());
                    break;
                case 10:
                case 11:
                    op3 = atoi(instruction.substr(8,6).c_str());
                    i = atoi(instruction.substr(19,1).c_str());
                    
                    if((i = 1) && (op3 != 110100 && op3 != 110101 && op3 != 110110 && op3 != 110111)) {
                        newInstruction->fmtAllEncodeInstruction(*it, this->instructionLayout.getFieldInstFmt2_1());
                        newPattern->fmtAllEncodePattern(*it, this->patternLayout.getFieldPattFmt2_1());
                    }
                    else {
                        newInstruction->fmtAllEncodeInstruction(*it, this->instructionLayout.getFieldInstFmt2_0());
                        newPattern->fmtAllEncodePattern(*it, this->patternLayout.getFieldPattFmt2_0());
                    }
                    break;
            }
            this->saveElements(newPattern, newInstruction);
        }
    }
    
    void
    Encode::statistics() {
        string instruction = encodedInstructions.front()->getEncodeInstruction();
        string pattern = encodedPatterns.front()->getEncodePattern();
        
        cout << "\n\n=============================================" << endl;
        cout << "----------------- Statistics ----------------" << endl;
        cout << "=============================================" << endl;
        cout << "Total Instructions: " << encodedInstructions.size() << endl;
        cout << "Total Patterns: " << encodedPatterns.size() << endl;
        cout << "Reuse rate: " << encodedInstructions.size() / encodedPatterns.size() << endl;
        cout << "Compress rate: " << (((encodedInstructions.size() * instruction.size())+(encodedPatterns.size() * pattern.size()))/(double)(originalInstructions.size() * 32)) * 100;
        cout << " %" << endl;
        cout << "Total Encoded: " << (double)((encodedInstructions.size() * instruction.size())+(encodedPatterns.size() * pattern.size()))/8 << " Bytes" << endl;
        cout << "Total Original: " << (double)((originalInstructions.size() * 32)/8) << " Bytes" << endl;
        cout << "Layout: (P)" << pattern.size() << " X " << instruction.size() << "(I)" << endl;
        cout << "=============================================\n" << endl;
    }
    
    void
    Encode::createNewElements(EncodePattern*& newPattern, EncodeInstruction*& newInstruction) {
        newInstruction = new EncodeInstruction();
        newPattern = new EncodePattern();
    }
  
    void
    Encode::saveElements(EncodePattern*& pattern, EncodeInstruction*& instruction) {
        IPBIWEncodePattern& returnedPattern = hasPattern(*pattern);
        
        if(&returnedPattern == pattern) {
            pattern->setAddress(encodedPatterns.size());
            encodedPatterns.push_back(pattern);            
        }
        else {
            delete pattern; 
        }
        
        instruction->setPointToPattern(returnedPattern);
        instruction->setAddress(returnedPattern.getAddress());
        instruction->setAddress_Seq(encodedInstructions.size());
        encodedInstructions.push_back(instruction);        
    }

    IPBIWEncodePattern&
    Encode::hasPattern(IPBIWEncodePattern& pattern) {
        EncPatDeque::iterator it;

        if(encodedPatterns.empty()) {
            return pattern;
        }
        else {
            for(it = encodedPatterns.begin(); it != encodedPatterns.end(); it++) {
                if((*it)->getEncodePattern().compare(pattern.getEncodePattern()) == 0) {
                    return **it; 
                }
            }
            return pattern;
        }
    }
    
    string
    Encode::encodeLayout() {
        ParseFile parse;
        string encodedLayout;
        
        encodedLayout = parse.intToHex(instructionLayout.getIndexSize()) ;
        encodedLayout += processFields(instructionLayout.getFieldsInstruction());
        encodedLayout += '\xFF' + processFields(patternLayout.getFieldsPattern());
        
        return encodedLayout;
    }
    
    string
    Encode::processFields(AllFieldsDeque fields) {
        ParseFile parse;
        AllFieldsDeque::const_iterator it1;
        string encodedLayout;
        
        for(it1 = fields.begin(); it1 < fields.end(); it1++) {
            FieldsDeque::iterator it2;
            for(it2 = (*it1)->begin(); it2 < (*it1)->end(); it2++) {
                encodedLayout += parse.intToHex((*it2).getFirstField());
                encodedLayout += parse.intToHex((*it2).getSizeField());
            }
            if(it1+1 != fields.end())
                encodedLayout += '\xFF';
            else
                encodedLayout += "\xFF";
        }
        
        return encodedLayout;
    }
        
    
    Encode::EncInstDeque
    Encode::getEncodedInstructions() {
        return EncInstDeque(this->encodedInstructions.begin(), this->encodedInstructions.end());
    }
    
    Encode::EncPatDeque
    Encode::getEncodedPatterns() {
        return EncPatDeque(this->encodedPatterns.begin(), this->encodedPatterns.end());
    }
    
    InstructionLayout
    Encode::getInstrucionLayout() {
        return instructionLayout;
    }
    
    PatternLayout
    Encode::getPatternLayout() {
        return patternLayout;
    }
    
    void
    Encode::printEncoded() {
        EncPatDeque::iterator it2;
        
        cout << "=============================================" << endl;
        cout << "===== Encoded Patterns and Instructions =====" << endl;
                
        for(it2 = encodedPatterns.begin(); it2 < encodedPatterns.end(); it2++){
            (*it2)->printPattern();
            cout << endl;
        }                
        cout << "=============================================" << endl;
    }
    
    void
    Encode::printInstructionsFile() {
        ofstream File("instruction_encode.txt");
        EncInstDeque::iterator it;
        
        for(it = encodedInstructions.begin(); it < encodedInstructions.end(); it++) {
            File << (*it)->getEncodeInstruction() << endl;
        } 
    }
    
    void
    Encode::printPatternsFile() {
        ofstream File("pattern_encode.txt");
        EncPatDeque::iterator it;
        
        for(it = encodedPatterns.begin(); it < encodedPatterns.end(); it++) {
            File << (*it)->getEncodePattern() << endl;
        } 
    }
    
    void
    Encode::printEncodedFiles() {
        this->printInstructionsFile();
        this->printPatternsFile();
    }
    
    void
    Encode::printUniquePaterns() {
        EncPatDeque::iterator it;
        int count = 0;
        
        for(it = encodedPatterns.begin(); it < encodedPatterns.end(); it++) {
            if((*it)->getInstructionsThatUseIt().size() == 1) {
//                (*it)->printPattern();
                count++;
            }
        }
        
        cout << "Unique patterns: " << count << endl;
    }
}

}

}
