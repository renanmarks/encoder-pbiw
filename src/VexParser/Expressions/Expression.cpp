
#include <sstream>

#include "Expression.h"

namespace VexParser
{

  Expression::Expression( char op, Expression& s1, Expression& s2 )
  {
    int nval;
    int v1=s1.GetValue();
    int v2=s2.GetValue();

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

    if (!s1.GetString().empty() && !s2.GetString().empty())
    {
      std::stringstream msg;
      msg << "illegal binary exp (" << s1.GetString() << ", " << s1.GetString() << ") at line " /*<< yylineno*/ << std::endl;
      throw new IllegalBinaryOperationException(msg.str());
    }

    this->SetString(s1.GetString().empty() ? s2.GetString() : s1.GetString());
    this->SetValue(nval);
  }

  Expression::Expression( char op, Expression& s1 )
  {
    int nval;
    int v1=s1.GetValue();

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

    if (!s1.GetString().empty())
    {
      std::stringstream msg;
      msg << "illegal unary exp (`" << s1.GetString() << "') at line " /*<< yylineno*/ << std::endl;
      throw new IllegalBinaryOperationException(msg.str());
    }

    this->SetValue(nval);
  }

  /**
   * Memory reference. 
   * First parameter is the offset, second parameter is register.
   */
  Expression::Expression( Expression& s1, std::string s2 )
  {
    this->SetString(s2);
    this->SetValue(s1.GetValue());
  }
  
  /**
   * Register reference
   */
  Expression::Expression( std::string string )
  : value( 0 )
  {
    this->SetString(string);
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
    int x = this->GetValue();
    std::string s = this->GetString();

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
}
