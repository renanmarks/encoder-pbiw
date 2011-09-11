
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ALIGN = 258,
     _ASCII = 259,
     _BSS = 260,
     _CALL_JMP = 261,
     _COMMENT = 262,
     _COMMON = 263,
     _DATA = 264,
     _DATA1 = 265,
     _DATA2 = 266,
     _DATA4 = 267,
     _ENDP = 268,
     _ENTRY = 269,
     _EQU = 270,
     _IMPORT = 271,
     _PROC = 272,
     _REAL4 = 273,
     _REAL8 = 274,
     _RETURN = 275,
     _RTA = 276,
     _SECTION = 277,
     _SKIP = 278,
     _SVERSION = 279,
     _TEXT = 280,
     _TRACE = 281,
     _TYPE = 282,
     CLUST = 283,
     NAME = 284,
     NUMBER = 285,
     OPCODE = 286,
     XNOP = 287,
     QUOTE_STRING = 288,
     REGNAME = 289,
     USIGN = 290,
     INIT = 291,
     ARGS = 292,
     BLOCK = 293,
     BUNDLE = 294,
     EQU = 295,
     LABEL = 296
   };
#endif
/* Tokens.  */
#define _ALIGN 258
#define _ASCII 259
#define _BSS 260
#define _CALL_JMP 261
#define _COMMENT 262
#define _COMMON 263
#define _DATA 264
#define _DATA1 265
#define _DATA2 266
#define _DATA4 267
#define _ENDP 268
#define _ENTRY 269
#define _EQU 270
#define _IMPORT 271
#define _PROC 272
#define _REAL4 273
#define _REAL8 274
#define _RETURN 275
#define _RTA 276
#define _SECTION 277
#define _SKIP 278
#define _SVERSION 279
#define _TEXT 280
#define _TRACE 281
#define _TYPE 282
#define CLUST 283
#define NAME 284
#define NUMBER 285
#define OPCODE 286
#define XNOP 287
#define QUOTE_STRING 288
#define REGNAME 289
#define USIGN 290
#define INIT 291
#define ARGS 292
#define BLOCK 293
#define BUNDLE 294
#define EQU 295
#define LABEL 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 48 "grammar.y"

   int       val;
   char      *text;
   vexopc    *opc;
   vexexp    *exp;
   vexfun    fun;



/* Line 1676 of yacc.c  */
#line 144 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


