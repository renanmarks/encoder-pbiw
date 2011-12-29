/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
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

/* Line 293 of lalr1.cc  */
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
  


/* Line 293 of lalr1.cc  */
#line 56 "parser.tab.cc"


#include "parser.tab.hh"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 181 "parser.yy"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 79 "parser.tab.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
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


namespace VexParser {

/* Line 382 of lalr1.cc  */
#line 165 "parser.tab.cc"

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
#line 270 "parser.tab.cc"
	break;
      case 40: /* "CLUST" */

/* Line 480 of lalr1.cc  */
#line 160 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 279 "parser.tab.cc"
	break;
      case 41: /* "NAME" */

/* Line 480 of lalr1.cc  */
#line 161 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 288 "parser.tab.cc"
	break;
      case 43: /* "OPCODE" */

/* Line 480 of lalr1.cc  */
#line 162 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 297 "parser.tab.cc"
	break;
      case 44: /* "XNOP" */

/* Line 480 of lalr1.cc  */
#line 163 "parser.yy"
	{ delete (yyvaluep->opcode); };

/* Line 480 of lalr1.cc  */
#line 306 "parser.tab.cc"
	break;
      case 45: /* "QUOTE_STRING" */

/* Line 480 of lalr1.cc  */
#line 164 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 315 "parser.tab.cc"
	break;
      case 64: /* "data_val" */

/* Line 480 of lalr1.cc  */
#line 171 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 324 "parser.tab.cc"
	break;
      case 85: /* "call_jmp_tgt" */

/* Line 480 of lalr1.cc  */
#line 167 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 333 "parser.tab.cc"
	break;
      case 86: /* "entry_dir" */

/* Line 480 of lalr1.cc  */
#line 173 "parser.yy"
	{ delete (yyvaluep->function); };

/* Line 480 of lalr1.cc  */
#line 342 "parser.tab.cc"
	break;
      case 89: /* "arg" */

/* Line 480 of lalr1.cc  */
#line 169 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 351 "parser.tab.cc"
	break;
      case 90: /* "ret" */

/* Line 480 of lalr1.cc  */
#line 170 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 360 "parser.tab.cc"
	break;
      case 110: /* ".mop_arglist" */

/* Line 480 of lalr1.cc  */
#line 177 "parser.yy"
	{ delete (yyvaluep->syllableArguments); };

/* Line 480 of lalr1.cc  */
#line 369 "parser.tab.cc"
	break;
      case 111: /* "mop_arglist" */

/* Line 480 of lalr1.cc  */
#line 176 "parser.yy"
	{ delete (yyvaluep->arguments); };

/* Line 480 of lalr1.cc  */
#line 378 "parser.tab.cc"
	break;
      case 112: /* "mop_arg" */

/* Line 480 of lalr1.cc  */
#line 175 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 387 "parser.tab.cc"
	break;
      case 113: /* "expr" */

/* Line 480 of lalr1.cc  */
#line 172 "parser.yy"
	{ delete (yyvaluep->expression); };

/* Line 480 of lalr1.cc  */
#line 396 "parser.tab.cc"
	break;
      case 114: /* "name" */

/* Line 480 of lalr1.cc  */
#line 168 "parser.yy"
	{ delete (yyvaluep->text); };

/* Line 480 of lalr1.cc  */
#line 405 "parser.tab.cc"
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

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

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
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 565 of lalr1.cc  */
#line 52 "parser.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}

/* Line 565 of lalr1.cc  */
#line 503 "parser.tab.cc"

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
    if (yy_pact_value_is_default_ (yyn))
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
	if (yy_table_value_is_error_ (yyn))
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
	  case 7:

/* Line 690 of lalr1.cc  */
#line 209 "parser.yy"
    { delete (yysemantic_stack_[(2) - (2)].text); }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 210 "parser.yy"
    { delete (yysemantic_stack_[(2) - (2)].text); }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 231 "parser.yy"
    { }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 232 "parser.yy"
    { }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 233 "parser.yy"
    { delete (yysemantic_stack_[(2) - (1)].text); }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 234 "parser.yy"
    { }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 235 "parser.yy"
    { }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 236 "parser.yy"
    { }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 237 "parser.yy"
    { }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 238 "parser.yy"
    { }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 245 "parser.yy"
    { delete (yysemantic_stack_[(3) - (2)].expression); }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 246 "parser.yy"
    { }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 247 "parser.yy"
    { delete (yysemantic_stack_[(2) - (2)].text); }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 250 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 251 "parser.yy"
    { (yyval.expression) = new Expression((yysemantic_stack_[(3) - (1)].value)); }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 253 "parser.yy"
    { (yyval.value) = 1; }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 254 "parser.yy"
    { (yyval.value) = 2; }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 255 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 256 "parser.yy"
    { (yyval.value) = 4; }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 257 "parser.yy"
    { (yyval.value) = 8; }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 260 "parser.yy"
    { (yyval.value) = 0;  }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 261 "parser.yy"
    { (yyval.value) = (yysemantic_stack_[(2) - (2)].value); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 265 "parser.yy"
    { delete (yysemantic_stack_[(2) - (2)].text); }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 286 "parser.yy"
    { }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 287 "parser.yy"
    { }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 290 "parser.yy"
    { delete (yysemantic_stack_[(2) - (1)].text); }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 293 "parser.yy"
    { delete (yysemantic_stack_[(6) - (2)].text); }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 316 "parser.yy"
    { }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 320 "parser.yy"
    { }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 321 "parser.yy"
    { delete (yysemantic_stack_[(4) - (2)].text); }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 325 "parser.yy"
    { }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 344 "parser.yy"
    { driver.context.setLabel(*(yysemantic_stack_[(2) - (1)].text), (yysemantic_stack_[(2) - (2)].scope)); delete (yysemantic_stack_[(2) - (1)].text); }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 349 "parser.yy"
    { 
                            //delete $1; 
                            delete (yysemantic_stack_[(14) - (2)].text); 
                            delete (yysemantic_stack_[(14) - (6)].text); 
                            delete (yysemantic_stack_[(14) - (11)].text); 
                        }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 357 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 358 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 359 "parser.yy"
    { (yyval.text) = new std::string(""); }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 362 "parser.yy"
    { 
                            driver.context.setLabel(*(yysemantic_stack_[(11) - (10)].text), (yysemantic_stack_[(11) - (11)].scope));
                            delete (yysemantic_stack_[(11) - (6)].text);
                            delete (yysemantic_stack_[(11) - (10)].text);
                        }
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 367 "parser.yy"
    {
                            driver.context.setLabel(*(yysemantic_stack_[(2) - (1)].text), (yysemantic_stack_[(2) - (2)].scope));
                            delete (yysemantic_stack_[(2) - (1)].text);
                        }
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 373 "parser.yy"
    { delete (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 376 "parser.yy"
    { delete (yysemantic_stack_[(5) - (2)].text); }
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 379 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 382 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 385 "parser.yy"
    { delete (yysemantic_stack_[(2) - (2)].text); }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 388 "parser.yy"
    { delete (yysemantic_stack_[(4) - (2)].text); delete (yysemantic_stack_[(4) - (4)].expression); }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 391 "parser.yy"
    { (yyval.scope) = rVex::Label::LOCAL; }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 392 "parser.yy"
    { (yyval.scope) = rVex::Label::GLOBAL; }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 395 "parser.yy"
    { delete (yysemantic_stack_[(5) - (2)].text); delete (yysemantic_stack_[(5) - (5)].text); }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 407 "parser.yy"
    { delete (yysemantic_stack_[(4) - (1)].expression); }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 414 "parser.yy"
    { delete (yysemantic_stack_[(3) - (1)].expression); }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 415 "parser.yy"
    { delete (yysemantic_stack_[(5) - (1)].expression); delete (yysemantic_stack_[(5) - (3)].expression); }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 416 "parser.yy"
    { delete (yysemantic_stack_[(4) - (2)].expression); }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 419 "parser.yy"
    { delete (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 420 "parser.yy"
    { }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 427 "parser.yy"
    { delete (yysemantic_stack_[(3) - (1)].text); delete (yysemantic_stack_[(3) - (3)].expression); }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 435 "parser.yy"
    { 
                          driver.context.endInstruction();
                          
                          if (driver.context.isDebuggingEnabled())
                            std::cout << ";;" << std::endl; 
                        }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 460 "parser.yy"
    { 
                          driver.context.packSyllable( (yysemantic_stack_[(3) - (2)].opcode)->syllableConstructor->create(), (yysemantic_stack_[(3) - (3)].syllableArguments) ); 
                          
                          if (driver.context.isDebuggingEnabled())
                          {
                            std::cout << " " << (yysemantic_stack_[(3) - (2)].opcode)->as_op << " ";
                            if ( (yysemantic_stack_[(3) - (3)].syllableArguments)->getDestinyArguments() )
                            {
                              (yysemantic_stack_[(3) - (3)].syllableArguments)->getDestinyArguments()->print(std::cout);
                              std::cout << " = ";
                            }
                            (yysemantic_stack_[(3) - (3)].syllableArguments)->getSourceArguments()->print(std::cout);
                            std::cout << std::endl;
                          }
                          
                          delete (yysemantic_stack_[(3) - (1)].text);
                          //delete $2;
                          delete (yysemantic_stack_[(3) - (3)].syllableArguments);
                        }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 482 "parser.yy"
    { 
                          Expression* ex = new Expression((yysemantic_stack_[(2) - (2)].value));
                          SyllableArguments* argument = new SyllableArguments(new Arguments(ex));
                          driver.context.packSyllable( (yysemantic_stack_[(2) - (1)].opcode)->syllableConstructor->create(), argument ); 
                          
                          if (driver.context.isDebuggingEnabled())
                            std::cout << " " << (yysemantic_stack_[(2) - (1)].opcode)->as_op << " " << (yysemantic_stack_[(2) - (2)].value) << std::endl;
                          
                          delete (yysemantic_stack_[(2) - (1)].opcode);
                          delete argument;
                        }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 496 "parser.yy"
    { delete (yysemantic_stack_[(5) - (1)].text); delete (yysemantic_stack_[(5) - (2)].opcode); delete (yysemantic_stack_[(5) - (5)].syllableArguments); }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 503 "parser.yy"
    { }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 504 "parser.yy"
    { (yyval.syllableArguments) = new SyllableArguments((yysemantic_stack_[(3) - (1)].arguments), (yysemantic_stack_[(3) - (3)].arguments)); }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 505 "parser.yy"
    { (yyval.syllableArguments) = new SyllableArguments((yysemantic_stack_[(2) - (1)].arguments)); }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 506 "parser.yy"
    { (yyval.syllableArguments) = new SyllableArguments((yysemantic_stack_[(1) - (1)].arguments)); }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 510 "parser.yy"
    { (yyval.arguments) = new Arguments((yysemantic_stack_[(1) - (1)].expression)); }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 511 "parser.yy"
    { (yyval.arguments) = new Arguments(*(yysemantic_stack_[(3) - (1)].arguments), (yysemantic_stack_[(3) - (3)].expression)); delete (yysemantic_stack_[(3) - (1)].arguments);}
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 514 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(1) - (1)].expression); }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 515 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(3) - (2)].text)); delete (yysemantic_stack_[(3) - (2)].text);}
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 516 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(4) - (1)].expression), *(yysemantic_stack_[(4) - (3)].text)); delete (yysemantic_stack_[(4) - (1)].expression); delete (yysemantic_stack_[(4) - (3)].text);}
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 523 "parser.yy"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].expression); }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 524 "parser.yy"
    { (yyval.expression) = new Expression('+', *(yysemantic_stack_[(3) - (1)].expression), *(yysemantic_stack_[(3) - (3)].expression)); delete (yysemantic_stack_[(3) - (1)].expression); delete (yysemantic_stack_[(3) - (3)].expression); }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 525 "parser.yy"
    { (yyval.expression) = new Expression('-', *(yysemantic_stack_[(3) - (1)].expression), *(yysemantic_stack_[(3) - (3)].expression)); delete (yysemantic_stack_[(3) - (1)].expression); delete (yysemantic_stack_[(3) - (3)].expression);}
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 526 "parser.yy"
    { (yyval.expression) = new Expression('-', *(yysemantic_stack_[(2) - (2)].expression)); delete (yysemantic_stack_[(2) - (2)].expression);}
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 527 "parser.yy"
    { (yyval.expression) = new Expression('+', *(yysemantic_stack_[(2) - (2)].expression)); delete (yysemantic_stack_[(2) - (2)].expression);}
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 528 "parser.yy"
    { (yyval.expression) = new Expression('~', *(yysemantic_stack_[(2) - (2)].expression)); delete (yysemantic_stack_[(2) - (2)].expression);}
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 529 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(1) - (1)].text)); delete (yysemantic_stack_[(1) - (1)].text);}
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 530 "parser.yy"
    { (yyval.expression) = new Expression(*(yysemantic_stack_[(1) - (1)].text)); delete (yysemantic_stack_[(1) - (1)].text);}
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 531 "parser.yy"
    { (yyval.expression) = new Expression((yysemantic_stack_[(1) - (1)].value)); }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 537 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 538 "parser.yy"
    { (yyval.text) = new std::string((yysemantic_stack_[(1) - (1)].opcode)->as_op); delete (yysemantic_stack_[(1) - (1)].opcode);}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 539 "parser.yy"
    { (yyval.text) = (yysemantic_stack_[(1) - (1)].text); }
    break;



/* Line 690 of lalr1.cc  */
#line 1220 "parser.tab.cc"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
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
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
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

    yyerror_range[1] = yylocation_stack_[yylen - 1];
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
	if (!yy_pact_value_is_default_ (yyn))
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

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

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
  Parser::yysyntax_error_ (int yystate, int yytoken)
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yychar.
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            /* Stay within bounds of both yycheck and yytname.  */
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = 0;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int Parser::yypact_ninf_ = -204;
  const short int
  Parser::yypact_[] =
  {
       103,   -35,   -22,    21,    80,    94,  -204,  -204,  -204,    88,
      57,    42,  -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,
    -204,   -21,    80,    80,    13,  -204,    88,  -204,  -204,  -204,
    -204,    29,    22,    80,    32,    80,  -204,    57,  -204,  -204,
    -204,  -204,  -204,    29,    45,    80,  -204,  -204,    42,  -204,
    -204,    11,  -204,  -204,  -204,  -204,    29,  -204,    64,    71,
    -204,  -204,    73,  -204,  -204,  -204,  -204,    81,  -204,  -204,
    -204,  -204,  -204,  -204,    76,   120,    29,  -204,    72,   215,
    -204,    83,   158,  -204,   108,   154,   104,   106,   114,   124,
      93,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   134,   -12,
    -204,  -204,  -204,  -204,   160,   152,   215,   215,   215,   215,
    -204,  -204,    50,  -204,   144,   141,  -204,  -204,  -204,  -204,
    -204,   145,   158,  -204,   234,   147,  -204,   167,  -204,  -204,
     170,   174,   113,  -204,  -204,  -204,   177,  -204,   114,  -204,
    -204,   164,  -204,  -204,  -204,   123,   215,   215,  -204,  -204,
    -204,  -204,   180,   188,    50,   191,   181,  -204,    76,   150,
     192,   193,   187,  -204,   -27,  -204,    20,  -204,  -204,  -204,
    -204,  -204,   198,   204,  -204,   215,   200,   216,   215,   213,
     150,   219,  -204,   143,  -204,   173,   214,   173,   173,   206,
    -204,  -204,    50,   191,   220,  -204,   212,    61,  -204,   219,
     189,   150,   217,   196,  -204,  -204,  -204,   229,   228,   150,
    -204,   232,    27,  -204,   236,   225,  -204,   199,    31,  -204,
     235,   150,  -204,  -204,  -204,   241,    27,    80,   237,  -204,
    -204,    29,   240,  -204,   104,   239,   150,   244,  -204
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     0,     0,     2,     7,     9,    39,
      11,    51,     4,     5,     6,   137,   135,   136,     8,     1,
       3,     0,     0,     0,     0,    38,    40,    41,    43,    44,
      45,     0,     0,     0,     0,     0,    10,    12,    13,    21,
      20,    19,    22,     0,     0,     0,    64,    50,    52,    53,
      55,     0,    59,    57,    56,    58,     0,    46,     0,     0,
      47,    42,    88,    48,    15,    37,    16,     0,    14,    17,
      60,    86,    54,    63,     0,   107,     0,    75,     0,     0,
      89,     0,     0,    82,     0,    79,     0,     0,   137,     0,
     107,    65,    72,    70,    68,    71,    69,    67,     0,   108,
     109,   111,   112,   113,    81,     0,     0,     0,     0,     0,
     134,   133,    87,   132,     0,     0,    30,    31,    32,    33,
      34,     0,    18,    23,     0,     0,    78,     0,    77,    85,
       0,    73,   117,   115,    61,    66,     0,   105,     0,   110,
      62,     0,   130,   129,   131,     0,     0,     0,    90,    27,
      26,    24,   134,    35,    28,     0,     0,   102,     0,    91,
       0,     0,     0,   114,   120,   121,   123,   106,    49,   126,
     127,   128,     0,     0,    25,     0,     0,     0,     0,     0,
       0,    92,    95,     0,    74,   117,     0,     0,   119,     0,
      29,    36,   104,    84,     0,   103,     0,     0,    83,    93,
       0,     0,     0,     0,   116,   124,   122,   118,     0,    91,
      84,     0,     0,    96,     0,     0,    97,     0,   132,   125,
       0,    91,    99,   100,    94,     0,     0,     0,     0,   101,
      98,     0,     0,    80,     0,     0,    91,     0,    76
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -204,  -204,   276,  -204,  -204,  -204,   245,  -204,  -204,   161,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,   258,  -204,     6,
    -204,  -204,  -204,   238,  -204,  -204,  -204,   195,  -204,   -73,
    -204,  -204,  -204,   129,  -204,    92,    55,  -204,     2,   -42,
      -8,  -194,  -204,   110,    90,  -203,  -204,   116,  -204,  -204,
    -204,  -204,   194,  -204,  -204,  -204,   109,   107,   111,   -71,
      -4
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     5,     6,    12,    36,    37,    38,    82,   122,   123,
     153,   124,   174,    39,    13,    25,    26,    27,    28,    29,
      14,    47,    48,    49,    50,    51,    90,    91,    92,    52,
      94,   127,    75,    84,    95,   194,   130,    53,    30,    63,
      42,   179,   180,   181,   182,   216,   156,   157,    97,   137,
      98,    99,   100,   101,   102,   103,   163,   164,   165,   166,
     113
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char Parser::yytable_ninf_ = -101;
  const short int
  Parser::yytable_[] =
  {
        18,    69,    93,    55,   187,    31,    43,    56,   112,   222,
       7,   188,    41,    54,    77,   220,    40,    93,    58,    59,
       8,    57,    31,   230,    73,    74,     9,   228,   138,    65,
      10,    67,    89,    43,   104,   142,   143,   144,   145,    41,
      55,    71,   237,    40,    56,    44,    11,    76,   146,   147,
      54,    15,    16,   154,    17,    60,   189,    23,    45,    46,
      32,    62,  -100,   215,    64,    22,  -100,    15,    16,    35,
      17,    56,    23,    33,    66,   170,   171,    96,   146,   147,
      34,   128,    15,    16,    35,    17,    56,    70,   183,   146,
     147,    21,    96,   212,    19,    78,    22,    15,    16,    85,
      17,     1,    79,    23,   192,    80,   134,   197,    23,   200,
       1,    24,    81,    86,   105,     2,     3,    83,     4,    87,
      15,    16,   114,    17,     2,     3,    85,     4,    15,    16,
     200,    17,   217,    88,    16,    23,    17,    89,   183,   125,
      86,   106,   107,   108,   161,   129,    87,   109,   131,   162,
     183,   146,   147,    15,    16,   110,    17,   132,   169,   111,
      88,    16,   115,    17,    89,   183,   133,   136,   116,   117,
     118,   146,   147,   140,   202,   203,   119,   120,   106,   107,
     108,   121,   178,   141,   109,   148,   149,   150,   155,   233,
      15,    16,   110,    17,    15,    16,   111,    17,   158,   218,
     126,   106,   107,   108,   159,   160,   168,   109,   223,   162,
     167,   172,   176,    15,    16,   110,    17,   146,   147,   111,
     173,   203,   223,   231,   106,   107,   108,   146,   147,   175,
     109,   226,   215,   186,   184,   185,    15,    16,   110,    17,
     190,   193,   111,   106,   107,   108,   191,   196,   198,   109,
     201,   205,   208,   210,   209,    15,    16,   110,    17,   214,
     187,   111,   106,   107,   108,   219,   221,   225,   109,   224,
     227,   234,   232,   236,    15,    16,   152,    17,   229,   238,
     111,    20,    68,   151,    61,   135,    72,   177,   211,   235,
     199,   213,   195,   139,   204,   207,     0,     0,   206
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         4,    43,    75,    11,    31,     9,    10,    11,    79,   212,
      45,    38,    10,    11,    56,   209,    10,    90,    22,    23,
      42,    42,    26,   226,    13,    14,     5,   221,    40,    33,
       9,    35,    44,    37,    76,   106,   107,   108,   109,    37,
      48,    45,   236,    37,    48,     3,    25,    51,    28,    29,
      48,    40,    41,   124,    43,    42,    36,    15,    16,    17,
       3,    32,    31,    36,    42,     8,    35,    40,    41,    27,
      43,    75,    15,    16,    42,   146,   147,    75,    28,    29,
      23,    85,    40,    41,    27,    43,    90,    42,   159,    28,
      29,     3,    90,    32,     0,    31,     8,    40,    41,     6,
      43,     7,    31,    15,   175,    32,    13,   178,    15,   180,
       7,    23,    31,    20,    42,    21,    22,    41,    24,    26,
      40,    41,    39,    43,    21,    22,     6,    24,    40,    41,
     201,    43,   203,    40,    41,    15,    43,    44,   209,    31,
      20,    28,    29,    30,    31,    41,    26,    34,    42,    36,
     221,    28,    29,    40,    41,    42,    43,    43,    35,    46,
      40,    41,     4,    43,    44,   236,    42,    33,    10,    11,
      12,    28,    29,    13,    31,    32,    18,    19,    28,    29,
      30,    23,    32,    31,    34,    41,    45,    42,    41,   231,
      40,    41,    42,    43,    40,    41,    46,    43,    31,   203,
      46,    28,    29,    30,    34,    31,    42,    34,   212,    36,
      33,    31,    31,    40,    41,    42,    43,    28,    29,    46,
      32,    32,   226,   227,    28,    29,    30,    28,    29,    38,
      34,    32,    36,    46,    42,    42,    40,    41,    42,    43,
      42,    41,    46,    28,    29,    30,    42,    31,    35,    34,
      31,    37,    46,    41,    34,    40,    41,    42,    43,    42,
      31,    46,    28,    29,    30,    37,    34,    42,    34,    33,
      35,    31,    35,    34,    40,    41,    42,    43,    37,    35,
      46,     5,    37,   122,    26,    90,    48,   158,   196,   234,
     180,   201,   176,    99,   185,   188,    -1,    -1,   187
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     7,    21,    22,    24,    55,    56,    45,    42,     5,
       9,    25,    57,    68,    74,    40,    41,    43,   114,     0,
      56,     3,     8,    15,    23,    69,    70,    71,    72,    73,
      92,   114,     3,    16,    23,    27,    58,    59,    60,    67,
      73,    92,    94,   114,     3,    16,    17,    75,    76,    77,
      78,    79,    83,    91,    92,    94,   114,    42,   114,   114,
      42,    71,    32,    93,    42,   114,    42,   114,    60,    93,
      42,   114,    77,    13,    14,    86,   114,    93,    31,    31,
      32,    31,    61,    41,    87,     6,    20,    26,    40,    44,
      80,    81,    82,    83,    84,    88,    92,   102,   104,   105,
     106,   107,   108,   109,    93,    42,    28,    29,    30,    34,
      42,    46,   113,   114,    39,     4,    10,    11,    12,    18,
      19,    23,    62,    63,    65,    31,    46,    85,   114,    41,
      90,    42,    43,    42,    13,    81,    33,   103,    40,   106,
      13,    31,   113,   113,   113,   113,    28,    29,    41,    45,
      42,    63,    42,    64,   113,    41,   100,   101,    31,    34,
      31,    31,    36,   110,   111,   112,   113,    33,    42,    35,
     113,   113,    31,    32,    66,    38,    31,    87,    32,    95,
      96,    97,    98,   113,    42,    42,    46,    31,    38,    36,
      42,    42,   113,    41,    89,   101,    31,   113,    35,    97,
     113,    31,    31,    32,   110,    37,   112,   111,    46,    34,
      41,    89,    32,    98,    42,    36,    99,   113,   114,    37,
      95,    34,    99,   114,    33,    42,    32,    35,    95,    37,
      99,   114,    35,    93,    31,    90,    34,    95,    35
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
      77,    78,    78,    78,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    83,    84,    85,    85,    85,
      86,    86,    87,    88,    89,    90,    91,    92,    93,    93,
      94,    95,    95,    95,    96,    97,    97,    98,    98,    98,
      99,    99,   100,   100,   101,   102,   103,   104,   104,   105,
     105,   106,   106,   106,   107,   108,   109,   110,   110,   110,
     110,   111,   111,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   114
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
       2,     4,     4,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     4,     2,    14,     1,     1,     0,
      11,     2,     1,     5,     1,     1,     2,     4,     1,     2,
       5,     0,     1,     2,     4,     1,     3,     3,     5,     4,
       1,     3,     1,     3,     3,     2,     2,     0,     1,     1,
       2,     1,     1,     1,     3,     2,     5,     0,     3,     2,
       1,     1,     3,     1,     3,     4,     3,     3,     3,     2,
       2,     2,     1,     1,     1,     1,     1,     1
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
  "text_inst_list", "text_inst", "proc_inst", "proc", "code_list",
  "code_item", "trace_dir", "label_decl", "call_jmp_dir", "call_jmp_tgt",
  "entry_dir", "callc", "return_dir", "arg", "ret", "text_global_dir",
  "equ_dir", "scope", "type_dir", ".arg_list", "stackexp", "arg_list",
  "arg_desc", "arg_type", "regloclist", "regloc", "bundle", "end_bundle",
  ".mop_list", "mop_list", "mop", "normal_mop", "xnop_mop", "asm_mop",
  ".mop_arglist", "mop_arglist", "mop_arg", "expr", "name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        55,     0,    -1,    56,    -1,    55,    56,    -1,    22,    57,
      -1,    22,    68,    -1,    22,    74,    -1,     7,    45,    -1,
      24,   114,    -1,    21,    42,    -1,     9,    58,    -1,    -1,
      59,    -1,    60,    -1,    59,    60,    -1,     3,    42,    -1,
      23,    42,    -1,    -1,   114,    93,    61,    62,    -1,    92,
      -1,    73,    -1,    67,    -1,    94,    -1,    63,    -1,    62,
      63,    -1,    65,    64,    66,    -1,    23,    42,    -1,     4,
      45,    -1,   113,    -1,    42,    31,    42,    -1,    10,    -1,
      11,    -1,    12,    -1,    18,    -1,    19,    -1,    -1,    32,
      42,    -1,    16,   114,    -1,     5,    69,    -1,    -1,    70,
      -1,    71,    -1,    70,    71,    -1,    72,    -1,    73,    -1,
      92,    -1,     3,    42,    -1,    23,    42,    -1,   114,    93,
      -1,     8,   114,    31,    42,    31,    42,    -1,    25,    75,
      -1,    -1,    76,    -1,    77,    -1,    76,    77,    -1,    78,
      -1,    92,    -1,    91,    -1,    94,    -1,    83,    -1,     3,
      42,    -1,    79,    86,    80,    13,    -1,    79,   114,    93,
      13,    -1,    79,    13,    -1,    17,    -1,    81,    -1,    80,
      81,    -1,   102,    -1,    84,    -1,    92,    -1,    83,    -1,
      88,    -1,    82,    -1,    26,    42,    -1,    26,    42,    31,
      42,    -1,   114,    93,    -1,     6,    85,    31,    87,    31,
      89,    34,    95,    35,    31,    90,    34,    95,    35,    -1,
     114,    -1,    46,    -1,    -1,    14,    87,    31,   100,    31,
      89,    34,    95,    35,   114,    93,    -1,   114,    93,    -1,
      41,    -1,    20,    90,    34,    95,    35,    -1,    41,    -1,
      41,    -1,    16,   114,    -1,    15,   114,    31,   113,    -1,
      32,    -1,    32,    32,    -1,    27,   114,    31,    39,    41,
      -1,    -1,    97,    -1,    96,    97,    -1,   113,    31,    42,
      33,    -1,    98,    -1,    97,    31,    98,    -1,   113,    32,
      99,    -1,   113,    32,   113,    32,    99,    -1,    32,   113,
      32,    99,    -1,   114,    -1,    36,    42,    37,    -1,   101,
      -1,   100,    31,   101,    -1,    41,    38,   113,    -1,   104,
     103,    -1,    33,    33,    -1,    -1,   105,    -1,   106,    -1,
     105,   106,    -1,   107,    -1,   108,    -1,   109,    -1,    40,
      43,   110,    -1,    44,    42,    -1,    40,    43,    31,    42,
     110,    -1,    -1,   111,    38,   111,    -1,   111,    38,    -1,
     111,    -1,   112,    -1,   111,    31,   112,    -1,   113,    -1,
      36,    46,    37,    -1,   113,    36,    46,    37,    -1,    34,
     113,    35,    -1,   113,    28,   113,    -1,   113,    29,   113,
      -1,    29,   113,    -1,    28,   113,    -1,    30,   113,    -1,
     114,    -1,    46,    -1,    42,    -1,    41,    -1,    43,    -1,
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
     149,   152,   157,   162,   165,   167,   169,   172,   174,   176,
     178,   180,   182,   184,   187,   192,   195,   210,   212,   214,
     215,   227,   230,   232,   238,   240,   242,   245,   250,   252,
     255,   261,   262,   264,   267,   272,   274,   278,   282,   288,
     293,   295,   299,   301,   305,   309,   312,   315,   316,   318,
     320,   323,   325,   327,   329,   333,   336,   342,   343,   347,
     350,   352,   354,   358,   360,   364,   369,   373,   377,   381,
     384,   387,   390,   392,   394,   396,   398,   400
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
     316,   319,   321,   322,   325,   328,   329,   332,   333,   334,
     335,   336,   337,   340,   341,   344,   347,   357,   358,   359,
     362,   367,   373,   376,   379,   382,   385,   388,   391,   392,
     395,   402,   403,   404,   407,   410,   411,   414,   415,   416,
     419,   420,   423,   424,   427,   434,   443,   446,   447,   450,
     451,   454,   455,   456,   459,   481,   495,   503,   504,   505,
     506,   510,   511,   514,   515,   516,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   537,   538,   539
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
  const int Parser::yylast_ = 298;
  const int Parser::yynnts_ = 61;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 19;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 54;

  const unsigned int Parser::yyuser_token_number_max_ = 308;
  const Parser::token_number_type Parser::yyundef_token_ = 2;


} // VexParser

/* Line 1136 of lalr1.cc  */
#line 1952 "parser.tab.cc"


/* Line 1138 of lalr1.cc  */
#line 546 "parser.yy"
 /*** Additional Code ***/

void VexParser::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

