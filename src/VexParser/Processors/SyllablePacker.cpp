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
      switch(syllable->getOpcode())
      {
        // If is a MOV with immediate operand then is a pseudo-instruction...
        case rVex::Syllable::opMOV:
        {
          // Change MOV syllable to ADD syllable
          rVex::Operations::ALU::ADD add;
          memcpy(syllable, &add, sizeof(add));

          int value = arguments.getSourceArguments().getArguments()[0].getValue();

          if (arguments.getSourceArguments().getArguments()[0].getParsedValue().isImmediate)
          {
            // Change from: mov $r0.x = 12345
            // to: add $r0.x = $r0.0, 12345
            arguments.getSourceArguments().clearArguments();
            arguments.getSourceArguments().addArgument(Expression("$r0.0"));
            arguments.getSourceArguments().addArgument(Expression(value));
          }
          else
          {
            // Change from: mov $r0.x = $r0.y
            // to: add $r0.x = $r0.y, $r0.0
            int value = arguments.getSourceArguments().getArguments()[0].getValue();

            std::stringstream strBuilder;
            strBuilder << "$r0." << value << std::endl;

            arguments.getSourceArguments().addArgument(Expression("$r0.0"));
            arguments.getSourceArguments().addArgument(Expression(strBuilder.str()));
          }
        } 
        break;
      }

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
            context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
          else
          {
            // If is a register, change CALL syllable to ICALL syllable
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
            context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
          else
          {
            // If is a register, change GOTO syllable to IGOTO syllable
            rVex::Operations::CTRL::IGOTO igoto;
            memcpy(syllable, &igoto, sizeof(igoto));
          }

          break;
        }

        case rVex::Syllable::opRETURN:
        {
          Expression::ParseInfo argumentInfo = 
            arguments.getSourceArguments().getArguments()[1].getParsedValue();

          if (argumentInfo.isLabel)
            context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));

          break;
        }  

        case rVex::Syllable::opBR:
        case rVex::Syllable::opBRF:
            context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
          break;

        default:
          break;
      }

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