
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   VexParserlex

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 5 "parser.yy"
 /*** C/C++ Declarations ***/
  
//#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "VexTypes.h"
#include "Expressions/Expression.h"
#include "Expressions/Arguments.h"
#include "Expressions/SyllableArguments.h"
  


/* Line 311 of lalr1.cc  */
#line 58 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 181 "parser.yy"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 81 "parser.tab.cc"

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace VexParser {

/* Line 380 of lalr1.cc  */
#line 150 "parser.tab.cc"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 6: /* "_CALL_JMP" */

/* Line 480 of lalr1.cc  */
#line 165 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 257 "parser.tab.cc"
	break;
      case 40: /* "CLUST" */

/* Line 480 of lalr1.cc  */
#line 160 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 266 "parser.tab.cc"
	break;
      case 41: /* "NAME" */

/* Line 480 of lalr1.cc  */
#line 161 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 275 "parser.tab.cc"
	break;
      case 43: /* "OPCODE" */

/* Line 480 of lalr1.cc  */
#line 162 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 284 "parser.tab.cc"
	break;
      case 44: /* "XNOP" */

/* Line 480 of lalr1.cc  */
#line 163 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 293 "parser.tab.cc"
	break;
      case 45: /* "QUOTE_STRING" */

/* Line 480 of lalr1.cc  */
#line 164 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 302 "parser.tab.cc"
	break;
      case 64: /* "data_val" */

/* Line 480 of lalr1.cc  */
#line 171 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 311 "parser.tab.cc"
	break;
      case 88: /* "call_jmp_tgt" */

/* Line 480 of lalr1.cc  */
#line 167 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 320 "parser.tab.cc"
	break;
      case 89: /* "entry_dir" */

/* Line 480 of lalr1.cc  */
#line 173 "parser.yy"
	{ delete (yyvaluep->function); };

/* Line 480 of lalr1.cc  */
#line 329 "parser.tab.cc"
	break;
      case 92: /* "arg" */

/* Line 480 of lalr1.cc  */
#line 169 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 338 "parser.tab.cc"
	break;
      case 93: /* "ret" */

/* Line 480 of lalr1.cc  */
#line 170 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 347 "parser.tab.cc"
	break;
      case 114: /* ".mop_arglist" */

/* Line 480 of lalr1.cc  */
#line 177 "parser.yy"
	{ delete (yyvaluep->syllableArguments); };

/* Line 480 of lalr1.cc  */
#line 356 "parser.tab.cc"
	break;
      case 115: /* "mop_arglist" */

/* Line 480 of lalr1.cc  */
#line 176 "parser.yy"
	{ delete (yyvaluep->arguments); };

/* Line 480 of lalr1.cc  */
#line 365 "parser.tab.cc"
	break;
      case 116: /* "mop_arg" */

/* Line 480 of lalr1.cc  */
#line 175 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 374 "parser.tab.cc"
	break;
      case 117: /* "expr" */

/* Line 480 of lalr1.cc  */
#line 172 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 383 "parser.tab.cc"
	break;
      case 118: /* "name" */

/* Line 480 of lalr1.cc  */
#line 168 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 392 "parser.tab.cc"
	break;

	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  Parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 52 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 478 "parser.tab.cc"

    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 15:

/* Line 678 of lalr1.cc  */
#line 231 "parser.yy"
    { }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 232 "parser.yy"
    { }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 233 "parser.yy"
    { }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 234 "parser.yy"
    { }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 235 "parser.yy"
    { }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 236 "parser.yy"
    { }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 237 "parser.yy"
    { }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 238 "parser.yy"
    { }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 245 "parser.yy"
    { }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 246 "parser.yy"
    { }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 247 "parser.yy"
    { }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 250 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 251 "parser.yy"
    { (yyval.expression) = new Expression((yysemantic_stack_[(3) - (1)].value)); }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 253 "parser.yy"
    { (yyval.value) = 1; }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 254 "parser.yy"
    { (yyval.value) = 2; }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 255 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 256 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 257 "parser.yy"
    { (yyval.value) = 8; }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 260 "parser.yy"
    { (yyval.value) = 0;  }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 261 "parser.yy"
    { (yyval.value) = (yysemantic_stack_[(2) - (2)].value); }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 265 "parser.yy"
    { }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 286 "parser.yy"
    { }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 287 "parser.yy"
    { }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 290 "parser.yy"
    { }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 316 "parser.yy"
    { }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 319 "parser.yy"
    { }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 320 "parser.yy"
    { }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 321 "parser.yy"
    { }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 325 "parser.yy"
    { }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 344 "parser.yy"
    { driver.context.setLabel(*(yysemantic_stack_[(2) - (1)].text), (yysemantic_stack_[(2) - (2)].scope)); }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 347 "parser.yy"
    { }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 348 "parser.yy"
    { }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 349 "parser.yy"
    { }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 352 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 353 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 354 "parser.yy"
    { (yyval.text) = new std::string(""); }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 357 "parser.yy"
    { 
                            driver.context.setLabel(*(yysemantic_stack_[(11) - (10)].text), (yysemantic_stack_[(11) - (11)].scope));
                        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 360 "parser.yy"
    {
                            driver.context.setLabel(*(yysemantic_stack_[(2) - (1)].text), (yysemantic_stack_[(2) - (2)].scope));
                        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 365 "parser.yy"
    { }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 368 "parser.yy"
    { }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 371 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 374 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 377 "parser.yy"
    { }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 380 "parser.yy"
    { }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 383 "parser.yy"
    { (yyval.scope) = rVex::Label::LOCAL; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 384 "parser.yy"
    { (yyval.scope) = rVex::Label::GLOBAL; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 399 "parser.yy"
    { }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 406 "parser.yy"
    { }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 407 "parser.yy"
    { }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 408 "parser.yy"
    { }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 411 "parser.yy"
    { }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 412 "parser.yy"
    { }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 419 "parser.yy"
    { }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 427 "parser.yy"
    { 
                          driver.context.endInstruction(); 
                          std::cout << ";;" << std::endl; 
                        }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 450 "parser.yy"
    { 
                          driver.context.packSyllable( (yysemantic_stack_[(3) - (2)].opcode)->syllableConstructor->create(), (yysemantic_stack_[(3) - (3)].syllableArguments) ); 
                          
                          std::cout << " " << (yysemantic_stack_[(3) - (2)].opcode)->as_op << " ";
                          
                          if ( (yysemantic_stack_[(3) - (3)].syllableArguments)->getDestinyArguments() )
                          {
                            (yysemantic_stack_[(3) - (3)].syllableArguments)->getDestinyArguments()->print(std::cout);
                            std::cout << " = ";
                          }
                          (yysemantic_stack_[(3) - (3)].syllableArguments)->getSourceArguments()->print(std::cout);
                          
                          std::cout << std::endl;
                        }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 467 "parser.yy"
    { 
                          Expression* ex = new Expression((yysemantic_stack_[(2) - (2)].value));
                          SyllableArguments* argument = new SyllableArguments(new Arguments(ex));
                          driver.context.packSyllable( (yysemantic_stack_[(2) - (1)].opcode)->syllableConstructor->create(), argument ); 
                          
                          std::cout << " " << (yysemantic_stack_[(2) - (1)].opcode)->as_op << " " << (yysemantic_stack_[(2) - (2)].value) << std::endl;
                        }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 476 "parser.yy"
    { }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 477 "parser.yy"
    { }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 484 "parser.yy"
    { }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 485 "parser.yy"
    { (yyval.syllableArguments) = new SyllableArguments((yysemantic_stack_[(3) - (1)].arguments), (yysemantic_stack_[(3) - (3)].arguments)); }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 486 "parser.yy"
    { (yyval.syllableArguments) = new SyllableArguments((yysemantic_stack_[(2) - (1)].arguments)); }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 487 "parser.yy"
    { (yyval.syllableArguments) = new SyllableArguments((yysemantic_stack_[(1) - (1)].arguments)); }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 491 "parser.yy"
    { (yyval.arguments) = new Arguments((yysemantic_stack_[(1) - (1)].expression)); }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 492 "parser.yy"
    { (yyval.arguments) = new Arguments(*(yysemantic_stack_[(3) - (1)].arguments), (yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 495 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 496 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(3) - (2)].text)); }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 497 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(4) - (1)].expression), *(yysemantic_stack_[(4) - (3)].text)); }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 504 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].expression); }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 505 "parser.yy"
    { (yyval.expression) = new Expression('+', *(yysemantic_stack_[(3) - (1)].expression), *(yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 506 "parser.yy"
    { (yyval.expression) = new Expression('-', *(yysemantic_stack_[(3) - (1)].expression), *(yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 507 "parser.yy"
    { (yyval.expression) = new Expression('-', *(yysemantic_stack_[(2) - (2)].expression)); }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 508 "parser.yy"
    { (yyval.expression) = new Expression('+', *(yysemantic_stack_[(2) - (2)].expression)); }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 509 "parser.yy"
    { (yyval.expression) = new Expression('~', *(yysemantic_stack_[(2) - (2)].expression)); }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 510 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(1) - (1)].text)); }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 511 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(1) - (1)].text)); }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 512 "parser.yy"
    { (yyval.expression) = new Expression((yysemantic_stack_[(1) - (1)].value)); }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 518 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 519 "parser.yy"
    { (yyval.text) = new std::string((yysemantic_stack_[(1) - (1)].opcode)->as_op); }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 520 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;



/* Line 678 of lalr1.cc  */
#line 1176 "parser.tab.cc"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Parser::yypact_ninf_ = -202;
  const short int
  Parser::yypact_[] =
  {
       222,   -34,   -12,    43,   144,   124,  -202,  -202,  -202,    56,
      35,    50,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,    -3,   144,   144,     7,  -202,    56,  -202,  -202,  -202,
    -202,    25,    18,   144,    32,   144,  -202,    35,  -202,  -202,
    -202,  -202,  -202,    25,    42,   144,  -202,  -202,    50,  -202,
    -202,    94,  -202,  -202,  -202,  -202,    25,  -202,    54,    57,
    -202,  -202,    63,  -202,  -202,  -202,  -202,    67,  -202,  -202,
    -202,  -202,  -202,  -202,    62,  -202,    25,  -202,    68,   211,
    -202,    77,   132,  -202,    82,    86,   115,   101,   211,   211,
     211,   211,  -202,  -202,    44,  -202,    97,    95,  -202,  -202,
    -202,  -202,  -202,   105,   132,  -202,   230,   108,    79,   111,
     119,   120,   123,    74,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   133,   -27,  -202,  -202,  -202,  -202,  -202,   130,  -202,
    -202,  -202,   125,   211,   211,  -202,  -202,  -202,  -202,   142,
     143,    44,   148,   151,  -202,  -202,   171,  -202,  -202,   146,
     172,   128,  -202,  -202,  -202,   174,  -202,   120,  -202,  -202,
    -202,  -202,  -202,   163,   166,  -202,   211,   173,    62,   149,
     175,   177,   169,  -202,    23,  -202,    27,  -202,  -202,  -202,
      44,   148,   196,  -202,   200,   211,   201,   149,   206,  -202,
     165,  -202,  -202,   205,   170,   170,   202,   149,  -202,   195,
    -202,   206,   233,   149,   207,   192,   170,  -202,  -202,   216,
     213,   220,   215,   -20,  -202,   234,   221,  -202,   246,    51,
    -202,  -202,   144,  -202,   232,  -202,  -202,  -202,   231,   -20,
      25,   149,  -202,  -202,  -202,   242,   238,  -202,   111,   245,
     149,   247,  -202
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     2,     7,     9,    39,
      11,    51,     4,     5,     6,   141,   139,   140,     8,     1,
       3,     0,     0,     0,     0,    38,    40,    41,    43,    44,
      45,     0,     0,     0,     0,     0,    10,    12,    13,    21,
      20,    19,    22,     0,     0,     0,    65,    50,    52,    53,
      55,     0,    59,    57,    56,    58,     0,    46,     0,     0,
      47,    42,    91,    48,    15,    37,    16,     0,    14,    17,
      60,    89,    54,    64,     0,    61,     0,    76,     0,     0,
      92,     0,     0,    85,     0,   110,    84,     0,     0,     0,
       0,     0,   138,   137,    90,   136,     0,     0,    30,    31,
      32,    33,    34,     0,    18,    23,     0,     0,    82,     0,
       0,   141,     0,   110,    66,    73,    71,    69,    72,    70,
      68,     0,   111,   112,   114,   115,   116,    63,     0,   134,
     133,   135,     0,     0,     0,    93,    27,    26,    24,   138,
      35,    28,     0,     0,   105,    81,     0,    80,    88,     0,
      74,   121,   118,    62,    67,     0,   108,     0,   113,    49,
     130,   131,   132,     0,     0,    25,     0,     0,     0,    94,
       0,     0,     0,   117,   124,   125,   127,   109,    29,    36,
     107,    87,     0,   106,     0,     0,     0,     0,    95,    98,
       0,    75,   119,     0,     0,   123,     0,    94,    77,     0,
      86,    96,     0,     0,     0,     0,   121,   128,   126,   122,
       0,     0,     0,     0,    99,     0,     0,   100,     0,   136,
     120,   129,     0,    87,     0,   102,   103,    97,     0,     0,
       0,    94,   104,   101,    83,     0,     0,    78,     0,     0,
      94,     0,    79
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -202,  -202,   275,  -202,  -202,  -202,   244,  -202,  -202,   179,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,   258,  -202,     0,
    -202,  -202,  -202,   237,  -202,  -202,  -202,  -202,   176,  -202,
     -81,  -202,  -202,  -202,  -202,  -202,   118,  -202,    75,    52,
    -202,    -2,   -42,    -8,  -195,  -202,   104,    85,  -201,  -202,
     126,  -202,  -202,  -202,  -202,   178,  -202,  -202,  -202,  -202,
      88,   100,    98,   -64,    -4
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     5,     6,    12,    36,    37,    38,    82,   104,   105,
     140,   106,   165,    39,    13,    25,    26,    27,    28,    29,
      14,    47,    48,    49,    50,    85,    51,   113,   114,   115,
      52,   117,   212,   238,   146,    75,    84,   118,   182,   149,
      53,    30,    63,    42,   186,   187,   188,   189,   217,   143,
     144,   120,   156,   121,   122,   123,   124,   125,   126,   206,
     173,   174,   175,   176,    95
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -104;
  const short int
  Parser::yytable_[] =
  {
        18,    69,   211,    55,   116,    31,    43,    56,    41,    54,
      40,     7,   225,   157,    77,    94,   216,   112,    58,    59,
      15,    16,    31,    17,   129,   130,   131,   132,   233,    65,
       8,    67,   116,    43,    86,    41,   235,    40,    32,    57,
      55,    71,   141,    22,    56,   241,    54,    76,     9,    60,
      23,    33,    10,    44,   194,   133,   134,    62,    34,    21,
      64,   195,    35,   196,    22,    23,    45,    46,    11,   161,
     162,    23,   133,   134,    66,    15,    16,    35,    17,    24,
     108,    56,  -103,   119,    70,    78,  -103,   153,    79,    23,
      15,    16,   108,    17,   109,    80,    15,    16,    81,    17,
     110,    23,   180,    83,   147,   190,   109,    73,    74,    56,
      87,   119,   110,   107,   111,    16,    96,    17,   112,    15,
      16,   199,    17,   202,    19,   145,   111,    16,   127,    17,
     112,     1,   128,   190,    15,    16,    97,    17,   135,   202,
     136,   218,    98,    99,   100,     2,     3,   137,     4,   142,
     101,   102,   148,   133,   134,   103,    88,    89,    90,   171,
     160,   150,    91,   151,   172,   152,   155,   190,    15,    16,
      92,    17,   159,   163,    93,   164,   190,    88,    89,    90,
     169,   185,   167,    91,    15,    16,   166,    17,   234,    15,
      16,    92,    17,   133,   134,    93,   204,   205,    88,    89,
      90,   219,   168,   170,    91,   178,   172,   177,   179,   226,
      15,    16,    92,    17,   181,   193,    93,   191,   230,   192,
      88,    89,    90,   133,   134,   226,    91,   213,   216,     1,
     197,   198,    15,    16,    92,    17,   200,   203,    93,    88,
      89,    90,   207,     2,     3,    91,     4,   194,   210,   215,
     221,    15,    16,    92,    17,   222,   223,    93,    88,    89,
      90,   133,   134,   228,    91,   205,   231,   227,   232,   237,
      15,    16,   139,    17,   133,   134,    93,   236,   229,   240,
      20,    68,   242,   138,    61,    72,   184,   224,   214,   154,
     239,   201,   208,   183,   220,   209,     0,     0,     0,     0,
     158
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         4,    43,   197,    11,    85,     9,    10,    11,    10,    11,
      10,    45,   213,    40,    56,    79,    36,    44,    22,    23,
      40,    41,    26,    43,    88,    89,    90,    91,   229,    33,
      42,    35,   113,    37,    76,    37,   231,    37,     3,    42,
      48,    45,   106,     8,    48,   240,    48,    51,     5,    42,
      15,    16,     9,     3,    31,    28,    29,    32,    23,     3,
      42,    38,    27,    36,     8,    15,    16,    17,    25,   133,
     134,    15,    28,    29,    42,    40,    41,    27,    43,    23,
       6,    85,    31,    85,    42,    31,    35,    13,    31,    15,
      40,    41,     6,    43,    20,    32,    40,    41,    31,    43,
      26,    15,   166,    41,   108,   169,    20,    13,    14,   113,
      42,   113,    26,    31,    40,    41,    39,    43,    44,    40,
      41,   185,    43,   187,     0,    46,    40,    41,    13,    43,
      44,     7,    31,   197,    40,    41,     4,    43,    41,   203,
      45,   205,    10,    11,    12,    21,    22,    42,    24,    41,
      18,    19,    41,    28,    29,    23,    28,    29,    30,    31,
      35,    42,    34,    43,    36,    42,    33,   231,    40,    41,
      42,    43,    42,    31,    46,    32,   240,    28,    29,    30,
      34,    32,    31,    34,    40,    41,    38,    43,   230,    40,
      41,    42,    43,    28,    29,    46,    31,    32,    28,    29,
      30,   205,    31,    31,    34,    42,    36,    33,    42,   213,
      40,    41,    42,    43,    41,    46,    46,    42,   222,    42,
      28,    29,    30,    28,    29,   229,    34,    32,    36,     7,
      34,    31,    40,    41,    42,    43,    35,    31,    46,    28,
      29,    30,    37,    21,    22,    34,    24,    31,    46,    42,
      37,    40,    41,    42,    43,    35,    41,    46,    28,    29,
      30,    28,    29,    42,    34,    32,    34,    33,    37,    31,
      40,    41,    42,    43,    28,    29,    46,    35,    32,    34,
       5,    37,    35,   104,    26,    48,   168,   212,   203,   113,
     238,   187,   194,   167,   206,   195,    -1,    -1,    -1,    -1,
     122
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     7,    21,    22,    24,    55,    56,    45,    42,     5,
       9,    25,    57,    68,    74,    40,    41,    43,   118,     0,
      56,     3,     8,    15,    23,    69,    70,    71,    72,    73,
      95,   118,     3,    16,    23,    27,    58,    59,    60,    67,
      73,    95,    97,   118,     3,    16,    17,    75,    76,    77,
      78,    80,    84,    94,    95,    97,   118,    42,   118,   118,
      42,    71,    32,    96,    42,   118,    42,   118,    60,    96,
      42,   118,    77,    13,    14,    89,   118,    96,    31,    31,
      32,    31,    61,    41,    90,    79,    96,    42,    28,    29,
      30,    34,    42,    46,   117,   118,    39,     4,    10,    11,
      12,    18,    19,    23,    62,    63,    65,    31,     6,    20,
      26,    40,    44,    81,    82,    83,    84,    85,    91,    95,
     105,   107,   108,   109,   110,   111,   112,    13,    31,   117,
     117,   117,   117,    28,    29,    41,    45,    42,    63,    42,
      64,   117,    41,   103,   104,    46,    88,   118,    41,    93,
      42,    43,    42,    13,    82,    33,   106,    40,   109,    42,
      35,   117,   117,    31,    32,    66,    38,    31,    31,    34,
      31,    31,    36,   114,   115,   116,   117,    33,    42,    42,
     117,    41,    92,   104,    90,    32,    98,    99,   100,   101,
     117,    42,    42,    46,    31,    38,    36,    34,    31,   117,
      35,   100,   117,    31,    31,    32,   113,    37,   116,   115,
      46,    98,    86,    32,   101,    42,    36,   102,   117,   118,
     114,    37,    35,    41,    92,   102,   118,    33,    42,    32,
     118,    34,    37,   102,    96,    98,    35,    31,    87,    93,
      34,    98,    35
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    60,    61,    60,    60,
      60,    60,    60,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    67,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    72,    73,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    79,    78,    78,    78,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    83,    83,    84,    86,    87,    85,
      88,    88,    88,    89,    89,    90,    91,    92,    93,    94,
      95,    96,    96,    97,    98,    98,    98,    99,   100,   100,
     101,   101,   101,   102,   102,   103,   103,   104,   105,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   111,   113,
     112,   114,   114,   114,   114,   115,   115,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   118
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     1,     1,     2,     2,     2,     0,     4,     1,
       1,     1,     1,     1,     2,     3,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     0,     2,     2,     2,     0,
       1,     1,     2,     1,     1,     1,     2,     2,     2,     6,
       2,     0,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     0,     5,     4,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     4,     2,     0,     0,    16,
       1,     1,     0,    11,     2,     1,     5,     1,     1,     2,
       4,     1,     2,     5,     0,     1,     2,     4,     1,     3,
       3,     5,     4,     1,     3,     1,     3,     3,     2,     2,
       0,     1,     1,     2,     1,     1,     1,     3,     2,     0,
       6,     0,     3,     2,     1,     1,     3,     1,     3,     4,
       3,     3,     3,     2,     2,     2,     1,     1,     1,     1,
       1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "_ALIGN", "_ASCII", "_BSS",
  "_CALL_JMP", "_COMMENT", "_COMMON", "_DATA", "_DATA1", "_DATA2",
  "_DATA4", "_ENDP", "_ENTRY", "_EQU", "_IMPORT", "_PROC", "_REAL4",
  "_REAL8", "_RETURN", "_RTA", "_SECTION", "_SKIP", "_SVERSION", "_TEXT",
  "_TRACE", "_TYPE", "__PLUS", "__MINUS", "__NOT", "__COMMA", "__COLON",
  "__SEMICOLON", "__LPAREN", "__RPAREN", "__LBRACKET", "__RBRACKET",
  "__EQUAL", "__AT", "CLUST", "NAME", "NUMBER", "OPCODE", "XNOP",
  "QUOTE_STRING", "REGNAME", "USIGN", "INIT", "ARGS", "BLOCK", "BUNDLE",
  "EQU", "LABEL", "$accept", "asm_file", "asm_section", "data_section",
  ".data_dir_list", "data_dir_list", "data_dir", "$@1", "init_list",
  "init_dir", "data_val", "data_size", ".dup", "data_global_dir",
  "bss_section", ".bss_dir_list", "bss_dir_list", "bss_dir",
  "bss_label_decl", "common_dir", "text_section", ".text_inst_list",
  "text_inst_list", "text_inst", "proc_inst", "$@2", "proc", "code_list",
  "code_item", "trace_dir", "label_decl", "call_jmp_dir", "$@3", "$@4",
  "call_jmp_tgt", "entry_dir", "callc", "return_dir", "arg", "ret",
  "text_global_dir", "equ_dir", "scope", "type_dir", ".arg_list",
  "stackexp", "arg_list", "arg_desc", "arg_type", "regloclist", "regloc",
  "bundle", "end_bundle", ".mop_list", "mop_list", "mop", "normal_mop",
  "xnop_mop", "asm_mop", "$@5", ".mop_arglist", "mop_arglist", "mop_arg",
  "expr", "name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        55,     0,    -1,    56,    -1,    55,    56,    -1,    22,    57,
      -1,    22,    68,    -1,    22,    74,    -1,     7,    45,    -1,
      24,   118,    -1,    21,    42,    -1,     9,    58,    -1,    -1,
      59,    -1,    60,    -1,    59,    60,    -1,     3,    42,    -1,
      23,    42,    -1,    -1,   118,    96,    61,    62,    -1,    95,
      -1,    73,    -1,    67,    -1,    97,    -1,    63,    -1,    62,
      63,    -1,    65,    64,    66,    -1,    23,    42,    -1,     4,
      45,    -1,   117,    -1,    42,    31,    42,    -1,    10,    -1,
      11,    -1,    12,    -1,    18,    -1,    19,    -1,    -1,    32,
      42,    -1,    16,   118,    -1,     5,    69,    -1,    -1,    70,
      -1,    71,    -1,    70,    71,    -1,    72,    -1,    73,    -1,
      95,    -1,     3,    42,    -1,    23,    42,    -1,   118,    96,
      -1,     8,   118,    31,    42,    31,    42,    -1,    25,    75,
      -1,    -1,    76,    -1,    77,    -1,    76,    77,    -1,    78,
      -1,    95,    -1,    94,    -1,    97,    -1,    84,    -1,     3,
      42,    -1,    -1,    80,    89,    79,    81,    13,    -1,    80,
     118,    96,    13,    -1,    80,    13,    -1,    17,    -1,    82,
      -1,    81,    82,    -1,   105,    -1,    85,    -1,    95,    -1,
      84,    -1,    91,    -1,    83,    -1,    26,    42,    -1,    26,
      42,    31,    42,    -1,   118,    96,    -1,    -1,    -1,     6,
      88,    31,    90,    31,    86,    92,    34,    98,    35,    31,
      87,    93,    34,    98,    35,    -1,   118,    -1,    46,    -1,
      -1,    14,    90,    31,   103,    31,    92,    34,    98,    35,
     118,    96,    -1,   118,    96,    -1,    41,    -1,    20,    93,
      34,    98,    35,    -1,    41,    -1,    41,    -1,    16,   118,
      -1,    15,   118,    31,   117,    -1,    32,    -1,    32,    32,
      -1,    27,   118,    31,    39,    41,    -1,    -1,   100,    -1,
      99,   100,    -1,   117,    31,    42,    33,    -1,   101,    -1,
     100,    31,   101,    -1,   117,    32,   102,    -1,   117,    32,
     117,    32,   102,    -1,    32,   117,    32,   102,    -1,   118,
      -1,    36,    42,    37,    -1,   104,    -1,   103,    31,   104,
      -1,    41,    38,   117,    -1,   107,   106,    -1,    33,    33,
      -1,    -1,   108,    -1,   109,    -1,   108,   109,    -1,   110,
      -1,   111,    -1,   112,    -1,    40,    43,   114,    -1,    44,
      42,    -1,    -1,    40,    43,    31,    42,   113,   114,    -1,
      -1,   115,    38,   115,    -1,   115,    38,    -1,   115,    -1,
     116,    -1,   115,    31,   116,    -1,   117,    -1,    36,    46,
      37,    -1,   117,    36,    46,    37,    -1,    34,   117,    35,
      -1,   117,    28,   117,    -1,   117,    29,   117,    -1,    29,
     117,    -1,    28,   117,    -1,    30,   117,    -1,   118,    -1,
      46,    -1,    42,    -1,    41,    -1,    43,    -1,    40,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    14,    17,    20,    23,
      26,    29,    30,    32,    34,    37,    40,    43,    44,    49,
      51,    53,    55,    57,    59,    62,    66,    69,    72,    74,
      78,    80,    82,    84,    86,    88,    89,    92,    95,    98,
      99,   101,   103,   106,   108,   110,   112,   115,   118,   121,
     128,   131,   132,   134,   136,   139,   141,   143,   145,   147,
     149,   152,   153,   159,   164,   167,   169,   171,   174,   176,
     178,   180,   182,   184,   186,   189,   194,   197,   198,   199,
     216,   218,   220,   221,   233,   236,   238,   244,   246,   248,
     251,   256,   258,   261,   267,   268,   270,   273,   278,   280,
     284,   288,   294,   299,   301,   305,   307,   311,   315,   318,
     321,   322,   324,   326,   329,   331,   333,   335,   339,   342,
     343,   350,   351,   355,   358,   360,   362,   366,   368,   372,
     377,   381,   385,   389,   392,   395,   398,   400,   402,   404,
     406,   408
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   202,   202,   203,   206,   207,   208,   209,   210,   211,
     218,   222,   223,   226,   227,   231,   232,   233,   233,   235,
     236,   237,   238,   241,   242,   245,   246,   247,   250,   251,
     253,   254,   255,   256,   257,   260,   261,   265,   272,   275,
     276,   279,   280,   283,   284,   285,   286,   287,   290,   293,
     300,   303,   304,   307,   308,   311,   312,   313,   314,   315,
     316,   319,   319,   321,   322,   325,   328,   329,   332,   333,
     334,   335,   336,   337,   340,   341,   344,   347,   348,   347,
     352,   353,   354,   357,   360,   365,   368,   371,   374,   377,
     380,   383,   384,   387,   394,   395,   396,   399,   402,   403,
     406,   407,   408,   411,   412,   415,   416,   419,   426,   433,
     436,   437,   440,   441,   444,   445,   446,   449,   466,   476,
     476,   484,   485,   486,   487,   491,   492,   495,   496,   497,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   518,
     519,   520
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 300;
  const int Parser::yynnts_ = 65;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 19;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 54;

  const unsigned int Parser::yyuser_token_number_max_ = 308;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // VexParser

/* Line 1054 of lalr1.cc  */
#line 1852 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 527 "parser.yy"
 /*** Additional Code ***/

void VexParser::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

