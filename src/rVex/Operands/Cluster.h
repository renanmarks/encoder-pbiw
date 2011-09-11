/* 
 * File:   Cluster.h
 * Author: helix
 *
 * Created on September 1, 2011, 2:45 PM
 */

#ifndef CLUSTER_H
#define	CLUSTER_H

namespace rVex
{
  namespace Operands
  {

    class Cluster : public Expression
    {
    public:

      explicit
      Cluster( char op, Expression& s1, Expression& s2 ) : Expression( op, s1, s2 )
      {
      };

      explicit
      Cluster( char op, Expression& s1 ) : Expression( op, s1 )
      {
      };

      explicit
      Cluster( std::string str ) : Expression( str )
      {
      };

      explicit
      Cluster( int value ) : Expression( value )
      {
      };

      Cluster( const Cluster& orig );
      virtual ~Cluster( );
    private:

    };
  }
}

#endif	/* CLUSTER_H */
