/* 
 * File:   ParseFile.cpp
 * Author: renato
 * 
 * Created on October 16, 2012, 10:23 PM
 */

#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <ios>
#include <map>
#include <deque>

#include "ParseFile.h"

namespace Sparc
{

namespace PBIW
{

ParseFile::ParseFile() {
}

ParseFile::ParseFile(const ParseFile& orig) {
}

ParseFile::~ParseFile() {
}

void
ParseFile::readFile(string nameFile) {
    
    std::cout << "Nome do arquivo " << nameFile << std::endl;
    
    ifstream file(nameFile.c_str());
    ofstream binaryFile;
    
    char line[255];
    
    if(!file.is_open()) {
        cout << "Could not open the file";
        file.clear();
    }
    
    if(!binaryFile.is_open()) {
            binaryFile.open("binary.txt");
    }
    
    while(!file.eof()) {
        file.getline(line, 255);

        char* p;
        p = strtok(line, " ");
                
        while(p != NULL) {
           
            if(p[0] != '.' && p[1] != '.') {
                if(p[1] == 'x') {
                    cout << '\t' << p << endl;
                    p = NULL;
                }
                else {
                    string temp = p;
                    
                    if(temp.size() == 8) {
                        cout << temp << endl;
                        string bin = hexToBin(temp);
                        binaryFile << bin << endl;
                        binaryDeque.push_back(OriginalInstruction(temp, bin));
                    }
                }

            }
            p = strtok(NULL, " ");
        }
    }
    binaryFile.close();
    cout << binaryDeque.size() << endl;
    
}

string
ParseFile::hexToBin(string hex)
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
        cout << caractere << endl;
    }
    return caractere;
    
}

std::deque<OriginalInstruction>
ParseFile::getInstructionsDeque() {
    return std::deque<OriginalInstruction>(binaryDeque.begin(), binaryDeque.end());
}

}

}
