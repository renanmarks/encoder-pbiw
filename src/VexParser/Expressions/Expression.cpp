#include <iostream>
#include <string>
using namespace std;

#include <sstream>
#include <cstdlib>

#include "Expression.h"

namespace VexParser
{

  Expression::Expression( char op, Expression& s1, Expression& s2 )
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

  Expression::Expression( char op, Expression& s1 )
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
  Expression::Expression( Expression& s1, std::string s2 )
  : value(s1.getValue()), string(s2), isMemReference(true)
  {
    
  }

  /**
   * Register reference
   */
  Expression::Expression( std::string string )
  : value( 0 ), string(string), isMemReference(false)
  {
    
  }

  /**
   * Integer value
   */
  Expression::Expression( int value )
  : value( value ), string( "" ), isMemReference(false)
  {

  }

  void
  Expression::print( std::ostream& ostream )
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
  Expression::getParsedValue( ) const
  {
    int integerValue=this->getValue();
    std::string stringValue=this->getString();
    ParseInfo parsedValue;
    
    parsedValue.isImmediate      = false;
    parsedValue.isBranchRegister = false;
    parsedValue.isLabel          = false;

    // verify if string has a register
    std::size_t registerString = stringValue.find("$r");
    std::size_t linkRegisterString = stringValue.find("$l");
    std::size_t branchRegisterString = stringValue.find("$b");

    if (registerString != string::npos ) // General Register
    {
      std::size_t number        = stringValue.substr(registerString).find(".");
      std::string numberString  = stringValue.substr(++number);
      parsedValue.value         = std::atoi(numberString.c_str());
    } 
    else if (linkRegisterString != string::npos ) // Link Register
    {
      parsedValue.value         = 31;
    } 
    else if (branchRegisterString != string::npos ) // Branch Register
    {
      std::size_t number        = stringValue.substr(branchRegisterString).find(".");
      std::string numberString  = stringValue.substr(++number);
      parsedValue.value            = std::atoi(numberString.c_str());
      parsedValue.isBranchRegister = true;
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
