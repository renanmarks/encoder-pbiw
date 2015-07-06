/* 
 * File:   ParseFile.cpp
 * Author: renato
 * 
 * Created on October 16, 2012, 10:23 PM
 */

#include <fstream>
#include <iostream>
#include <streambuf>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <ios>
#include <map>
#include <deque>
#include <bitset>
#include <memory>
#include <math.h>

#include "../elfio/elfio.hpp"
#include "ParseFile.h"

using namespace ELFIO;
using namespace std;

namespace Sparc
{

namespace PBIW
{

namespace Tools
{

ParseFile::ParseFile() {
}

ParseFile::ParseFile(int indexSize):indexSize(indexSize) {
}

ParseFile::~ParseFile() {
}

void
ParseFile::readFile(string nameFile) {
    elfio elf;
    elf.load(nameFile);
    
    Elf_Half index;
    for ( int i = 0; i < elf.sections.size(); ++i ) {
        if(!strcasecmp(elf.sections[i]->get_name().c_str(), ".text")) {
            index = elf.sections[i]->get_index();
            break;
        }
    }

    int size = elf.sections[index]->get_size();
    const char* data = elf.sections[index]->get_data();
    int align = elf.sections[index]->get_addr_align();
    
    ofstream file;
    file.open("instructions.txt");
    
    string temp;
    char* hex = new char[align];
    int j = 0;
    for(int i = 0; i < size; ++i) {
        temp += hexToBin(data[i]);
        hex[j++] = data[i];

        if((i+1) % align == 0) {
            file << temp << endl;
            binaryDeque.push_back(Tools::OriginalInstruction(binToStrHex(temp), temp, hex));
            temp = "";
            j = 0;
        }
    }
    
    file.close();
    
    delete [] hex;
    
//    string nameFileTxt = nameFile + "_text.txt";
//    ofstream file("fat2_text.txt");
////    file.open("fat2_text.txt", ios::out | ios::binary);
//    int j = 0;
//    ostream& out = cout;
//    
//        out << DUMP_HEX_FORMAT(8) << data.substr(j,8);
    
//----------------------------------------------------------    
        
//    std::cout << "File name: " << nameFile << std::endl;
//    
//    ifstream file(nameFile.c_str());
//    ofstream binaryFile;
//    
//    char line[255];
//    
//    if(!file.is_open()) {
//        cout << "Could not open the file";
//        file.clear();
//    }
//    
//    if(!binaryFile.is_open()) {
//            binaryFile.open("binary.txt");
//    }
//    
//    while(!file.eof()) {
//        file.getline(line, 255);
//
//        char* p;
//        p = strtok(line, " ");
//                
//        while(p != NULL) {
//            string c = p;
//            if(c.find('.') > 100){                
//                if(p[1] == 'x') {
//                    cout << '\t' << p << endl;
//                    p = NULL;
//                }
//                else {
//                    string temp = p;
//                    
//                    if(temp.size() == 8) {
//                        cout << temp << endl;
//                        string bin = hexToStrBin(temp);
//                        binaryFile << bin << endl;
//                        
//                        binaryDeque.push_back(OriginalInstruction(temp, bin));
//                    }
//                }
//
//            }
//            p = strtok(NULL, " ");
//        }
//    }
//    binaryFile.close();
//    cout << binaryDeque.size() << endl;
//    
//    elfio reader;
//    reader.load("sample");
//    
//    string data = reader.sections[11]->get_data();
//    cout << "READ " << data.size() << endl; 
    
}

string
ParseFile::intToHex(int value) {
    stringstream stream;
    stream << std::setfill ('0') 
           << std::setw(2) 
           << std::hex << value;
    
    return hexStrToHex(stream.str());
}

int
ParseFile::hexToInt_(char hex) {
    return convertBinToInt(hexToBin(hex));
}

int
ParseFile::hexToInt(char* hex) {
    string temp;
            
    for(int i = 0; i < indexSize / 8; i++)
        temp += hexToBin(hex[i]);
    
    return convertBinToInt(temp);
}

int
ParseFile::hexToInt(const std::string& hex) {
    string bin;
    
    for(int i = 0; i < hex.length(); i++) {
        bin += hexToBin(hex.c_str()[i]);
    }
    
    return convertBinToInt(bin);
}

int
ParseFile::convertBinToInt(string bin) {
    int integer = 0;
    
    int exponent = bin.size();
    for(int i = 0; i < bin.size() ; ++i){
        --exponent;
        if(bin.substr(i, 1).compare("0"))
            integer += pow(2, exponent);
    }
            
    return integer;
}

string
ParseFile::hexStrToHex(string hex) {
    getChar.clear();
    getChar["0"] = '\x0';
    getChar["1"] = '\x1';
    getChar["2"] = '\x2';
    getChar["3"] = '\x3';
    getChar["4"] = '\x4';
    getChar["5"] = '\x5';
    getChar["6"] = '\x6';
    getChar["7"] = '\x7';
    getChar["8"] = '\x8';
    getChar["9"] = '\x9';
    getChar["a"] = '\xA';
    getChar["b"] = '\xB';
    getChar["c"] = '\xC';
    getChar["d"] = '\xD';
    getChar["e"] = '\xE';
    getChar["f"] = '\xF';

    string caractere;
    std::map<string,char>::iterator it;

        it = getChar.find(hex.substr(0,1));
        char auxL = it->second;
        auxL <<= 4;
        it = getChar.find(hex.substr(1,1));
        char auxR = it->second;
        caractere += auxL | auxR;            
    
    return caractere; 
}

string
ParseFile::hexToBin(char hex)
{
    if(getBin.size() != 16) {
        getBin.clear();
        getBin['\x0'] = "0000";
        getBin['\x1'] = "0001";
        getBin['\x2'] = "0010";
        getBin['\x3'] = "0011";
        getBin['\x4'] = "0100";
        getBin['\x5'] = "0101";
        getBin['\x6'] = "0110";
        getBin['\x7'] = "0111";
        getBin['\x8'] = "1000";
        getBin['\x9'] = "1001";
        getBin['\xA'] = "1010";
        getBin['\xB'] = "1011";
        getBin['\xC'] = "1100";
        getBin['\xD'] = "1101";
        getBin['\xE'] = "1110";
        getBin['\xF'] = "1111";
    }
    
    string caractere;
 
    std::map<char,string>::iterator it;
    char aux = hex;
    it = getBin.find((aux & 0xF0) >> 4);
    caractere += it->second;
    it = getBin.find((aux & 0xF));
    caractere += it->second;
    
    return caractere;     
}

string
ParseFile::hexToStrBin(string hex)
{
    if(getBin.size() != 16) {
        getBin.clear();
        getBin['0'] = "0000";
        getBin['1'] = "0001";
        getBin['2'] = "0010";
        getBin['3'] = "0011";
        getBin['4'] = "0100";
        getBin['5'] = "0101";
        getBin['6'] = "0110";
        getBin['7'] = "0111";
        getBin['8'] = "1000";
        getBin['9'] = "1001";
        getBin['a'] = "1010";
        getBin['b'] = "1011";
        getBin['c'] = "1100";
        getBin['d'] = "1101";
        getBin['e'] = "1110";
        getBin['f'] = "1111";
    }
    
    string caractere;
    
    if(hex.size() != 0) {
        int i = 0;
        
        std::map<char,string>::iterator it;
        
        while(i < hex.size()) {
            it = getBin.find(*(hex.substr(i++,1)).c_str());
            caractere += it->second;
        }
    }
    return caractere; 
    
}

string
ParseFile::binToHex(string bin) {
        getHex.clear();
        getHex["0000"] = '\x0';
        getHex["0001"] = '\x1';
        getHex["0010"] = '\x2';
        getHex["0011"] = '\x3';
        getHex["0100"] = '\x4';
        getHex["0101"] = '\x5';
        getHex["0110"] = '\x6';
        getHex["0111"] = '\x7';
        getHex["1000"] = '\x8';
        getHex["1001"] = '\x9';
        getHex["1010"] = '\xA';
        getHex["1011"] = '\xB';
        getHex["1100"] = '\xC';
        getHex["1101"] = '\xD';
        getHex["1110"] = '\xE';
        getHex["1111"] = '\xF';
        
        string caractere;
    
    if(bin.size() != 0) {
        
        std::map<string,char>::iterator it;
        
        for(int i = 0 ; i < bin.size(); i+=8) {
            it = getHex.find(bin.substr(i,4));
            char auxL = it->second;
            auxL <<= 4;
            it = getHex.find(bin.substr(i+4,4));
            char auxR = it->second;
            caractere += auxL | auxR;            
        }
    }
    return caractere; 
}

string
ParseFile::binToStrHex(string bin) {
        getHex.clear();
        getHex["0000"] = '0';
        getHex["0001"] = '1';
        getHex["0010"] = '2';
        getHex["0011"] = '3';
        getHex["0100"] = '4';
        getHex["0101"] = '5';
        getHex["0110"] = '6';
        getHex["0111"] = '7';
        getHex["1000"] = '8';
        getHex["1001"] = '9';
        getHex["1010"] = 'A';
        getHex["1011"] = 'B';
        getHex["1100"] = 'C';
        getHex["1101"] = 'D';
        getHex["1110"] = 'E';
        getHex["1111"] = 'F';
        
        string caractere;
    
    if(bin.size() != 0) {
        
        std::map<string,char>::iterator it;
        
        for(int i = 0 ; i < bin.size(); i+=4) {
            it = getHex.find(bin.substr(i,4));
            caractere += it->second;            
        }       
    }
    return caractere; 
}

void
ParseFile::readLayoutFile(string nameFile) {
    std::cout << "File name: " << nameFile << std::endl;
    
    ifstream file(nameFile.c_str());
    
    char line[255];
    
    if(!file.is_open()) {
        cout << "Could not open the file";
        file.clear();
    }
    else {
        LayoutFieldsFMTMap* fmtDeques;
        LayoutFieldsFMTMap::iterator it;
        bool isPattern = true;
        int size;

        while(!file.eof()) {
            file.getline(line, 255);

            char* p;
            p = strtok(line, " ,");

            string temp;

            if(p != NULL)
                temp = p;

            if(!strcasecmp(temp.c_str(), "index_size")) {
                    p = strtok(NULL, " ,");
                    this->indexSize = atoi(p);
                    p = strtok(NULL, " ,");
            }
            else if(!strcasecmp(temp.c_str(), "Instruction")) {
                LayoutFieldsDeque fmt0_10, fmt0_100, fmt1, fmt2_0, fmt2_1;
                instructionFields["fmt0_10"] = fmt0_10;
                instructionFields["fmt0_100"] = fmt0_100;
                instructionFields["fmt1"] = fmt1;
                instructionFields["fmt2_0"] = fmt2_0;
                instructionFields["fmt2_1"] = fmt2_1;
                fmtDeques = &instructionFields;
                p = strtok(NULL, " ");
                isPattern = false;
                size = 0;
            }
            else if(!strcasecmp(temp.c_str(), "Pattern")) {
                LayoutFieldsDeque fmt0_10, fmt0_100, fmt1, fmt2_0, fmt2_1;
                patternFields["fmt0_10"] = fmt0_10;
                patternFields["fmt0_100"] = fmt0_100;
                patternFields["fmt1"] = fmt1;
                patternFields["fmt2_0"] = fmt2_0;
                patternFields["fmt2_1"] = fmt2_1;
                fmtDeques = &patternFields;
                p = strtok(NULL, " ");
                isPattern = true;
                size = 0;
            }

            if(!strcasecmp("fmt0_10", temp.c_str())) {
                it = fmtDeques->find("fmt0_10");
                p = strtok(NULL, " ,");
            }
            else if(!strcasecmp("fmt0_100", temp.c_str())) {
                it = fmtDeques->find("fmt0_100");
                p = strtok(NULL, " ,");
            }
            else if(!strcasecmp("fmt1", temp.c_str())) {
                it = fmtDeques->find("fmt1");
                p = strtok(NULL, " ,");
            }
            else if(!strcasecmp("fmt2_0", temp.c_str())) {
                it = fmtDeques->find("fmt2_0");
                p = strtok(NULL, " ,");
            }
            else if(!strcasecmp("fmt2_1", temp.c_str())) {
                it = fmtDeques->find("fmt2_1");
                p = strtok(NULL, " ,");
            }

            while(p != NULL) {
                int first = atoi(p);
                p = strtok(NULL, " ,");
                int second = atoi(p);
                it->second.push_back(Tools::Field(first, second));
                p = strtok(NULL, " ,");
            }
        }        
    }
}

ParseFile::LayoutFieldsFMTMap
ParseFile::getInstructionFields() {
    return LayoutFieldsFMTMap(this->instructionFields.begin(),this->instructionFields.end());
}

ParseFile::LayoutFieldsFMTMap
ParseFile::getPatternFields() {
    return LayoutFieldsFMTMap(this->patternFields.begin(),this->patternFields.end());
}

int
ParseFile::getIndexSize() {
    return this->indexSize;
}

std::deque<Tools::OriginalInstruction>
ParseFile::getInstructionsDeque() {
    return std::deque<Tools::OriginalInstruction>(binaryDeque.begin(), binaryDeque.end());
}

}

}

}
