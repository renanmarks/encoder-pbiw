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
 * File:   IParserProcessor.h
 * Author: helix
 *
 * Created on January 14, 2012, 5:09 PM
 */

#ifndef IPARSERPROCESSOR_H
#define	IPARSERPROCESSOR_H

#include "rVex/Base/rVex.h"
#include "rVex/Parser/Expressions/SyllableArguments.h"

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

