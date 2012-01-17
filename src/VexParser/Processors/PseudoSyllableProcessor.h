/* 
 * File:   PseudoSyllableProcessor.h
 * Author: helix
 *
 * Created on January 14, 2012, 5:22 PM
 */

#ifndef PSEUDOSYLLABLEPROCESSOR_H
#define	PSEUDOSYLLABLEPROCESSOR_H

#include "src/VexParser/Interfaces/IParserProcessor.h"

namespace VexParser
{
  class VexContext;
  
  using namespace Interfaces;
  
  namespace Processors
  {

    class PseudoSyllableProcessor : public IParserProcessor
    {
    public:
      PseudoSyllableProcessor(VexContext&);
      PseudoSyllableProcessor(const PseudoSyllableProcessor&);
      virtual ~PseudoSyllableProcessor();
      
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
      
      int getSyllableBufferItemPosition(rVex::Syllable* syllable);
    };
  }
}

#endif	/* PSEUDOSYLLABLEPROCESSOR_H */

