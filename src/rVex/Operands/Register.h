/* 
 * File:   Register.h
 * Author: helix
 *
 * Created on September 1, 2011, 2:45 PM
 */

#ifndef REGISTER_H
#define	REGISTER_H

#include "Register.h"

namespace rVex
{
  namespace Operands
  {

    class Register : public Expression
    {
    public:

      explicit
      Register( char op, Expression& s1, Expression& s2 ) : Expression( op, s1, s2 )
      {
      };

      explicit
      Register( char op, Expression& s1 ) : Expression( op, s1 )
      {
      };

      explicit
      Register( std::string str ) : Expression( str )
      {
      };

      explicit
      Register( int value ) : Expression( value )
      {
      };

      Register( const Register& orig );
      virtual ~Register( );
    private:

    };
  }
}
#endif	/* REGISTER_H */

