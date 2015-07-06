/* 
 * File:   Decode.h
 * Author: renato
 *
 * Created on February 25, 2013, 6:43 PM
 */


#ifndef PBIWSPARC_TOOLS_DECODE_H
#define	PBIWSPARC_TOOLS_DECODE_H

#include <deque>
#include <map>

#include "../elfio/elfio.hpp"
#include "OriginalInstruction.h"
#include "Interfaces/IPBIWEncodePattern.h"
#include "Interfaces/IPBIWEncodePattern.h"
#include "InstructionLayout.h"
#include "PatternLayout.h"
#include "Interfaces/IPBIWEncodeInstruction.h"
#include "Field.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    
    using namespace std;
    using namespace Intefaces;
    using namespace ELFIO;
    
    class Decode {
    public:
        typedef std::deque<IPBIWEncodeInstruction*> EncInstDeque;
        typedef std::deque<IPBIWEncodePattern*> EncPattDeque;
        typedef std::deque<OriginalInstruction> OriginalInstDeque;        
        typedef std::deque<Field> FieldDeque;
        typedef std::deque<FieldDeque> AllFieldsDeque;
        
        Decode(string name);
        Decode(string name, InstructionLayout& inst, PatternLayout& patt);
        virtual ~Decode();
        
        virtual void decodeInstructions();
        virtual void decode();
        virtual void setOnELF();
        virtual void restoreOriginalInstruction(IPBIWEncodePattern*& pattern, IPBIWEncodeInstruction*& instruction);
        virtual string fmtAllDecode(IPBIWEncodeInstruction* instruction, IPBIWEncodePattern* pattern, FieldDeque instLayout, FieldDeque pattLayout);
        virtual void loadLayout();
        virtual void loadInstructions();
        virtual void loadPatterns();
        virtual void removeSections();
        virtual void print();
        virtual void printDecoded();
        
    private:
        virtual AllFieldsDeque processFields(const char* data, int* index, int size);
        InstructionLayout* instructionLayout;
        PatternLayout* patternLayout;
        
//        OriginalInstruction* original;
        EncInstDeque encodeInstructions;
        EncPattDeque encodePatterns;
        OriginalInstDeque originalInstructions;
        string fileName;
        elfio reader;
    };
}

}

}
#endif	/* DECODE_H */

