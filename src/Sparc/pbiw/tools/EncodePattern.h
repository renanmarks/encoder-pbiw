/* 
 * File:   EncodePattern.h
 * Author: renato
 *
 * Created on October 24, 2012, 4:55 PM
 */

#ifndef PBIWSPARC_TOOLS_ENCODEPATTERN_H
#define	PBIWSPARC_TOOLS_ENCODEPATTERN_H

#include <deque>
#include "OriginalInstruction.h"
#include "EncodeInstruction.h"
#include "Interfaces/IPBIWEncodePattern.h"
#include "Interfaces/IPBIWEncodeInstruction.h"
#include "PatternLayout.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    using namespace Tools::Intefaces;

    class EncodePattern : public IPBIWEncodePattern {
    public:
        EncodePattern();
        virtual ~EncodePattern();

        virtual void setHexEncodePattern(string pattern);
        virtual string getHexEncodePattern() const;
        
        virtual void setStrHexEncPattern(string pattern);
        virtual string getStrHexEncPattern(); 
        
        virtual void setEncodePattern(string pattern);
        virtual string getEncodePattern() const;

        virtual void setAddress(int address);
        virtual int getAddress() const;
        
        virtual std::deque<IPBIWEncodeInstruction*> getInstructionsThatUseIt();
        
        virtual void includeInstructionUseIt(IPBIWEncodeInstruction* instruction);

        virtual void fmtAllEncodePattern(OriginalInstruction instruction, FieldPattern pattLayout);
        
        virtual void printPattern();
        virtual void printPattern(IPBIWEncodePattern* pattern) const;
        
        virtual bool operator==(const IPBIWEncodePattern& other) const;
        virtual bool operator!=(const IPBIWEncodePattern& other) const;

    private:
        typedef std::deque<IPBIWEncodeInstruction*> EncInstDeque;
        EncInstDeque instructionsThatUseIt;

        int address;
        string hexEncodedPattern;
        string strHexEncPattern;
        string encodedPattern;
    };

}

}

}
#endif	/* ENCODEPATTERN_H */

