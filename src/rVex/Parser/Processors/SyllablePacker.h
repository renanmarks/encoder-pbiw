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
 * File:   SyllablePacker.h
 * Author: helix
 *
 * Created on January 14, 2012, 5:21 PM
 */

#ifndef SYLLABLEPACKER_H
#define	SYLLABLEPACKER_H

#include "rVex/Parser/Interfaces/IParserProcessor.h"

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
      
      virtual void process(rVex::Base::SyllableALU* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::Base::SyllableCTRL* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::Base::SyllableMUL* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::Base::SyllableMEM* syllable, SyllableArguments& arguments);
      
      virtual void process(rVex::Base::SyllableMISC* syllable, SyllableArguments& arguments);

      VexContext&
      getContext() const
      { return context; }
      
    private:
      VexContext& context;

    };
  }
}

#endif	/* SYLLABLEPACKER_H */

