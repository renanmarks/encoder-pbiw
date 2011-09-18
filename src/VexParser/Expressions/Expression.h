/* 
 * File:   Expression.h
 * Author: helix
 *
 * Created on September 1, 2011, 2:43 PM
 */

#ifndef EXPRESSION_H
#define	EXPRESSION_H

#include <ostream>
#include <string>

namespace VexParser
{

  class Expression
  {
  public:
    /* Binary Operation */
    explicit Expression( char, Expression&, Expression& );
    
    /* Unary Operation */
    explicit Expression( char, Expression& );
    
    /* Memory Reference */
    explicit Expression( Expression&, std::string );
    
    /* Label Reference */
    explicit Expression( std::string );
    
    /* Register or number */
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
    print(std::ostream&);

  protected:
    int value;
    std::string string;

  };

  /**
   * Exception trown when there is a invalid operation in a expression.
   */
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

