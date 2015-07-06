/* 
 * File:   ElfHandling.h
 * Author: renato
 *
 * Created on January 28, 2013, 3:23 PM
 */

#include "../elfio/elfio.hpp"
#include "Encode.h"


#ifndef PBIWSPARC_TOOLS_ELFHANDLING_H
#define	PBIWSPARC_TOOLS_ELFHANDLING_H

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    
    using namespace std;
    using namespace ELFIO;
    
    class ElfHandling {
    public:
        typedef std::deque<IPBIWEncodeInstruction*> EncInstDeque;
        typedef std::deque<IPBIWEncodePattern*> EncPattDeque;
        typedef std::deque<OriginalInstruction> OriginalInstDeque;
        
        ElfHandling(string file);
        ElfHandling(Encode* encoded, string fileName);
        virtual ~ElfHandling();
        
        virtual void setEncode(Encode* encode);
        virtual Encode* getEncode();
        
        virtual void clearSectionText();
        
        virtual void setEncodedInstructions();
        virtual void addEncodedPatterns();
        virtual void addLayoutSection();
        virtual void setDecodedInstructions(OriginalInstDeque& originalInstructions, int alingnment);
        
    private:
        virtual void setCodeOnELF(string data, string section, int alignment, int operation);
        virtual int setSegmentSize(elfio& write);
        
        enum {encoding = 1, decoding = 0};
        
        OriginalInstDeque originalInstructions;
        const char* data;
        Encode* encode;
        string file;
    };
}

}

}
#endif	/* ELFHANDLING_H */



