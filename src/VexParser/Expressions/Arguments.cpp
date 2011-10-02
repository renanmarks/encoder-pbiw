/* 
 * File:   Arguments.cpp
 * Author: helix
 * 
 * Created on September 18, 2011, 2:56 PM
 */

#include "Arguments.h"

namespace VexParser
{
  Arguments::Arguments( Expression* ex )
  {
    addArgument(ex);
  }

  Arguments::Arguments( Arguments& arguments, Expression* ex )
  {
    this->arguments = arguments.getArguments();
    addArgument(ex);
  }
  
  Arguments::~Arguments()
  {
    ArgumentVector::iterator it;
    
    for (it = arguments.begin(); it < arguments.end(); it++)
      delete (*it);
  }

  void
  Arguments::addArgument( Expression* ex )
  {
    arguments.push_back(ex);
  }

  std::vector<Expression*>
  Arguments::getArguments( ) const
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

