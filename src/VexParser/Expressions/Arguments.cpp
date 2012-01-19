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

  Arguments::Arguments( Arguments& args, Expression* ex ) // O(1)
  {
    ArgumentVector::const_iterator it;

    for (it=args.getArguments().begin(); it < args.getArguments().end(); it++) // O(1)
      addArgument( new Expression(**it) );
    
    addArgument(ex);
  }
  
  Arguments::~Arguments()
  {
    clearArguments();
  }

  void
  Arguments::addArgument( Expression* ex ) // O(1)
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
  Arguments::getArguments( )  // O(1)
  {
    return arguments;
  }

  void
  Arguments::print( std::ostream& ostream ) const // O(1)
  {
    ArgumentVector::const_iterator it;

    for (it=arguments.begin(); it < arguments.end(); it++) // O(|arguments|) = O(4) = O(1)
      (*it)->print(ostream);
  }
  
  void
  Arguments::clearArguments( ) // O(1)
  {
    ArgumentVector::iterator it;

    for (it=arguments.begin(); it < arguments.end(); it++)
      delete *it;
    
    arguments.clear();
  }
}

