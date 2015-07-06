/* 
 * File:   ParseFile.h
 * Author: renato
 *
 * Created on October 16, 2012, 10:23 PM
 */


#ifndef PBIWSPARC_PARSEFILE_H
#define	PBIWSPARC_PARSEFILE_H

#include <fstream>
#include <iostream>
#include <map>
#include <deque>
#include <set>

#include "OriginalInstruction.h"

using namespace std;

namespace Sparc
{

namespace PBIW
{

class ParseFile {
public:
    ParseFile();
    ParseFile(const ParseFile& orig);
    virtual ~ParseFile();
    
    virtual void readFile(string nameFile);    
    virtual string hexToBin(string hex);
    virtual std::deque<OriginalInstruction> getInstructionsDeque();
        
private:
    std::map<char, string> getBin;    
    typedef std::deque<OriginalInstruction> BinaryDeque;
    BinaryDeque binaryDeque;    
};

}

}

#endif	/* PARSEFILE_H */

