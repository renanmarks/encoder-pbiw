/* $Id: scanner.ll 44 2008-10-23 09:03:19Z tb $ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <cstdio>
#include <string>
using namespace std;
  
#include "scanner.h"
#include "vextypes.h"

/* opcode definitions */
#include "vexopc.h"

/* import the parser's token type into a local typedef */
typedef VexParser::Parser::token token;
typedef VexParser::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

#define Token(n) return(n)

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "VexFlexLexer" */
%option prefix="Vex"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

hex         "0x"[0-9a-f]+ 
dec         [0-9]+
quotetext   \"([^\"]|\\\")*\"
comtext     "#".*$
stabtext    \.stab[snd].*$
regname     \$(r|b|l)[0-9]\.[0-9]+
cl1    	    c[0-9](\.[0-9])?
cl2         c[0-9](\.[0-9])?"="c[0-9](\.[0-9])?
symbolname  [0-9a-zA-Z\._\$\?]+
operator    [=\-\+\[\]~,\(\):;@]
wspace      [ \t]+

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/

{comtext}       { }
{stabtext}      { }
{hex}|{dec}     { yylval->value = strtol(yytext,0,0); Token(token::NUMBER); }
{quotetext}     { return makeQuoted(yytext, yylval);                                }
{regname}       { return makeRegister(yytext, yylval);                              }
{cl1}|{cl2}     { return makeCluster(yytext, yylval);                               }
{symbolname}    { return checkReserved(yytext, yylval);                             }
\n              { }
{wspace}        { /* ignore white space */                                  }
{operator}      { return makeOperator(yytext, yylval);                              }

 /* pass all other characters up to bison */
. {
    cerr << "error: unexpected " << yytext[0] << " at " << yylineno << endl;
//    return 2;
    return static_cast<token_type>(*yytext);
}

 /*** END EXAMPLE - Change the example lexer rules above ***/

%% /*** Additional Code ***/

namespace VexParser {

  Scanner::Scanner(std::istream* in,
       std::ostream* out)
      : VexFlexLexer(in, out)
  {
  }

  Scanner::~Scanner()
  {
  }

  void Scanner::set_debug(bool b)
  {
      yy_flex_debug = b;
  }

  /* check list of reserved words       */
  
  token_type Scanner::checkReserved(const char *buf, VexParser::Parser::semantic_type* yylval)
  {
      int i;
      int sizeOperationTable = optab.size();
      
      yylval->opcode = NULL;
      
      for (i = 0; i < sizeOperationTable; i++)
      {
        if (optab[i].as_op == buf)
        {
            yylval->opcode = &optab[i];
            Token(yylval->opcode->tok);
        }
      }
      
      yylval->text = new std::string(buf);
      Token(token::NAME);
  }

  token_type Scanner::makeCluster(const char *buf, VexParser::Parser::semantic_type* yylval)
  {
      yylval->text = new std::string(buf);
      Token(token::CLUST);
  }

  token_type Scanner::makeRegister(const char *buf, VexParser::Parser::semantic_type* yylval)
  {
      yylval->text = new std::string(buf);
      Token(token::REGNAME);
  }
  
  token_type Scanner::makeOperator(const char *buf, VexParser::Parser::semantic_type* yylval)
  {
      // TODO
    
//      yylval->text = strdup(buf);
      Token(token::__PLUS);
  }

  /*  count new lines in quoted string  */

  token_type Scanner::makeQuoted(const char *buf, VexParser::Parser::semantic_type* yylval)
  {
      yylval->text = new std::string(buf);
      Token(token::QUOTE_STRING);
  }
}

/* This implementation of VexFlexLexer::yylex() is required to fill the
 * vtable of the class VexFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int VexFlexLexer::yylex()
{
    std::cerr << "in VexFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int VexFlexLexer::yywrap()
{
    return 1;
}
