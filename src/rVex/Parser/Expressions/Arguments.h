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
 * File:   Arguments.h
 * Author: helix
 *
 * Created on September 18, 2011, 2:56 PM
 */

#ifndef ARGUMENTS_H
#define	ARGUMENTS_H

#include <ostream>
#include <vector>
#include <deque>
#include "Expression.h"

namespace VexParser
{
  /**
   * Arguments used by the syllables
   */
  class Arguments
  {
  public:
    typedef std::deque<Expression> ArgumentVector;
    
    explicit Arguments() { }
    
    explicit Arguments(const Expression&);
    explicit Arguments(Arguments&, const Expression&);

    Arguments(Arguments&);
    Arguments(const Arguments&);
    
    ~Arguments();
    
    Arguments& operator =( const Arguments& );
    
    bool operator ==(const Arguments&) const;
    bool operator !=(const Arguments&) const;
    
    void addArgument(const Expression&);
    ArgumentVector& getArguments();
    Arguments::ArgumentVector getArgumentsCopy( ) const;
    
    void clearArguments();
    
    void print(std::ostream&) const;
    
    bool hasArguments()
    { return arguments.size() > 0; }
    
  private:
    ArgumentVector arguments;
    
    Arguments& copyExpressions(const Arguments& other);
  };
}

#endif	/* ARGUMENTS_H */
