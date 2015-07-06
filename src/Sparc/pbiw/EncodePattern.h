/* 
 * File:   EncodePattern.h
 * Author: renato
 *
 * Created on October 24, 2012, 4:55 PM
 */

#ifndef PBIWSPARC_ENCODEPATTERN_H
#define	PBIWSPARC_ENCODEPATTERN_H

#include "OriginalInstruction.h"


using namespace std;

namespace Sparc
{

namespace PBIW
{

class EncodePattern {
public:
    EncodePattern();
//    EncodePattern(const EncodePattern& orig);
    virtual ~EncodePattern();

    virtual void setEncodePattern(string pattern);
    virtual string getEncodePattern();
    
    /**
     * @param instruction
     * 
     * Encode instruction with field op = 1.
     */
    virtual void fmt1EncodePattern(OriginalInstruction instruction);
    
    /**
     * @param instruction
     * 
     * Encode instruction with field op = 0.
     */
    virtual void fmt2EncodePattern(OriginalInstruction instruction);
    
    /**
     * @param instruction
     * 
     * Encode instruction with field op = 2 or op = 3.
     */
    virtual void fmt3EncodePattern(OriginalInstruction instruction);
    
private:
    string encodedPattern;    
};

}

}

#endif	/* ENCODEPATTERN_H */

