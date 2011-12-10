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
    SyllableArguments(Arguments* destiny, Arguments* source) 
    : source(source), destiny(destiny) { }
    
    explicit 
    SyllableArguments(Arguments* source)
    : source(source), destiny(NULL) { }
    
    ~SyllableArguments() 
    { delete source; delete destiny; }
    
    Arguments*
    getSourceArguments() const 
    { return source; }
    
    Arguments*
    getDestinyArguments() const
    { return destiny; }
    
  private:
    Arguments* source;
    Arguments* destiny;
  };
}

#endif	/* SYLLABLEARGUMENTS_H */

