/* 
 * File:   Decode.cpp
 * Author: renato
 * 
 * Created on February 25, 2013, 6:43 PM
 */

#include <iostream>
#include <string.h>
#include "Decode.h"
#include "EncodePattern.h"
#include "ParseFile.h"
#include "ElfHandling.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    Decode::Decode(string name):fileName(name)
    {       
        loadLayout();
    }
    
    Decode::Decode(string name, InstructionLayout& inst, PatternLayout& patt)
            :fileName(name),
            instructionLayout(&inst),
            patternLayout(&patt)
    {
        loadLayout();
    }

    Decode::~Decode() {
    }
    
    void
    Decode::decodeInstructions() {        
//        this->loadLayout();
        this->loadInstructions();
        this->loadPatterns();
        this->decode();
        this->setOnELF();
//        this->print();
    }
    
    void
    Decode::decode() {
        EncInstDeque::iterator it;
        
        for(it = encodeInstructions.begin(); it != encodeInstructions.end(); it++) {
            restoreOriginalInstruction(encodePatterns.at((*it)->getAddress()),*it);
        }
        
    }
    
    void
    Decode::setOnELF() {
        ElfHandling elfHandling(fileName);
        elfHandling.setDecodedInstructions(originalInstructions, 0x4);
    }
    
    void
    Decode::restoreOriginalInstruction(IPBIWEncodePattern*& pattern, IPBIWEncodeInstruction*& instruction) {
        int op2;
        int op3;
        int i;
        string restored;
        
        string patternBin = pattern->getEncodePattern();
        int twoBits = atoi(patternBin.substr(0,2).c_str());
                
        switch(twoBits)
        {
            case 00: 
                op2 = atoi(patternBin.substr(2,3).c_str());

                switch(op2)
                {
                    case 0:
                    case 100:
                        restored = fmtAllDecode(instruction, pattern, instructionLayout->getFieldInstFmt0_100(),
                                        patternLayout->getFieldPattFmt0_100());                            
                        break;
                    case 10:
                    case 110:
                    case 111: 
                        restored = fmtAllDecode(instruction, pattern, instructionLayout->getFieldInstFmt0_10(),
                                        patternLayout->getFieldPattFmt0_10());
                        break;
                }
                break;
            
            case 01: 
                restored = fmtAllDecode(instruction, pattern, instructionLayout->getFieldInstFmt1(),
                                patternLayout->getFieldPattFmt1());
                break;
            
            case 10:
            case 11:
                op3 = atoi(patternBin.substr(8,6).c_str());
                i = atoi(patternBin.substr(14,1).c_str());
                        
                if((i = 1) && (op3 != 110100 && op3 != 110101 && op3 != 110110 && op3 != 110111)) {
                    restored = fmtAllDecode(instruction, pattern, instructionLayout->getFieldInstFmt2_1(),
                                patternLayout->getFieldPattFmt2_1());
                }
                else {
                    restored = fmtAllDecode(instruction, pattern, instructionLayout->getFieldInstFmt2_0(),
                                patternLayout->getFieldPattFmt2_0());
                }
                break;
        }
        
        originalInstructions.push_back(OriginalInstruction(ParseFile().binToStrHex(restored), restored, ParseFile().binToHex(restored)));
    }
    
    string
    Decode::fmtAllDecode(IPBIWEncodeInstruction* instruction, IPBIWEncodePattern* pattern, FieldDeque instLayout, FieldDeque pattLayout) {
        FieldDeque::iterator itPatt;
        FieldDeque::iterator itInst; 
        FieldDeque frmPatt;
        FieldDeque frmInst;
        string patt = pattern->getEncodePattern();
        string inst = instruction->getEncodeInstruction();
        string original(32, '0');
        
        frmPatt.assign(pattLayout.begin(), pattLayout.end());
        frmInst.assign(instLayout.begin(), instLayout.end());
        
        int inst_off = 0;
        for(itPatt = frmPatt.begin(); itPatt < frmPatt.end(); itPatt++) {
            string temp = patt.substr(inst_off, itPatt->getSizeField());
            original.replace(itPatt->getFirstField(), itPatt->getSizeField(), temp);
            inst_off += itPatt->getSizeField();
        }

        inst_off = instructionLayout->getIndexSize();
        for(itInst = frmInst.begin(); itInst < frmInst.end(); itInst++) {
            string temp = inst.substr(inst_off, itInst->getSizeField());
            original.replace(itInst->getFirstField(), itInst->getSizeField(), temp);
            inst_off += itInst->getSizeField();
        }
        return original;
    }
        
    void
    Decode::loadLayout() {
        if(reader.load(fileName)) {
            Elf_Half index;
            for(int i = 0; i < reader.sections.size(); ++i) {
                if(!strcasecmp(reader.sections[i]->get_name().c_str(), ".layout")) {
                    index = reader.sections[i]->get_index();
                    break;
                }
            }
            
            int size = reader.sections[index]->get_size();
            const char* data = new char[size];
            data = reader.sections[index]->get_data();
            instructionLayout->setIndexSize(ParseFile().hexToInt_(data[0]));
            int index_ = 1;
            instructionLayout->setFieldsInstruction(processFields(data, &index_, size));
            patternLayout->setFieldsPattern(processFields(data, &index_, size));
        }
        else {
            cout << "File not found." << endl;
        }
    }
    
    Decode::AllFieldsDeque
    Decode::processFields(const char* data, int* pos, int size) {
        ParseFile parse;
        AllFieldsDeque fieldDeque;
        FieldDeque fields;
        int index = *pos;
        
        for( ; index < size; index++) {
            if(data[index] != '\xFF' && data[index+1] != '\xFF') {
                fields.push_back(Field(parse.hexToInt_(data[index]), parse.hexToInt_(data[index+1])));
                index ++;
            }
            else if(data[index] == '\xFF' && data[index+1] == '\xFF') {
                fieldDeque.push_back(fields);
                index += 2;
//                aux = data->substr(index, data->size()-index);
                break;
            }
            else {
                if(index+1 < 60)
                    fieldDeque.push_back(fields);
//                index++;
                fields.clear();
//                aux = data->substr(index, data->size()-index);
            }
        }
//        *data = data->substr(index, data->size()-index);
        *pos = index;
        return fieldDeque;
    }
    
    void
    Decode::loadInstructions() {
        if(reader.load(fileName)) {
            Elf_Half index;
            for(int i = 0; i < reader.sections.size(); ++i) {
                if(!strcasecmp(reader.sections[i]->get_name().c_str(), ".text")) {
                    index = reader.sections[i]->get_index();
                    break;
                }
            }

            int size = reader.sections[index]->get_size();
            const char* data = new char[size];
            data = reader.sections[index]->get_data();
            string temp;
            int align = reader.sections[index]->get_addr_align();
            char* hex = new char[align];
            int j = 0;
            IPBIWEncodeInstruction* instruction;
            ParseFile parse(this->instructionLayout->getIndexSize());

            for(int i = 0; i < size; ++i) {
                temp += parse.hexToBin(data[i]);
                hex[j++] = data[i];

                if((i+1) % align == 0) {
                    instruction = new EncodeInstruction();
                    instruction->setEncodeInstruction(temp);
                    instruction->setAddress(parse.hexToInt(hex));
                    encodeInstructions.push_back(instruction);
                    temp = "";
                    j = 0;
                }
            }
            delete [] hex;            
        }
        else {
            cout << "File not found." << endl;
        }
    }
    
    void
    Decode::loadPatterns() {
//        ifstream patterns;
//        patterns.open("pattern_encode.txt");
//        IPBIWEncodePattern* pattern;
//        string patternBin;
//        int address = 0;
//
//        while(patterns.good()) {
//            patterns >> patternBin;
//            pattern = new EncodePattern();
//            pattern->setEncodePattern(patternBin);
//            encodePatterns.push_back(pattern);
//            address++;            
//        }
        if(reader.load(fileName)) {
            Elf_Half index;
            for(int i = 0; i < reader.sections.size(); ++i) {
                if(!strcasecmp(reader.sections[i]->get_name().c_str(), ".pattern")) {
                    index = reader.sections[i]->get_index();
                    break;
                }
            }

            int size = reader.sections[index]->get_size();
            const char* data = new char[size];
            data = reader.sections[index]->get_data();
            string temp;
            int align = reader.sections[index]->get_addr_align();
            char* hex = new char[align];
            int j = 0;
            IPBIWEncodePattern* pattern;
            ParseFile parse;

            for(int i = 0; i < size; ++i) {
                temp += parse.hexToBin(data[i]);
                hex[j++] = data[i];

                if((i+1) % align == 0) {
                    pattern = new EncodePattern();
                    pattern->setEncodePattern(temp);
                    encodePatterns.push_back(pattern);
                    temp = "";
                    j = 0;
                }
            }
            delete [] hex;            
        }
        else {
            cout << "File not found." << endl;
        }
    }
    
    void
    Decode::removeSections() {
        elfio elf;
        
        elf.load(fileName);
        elf.remove_save(fileName);
    }
    
    void
    Decode::print() {
        OriginalInstDeque::iterator it;
        ofstream original;
        original.open("original_instructions.txt");
        
        for(it = originalInstructions.begin(); it != originalInstructions.end(); it++) {
            string instruction = it->getBinInstruction();
            original << instruction << endl;
            cout << instruction << endl;
        }        
        original.close();
    }
    
    void
    Decode::printDecoded() {
        EncPattDeque::iterator it2;
        
        for(it2 = encodePatterns.begin(); it2 < encodePatterns.end(); it2++){
            (*it2)->printPattern();
            cout << endl;
        }
    }
}

}

}
