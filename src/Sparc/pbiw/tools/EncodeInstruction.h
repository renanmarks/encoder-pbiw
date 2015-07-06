/* 
 * File:   EncodeInstruction.h
 * Author: renato
 *
 * Created on October 24, 2012, 4:55 PM
 */

#ifndef PBIWSPARC_TOOLS_ENCODEINSTRUCTION_H
#define	PBIWSPARC_TOOLS_ENCODEINSTRUCTION_H

#include <bitset>
#include "OriginalInstruction.h"
#include "EncodePattern.h"
#include "Interfaces/IPBIWEncodeInstruction.h"
#include "InstructionLayout.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    using namespace Tools::Intefaces;
    class EncodePattern;

    class EncodeInstruction : public IPBIWEncodeInstruction {
    public:
        EncodeInstruction();
        virtual ~EncodeInstruction();
        
        virtual void setHexEncodeInstruction(string hex);
        virtual string getHexEncodeInstruction();
        
        virtual void setStrHexEncInstruction(string hex);
        virtual string getStrHexEncInstruction();
        
        virtual void setEncodeInstruction(string instruction);
        virtual string getEncodeInstruction();

        virtual void setIndexSize(int indexSize);
        virtual int getIndexSize();
        
        virtual void setAddress(int address);
        virtual int getAddress();
        
        virtual void setAddress_Seq(int address);
        virtual int getAddress_Seq();
        
        virtual void setPointToPattern(IPBIWEncodePattern& pattern);
        virtual IPBIWEncodePattern& getPointToPattern();
        
        virtual void fmtAllEncodeInstruction(OriginalInstruction instruction, FieldInstruction instrLayout);
                
        virtual void printInstruction();
        virtual void printInstruction(IPBIWEncodeInstruction*) const;      
        
    private:
        int indexSize;
        string hexEncodedInstruction;
        string strHexEncInstruction; 
        string encodedInstruction;
        int address;
        int address_seq;
        EncodePattern* pointToPattern;
    };

}

}

}
#endif	/* ENCODEINSTRUCTION_H */

