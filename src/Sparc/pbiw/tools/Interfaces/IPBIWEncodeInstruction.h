/* 
 * File:   IPBIWEncodeInstruction.h
 * Author: renato
 *
 * Created on November 2, 2012, 11:44 PM
 */

#ifndef IPBIWENCODEINSTRUCTION_H
#define	IPBIWENCODEINSTRUCTION_H

#include <deque>
#include <string>
#include "../Field.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    namespace Intefaces {
        class IPBIWEncodePattern;
        
        class IPBIWEncodeInstruction {
        protected:
            typedef std::deque<Tools::Field> FieldInstruction;

        public:                      
            virtual void setHexEncodeInstruction(string) = 0;
            virtual string getHexEncodeInstruction() = 0;
            
            virtual void setStrHexEncInstruction(string) = 0;
            virtual string getStrHexEncInstruction() = 0;
            
            virtual void setEncodeInstruction(string) = 0;
            virtual string getEncodeInstruction() = 0;

            virtual void setIndexSize(int) = 0;
            virtual int getIndexSize() = 0;
            
            virtual void setAddress(int) = 0;
            virtual int getAddress() = 0;
            
            virtual void setAddress_Seq(int) = 0;
            virtual int getAddress_Seq() = 0;

            virtual void setPointToPattern(IPBIWEncodePattern&) = 0;
            virtual IPBIWEncodePattern& getPointToPattern() = 0;
            
            /**
             * @param originalInstruction, fieldInstruction
             * 
             * Deque with original instruction and deque with fields of the instruction layout
             */
            virtual void fmtAllEncodeInstruction(OriginalInstruction, FieldInstruction) = 0;
                        
            virtual void printInstruction() = 0;
            virtual void printInstruction(IPBIWEncodeInstruction*) const = 0;
        };
    }
}

}

}

#endif	/* IPBIWENCODEINSTRUCTION_H */

