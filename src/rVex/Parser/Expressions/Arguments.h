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
