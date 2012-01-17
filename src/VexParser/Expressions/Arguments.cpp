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
  Arguments::Arguments( const Expression& ex )
  { 
    addArgument(ex);
  }

  Arguments::Arguments( Arguments& args, const Expression& ex )
  {
    copyExpressions(args.getArguments());
    
    addArgument(ex);
  }
  
  Arguments::Arguments( Arguments& other )
  {
    if (this != &other) // protect against invalid self-assignment
    {
      copyExpressions(other.getArguments());
    }
  }
  
  Arguments::~Arguments()
  {
    clearArguments();
  }

  void Arguments::copyExpressions(const ArgumentVector& expressions)
  {
    ArgumentVector::const_iterator it;

    for (it=expressions.begin(); it < expressions.end(); it++)
      addArgument( *it );
  }
  
  void
  Arguments::addArgument( const Expression& ex )
  {
    if (ex.isMemoryReference())
    {
      arguments.push_back( Expression(ex.getValue()) );  // offset
      arguments.push_back( Expression(ex.getString()) ); // register
      
      return;
    }
    
    arguments.push_back(ex);
  }

  Arguments::ArgumentVector&
  Arguments::getArguments( )
  {
    return arguments;
  }

  void
  Arguments::print( std::ostream& ostream ) const
  {
    ArgumentVector::const_iterator it;

    for (it = arguments.begin(); it < arguments.end(); it++)
      it->print(ostream);
  }
  
  void
  Arguments::clearArguments( )
  {
    ArgumentVector::iterator it;

//    for (it=arguments.begin(); it < arguments.end(); it++)
//      delete *it;
    
    arguments.clear();
  }
}

