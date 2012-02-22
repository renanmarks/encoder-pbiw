/* 
 * File:   PseudoSyllableProcessor.cpp
 * Author: helix
 * 
 * Created on January 14, 2012, 5:22 PM
 */

#include <sstream>
#include <iostream>
#include "src/VexParser/VexContext.h"
#include "PseudoSyllableProcessor.h"
#include "src/VexParser/VexContext.h"

namespace VexParser
{
  namespace Processors
  {

    PseudoSyllableProcessor::PseudoSyllableProcessor(VexContext& contextRef)
     : context(contextRef)
    { }

    PseudoSyllableProcessor::PseudoSyllableProcessor(const PseudoSyllableProcessor& orig)
     : context(orig.getContext())
    { }
    
    PseudoSyllableProcessor::~PseudoSyllableProcessor()
    { }

    int 
    PseudoSyllableProcessor::getSyllableBufferItemPosition(rVex::Syllable* syllable)
    {
      VexContext::SyllableBuffer::const_iterator it;
      int i;
      
      for(i = 0, it = context.getSyllableBuffer().begin();
          it < context.getSyllableBuffer().end();
          i++, it++)
      {
        if (it->getSyllable() == syllable)
          return i;
      }
      
      return -1;
    }
    
    void
    PseudoSyllableProcessor::process(rVex::SyllableALU* syllable, SyllableArguments& arguments)
    {
      std::string textRepresentation = "(from ";
      textRepresentation.append(syllable->getTextRepresentation());
      textRepresentation.append(")");
      
      switch (syllable->getOpcode()) 
      {
        case rVex::Syllable::opCMPEQ:
        case rVex::Syllable::opCMPGE:
        case rVex::Syllable::opCMPGEU:
        case rVex::Syllable::opCMPGT:
        case rVex::Syllable::opCMPGTU:
        case rVex::Syllable::opCMPLE:
        case rVex::Syllable::opCMPLEU:
        case rVex::Syllable::opCMPLT:
        case rVex::Syllable::opCMPLTU:
        case rVex::Syllable::opCMPNE:
        case rVex::Syllable::opNANDL:
        case rVex::Syllable::opNORL:
        case rVex::Syllable::opORL:
          // Change from: cmpXX $r0.x = $r0.y, 12345
          // to: 
          // add $r0.31 = $r0.0, 12345
          // cmpXX $r0.x = $r0.y, $r0.31

          // WARNING: this is only suitable if the PBIW encoding supports indexing
          // the $r0.32 register
          if (arguments.getSourceArguments().getArguments()[1].getParsedValue().isImmediate)
          {
            // If not enough space to fit the add, get a new instruction
//            if (context.getSyllableBuffer().size() > 3)
//              context.endInstruction();
            
            int position = getSyllableBufferItemPosition(syllable);
            
            std::string assemblerRegister = "$r0.31";

            // Save cmpXX original values for posterior use
            std::string destinyReg=arguments.getDestinyArguments().getArguments()[0].getString();
            std::string sourceReg=arguments.getSourceArguments().getArguments()[0].getString();
            int value=arguments.getSourceArguments().getArguments()[1].getValue();
            
            rVex::SyllableALU* add = new rVex::Operations::ALU::ADD();
            add->setTextRepresentation(textRepresentation);
            
            arguments.getDestinyArguments().clearArguments();
            arguments.getDestinyArguments().addArgument(Expression(assemblerRegister));

            arguments.getSourceArguments().clearArguments();
            arguments.getSourceArguments().addArgument(Expression("$r0.0"));
            arguments.getSourceArguments().addArgument(Expression(value));

            add->fillSyllable(arguments);
            context.getSyllableBuffer().at(position) = Structs::SyllableBufferItem(add, arguments);

            // Get a new instruction because of the use of the previous 
            // assigned register $r0.31
            context.endInstruction();

            arguments.getDestinyArguments().clearArguments();
            arguments.getDestinyArguments().addArgument(Expression(destinyReg));

            arguments.getSourceArguments().clearArguments();
            arguments.getSourceArguments().addArgument(Expression(sourceReg));
            arguments.getSourceArguments().addArgument(Expression(assemblerRegister));

            syllable->setTextRepresentation(textRepresentation);
            syllable->fillSyllable(arguments);
            context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
            context.endInstruction();

            return;
          }
          break;
      }
    }

    void
    PseudoSyllableProcessor::process(rVex::SyllableMEM* syllable, SyllableArguments& arguments)
    {

    }

    void
    PseudoSyllableProcessor::process(rVex::SyllableMUL* syllable, SyllableArguments& arguments)
    {

    }

    void
    PseudoSyllableProcessor::process(rVex::SyllableCTRL* syllable, SyllableArguments& arguments)
    {

    }

    void
    PseudoSyllableProcessor::process(rVex::SyllableMISC* syllable, SyllableArguments& arguments)
    {

    }

  }
}
