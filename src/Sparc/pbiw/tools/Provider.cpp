/* 
 * File:   Provider.cpp
 * Author: renato
 * 
 * Created on February 28, 2013, 2:25 PM
 */

#include "Provider.h"
#include "ParseFile.h"
#include "ElfHandling.h"

namespace Sparc
{

namespace PBIW
{

namespace Tools {
    
    Provider::Provider(string file):elfFile(file) {
    }    

    Provider::~Provider() {
    }
    
    void
    Provider::defaultEncode() {
        defaultEncode(false);
    }
    
    void
    Provider::defaultEncode(bool print){
        ParseFile parse;
        parse.readFile(elfFile);
        Encode encode = Encode(parse.getInstructionsDeque());
        processEncode(encode, print);          
    }
    
    void
    Provider::otherLayoutEncode(string layoutFile) {
        otherLayoutEncode(layoutFile, false);
    }
    
    void
    Provider::otherLayoutEncode(string layoutFile, bool print) {
        ParseFile parse;
        parse.readFile(elfFile);
        parse.readLayoutFile(layoutFile);
        InstructionLayout instructionLayout = InstructionLayout(parse.getInstructionFields(), parse.getIndexSize());
        PatternLayout patternLayout = PatternLayout(parse.getPatternFields());
        Encode encode = Encode(parse.getInstructionsDeque(), instructionLayout, patternLayout);
        processEncode(encode, print);               
    }    
        
    void
    Provider::defaultDecode() {
        defaultDecode(false);
    }
    
    void
    Provider::defaultDecode(bool print) {
        InstructionLayout instructionLayout = InstructionLayout();
        PatternLayout patternLayout = PatternLayout();
        processDecode(instructionLayout, patternLayout, print);
    }
    
    void
    Provider::processEncode(Encode& encode, bool print) {
        encode.toEncode();
        encode.printEncodedFiles();
        if(print)
            encode.printEncoded();
        encode.statistics();
        ElfHandling elfHandler = ElfHandling(&encode, elfFile);       
        elfHandler.setEncodedInstructions();        
        printOk("Encode");
        elfHandler.addEncodedPatterns();  
        elfHandler.addLayoutSection();
    }
    
    void
    Provider::processDecode(InstructionLayout& instructionLayout, PatternLayout& patternLayout, bool print) {
        Decode decode(elfFile, instructionLayout, patternLayout);
        decode.decodeInstructions();
        decode.removeSections();
        printOk("Decode");
    }
    
    void
    Provider::printOk(string operation) {
        cout << operation << " " << setfill('.') << setw(39) << setprecision(39) << "Ok" << endl;
    }    
}

}

}
