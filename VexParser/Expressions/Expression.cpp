
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

  Expression::Expression( std::string string )
  : value( 0 )
  {
    this->SetString(string);
  }

  Expression::Expression( int value )
  : value( value ), string( "" )
  {

  }

  void
  Expression::print( )
  {
    int x=this->GetValue();
    std::string s=this->GetString();

    if (x && s.length())
      std::cout << "(";

    if (s.length())
    {
      std::cout << s;
      if (x > 0)
        std::cout << " + " << x;
      if (x < 0)
        std::cout << " - " << -x;
    } else
      std::cout << x;

    if (x && s.length())
      std::cout << ")";
  }
}
