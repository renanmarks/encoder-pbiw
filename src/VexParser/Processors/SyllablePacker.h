/* 
 * File:   SyllablePacker.h
 * Author: helix
 *
 * Created on January 14, 2012, 5:21 PM
 */

#ifndef SYLLABLEPACKER_H
#define	SYLLABLEPACKER_H

#include "src/VexParser/Interfaces/IParserProcessor.h"

namespace VexParser
{
  class VexContext;
  
  using namespace Interfaces;
  
  namespace Processors
  {
    class SyllablePacker : public IParserProcessor
    {
    public:
      explicit SyllablePacker(VexContext&);
      SyllablePacker(const SyllablePacker&);
      virtual ~SyllablePacker();
      
      virtual void process(rVex::SyllableALU* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::SyllableCTRL* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::SyllableMUL* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::SyllableMEM* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::SyllableMISC* syllable, SyllableArguments& arguments);

      VexContext&
      getContext() const
      { return context; }
      
    private:
      VexContext& context;

    };
  }
}

#endif	/* SYLLABLEPACKER_H */

