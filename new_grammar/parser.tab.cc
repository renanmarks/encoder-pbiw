
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
#line 4 "parser.yy"
 /*** C/C++ Declarations ***/
  
//#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "vextypes.h"
#include "Expressions/Expression.h"

enum { LOCAL = 0, GLOBAL = 1 };
  


/* Line 311 of lalr1.cc  */
#line 58 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 168 "parser.yy"


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
#line 153 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 257 "parser.tab.cc"
	break;
      case 40: /* "CLUST" */

/* Line 480 of lalr1.cc  */
#line 147 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 266 "parser.tab.cc"
	break;
      case 41: /* "NAME" */

/* Line 480 of lalr1.cc  */
#line 148 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 275 "parser.tab.cc"
	break;
      case 43: /* "OPCODE" */

/* Line 480 of lalr1.cc  */
#line 150 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 284 "parser.tab.cc"
	break;
      case 44: /* "XNOP" */

/* Line 480 of lalr1.cc  */
#line 151 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 293 "parser.tab.cc"
	break;
      case 45: /* "QUOTE_STRING" */

/* Line 480 of lalr1.cc  */
#line 152 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 302 "parser.tab.cc"
	break;
      case 64: /* "data_val" */

/* Line 480 of lalr1.cc  */
#line 162 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 311 "parser.tab.cc"
	break;
      case 88: /* "call_jmp_tgt" */

/* Line 480 of lalr1.cc  */
#line 155 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 320 "parser.tab.cc"
	break;
      case 89: /* "entry_dir" */

/* Line 480 of lalr1.cc  */
#line 164 "parser.yy"
	{ delete (yyvaluep->function); };

/* Line 480 of lalr1.cc  */
#line 329 "parser.tab.cc"
	break;
      case 92: /* "arg" */

/* Line 480 of lalr1.cc  */
#line 157 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 338 "parser.tab.cc"
	break;
      case 93: /* "ret" */

/* Line 480 of lalr1.cc  */
#line 158 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 347 "parser.tab.cc"
	break;
      case 118: /* "expr" */

/* Line 480 of lalr1.cc  */
#line 163 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 356 "parser.tab.cc"
	break;
      case 119: /* "name" */

/* Line 480 of lalr1.cc  */
#line 156 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 365 "parser.tab.cc"
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
#line 45 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 553 of lalr1.cc  */
#line 451 "parser.tab.cc"

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
#line 218 "parser.yy"
    { }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 219 "parser.yy"
    { }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 220 "parser.yy"
    { }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 221 "parser.yy"
    { }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 222 "parser.yy"
    { }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 223 "parser.yy"
    { }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 224 "parser.yy"
    { }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 225 "parser.yy"
    { }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 232 "parser.yy"
    { }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 233 "parser.yy"
    { }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 234 "parser.yy"
    { }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 237 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 29:

/* Line 678 of lalr1.cc  */
#line 238 "parser.yy"
    { (yyval.expression) = new Expression((yysemantic_stack_[(3) - (1)].value)); }
    break;

  case 30:

/* Line 678 of lalr1.cc  */
#line 240 "parser.yy"
    { (yyval.value) = 1; }
    break;

  case 31:

/* Line 678 of lalr1.cc  */
#line 241 "parser.yy"
    { (yyval.value) = 2; }
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 242 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 243 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 244 "parser.yy"
    { (yyval.value) = 8; }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 247 "parser.yy"
    { (yyval.value) = 0;  }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 248 "parser.yy"
    { (yyval.value) = (yysemantic_stack_[(2) - (2)].value); }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 252 "parser.yy"
    { }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 273 "parser.yy"
    { }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 274 "parser.yy"
    { }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 277 "parser.yy"
    { }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 303 "parser.yy"
    { }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 306 "parser.yy"
    { }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 307 "parser.yy"
    { }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 308 "parser.yy"
    { }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 312 "parser.yy"
    { }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 331 "parser.yy"
    { }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 334 "parser.yy"
    { }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 335 "parser.yy"
    { }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 336 "parser.yy"
    { }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 339 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 340 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 341 "parser.yy"
    { (yyval.text) = new std::string(""); }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 344 "parser.yy"
    { 
                            (yyval.function)->str = (yysemantic_stack_[(11) - (10)].text);
                            (yyval.function)->scope = (yysemantic_stack_[(11) - (11)].value);
                        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 348 "parser.yy"
    {
                            (yyval.function)->str = (yysemantic_stack_[(2) - (1)].text);
                            (yyval.function)->scope = (yysemantic_stack_[(2) - (2)].value);
                        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 354 "parser.yy"
    { }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 357 "parser.yy"
    { }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 360 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 363 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 366 "parser.yy"
    { }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 369 "parser.yy"
    { }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 372 "parser.yy"
    { (yyval.value) = LOCAL; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 373 "parser.yy"
    { (yyval.value) = GLOBAL; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 388 "parser.yy"
    { }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 395 "parser.yy"
    { }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 396 "parser.yy"
    { }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 397 "parser.yy"
    { }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 400 "parser.yy"
    { }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 401 "parser.yy"
    { }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 408 "parser.yy"
    { }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 415 "parser.yy"
    { }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 421 "parser.yy"
    { }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 434 "parser.yy"
    { }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 435 "parser.yy"
    { }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 438 "parser.yy"
    { }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 441 "parser.yy"
    { }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 442 "parser.yy"
    { }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 460 "parser.yy"
    { }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 461 "parser.yy"
    { }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 462 "parser.yy"
    { }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 469 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].expression); }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 470 "parser.yy"
    { (yyval.expression) = new Expression('+', *(yysemantic_stack_[(3) - (1)].expression), *(yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 471 "parser.yy"
    { (yyval.expression) = new Expression('-', *(yysemantic_stack_[(3) - (1)].expression), *(yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 472 "parser.yy"
    { (yyval.expression) = new Expression('-', *(yysemantic_stack_[(2) - (2)].expression)); }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 473 "parser.yy"
    { (yyval.expression) = new Expression('+', *(yysemantic_stack_[(2) - (2)].expression)); }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 474 "parser.yy"
    { (yyval.expression) = new Expression('~', *(yysemantic_stack_[(2) - (2)].expression)); }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 475 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(1) - (1)].text)); }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 476 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(1) - (1)].text)); }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 477 "parser.yy"
    { (yyval.expression) = new Expression((yysemantic_stack_[(1) - (1)].value)); }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 483 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 484 "parser.yy"
    { (yyval.text) = new std::string((yysemantic_stack_[(1) - (1)].opcode)->as_op); }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 485 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;



/* Line 678 of lalr1.cc  */
#line 1101 "parser.tab.cc"
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
  const short int Parser::yypact_ninf_ = -193;
  const short int
  Parser::yypact_[] =
  {
        65,   -24,   -19,    11,    14,   145,  -193,  -193,  -193,    56,
      35,    50,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,   -14,    14,    14,    -3,  -193,    56,  -193,  -193,  -193,
    -193,    13,    10,    14,    21,    14,  -193,    35,  -193,  -193,
    -193,  -193,  -193,    13,    43,    14,  -193,  -193,    50,  -193,
    -193,    60,  -193,  -193,  -193,  -193,    13,  -193,    51,    76,
    -193,  -193,    78,  -193,  -193,  -193,  -193,    93,  -193,  -193,
    -193,  -193,  -193,  -193,    75,  -193,    13,  -193,    87,   205,
    -193,    96,   152,  -193,   109,   117,   131,   115,   205,   205,
     205,   205,  -193,  -193,   -16,  -193,   108,   110,  -193,  -193,
    -193,  -193,  -193,   111,   152,  -193,   224,   113,   159,   118,
     123,   125,   135,   107,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,   148,    40,  -193,  -193,  -193,  -193,  -193,   146,  -193,
    -193,  -193,    77,   205,   205,  -193,  -193,  -193,  -193,   160,
     161,   -16,   154,   163,  -193,  -193,   173,  -193,  -193,   177,
     181,   188,  -193,  -193,  -193,   184,  -193,   125,  -193,  -193,
    -193,  -193,  -193,   179,   182,  -193,   205,   189,    75,   144,
     194,   195,   167,  -193,  -193,  -193,   -16,   154,   197,  -193,
     192,   205,   203,   144,   209,  -193,   151,  -193,  -193,   196,
    -193,   -21,  -193,    32,   144,  -193,    66,  -193,   209,    86,
     144,   199,   186,   167,   206,   167,   167,   198,   214,   215,
      85,  -193,   217,   213,  -193,   102,    57,  -193,  -193,  -193,
     226,   222,    14,  -193,   227,  -193,  -193,  -193,   223,    85,
    -193,    13,   144,  -193,  -193,  -193,   228,   231,  -193,   118,
     234,   144,   236,  -193
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     2,     7,     9,    39,
      11,    51,     4,     5,     6,   142,   140,   141,     8,     1,
       3,     0,     0,     0,     0,    38,    40,    41,    43,    44,
      45,     0,     0,     0,     0,     0,    10,    12,    13,    21,
      20,    19,    22,     0,     0,     0,    65,    50,    52,    53,
      55,     0,    59,    57,    56,    58,     0,    46,     0,     0,
      47,    42,    91,    48,    15,    37,    16,     0,    14,    17,
      60,    89,    54,    64,     0,    61,     0,    76,     0,     0,
      92,     0,     0,    85,     0,   110,    84,     0,     0,     0,
       0,     0,   139,   138,    90,   137,     0,     0,    30,    31,
      32,    33,    34,     0,    18,    23,     0,     0,    82,     0,
       0,   142,     0,   110,    66,    73,    71,    69,    72,    70,
      68,     0,   111,   112,   114,   115,   116,    63,     0,   135,
     134,   136,     0,     0,     0,    93,    27,    26,    24,   139,
      35,    28,     0,     0,   105,    81,     0,    80,    88,     0,
      74,   117,   119,    62,    67,     0,   108,     0,   113,    49,
     131,   132,   133,     0,     0,    25,     0,     0,     0,    94,
       0,     0,   122,   109,    29,    36,   107,    87,     0,   106,
       0,     0,     0,     0,    95,    98,     0,    75,   120,     0,
     118,   125,   126,   128,    94,    77,     0,    86,    96,     0,
       0,     0,     0,   122,     0,     0,   124,     0,     0,     0,
       0,    99,     0,     0,   100,     0,   137,   121,   129,   127,
     123,     0,     0,    87,     0,   102,   103,    97,     0,     0,
     130,     0,    94,   104,   101,    83,     0,     0,    78,     0,
       0,    94,     0,    79
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -193,  -193,   264,  -193,  -193,  -193,   235,  -193,  -193,   169,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,   248,  -193,    -7,
    -193,  -193,  -193,   229,  -193,  -193,  -193,  -193,   162,  -193,
     -81,  -193,  -193,  -193,  -193,  -193,   112,  -193,    67,    39,
    -193,    -2,   -42,     0,  -192,  -193,    98,    79,  -173,  -193,
     116,  -193,  -193,  -193,  -193,   164,  -193,  -193,  -193,  -193,
    -193,    81,    82,    80,   -64,    -4
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     5,     6,    12,    36,    37,    38,    82,   104,   105,
     140,   106,   165,    39,    13,    25,    26,    27,    28,    29,
      14,    47,    48,    49,    50,    85,    51,   113,   114,   115,
      52,   117,   209,   239,   146,    75,    84,   118,   178,   149,
      53,    30,    63,    42,   182,   183,   184,   185,   214,   143,
     144,   120,   156,   121,   122,   123,   124,   172,   125,   126,
     203,   190,   191,   192,   186,    95
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -104;
  const short int
  Parser::yytable_[] =
  {
        18,    69,   208,    40,   116,    31,    43,    56,    41,    54,
     205,    55,   133,   134,    77,    94,     9,   206,    58,    59,
      10,     7,    31,     8,   129,   130,   131,   132,    57,    65,
      40,    67,   116,    43,    86,    41,    11,   225,    32,    60,
     236,    71,   141,    22,    56,    62,    54,    76,    55,   242,
      23,    33,    64,    44,    15,    16,   234,    17,    34,    21,
     133,   134,    35,    66,    22,    23,    45,    46,   207,   161,
     162,    23,     1,    73,    74,    15,    16,    35,    17,    24,
     157,    56,    78,   119,   112,    70,     2,     3,  -103,     4,
      15,    16,  -103,    17,   133,   134,    15,    16,   210,    17,
      15,    16,   176,    17,   147,   133,   134,    79,   193,    56,
      80,   119,   160,   108,   133,   134,    83,   196,   202,   199,
     153,   213,    23,   108,    81,    15,    16,   109,    17,    87,
     133,   134,    23,   110,   229,    96,   199,   109,   215,   193,
     107,   193,   193,   110,   127,    19,   128,   111,    16,   135,
      17,   112,     1,   137,   142,   136,    97,   111,    16,   148,
      17,   112,    98,    99,   100,   150,     2,     3,   151,     4,
     101,   102,    88,    89,    90,   103,   181,   152,    91,   133,
     134,   155,   201,   202,    15,    16,    92,    17,   159,   235,
      93,   163,   166,   164,   167,    88,    89,    90,   216,    15,
      16,    91,    17,   189,   168,   145,   226,    15,    16,    92,
      17,   169,   170,    93,    88,    89,    90,   173,   231,   171,
      91,   174,   213,   195,   175,   226,    15,    16,    92,    17,
     177,   194,    93,    88,    89,    90,   187,   188,   197,    91,
     200,   212,   204,   218,   221,    15,    16,    92,    17,   222,
     227,    93,    88,    89,    90,   228,   223,   205,    91,   230,
     233,   232,   238,   237,    15,    16,   139,    17,   241,    20,
      93,   243,    68,   138,    61,   154,   224,    72,   240,   211,
     180,   198,     0,   179,   217,   219,   158,     0,   220
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         4,    43,   194,    10,    85,     9,    10,    11,    10,    11,
      31,    11,    28,    29,    56,    79,     5,    38,    22,    23,
       9,    45,    26,    42,    88,    89,    90,    91,    42,    33,
      37,    35,   113,    37,    76,    37,    25,   210,     3,    42,
     232,    45,   106,     8,    48,    32,    48,    51,    48,   241,
      15,    16,    42,     3,    40,    41,   229,    43,    23,     3,
      28,    29,    27,    42,     8,    15,    16,    17,    36,   133,
     134,    15,     7,    13,    14,    40,    41,    27,    43,    23,
      40,    85,    31,    85,    44,    42,    21,    22,    31,    24,
      40,    41,    35,    43,    28,    29,    40,    41,    32,    43,
      40,    41,   166,    43,   108,    28,    29,    31,   172,   113,
      32,   113,    35,     6,    28,    29,    41,   181,    32,   183,
      13,    36,    15,     6,    31,    40,    41,    20,    43,    42,
      28,    29,    15,    26,    32,    39,   200,    20,   202,   203,
      31,   205,   206,    26,    13,     0,    31,    40,    41,    41,
      43,    44,     7,    42,    41,    45,     4,    40,    41,    41,
      43,    44,    10,    11,    12,    42,    21,    22,    43,    24,
      18,    19,    28,    29,    30,    23,    32,    42,    34,    28,
      29,    33,    31,    32,    40,    41,    42,    43,    42,   231,
      46,    31,    38,    32,    31,    28,    29,    30,   202,    40,
      41,    34,    43,    36,    31,    46,   210,    40,    41,    42,
      43,    34,    31,    46,    28,    29,    30,    33,   222,    31,
      34,    42,    36,    31,    42,   229,    40,    41,    42,    43,
      41,    34,    46,    28,    29,    30,    42,    42,    35,    34,
      31,    42,    46,    37,    46,    40,    41,    42,    43,    35,
      33,    46,    28,    29,    30,    42,    41,    31,    34,    37,
      37,    34,    31,    35,    40,    41,    42,    43,    34,     5,
      46,    35,    37,   104,    26,   113,   209,    48,   239,   200,
     168,   183,    -1,   167,   203,   205,   122,    -1,   206
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     7,    21,    22,    24,    55,    56,    45,    42,     5,
       9,    25,    57,    68,    74,    40,    41,    43,   119,     0,
      56,     3,     8,    15,    23,    69,    70,    71,    72,    73,
      95,   119,     3,    16,    23,    27,    58,    59,    60,    67,
      73,    95,    97,   119,     3,    16,    17,    75,    76,    77,
      78,    80,    84,    94,    95,    97,   119,    42,   119,   119,
      42,    71,    32,    96,    42,   119,    42,   119,    60,    96,
      42,   119,    77,    13,    14,    89,   119,    96,    31,    31,
      32,    31,    61,    41,    90,    79,    96,    42,    28,    29,
      30,    34,    42,    46,   118,   119,    39,     4,    10,    11,
      12,    18,    19,    23,    62,    63,    65,    31,     6,    20,
      26,    40,    44,    81,    82,    83,    84,    85,    91,    95,
     105,   107,   108,   109,   110,   112,   113,    13,    31,   118,
     118,   118,   118,    28,    29,    41,    45,    42,    63,    42,
      64,   118,    41,   103,   104,    46,    88,   119,    41,    93,
      42,    43,    42,    13,    82,    33,   106,    40,   109,    42,
      35,   118,   118,    31,    32,    66,    38,    31,    31,    34,
      31,    31,   111,    33,    42,    42,   118,    41,    92,   104,
      90,    32,    98,    99,   100,   101,   118,    42,    42,    36,
     115,   116,   117,   118,    34,    31,   118,    35,   100,   118,
      31,    31,    32,   114,    46,    31,    38,    36,    98,    86,
      32,   101,    42,    36,   102,   118,   119,   115,    37,   117,
     116,    46,    35,    41,    92,   102,   119,    33,    42,    32,
      37,   119,    34,    37,   102,    96,    98,    35,    31,    87,
      93,    34,    98,    35
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
     107,   107,   108,   108,   109,   109,   109,   111,   110,   112,
     114,   113,   115,   115,   115,   115,   116,   116,   117,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   119
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
       0,     1,     1,     2,     1,     1,     1,     0,     4,     2,
       0,     6,     0,     3,     2,     1,     1,     3,     1,     3,
       4,     3,     3,     3,     2,     2,     2,     1,     1,     1,
       1,     1,     1
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
  "$@5", "xnop_mop", "asm_mop", "$@6", ".mop_arglist", "mop_arglist",
  "mop_arg", "expr", "name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        55,     0,    -1,    56,    -1,    55,    56,    -1,    22,    57,
      -1,    22,    68,    -1,    22,    74,    -1,     7,    45,    -1,
      24,   119,    -1,    21,    42,    -1,     9,    58,    -1,    -1,
      59,    -1,    60,    -1,    59,    60,    -1,     3,    42,    -1,
      23,    42,    -1,    -1,   119,    96,    61,    62,    -1,    95,
      -1,    73,    -1,    67,    -1,    97,    -1,    63,    -1,    62,
      63,    -1,    65,    64,    66,    -1,    23,    42,    -1,     4,
      45,    -1,   118,    -1,    42,    31,    42,    -1,    10,    -1,
      11,    -1,    12,    -1,    18,    -1,    19,    -1,    -1,    32,
      42,    -1,    16,   119,    -1,     5,    69,    -1,    -1,    70,
      -1,    71,    -1,    70,    71,    -1,    72,    -1,    73,    -1,
      95,    -1,     3,    42,    -1,    23,    42,    -1,   119,    96,
      -1,     8,   119,    31,    42,    31,    42,    -1,    25,    75,
      -1,    -1,    76,    -1,    77,    -1,    76,    77,    -1,    78,
      -1,    95,    -1,    94,    -1,    97,    -1,    84,    -1,     3,
      42,    -1,    -1,    80,    89,    79,    81,    13,    -1,    80,
     119,    96,    13,    -1,    80,    13,    -1,    17,    -1,    82,
      -1,    81,    82,    -1,   105,    -1,    85,    -1,    95,    -1,
      84,    -1,    91,    -1,    83,    -1,    26,    42,    -1,    26,
      42,    31,    42,    -1,   119,    96,    -1,    -1,    -1,     6,
      88,    31,    90,    31,    86,    92,    34,    98,    35,    31,
      87,    93,    34,    98,    35,    -1,   119,    -1,    46,    -1,
      -1,    14,    90,    31,   103,    31,    92,    34,    98,    35,
     119,    96,    -1,   119,    96,    -1,    41,    -1,    20,    93,
      34,    98,    35,    -1,    41,    -1,    41,    -1,    16,   119,
      -1,    15,   119,    31,   118,    -1,    32,    -1,    32,    32,
      -1,    27,   119,    31,    39,    41,    -1,    -1,   100,    -1,
      99,   100,    -1,   118,    31,    42,    33,    -1,   101,    -1,
     100,    31,   101,    -1,   118,    32,   102,    -1,   118,    32,
     118,    32,   102,    -1,    32,   118,    32,   102,    -1,   119,
      -1,    36,    42,    37,    -1,   104,    -1,   103,    31,   104,
      -1,    41,    38,   118,    -1,   107,   106,    -1,    33,    33,
      -1,    -1,   108,    -1,   109,    -1,   108,   109,    -1,   110,
      -1,   112,    -1,   113,    -1,    -1,    40,    43,   111,   115,
      -1,    44,    42,    -1,    -1,    40,    43,    31,    42,   114,
     115,    -1,    -1,   116,    38,   116,    -1,   116,    38,    -1,
     116,    -1,   117,    -1,   116,    31,   117,    -1,   118,    -1,
      36,    46,    37,    -1,   118,    36,    46,    37,    -1,    34,
     118,    35,    -1,   118,    28,   118,    -1,   118,    29,   118,
      -1,    29,   118,    -1,    28,   118,    -1,    30,   118,    -1,
     119,    -1,    46,    -1,    42,    -1,    41,    -1,    43,    -1,
      40,    -1
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
     321,   322,   324,   326,   329,   331,   333,   335,   336,   341,
     344,   345,   352,   353,   357,   360,   362,   364,   368,   370,
     374,   379,   383,   387,   391,   394,   397,   400,   402,   404,
     406,   408,   410
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   189,   189,   190,   193,   194,   195,   196,   197,   198,
     205,   209,   210,   213,   214,   218,   219,   220,   220,   222,
     223,   224,   225,   228,   229,   232,   233,   234,   237,   238,
     240,   241,   242,   243,   244,   247,   248,   252,   259,   262,
     263,   266,   267,   270,   271,   272,   273,   274,   277,   280,
     287,   290,   291,   294,   295,   298,   299,   300,   301,   302,
     303,   306,   306,   308,   309,   312,   315,   316,   319,   320,
     321,   322,   323,   324,   327,   328,   331,   334,   335,   334,
     339,   340,   341,   344,   348,   354,   357,   360,   363,   366,
     369,   372,   373,   376,   383,   384,   385,   388,   391,   392,
     395,   396,   397,   400,   401,   404,   405,   408,   415,   418,
     421,   422,   425,   426,   429,   430,   431,   434,   434,   438,
     441,   441,   449,   450,   451,   452,   456,   457,   460,   461,
     462,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     483,   484,   485
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
  const int Parser::yylast_ = 288;
  const int Parser::yynnts_ = 66;
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
#line 1774 "parser.tab.cc"


/* Line 1056 of lalr1.cc  */
#line 492 "parser.yy"
 /*** Additional Code ***/

void VexParser::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

