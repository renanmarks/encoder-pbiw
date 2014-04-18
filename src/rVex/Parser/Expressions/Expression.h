/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
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
    bool isMemReference;
     
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
    
    /* Copy constructor */
    Expression( const Expression& );
    
    virtual
    ~Expression( ) {}

    bool operator ==(const Expression&) const;
    bool operator !=(const Expression&) const;
    
    virtual bool
    isMemoryReference() const
    { return isMemReference; }
    
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
    print(std::ostream&) const;

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

