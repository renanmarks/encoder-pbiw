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

