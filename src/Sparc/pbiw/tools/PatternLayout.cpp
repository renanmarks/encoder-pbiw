/* 
 * File:   PatternLayout.cpp
 * Author: renato
 * 
 * Created on January 6, 2013, 11:28 PM
 */

#include <memory>

#include "PatternLayout.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {

    using namespace std;

    PatternLayout::PatternLayout() {
        this->setFieldPattFmt0_10(0,2);
        this->setFieldPattFmt0_10(7,3);
        this->setFieldPattFmt0_10(2,5);
        this->setFieldPattFmt0_10(10,14);
        
        this->setFieldPattFmt0_100(0,2);
        this->setFieldPattFmt0_100(7,3);
        this->setFieldPattFmt0_100(2,2);
        this->setFieldPattFmt0_100(10,17);
        
        this->setFieldPattFmt1(0,24);
        
        this->setFieldPattFmt2_0(0,13);
        this->setFieldPattFmt2_0(18,1);
        this->setFieldPattFmt2_0(13,2);
        this->setFieldPattFmt2_0(19,8);
        
        this->setFieldPattFmt2_1(0,13);
        this->setFieldPattFmt2_1(18,1);
        this->setFieldPattFmt2_1(13,5);
        this->setFieldPattFmt2_1(19,5);
        
        calcPatternSize();
    }

    PatternLayout::PatternLayout(LayoutFieldsFMTMap fieldMapDeques) {
        LayoutFieldsFMTMap::iterator it;
        
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
        
        calcPatternSize();
    }
    
    PatternLayout::~PatternLayout() {
    }

    PatternLayout::FieldPattern
    PatternLayout::getFieldPattFmt0_100() {
        return FieldPattern(fmt0_100.begin(), fmt0_100.end());
    }
    
    void
    PatternLayout::setFieldPattFmt0_100(int first, int size) {
        fmt0_100.push_back(Field(first, size));
    }
    
    PatternLayout::FieldPattern
    PatternLayout::getFieldPattFmt0_10() {
        return FieldPattern(fmt0_10.begin(), fmt0_10.end());
    }
    
    void
    PatternLayout::setFieldPattFmt0_10(int first, int size) {
        fmt0_10.push_back(Field(first, size));
    }
    
    PatternLayout::FieldPattern
    PatternLayout::getFieldPattFmt1() {
        return FieldPattern(fmt1.begin(), fmt1.end());
    }
    
    void
    PatternLayout::setFieldPattFmt1(int first, int size) {
        fmt1.push_back(Field(first, size));
    }
    
    PatternLayout::FieldPattern
    PatternLayout::getFieldPattFmt2_0() {
        return FieldPattern(fmt2_0.begin(), fmt2_0.end());
    }
    
    void
    PatternLayout::setFieldPattFmt2_0(int first, int size) {
        fmt2_0.push_back(Field(first, size));
    }
    
    PatternLayout::FieldPattern
    PatternLayout::getFieldPattFmt2_1() {
        return FieldPattern(fmt2_1.begin(), fmt2_1.end());
    }
    
    void
    PatternLayout::setFieldPattFmt2_1(int first, int size) {
        fmt2_1.push_back(Field(first, size));
    }
    
    PatternLayout::AllFieldsDeque
    PatternLayout::getFieldsPattern() {
        AllFieldsDeque allFields;
        
        allFields.push_back(&fmt0_10);
        allFields.push_back(&fmt0_100);
        allFields.push_back(&fmt1);
        allFields.push_back(&fmt2_0);
        allFields.push_back(&fmt2_1);
        
        calcPatternSize();
        
        return allFields;
    }
    
    void
    PatternLayout::calcPatternSize() {
        FieldPattern::iterator it;

        for(it = fmt0_10.begin(); it < fmt0_10.end(); it++) {
            patternSize += it->getSizeField();
        }
    }
    
    int
    PatternLayout::getAlign() {
        if(patternSize % 8 != 0){
            return patternSize / 8 + 1;
        }
        return patternSize / 8;
    }
 
    void
    PatternLayout::setFieldsPattern(AllFieldsDeque2 fields) {
        if(fields.size() == 5) {
            fmt0_10.assign(fields.at(0).begin(), fields.at(0).end());
            fmt0_100.assign(fields.at(1).begin(), fields.at(1).end());
            fmt1.assign(fields.at(2).begin(), fields.at(2).end());
            fmt2_0.assign(fields.at(3).begin(), fields.at(3).end());
            fmt2_1.assign(fields.at(4).begin(), fields.at(4).end());
        }
    }
}

}

}
