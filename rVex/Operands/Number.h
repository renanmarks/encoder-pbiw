/* 
 * File:   Number.h
 * Author: helix
 *
 * Created on September 1, 2011, 2:45 PM
 */

#ifndef NUMBER_H
#define	NUMBER_H

#include "Expression.h"

namespace rVex
{
  namespace Operands
  {

    class Number : public Expression
    {
    public:
      explicit
      Number( char op, Expression& s1, Expression& s2 ) : Expression( op, s1, s2 )
      {
      };

      explicit
      Number( char op, Expression& s1 ) : Expression( op, s1 )
      {
      };

      explicit
      Number( std::string str ) : Expression( str )
      {
      };

      explicit
      Number( int value ) : Expression( value )
      {
      };
      Number( const Number& orig );
      virtual ~Number( );
    private:

    };
  }
}

#endif	/* NUMBER_H */

