/* 
 * File:   Provider.h
 * Author: renato
 *
 * Created on February 28, 2013, 2:25 PM
 */

#ifndef PBIWSPARC_TOOLS_PROVIDER_H
#define	PBIWSPARC_TOOLS_PROVIDER_H

#include "Decode.h"
#include "ElfHandling.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    using namespace std;
    using namespace ELFIO;
    
    class Provider {
    public:
        Provider(string file);
        virtual ~Provider();
        
        virtual void defaultEncode();
        virtual void defaultEncode(bool print);
        virtual void otherLayoutEncode(string layoutFile);
        virtual void otherLayoutEncode(string layoutFile, bool print);
        virtual void defaultDecode(); 
        virtual void defaultDecode(bool print);
        virtual void printOk(string operation);
                
    private:
        virtual void processEncode(Encode& encode, bool print);
        virtual void processDecode(InstructionLayout& instructionLayout, PatternLayout& patternLayout, bool print);
        
        string elfFile;        
    };
}

}

}
#endif	/* PROVIDER_H */

