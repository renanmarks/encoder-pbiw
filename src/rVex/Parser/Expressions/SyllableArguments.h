/* 
 * File:   SyllableArguments.h
 * Author: helix
 *
 * Created on September 18, 2011, 4:16 PM
 */

#ifndef SYLLABLEARGUMENTS_H
#define	SYLLABLEARGUMENTS_H

#include "Arguments.h"

namespace VexParser
{
  class SyllableArguments
  {
  public:
    explicit
    SyllableArguments()
    { }
    
    explicit 
    SyllableArguments(Arguments& destinyRef, Arguments& sourceRef) 
      : source(sourceRef), 
        destiny(destinyRef) 
    { }
    
    explicit 
    SyllableArguments(Arguments& sourceRef)
      : source(sourceRef) 
    { }
    
    SyllableArguments(const SyllableArguments& orig)
      : source( orig.getSourceArgumentsCopy() ), 
      destiny( orig.getDestinyArgumentsCopy() ) 
    { }
//    
//    ~SyllableArguments() 
//    { /*delete source; delete destiny;*/ }
    
    SyllableArguments& operator =(const SyllableArguments& other)
    {
      source = other.getSourceArgumentsCopy();
      destiny = other.getDestinyArgumentsCopy();
      
      return *this;
    }
    
    bool operator ==(const SyllableArguments& other) const
    {
      return source == other.getSourceArgumentsCopy() && destiny == other.getDestinyArgumentsCopy();
    }
    
    bool operator !=(const SyllableArguments& other) const
    {
      return !(*this == other);
    }
    
    Arguments&
    getSourceArguments() 
    { return source; }
    
    Arguments
    getSourceArgumentsCopy() const
    { return source; }
    
    Arguments&
    getDestinyArguments()
    { return destiny; }
    
    Arguments
    getDestinyArgumentsCopy() const
    { return destiny; }
    
  private:
    Arguments source;
    Arguments destiny;
  };
}

#endif	/* SYLLABLEARGUMENTS_H */

