/* 
 * File:   IParserProcessor.h
 * Author: helix
 *
 * Created on January 14, 2012, 5:09 PM
 */

#ifndef IPARSERPROCESSOR_H
#define	IPARSERPROCESSOR_H

#include "src/rVex/rVex.h"
#include "src/rVex/Parser/Expressions/SyllableArguments.h"

namespace VexParser
{
  namespace Interfaces
  {
    class IParserProcessor
    {
    public :
      virtual ~IParserProcessor() { };
      
      virtual void process(rVex::SyllableALU* syllable, SyllableArguments& arguments) = 0;
      
      virtual void process(rVex::SyllableCTRL* syllable, SyllableArguments& arguments) = 0;
      
      virtual void process(rVex::SyllableMUL* syllable, SyllableArguments& arguments) = 0;
      
      virtual void process(rVex::SyllableMEM* syllable, SyllableArguments& arguments) = 0;
      
      virtual void process(rVex::SyllableMISC* syllable, SyllableArguments& arguments) = 0;
    };
  }
}

#endif	/* IPARSERPROCESSOR_H */

