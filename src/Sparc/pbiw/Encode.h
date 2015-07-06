/* 
 * File:   Encode.h
 * Author: renato
 *
 * Created on October 24, 2012, 2:36 PM
 */

#ifndef PBIWSPARC_ENCODE_H
#define	PBIWSPARC_ENCODE_H

#include <deque>
#include <set>
#include "OriginalInstruction.h"
#include "EncodeInstruction.h"
#include "EncodePattern.h"


using namespace std;

namespace Sparc
{

namespace PBIW
{

class Encode {
public:
    typedef std::deque<OriginalInstruction> OriginalInstDeque;
    
    Encode();
    Encode(OriginalInstDeque instrDeque);
    virtual ~Encode();
    
    virtual void toEncode();
    
    virtual bool hasPattern(EncodePattern pattern);
private:
    typedef std::deque<EncodeInstruction> EncInstDeque;
    EncInstDeque encInstDeque;
    
    typedef std::deque<EncodePattern> EncPatDeque;
    EncPatDeque encPatDeque;
    
    OriginalInstDeque originalInstructions;
};

}

}

#endif	/* ENCODE_H */

