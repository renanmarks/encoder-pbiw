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
#include <iostream>
#include <string>
using namespace std;

#include <sstream>
#include <cstdlib>

#include "Expression.h"

namespace VexParser
{

  Expression::Expression( char op, Expression& s1, Expression& s2 ) // O(1)
    : isMemReference(false)
  {
    int nval;
    int v1=s1.getValue();
    int v2=s2.getValue();

    switch (op) {
      case '-': nval=v1 - v2;
        break;
      case '+': nval=v1 + v2;
        break;
      default:
        std::stringstream msg;
        msg << "illegal binary op (`" << op << "') at line " /*<< yylineno*/ << std::endl;
        throw new IllegalBinaryOperationException(msg.str());
    }

    if (!s1.getString().empty() && !s2.getString().empty())
    {
      std::stringstream msg;
      msg << "illegal binary exp (" << s1.getString() << ", " << s1.getString() << ") at line " /*<< yylineno*/ << std::endl;
      throw new IllegalBinaryOperationException(msg.str());
    }

    this->setString(s1.getString().empty() ? s2.getString() : s1.getString());
    this->setValue(nval);
  }

  Expression::Expression( char op, Expression& s1 ) // O(1)
    : isMemReference(false)
  {
    int nval;
    int v1=s1.getValue();

    switch (op) {
      case '-': nval= -v1;
        break;
      case '+': nval= +v1;
        break;
      case '~': nval= ~v1;
        break;
      default:
        std::stringstream msg;
        msg << "illegal binary op (`" << op << "') at line " /*<< yylineno*/ << std::endl;
        throw new IllegalBinaryOperationException(msg.str());
    }

    if (!s1.getString().empty())
    {
      std::stringstream msg;
      msg << "illegal unary exp (`" << s1.getString() << "') at line " /*<< yylineno*/ << std::endl;
      throw new IllegalBinaryOperationException(msg.str());
    }

    this->setValue(nval);
  }

  /**
   * Memory reference. 
   * First parameter is the offset, second parameter is register.
   */
  Expression::Expression( Expression& s1, std::string s2 ) // O(1)
  : value(s1.getValue()), string(s2), isMemReference(true)
  {
    
  }

  /**
   * Register reference
   */
  Expression::Expression( std::string string )  // O(1)
  : value( 0 ), string(string), isMemReference(false)
  {
    
  }

  /**
   * Integer value
   */
  Expression::Expression( int value ) // O(1)
  : value( value ), string( "" ), isMemReference(false)
  {

  }
  
  /**
   * Copy
   */
  Expression::Expression( const Expression& orig)
  : value(orig.getValue()), string(orig.getString()), isMemReference(orig.isMemoryReference())
  {
    
  }

  bool Expression::operator ==(const Expression& other) const
  {
    return value == other.getValue() && string == other.getString() && isMemReference == other.isMemoryReference();
  }
  
  bool Expression::operator !=(const Expression& other) const
  {
    return !(*this == other);
  }
  
  void
  Expression::print( std::ostream& ostream ) const // O(1)
  {
    int x=this->getValue();
    std::string s=this->getString();

    if (x && s.length())
      ostream << "(";

    if (s.length())
    {
      ostream << s;
      if (x > 0)
        ostream << " + " << x;
      if (x < 0)
        ostream << " - " << -x;
    } else
      ostream << x;

    if (x && s.length())
      ostream << ")";
  }

  Expression::ParseInfo
  Expression::getParsedValue( ) const  // O(1)
  {
    int integerValue=this->getValue(); // O(1)
    std::string stringValue=this->getString(); // O(1)
    ParseInfo parsedValue;
    
    parsedValue.isImmediate      = false;
    parsedValue.isBranchRegister = false;
    parsedValue.isLabel          = false;

    // verify if string has a register
    std::size_t registerString = stringValue.find("$r"); // O(1)
    std::size_t linkRegisterString = stringValue.find("$l"); // O(1)
    std::size_t branchRegisterString = stringValue.find("$b"); // O(1)

    if (registerString != string::npos ) // General Register
    {
      std::size_t number        = stringValue.substr(registerString).find("."); // O(1)
      std::string numberString  = stringValue.substr(++number); // O(1)
      parsedValue.value         = std::atoi(numberString.c_str()); // O(1)
    } 
    else if (linkRegisterString != string::npos ) // Link Register
    {
      parsedValue.value         = 30;
    } 
    else if (branchRegisterString != string::npos ) // Branch Register
    {
      std::size_t number        = stringValue.substr(branchRegisterString).find("."); // O(1)
      std::string numberString  = stringValue.substr(++number); // O(1)
      parsedValue.value            = std::atoi(numberString.c_str()); // O(1)
      parsedValue.isBranchRegister = true; // O(1)
    } 
    else if (stringValue.length() > 0) // Label
    { 
      parsedValue.label   = stringValue;
      parsedValue.isLabel = true;
    }
    else // Immediate
    {
      parsedValue.value       = integerValue;
      parsedValue.isImmediate = true;
    } 

    return parsedValue;
  }
}
