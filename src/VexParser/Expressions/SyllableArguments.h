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
    
//    SyllableArguments(SyllableArguments& orig)
//      : source( orig.getSourceArguments() ), 
//      destiny( orig.getDestinyArguments() ) 
//    { }
//    
//    ~SyllableArguments() 
//    { /*delete source; delete destiny;*/ }
    
    bool operator ==(const SyllableArguments& other) const
    {
      return source == other.getSourceArguments() && destiny == other.getDestinyArguments();
    }
    
    bool operator !=(const SyllableArguments& other) const
    {
      return !(*this == other);
    }
    
    Arguments&
    getSourceArguments() 
    { return source; }
    
    Arguments&
    getDestinyArguments()
    { return destiny; }
    
  private:
    Arguments source;
    Arguments destiny;
  };
}

#endif	/* SYLLABLEARGUMENTS_H */

