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
 * File:   PseudoSyllableProcessor.cpp
 * Author: helix
 * 
 * Created on January 14, 2012, 5:22 PM
 */

#include <sstream>
#include <iostream>
#include "rVex/Parser/VexContext.h"
#include "PseudoSyllableProcessor.h"
#include "rVex/Parser/VexContext.h"

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
    PseudoSyllableProcessor::getSyllableBufferItemPosition(rVex::Base::Syllable* syllable)
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
    PseudoSyllableProcessor::process(rVex::Base::SyllableALU* syllable, SyllableArguments& arguments)
    {
      std::string textRepresentation = "(from ";
      textRepresentation.append(syllable->getTextRepresentation());
      textRepresentation.append(")");
      
      switch (syllable->getOpcode()) 
      {
        case rVex::Base::Syllable::opCMPEQ:
        case rVex::Base::Syllable::opCMPGE:
        case rVex::Base::Syllable::opCMPGEU:
        case rVex::Base::Syllable::opCMPGT:
        case rVex::Base::Syllable::opCMPGTU:
        case rVex::Base::Syllable::opCMPLE:
        case rVex::Base::Syllable::opCMPLEU:
        case rVex::Base::Syllable::opCMPLT:
        case rVex::Base::Syllable::opCMPLTU:
        case rVex::Base::Syllable::opCMPNE:
        case rVex::Base::Syllable::opNANDL:
        case rVex::Base::Syllable::opNORL:
        case rVex::Base::Syllable::opORL:
          // Change from: cmpXX $r0.x = $r0.y, 12345
          // to: 
          // add $r0.31 = $r0.0, 12345
          // cmpXX $r0.x = $r0.y, $r0.31

          // WARNING: this is only suitable if the PBIW encoding supports indexing
          // the $r0.32 register
          if (arguments.getSourceArguments().getArguments()[1].getParsedValue().isImmediate)
          {
            int position = getSyllableBufferItemPosition(syllable);
            
            std::string assemblerRegister = "$r0.31";

            // Save cmpXX original values for posterior use
            std::string destinyReg=arguments.getDestinyArguments().getArguments()[0].getString();
            std::string sourceReg=arguments.getSourceArguments().getArguments()[0].getString();
            int value=arguments.getSourceArguments().getArguments()[1].getValue();
            
            rVex::Base::SyllableALU* add = new rVex::Operations::ALU::ADD();
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
            
            return;
          }
          break;
      }
    }

    void
    PseudoSyllableProcessor::process(rVex::Base::SyllableMEM* syllable, SyllableArguments& arguments)
    {

    }

    void
    PseudoSyllableProcessor::process(rVex::Base::SyllableMUL* syllable, SyllableArguments& arguments)
    {

    }

    void
    PseudoSyllableProcessor::process(rVex::Base::SyllableCTRL* syllable, SyllableArguments& arguments)
    {

    }

    void
    PseudoSyllableProcessor::process(rVex::Base::SyllableMISC* syllable, SyllableArguments& arguments)
    {

    }

  }
}
