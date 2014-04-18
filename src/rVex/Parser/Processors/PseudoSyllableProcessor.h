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
 * File:   PseudoSyllableProcessor.h
 * Author: helix
 *
 * Created on January 14, 2012, 5:22 PM
 */

#ifndef PSEUDOSYLLABLEPROCESSOR_H
#define	PSEUDOSYLLABLEPROCESSOR_H

#include "rVex/Parser/Interfaces/IParserProcessor.h"

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

