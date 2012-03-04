/* 
 * File:   SyllablePacker.cpp
 * Author: helix
 * 
 * Created on January 14, 2012, 5:21 PM
 */

#include <cstring>
#include <sstream>
#include <vector>
#include <list>
#include "SyllablePacker.h"
#include "src/VexParser/VexContext.h"

namespace VexParser
{
  namespace Processors
  {

    SyllablePacker::SyllablePacker(VexContext& externalContext)
     : context(externalContext)
    { }

    SyllablePacker::SyllablePacker(const SyllablePacker& orig)
     : context(orig.getContext())
    { }

    SyllablePacker::~SyllablePacker()
    {
    }

    void SyllablePacker::process(rVex::SyllableALU* syllable, SyllableArguments& arguments)
    {
      std::string textRepresentation = syllable->getTextRepresentation();
      
      switch(syllable->getOpcode())
      {
        // If is a MOV with immediate operand then is a pseudo-instruction...
        case rVex::Syllable::opMOV:
          if (arguments.getSourceArguments().getArguments()[0].getParsedValue().isImmediate)
          {
            // Change from: mov $r0.x = 12345
            // to: add $r0.x = $r0.0, 12345
            // Change MOV syllable to ADD syllable
            textRepresentation.append("(To ADD)");
            
            rVex::Operations::ALU::ADD add;
            memcpy(syllable, &add, sizeof(add));
            
            int value = arguments.getSourceArguments().getArguments()[0].getValue();
            
            arguments.getSourceArguments().clearArguments();
            arguments.getSourceArguments().addArgument(Expression("$r0.0"));
            arguments.getSourceArguments().addArgument(Expression(value));
          }
          break;
      }

      syllable->setTextRepresentation(textRepresentation);
      
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }

    void SyllablePacker::process(rVex::SyllableMEM* syllable, SyllableArguments& arguments)
    {
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }

    void SyllablePacker::process(rVex::SyllableMUL* syllable, SyllableArguments& arguments)
    {
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }

    void SyllablePacker::process(rVex::SyllableCTRL* syllable, SyllableArguments& arguments)
    {
      std::string textRepresentation = syllable->getTextRepresentation();
      
      switch(syllable->getOpcode())
      {
        case rVex::Syllable::opXNOP:
          delete syllable;
          return; // Does not support XNOP yet.

        case rVex::Syllable::opCALL:
        {
          Expression::ParseInfo argumentInfo = 
            arguments.getSourceArguments().getArguments()[0].getParsedValue();

          if (argumentInfo.isLabel)
            context.getControlSyllables().push_back(syllable);
          else
          {
            // If is a register, change CALL syllable to ICALL syllable
            textRepresentation.append("(To ICALL)");
            
            rVex::Operations::CTRL::ICALL icall;
            memcpy(syllable, &icall, sizeof(icall));
          }

          break;
        }

        case rVex::Syllable::opGOTO:
        {
          Expression::ParseInfo argumentInfo = 
            arguments.getSourceArguments().getArguments()[0].getParsedValue();

          if (argumentInfo.isLabel)
            context.getControlSyllables().push_back(syllable);
          else
          {
            // If is a register, change GOTO syllable to IGOTO syllable
            textRepresentation.append("(To ICALL)");
            
            rVex::Operations::CTRL::IGOTO igoto;
            memcpy(syllable, &igoto, sizeof(igoto));
          }

          break;
        }

        case rVex::Syllable::opRETURN:
          return;
//        {
//          Expression::ParseInfo argumentInfo = 
//            arguments.getSourceArguments().getArguments()[1].getParsedValue();
//
//          if (argumentInfo.isLabel)
//            context.getControlSyllables().push_back(syllable);
//
//          break;
//        }  

        case rVex::Syllable::opBR:
        case rVex::Syllable::opBRF:
            context.getControlSyllables().push_back(syllable);
          break;

        default:
          break;
      }

      syllable->setTextRepresentation(textRepresentation);
      
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }

    void SyllablePacker::process(rVex::SyllableMISC* syllable, SyllableArguments& arguments)
    {
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }
    
  }
}