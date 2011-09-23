#include <iostream>
#include <string>
using namespace std;

#include <sstream>

#include "Expression.h"

namespace VexParser
{

  Expression::Expression( char op, Expression& s1, Expression& s2 )
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
  {
    this->setString(s2);
    this->setValue(s1.getValue());
  }
  
  /**
   * Register reference
   */
  Expression::Expression( std::string string )
  : value( 0 )
  {
    this->setString(string);
  }

  /**
   * Integer value
   */
  Expression::Expression( int value )
  : value( value ), string( "" )
  {

  }

  void
  Expression::print(std::ostream& ostream )
  {
    int x = this->getValue();
    std::string s = this->getString();

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
  Expression::getParsedValue() const
  {
    int integerValue = this->getValue();
    std::string stringValue = this->getString();
    ParseInfo parsedValue;
    
    size_t pos1, pos2;
    string strTmp1, strTmp2;
    const char *convert;
        /* TODO: Parsing */
        
    // verified if string has a register
    pos1 = stringValue.find("$");
    pos2 = stringValue.find("L");
    
    // enter if register
    if(pos1 != string::npos){
        strTmp1 = stringValue.substr(pos1);
        pos1 = strTmp1.find(".");
        strTmp2 = strTmp1.substr(++pos1);
        
        convert = strTmp2.c_str();
        parsedValue.value = atoi(convert);
        parsedValue.isImmediate = 0;
        parsedValue.isBranchRegister = 0;
        
    }
    else if(pos2 != string::npos){      // enter if label
		strTmp1 = stringValue.substr(pos2);
		parsedValue.isImmediate = 0;
                parsedValue.isBranchRegister = 1;
    }
    else {      // immediate.
        convert = stringValue.c_str();
        parsedValue.value = atoi(convert);        
        parsedValue.isImmediate = 1;
        parsedValue.isBranchRegister = 0;
    }
   
    //throw new CouldNotParseValueException("DEU MERDA");
    
    
    return parsedValue;

  }
}
