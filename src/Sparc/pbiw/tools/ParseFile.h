/* 
 * File:   ParseFile.h
 * Author: renato
 *
 * Created on October 16, 2012, 10:23 PM
 */


#ifndef PBIWSPARC_TOOLS_PARSEFILE_H
#define	PBIWSPARC_TOOLS_PARSEFILE_H

#include <fstream>
#include <iostream>
#include <map>
#include <deque>
#include <set>
#include <iomanip>

#include "../elfio/elfio.hpp"
#include "OriginalInstruction.h"
#include "InstructionLayout.h"

using namespace std;
using namespace ELFIO;

namespace Sparc
{

namespace PBIW
{

namespace Tools
{

class ParseFile {
  
public:
    ParseFile();
    ParseFile(int indexSize);
    virtual ~ParseFile();
    
    typedef std::deque<Tools::Field> LayoutFieldsDeque; 
    typedef std::map<string, LayoutFieldsDeque> LayoutFieldsFMTMap;
    
    virtual void readFile(string nameFile);
    virtual string intToHex(int value);
    virtual int hexToInt_(char hex);
    virtual int hexToInt(char* hex);
    virtual int hexToInt(const std::string& hex);
    virtual string hexStrToHex(string hex);
    virtual string hexToBin(char hex);
    virtual string hexToStrBin(string hex);
    virtual string binToHex(string bin);
    virtual string binToStrHex(string bin);
    virtual void readLayoutFile(string layoutFile);
    virtual LayoutFieldsFMTMap getInstructionFields();
    virtual LayoutFieldsFMTMap getPatternFields();
    virtual int getIndexSize();
    virtual std::deque<Tools::OriginalInstruction> getInstructionsDeque();
    
private:
    virtual int convertBinToInt(string bin);
    
    int indexSize;
    LayoutFieldsFMTMap instructionFields;
    LayoutFieldsFMTMap patternFields;
    std::map<char, string> getBin;
    std::map<string, char> getHex;
    std::map<string, char> getChar;
    typedef std::deque<Tools::OriginalInstruction> BinaryDeque;
    BinaryDeque binaryDeque;    
    

};

}

}

}
//#undef DUMP_HEX_FORMAT
#endif	/* PARSEFILE_H */

