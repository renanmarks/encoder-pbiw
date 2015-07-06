/* 
 * File:   EncodeInstruction.h
 * Author: renato
 *
 * Created on October 24, 2012, 4:55 PM
 */

#ifndef PBIWSPARC_ENCODEINSTRUCTION_H
#define	PBIWSPARC_ENCODEINSTRUCTION_H

#include "OriginalInstruction.h"


using namespace std;

namespace Sparc
{

namespace PBIW
{

class EncodeInstruction {
public:
    EncodeInstruction();
    EncodeInstruction(const EncodeInstruction& orig);
    virtual ~EncodeInstruction();
    
    virtual void setEncodeInstruction(string instruction);
    virtual string getEncodeInstruction();
    
    virtual void fmt1EncodeInstruction(OriginalInstruction instruction);
    virtual void fmt2EncodeInstruction(OriginalInstruction instruction);
    virtual void fmt3EncodeInstruction(OriginalInstruction instruction);
    
    
    
private:
    string encodedInstruction;
};

}

}

#endif	/* ENCODEINSTRUCTION_H */

