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
 * File:   SyllableBufferItem.h
 * Author: helix
 *
 * Created on January 12, 2012, 3:43 PM
 */

#ifndef SYLLABLEBUFFERITEM_H
#define	SYLLABLEBUFFERITEM_H

#include "rVex/Base/Syllable.h"
#include "rVex/Parser/Expressions/SyllableArguments.h"

namespace VexParser
{
  namespace Structs
  {
    class SyllableBufferItem
    {
    public:
      SyllableBufferItem()
        : syllable(NULL)
      { }
        
			SyllableBufferItem(rVex::Base::Syllable* syllableRef)
        : syllable(syllableRef)
      { }
        
			SyllableBufferItem(rVex::Base::Syllable* syllableRef, VexParser::SyllableArguments& argumentsRef)
        : syllable(syllableRef),
        arguments(argumentsRef)
      { }
      
      SyllableBufferItem(const SyllableBufferItem& orig)
        : syllable(orig.getSyllable()),
        arguments(orig.getArgumentsCopy()) 
      { }
      
      SyllableBufferItem& operator=(const SyllableBufferItem& orig)
      {
        if (this != &orig)
        {
          syllable = orig.getSyllable();
          arguments = orig.getArgumentsCopy();
        }
        
        return *this;
      }
      
      bool operator ==(const SyllableBufferItem& other) const
      {
        return syllable == other.getSyllable() && arguments == other.getArgumentsCopy();
      }
      
      bool operator !=(const SyllableBufferItem& other) const
      {
        return !(*this == other);
      }
      
      virtual ~SyllableBufferItem()
      { /*delete arguments;*/ }

      void
      setArguments(const VexParser::SyllableArguments& arguments)
      { this->arguments = arguments; }

      VexParser::SyllableArguments&
      getArguments()
      { return arguments; }
      
      VexParser::SyllableArguments
      getArgumentsCopy() const 
      { return arguments; }

      void
			setSyllable(rVex::Base::Syllable* syllable)
      { this->syllable = syllable; }

			rVex::Base::Syllable*
      getSyllable() const
      { return syllable; }
    
    private:
			rVex::Base::Syllable* syllable;
      VexParser::SyllableArguments arguments;
    };
  }
}

#endif	/* SYLLABLEBUFFERITEM_H */
