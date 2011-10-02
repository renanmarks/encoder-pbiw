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
  protected:
    int value;
    std::string string;
     
  public:
    
    /* Binary Operation */
    explicit Expression( char, Expression&, Expression& );
    
    /* Unary Operation */
    explicit Expression( char, Expression& );
    
    /* Memory Reference */
    explicit Expression( Expression&, std::string );
    
    /* Register or Label Reference */
    explicit Expression( std::string );
    
    /* Register or number */
    explicit Expression( int );

    virtual
    ~Expression( )
    {
    };

    virtual void
    setString( std::string string )
    {
      this->string=string;
    }

    virtual std::string
    getString( ) const
    {
      return string;
    }

    virtual void
    setValue( int value )
    {
      this->value=value;
    }

    virtual int
    getValue( ) const
    {
      return value;
    }
    
    struct ParseInfo
    {
      int value;
      std::string label;
      bool isImmediate; // Is immediate(1) or register(0)
      bool isBranchRegister; // Is BR(1) or GR(0)
      bool isLabel;   // Master of obvious
    };
    
    /**
     * Receives a register string and returns a unsigned integer that 
     * represents this register.
     */
    virtual ParseInfo
    getParsedValue() const;

    virtual void
    print(std::ostream&);

  };

  /**
   * Exception thrown when there is a invalid operation in a expression.
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
  
  /**
   * Exception thrown when the value cannot be parsed.
   */
  class CouldNotParseValueException : public std::exception
  {
  public:
    CouldNotParseValueException( );

    explicit
    CouldNotParseValueException( std::string reason ) throw () : reason( reason )
    {
    }

    virtual
    ~CouldNotParseValueException( ) throw ()
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

