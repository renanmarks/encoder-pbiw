/* 
 * File:   Encode.h
 * Author: renato
 *
 * Created on October 24, 2012, 2:36 PM
 */

#ifndef PBIWSPARC_TOOLS_ENCODE_H
#define	PBIWSPARC_TOOLS_ENCODE_H

#include <deque>
#include <set>
#include "OriginalInstruction.h"
#include "EncodePattern.h"
#include "Interfaces/IPBIWEncodePattern.h"
#include "Interfaces/IPBIWInstructionLayout.h"
#include "InstructionLayout.h"
#include "PatternLayout.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    using namespace std;

    class Encode {
    public:
        typedef std::deque<OriginalInstruction> OriginalInstDeque;
        typedef std::deque<Field> FieldsDeque;
        typedef std::deque<IPBIWEncodeInstruction*> EncInstDeque;
        typedef std::deque<IPBIWEncodePattern*> EncPatDeque;
        typedef std::deque<std::deque<Field>* > AllFieldsDeque;
        
        Encode();
        Encode(OriginalInstDeque instrDeque);
        Encode(OriginalInstDeque instrDeque, InstructionLayout instrLayout, PatternLayout pattLayout);
        virtual ~Encode();

        virtual void toEncode();

        virtual void createNewElements(EncodePattern*&, EncodeInstruction*&);
        virtual void saveElements(EncodePattern*& pattern, EncodeInstruction*& instruction);

        virtual IPBIWEncodePattern& hasPattern(IPBIWEncodePattern& pattern);
        virtual string encodeLayout();
        
        virtual EncInstDeque getEncodedInstructions();
        virtual EncPatDeque getEncodedPatterns();
        
        virtual InstructionLayout getInstrucionLayout();
        virtual PatternLayout getPatternLayout();        
        
        virtual void printEncoded();
        virtual void printInstructionsFile();
        virtual void printPatternsFile();
        virtual void printEncodedFiles();
        virtual void printUniquePaterns();
        virtual void statistics();        
                
    private:
        virtual string processFields(AllFieldsDeque fields);
        InstructionLayout instructionLayout;
        PatternLayout patternLayout;
        
        string encodedLayout;
        EncInstDeque encodedInstructions;
        EncPatDeque encodedPatterns;
        EncInstDeque hexInstructions;

        OriginalInstDeque originalInstructions;
    };
}

}

}
#endif	/* ENCODE_H */

