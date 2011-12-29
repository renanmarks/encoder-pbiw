/* 
 * File:   Arguments.cpp
 * Author: helix
 * 
 * Created on September 18, 2011, 2:56 PM
 */

#include "Arguments.h"
#include <exception>

namespace VexParser
{
  Arguments::Arguments( Expression* ex )
  { 
    addArgument(ex);
  }

  Arguments::Arguments( Arguments& args, Expression* ex )
  {
    ArgumentVector::const_iterator it;

    for (it=args.getArguments().begin(); it < args.getArguments().end(); it++)
      addArgument( new Expression(**it) );
    
    addArgument(ex);
  }
  
  Arguments::~Arguments()
  {
    clearArguments();
  }

  void
  Arguments::addArgument( Expression* ex )
  {
    if (ex->isMemoryReference())
    {
      arguments.push_back(new Expression(ex->getValue()));  // offset
      arguments.push_back(new Expression(ex->getString())); // register
      delete ex;
      
      return;
    }
    
    arguments.push_back(ex);
  }

  std::vector<Expression*>&
  Arguments::getArguments( )
  {
    return arguments;
  }

  void
  Arguments::print( std::ostream& ostream ) const
  {
    ArgumentVector::const_iterator it;

    for (it=arguments.begin(); it < arguments.end(); it++)
      (*it)->print(ostream);
  }
  
  void
  Arguments::clearArguments( )
  {
    ArgumentVector::iterator it;

    for (it=arguments.begin(); it < arguments.end(); it++)
      delete *it;
    
    arguments.clear();
  }
}

