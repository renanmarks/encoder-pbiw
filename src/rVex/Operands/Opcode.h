/* 
 * File:   Opcode.h
 * Author: helix
 *
 * Created on September 1, 2011, 2:45 PM
 */

#ifndef OPCODE_H
#define	OPCODE_H

#include "Expression.h"

namespace rVex
{
  namespace Operands
  {

    class Opcode : public Expression
    {
    public:
      explicit
      Opcode( char op, Expression& s1, Expression& s2 ) : Expression( op, s1, s2 )
      {
      };

      explicit
      Opcode( char op, Expression& s1 ) : Expression( op, s1 )
      {
      };

      explicit
      Opcode( std::string str ) : Expression( str )
      {
      };

      explicit
      Opcode( int value ) : Expression( value )
      {
      };
      
      Opcode( const Opcode& orig );
      virtual ~Opcode( );
    private:

    };
  }
}

#endif	/* OPCODE_H */

