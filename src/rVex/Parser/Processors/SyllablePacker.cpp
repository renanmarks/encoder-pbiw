/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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
#include "rVex/Parser/VexContext.h"

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

    void SyllablePacker::process(rVex::Base::SyllableALU* syllable, SyllableArguments& arguments)
    {
      std::string textRepresentation = syllable->getTextRepresentation();
      
      switch(syllable->getOpcode())
      {
        // If is a MOV with immediate operand then is a pseudo-instruction...
        case rVex::Base::Syllable::opMOV:
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

    void SyllablePacker::process(rVex::Base::SyllableMEM* syllable, SyllableArguments& arguments)
    {
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }

    void SyllablePacker::process(rVex::Base::SyllableMUL* syllable, SyllableArguments& arguments)
    {
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }

    void SyllablePacker::process(rVex::Base::SyllableCTRL* syllable, SyllableArguments& arguments)
    {
      std::string textRepresentation = syllable->getTextRepresentation();
      
      switch(syllable->getOpcode())
      {
        case rVex::Base::Syllable::opXNOP:
          delete syllable;
          return; // Does not support XNOP yet.

        case rVex::Base::Syllable::opCALL:
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

        case rVex::Base::Syllable::opGOTO:
        {
          Expression::ParseInfo argumentInfo = 
            arguments.getSourceArguments().getArguments()[0].getParsedValue();

          if (argumentInfo.isLabel)
            context.getControlSyllables().push_back(syllable);
          else
          {
            // If is a register, change GOTO syllable to IGOTO syllable
            textRepresentation.append("(To IGOTO)");
            
            rVex::Operations::CTRL::IGOTO igoto;
            memcpy(syllable, &igoto, sizeof(igoto));
          }

          break;
        }

        case rVex::Base::Syllable::opRETURN:
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

        case rVex::Base::Syllable::opBR:
        case rVex::Base::Syllable::opBRF:
            context.getControlSyllables().push_back(syllable);
          break;

        default:
          break;
      }

      syllable->setTextRepresentation(textRepresentation);
      
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }

    void SyllablePacker::process(rVex::Base::SyllableMISC* syllable, SyllableArguments& arguments)
    {
      syllable->fillSyllable(arguments);
      context.getSyllableBuffer().push_back(Structs::SyllableBufferItem(syllable, arguments));
    }
    
  }
}