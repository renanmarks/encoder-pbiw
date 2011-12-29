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
#include "Expression.h"

namespace VexParser
{
  /**
   * Arguments used by the syllables
   */
  class Arguments
  {
  public:
    explicit Arguments(Expression*);
    explicit Arguments(Arguments&, Expression*);
    ~Arguments();
    
    void addArgument(Expression*);
    std::vector<Expression*>& getArguments();
    
    void clearArguments();
    
    void print(std::ostream&) const;
    
  private:
    typedef std::vector<Expression*> ArgumentVector;
    ArgumentVector arguments;
  };
}

#endif	/* ARGUMENTS_H */

