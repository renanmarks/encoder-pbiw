/* 
 * File:   InstructionLayout.h
 * Author: renato
 *
 * Created on January 4, 2013, 9:11 AM
 */

#ifndef PBIWSPARC_TOOLS_INSTRUCTIONLAYOUT_H
#define	PBIWSPARC_TOOLS_INSTRUCTIONLAYOUT_H

#include <map>
#include <deque>
#include <string>
#include "Field.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    
    using namespace std;
    
    class InstructionLayout {
    public:
        typedef std::deque<Field> FieldInstruction;
        typedef std::map<string, FieldInstruction> LayoutFieldsFMTMap;
        typedef std::deque<FieldInstruction*> AllFieldsDeque;
        typedef std::deque<FieldInstruction> AllFieldsDeque2;
        
        InstructionLayout();
        InstructionLayout(LayoutFieldsFMTMap fieldMapDeques, int indexSize);
        virtual ~InstructionLayout();
        
        virtual FieldInstruction getFieldInstFmt0_100();
        virtual void setFieldInstFmt0_100(int first, int size);
        
        virtual FieldInstruction getFieldInstFmt0_10();
        virtual void setFieldInstFmt0_10(int first, int size);
        
        virtual FieldInstruction getFieldInstFmt1();
        virtual void setFieldInstFmt1(int first, int size);
        
        virtual FieldInstruction getFieldInstFmt2_0();
        virtual void setFieldInstFmt2_0(int first, int size);
        
        virtual FieldInstruction getFieldInstFmt2_1();
        virtual void setFieldInstFmt2_1(int first, int size);
        
        virtual int getIndexSize();
        virtual void setIndexSize(int indexSize);
        
        virtual void calcInstructionSize();
        virtual int getAlign();
        
        virtual AllFieldsDeque getFieldsInstruction();
        virtual void setFieldsInstruction(AllFieldsDeque2 fields);
        
    private:
        int indexSize;
        int instructionSize;
        FieldInstruction fmt0_100;
        FieldInstruction fmt0_10;
        FieldInstruction fmt1;
        FieldInstruction fmt2_0;
        FieldInstruction fmt2_1;

    };
}

}

}

#endif	/* INSTRUCTIONLAYOUT_H */

