/* 
 * File:   IPBIWInstructionLayout.h
 * Author: renato
 *
 * Created on January 4, 2013, 10:49 AM
 */

#ifndef IPBIWINSTRUCTIONLAYOUT_H
#define	IPBIWINSTRUCTIONLAYOUT_H

#include <deque>

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    namespace Intefaces {
        class IPBIWInstructionLayout {
        protected:
            struct Field;        
            typedef std::deque<Field> FieldInstruction;
            
        public:
            virtual FieldInstruction getFieldInstFmt0() const = 0;
            virtual void setFieldInstFmt0(int, int) = 0;

            virtual FieldInstruction getFieldInstFmt1() const = 0;
            virtual void setFieldInstFmt1(int first, int size) = 0;

            virtual FieldInstruction getFieldInstFmt2() const = 0;
            virtual void setFieldInstFmt2(int first, int size) = 0;
        };
    }
}

}

}
#endif	/* IPBIWINSTRUCTIONLAYOUT_H */

