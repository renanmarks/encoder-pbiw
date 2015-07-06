/* 
 * File:   OriginalInstruction.h
 * Author: renato
 *
 * Created on October 23, 2012, 8:16 PM
 */

#ifndef PBIWSPARC_TOOLS_ORIGINALINSTRUCTION_H
#define	PBIWSPARC_TOOLS_ORIGINALINSTRUCTION_H

#include <string>

using namespace std;

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    class OriginalInstruction {
    public:
        OriginalInstruction();
        OriginalInstruction(string bin);
        OriginalInstruction(string hexStr, string bin, string hex);
        virtual ~OriginalInstruction();

        virtual string getHexStrInstruction();
        virtual string getBinInstruction();
        virtual void setBinInstruction(string binInstruction);
        virtual string getHexInstruction();

    private:
        string hexStrInstruction;
        string binInstruction;
        string hexInstruction;
    };

}

}

}

#endif	/* ORIGINALINSTRUCTION_H */

