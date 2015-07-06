/* 
 * File:   IPBIWEncodePattern.h
 * Author: renato
 *
 * Created on November 2, 2012, 11:56 PM
 */

#ifndef IPBIWENCODEPATTERN_H
#define	IPBIWENCODEPATTERN_H

#include <deque>
#include "../Field.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    namespace Intefaces {
        class IPBIWEncodeInstruction;
        
        class IPBIWEncodePattern {
        protected:
            typedef std::deque<Tools::Field> FieldPattern;
        
        public:
            virtual void setHexEncodePattern(string) = 0;
            virtual string getHexEncodePattern() const = 0;
            
            virtual void setStrHexEncPattern(string) = 0;
            virtual string getStrHexEncPattern() = 0;
            
            virtual void setEncodePattern(string) = 0;
            virtual string getEncodePattern() const = 0;

            virtual void setAddress(int) = 0;
            virtual int getAddress() const = 0;
            
            virtual std::deque<IPBIWEncodeInstruction*> getInstructionsThatUseIt() = 0;

            virtual void includeInstructionUseIt(IPBIWEncodeInstruction*) = 0;

            /**
             * @param originalInstruction, fieldPattern
             * 
             * Deque with original instruction and deque with fields of the pattern layout
             */
            virtual void fmtAllEncodePattern(OriginalInstruction, FieldPattern) = 0;
            
            virtual void printPattern() = 0;
            virtual void printPattern(IPBIWEncodePattern*) const = 0;
            
            virtual bool operator==(const IPBIWEncodePattern&) const = 0;
            virtual bool operator!=(const IPBIWEncodePattern&) const = 0;

        };
    }
}

}

}
#endif	/* IPBIWENCODEPATTERN_H */

