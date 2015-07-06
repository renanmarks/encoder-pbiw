/* 
 * File:   OriginalInstruction.h
 * Author: renato
 *
 * Created on October 23, 2012, 8:16 PM
 */

#ifndef PBIWSPARC_ORIGINALINSTRUCTION_H
#define	PBIWSPARC_ORIGINALINSTRUCTION_H

#include <string>

using namespace std;

namespace Sparc
{

namespace PBIW
{

class OriginalInstruction {
public:
    OriginalInstruction();
    OriginalInstruction(string hex, string bin);
    virtual ~OriginalInstruction();
    
    virtual string getHexInstruction();
    virtual string getBinInstruction();
    
private:
    string hexInstruction;
    string binInstruction;
};

}

}

#endif	/* ORIGINALINSTRUCTION_H */

