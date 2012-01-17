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
    typedef std::vector<Expression> ArgumentVector;
    
    explicit Arguments() { }
    
    explicit Arguments(const Expression&);
    explicit Arguments(Arguments&, const Expression&);
    Arguments(Arguments&);
    ~Arguments();
    
    void addArgument(const Expression&);
    ArgumentVector& getArguments();
    
    void clearArguments();
    
    void print(std::ostream&) const;
    
    bool hasArguments()
    { return arguments.size() > 0; }
    
    bool operator ==(const Arguments& other) const
    {
      ArgumentVector::const_iterator it1 = arguments.begin();
      ArgumentVector::const_iterator it2 = other.getArguments().begin();
        
      while (it1 != arguments.end() && it2 != other.getArguments().end())
      {
        if (*it1 != *it2)
          return false;
        
        it1++;
        it2++;
      }
      
      if (it1 == arguments.end() && it2 == other.getArguments().end())
        return true;
      
      return false;
    }
    
    bool operator !=(const Arguments& other) const
    {
      return (*this != other);
    }
    
  private:
    ArgumentVector arguments;
    
    void copyExpressions(const ArgumentVector& expressions);
  };
}

#endif	/* ARGUMENTS_H */
