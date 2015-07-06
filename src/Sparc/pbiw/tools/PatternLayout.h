/* 
 * File:   PatternLayout.h
 * Author: renato
 *
 * Created on January 6, 2013, 11:28 PM
 */

#ifndef PBIWSPARC_TOOLS_PATTERNLAYOUT_H
#define	PBIWSPARC_TOOLS_PATTERNLAYOUT_H

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
    
    class PatternLayout {
    public:
        typedef std::deque<Field> FieldPattern;
        typedef std::map<string, FieldPattern> LayoutFieldsFMTMap;
        typedef std::deque<FieldPattern*> AllFieldsDeque;
        typedef std::deque<FieldPattern> AllFieldsDeque2;
        
        PatternLayout();
        PatternLayout(LayoutFieldsFMTMap fieldMapDeques);
        virtual ~PatternLayout();
        
        virtual FieldPattern getFieldPattFmt0_100();
        virtual void setFieldPattFmt0_100(int first, int size);
        
        virtual FieldPattern getFieldPattFmt0_10();
        virtual void setFieldPattFmt0_10(int first, int size);
        
        virtual FieldPattern getFieldPattFmt1();
        virtual void setFieldPattFmt1(int first, int size);
        
        virtual FieldPattern getFieldPattFmt2_0();
        virtual void setFieldPattFmt2_0(int first, int size);
        
        virtual FieldPattern getFieldPattFmt2_1();
        virtual void setFieldPattFmt2_1(int first, int size);
        
        virtual void calcPatternSize();
        virtual int getAlign();
//        virtual void setPatternAlign(int align);
        
        virtual AllFieldsDeque getFieldsPattern();
        virtual void setFieldsPattern(AllFieldsDeque2 fields);
        
    private:
        int patternSize;
        FieldPattern fmt0_100;
        FieldPattern fmt0_10;
        FieldPattern fmt1;
        FieldPattern fmt2_0;
        FieldPattern fmt2_1;
    };
}

}

}

#endif	/* PATTERNLAYOUT_H */

