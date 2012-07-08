/* 
 * File:   SyllableBufferItem.h
 * Author: helix
 *
 * Created on January 12, 2012, 3:43 PM
 */

#ifndef SYLLABLEBUFFERITEM_H
#define	SYLLABLEBUFFERITEM_H

#include "src/rVex/Syllable.h"
#include "src/rVex/Parser/Expressions/SyllableArguments.h"

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
        
      SyllableBufferItem(rVex::Syllable* syllableRef)
        : syllable(syllableRef)
      { }
        
      SyllableBufferItem(rVex::Syllable* syllableRef, VexParser::SyllableArguments& argumentsRef)
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
      setSyllable(rVex::Syllable* syllable)
      { this->syllable = syllable; }

      rVex::Syllable*
      getSyllable() const
      { return syllable; }
    
    private:
      rVex::Syllable* syllable;
      VexParser::SyllableArguments arguments;
    };
  }
}

#endif	/* SYLLABLEBUFFERITEM_H */
