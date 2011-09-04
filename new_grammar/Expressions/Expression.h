/* 
 * File:   Expression.h
 * Author: helix
 *
 * Created on September 1, 2011, 2:43 PM
 */

#ifndef EXPRESSION_H
#define	EXPRESSION_H

#include <iostream>
#include <string>

namespace VexParser
{

  class Expression
  {
  public:
    explicit Expression( char, Expression&, Expression& );
    explicit Expression( char, Expression& );
    explicit Expression( std::string );
    explicit Expression( int );

    virtual
    ~Expression( )
    {
    };

    virtual void
    SetString( std::string string )
    {
      this->string=string;
    }

    virtual std::string
    GetString( ) const
    {
      return string;
    }

    virtual void
    SetValue( int value )
    {
      this->value=value;
    }

    virtual int
    GetValue( ) const
    {
      return value;
    }

    virtual void
    print( );

  protected:
    int value;
    std::string string;

  };

  class IllegalBinaryOperationException : public std::exception
  {
  public:
    IllegalBinaryOperationException( );

    explicit
    IllegalBinaryOperationException( std::string reason ) throw () : reason( reason )
    {
    }

    virtual
    ~IllegalBinaryOperationException( ) throw ()
    {
    };

    virtual const char*
    what( ) const throw ()
    {
      return reason.c_str();
    }

  private:
    std::string reason;
  };
}

#endif	/* EXPRESSION_H */

