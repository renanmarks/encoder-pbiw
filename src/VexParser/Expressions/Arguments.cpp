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

  Arguments::Arguments( Arguments& args, const Expression& ex )  // O(1)
  {
    copyExpressions(args);
    addArgument(ex);
  }
  
  Arguments::Arguments( Arguments& other )
  {
    copyExpressions(other);
  }
  
  Arguments::Arguments( const Arguments& other )
  {
    copyExpressions(other);
  }
  
  Arguments::~Arguments()
  {
    clearArguments();
  }
  
  Arguments& Arguments::operator =( const Arguments& other )
  {
    if (this != &other) // protect against invalid self-assignment
      copyExpressions(other);
    
    return *this;
  }
  
  bool Arguments::operator ==(const Arguments& other) const
  {
    ArgumentVector::const_iterator it1 = arguments.begin();
    ArgumentVector otherVector = other.getArgumentsCopy();
    ArgumentVector::const_iterator it2 = otherVector.begin();

    while (it1 != arguments.end() && it2 != otherVector.end())
    {
      if (*it1 != *it2)
        return false;

      it1++;
      it2++;
    }

    if (it1 == arguments.end() && it2 == otherVector.end())
      return true;

    return false;
  }

  bool Arguments::operator !=(const Arguments& other) const
  {
    return (*this != other);
  }

  Arguments& Arguments::copyExpressions(const Arguments& other)
  {
    ArgumentVector arguments = other.getArgumentsCopy();
    ArgumentVector::const_iterator it;

    for (it=arguments.begin(); it < arguments.end(); it++)
      addArgument( *it );
    
    return *this;
  }
  
  void
  Arguments::addArgument( const Expression& ex ) // O(1)
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
  Arguments::getArguments( ) // O(1)
  {
    return arguments;
  }
  
  Arguments::ArgumentVector
  Arguments::getArgumentsCopy( ) const
  {
    return arguments;
  }

  void
  Arguments::print( std::ostream& ostream ) const // O(1)
  {
    ArgumentVector::const_iterator it;

    for (it = arguments.begin(); it < arguments.end(); it++) // O(|arguments|) = O(4) = O(1)
      it->print(ostream);
  }
  
  void
  Arguments::clearArguments( ) // O(1)
  {
//    ArgumentVector::iterator it;

//    for (it=arguments.begin(); it < arguments.end(); it++)
//      delete *it;
    
    arguments.clear();
  }
}

