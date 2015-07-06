/* 
 * File:   InstructionLayout.cpp
 * Author: renato
 * 
 * Created on January 4, 2013, 9:11 AM
 */

#include <string.h>

#include "InstructionLayout.h"
#include "ParseFile.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    using namespace std;

    InstructionLayout::InstructionLayout() {
        this->indexSize = 8;
        
        this->setFieldInstFmt0_10(24,8);
        
        this->setFieldInstFmt0_100(4,3);
        this->setFieldInstFmt0_100(27,5);
        
        this->setFieldInstFmt1(24,8);
        
        this->setFieldInstFmt2_0(15,3);
        this->setFieldInstFmt2_0(27,5);
        
        this->setFieldInstFmt2_1(24,8);
    }

    InstructionLayout::InstructionLayout(LayoutFieldsFMTMap fieldMapDeques, int indexSize) {
        LayoutFieldsFMTMap::iterator it;
        
        this->indexSize = indexSize;
        
        it = fieldMapDeques.find("fmt0_10");
        this->fmt0_10.assign(it->second.begin(), it->second.end());
        
        it = fieldMapDeques.find("fmt0_100");
        this->fmt0_100.assign(it->second.begin(), it->second.end());
        
        it = fieldMapDeques.find("fmt1");
        this->fmt1.assign(it->second.begin(), it->second.end());
        
        it = fieldMapDeques.find("fmt2_0");
        this->fmt2_0.assign(it->second.begin(), it->second.end());
        
        it = fieldMapDeques.find("fmt2_1");
        this->fmt2_1.assign(it->second.begin(), it->second.end());
    }

    InstructionLayout::~InstructionLayout() {
    }

    InstructionLayout::FieldInstruction
    InstructionLayout::getFieldInstFmt0_100() {
        return FieldInstruction(fmt0_100.begin(), fmt0_100.end());
    }
    
    void
    InstructionLayout::setFieldInstFmt0_100(int first, int size) {
        fmt0_100.push_back(Field(first, size));
    }
    
    InstructionLayout::FieldInstruction
    InstructionLayout::getFieldInstFmt0_10() {
        return FieldInstruction(fmt0_10.begin(), fmt0_10.end());
    }
    
    void
    InstructionLayout::setFieldInstFmt0_10(int first, int size) {
        fmt0_10.push_back(Field(first, size));
    }
    
    InstructionLayout::FieldInstruction
    InstructionLayout::getFieldInstFmt1() {
        return FieldInstruction(fmt1.begin(), fmt1.end());
    }
    
    void
    InstructionLayout::setFieldInstFmt1(int first, int size) {
        fmt1.push_back(Field(first, size));
    }
    
    InstructionLayout::FieldInstruction
    InstructionLayout::getFieldInstFmt2_0() {
        return FieldInstruction(fmt2_0.begin(), fmt2_0.end());
    }
    
    void
    InstructionLayout::setFieldInstFmt2_0(int first, int size) {
        fmt2_0.push_back(Field(first, size));
    }
    
    InstructionLayout::FieldInstruction
    InstructionLayout::getFieldInstFmt2_1() {
        return FieldInstruction(fmt2_1.begin(), fmt2_1.end());
    }
    
    void
    InstructionLayout::setFieldInstFmt2_1(int first, int size) {
        fmt2_1.push_back(Field(first, size));
    }
    
    InstructionLayout::AllFieldsDeque
    InstructionLayout::getFieldsInstruction() {
        AllFieldsDeque allFields;
        
        allFields.push_back(&fmt0_10);
        allFields.push_back(&fmt0_100);
        allFields.push_back(&fmt1);
        allFields.push_back(&fmt2_0);
        allFields.push_back(&fmt2_1);
        
        return allFields;
    }
    

    void
    InstructionLayout::setFieldsInstruction(AllFieldsDeque2 fields) {
        if(fields.size() == 5) {
            fmt0_10.assign(fields.at(0).begin(), fields.at(0).end());
            fmt0_100.assign(fields.at(1).begin(), fields.at(1).end());
            fmt1.assign(fields.at(2).begin(), fields.at(2).end());
            fmt2_0.assign(fields.at(3).begin(), fields.at(3).end());
            fmt2_1.assign(fields.at(4).begin(), fields.at(4).end());            
        }
    }
    
    int
    InstructionLayout::getIndexSize() {
        return indexSize;
    }
    
    void
    InstructionLayout::setIndexSize(int indexSize) {
        this->indexSize = indexSize;
    }
    
    void
    InstructionLayout::calcInstructionSize() {
        FieldInstruction::iterator it;

        for(it = fmt0_10.begin(); it < fmt0_10.end(); it++) {
            instructionSize += it->getSizeField();
        }
        instructionSize += indexSize;
    }
    
    int
    InstructionLayout::getAlign() {
        calcInstructionSize();
        
        if(instructionSize % 8 != 0){
            return instructionSize / 8 + 1;
        }
        return instructionSize / 8;
    }
}

}

}
