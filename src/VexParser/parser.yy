/* $Id: parser.yy 48 2009-09-05 08:07:10Z tb $ -*- mode: c++ -*- */
/** \file parser.yy Contains the rVex Bison parser source */

/* Declaration at parser implementation */
%{ /*** C/C++ Declarations ***/
  
//#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "VexTypes.h"
#include "Expressions/Expression.h"
#include "Expressions/Arguments.h"
#include "Expressions/SyllableArguments.h"
//#include "../rVex/Label.h"
  
//enum { LOCAL = 0, GLOBAL = 1 };
  
%}

/* Declaration at parser header */
%code requires {
#include "../rVex/Label.h"
}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start asm_file

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="VexParser"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

 /*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
   int                        value;
   rVex::Label::LabelScope    scope;
   std::string*               text;
   struct VexOpcode*          opcode;
   struct VexFunction*        function;
   class Arguments*           arguments;
   class SyllableArguments*   syllableArguments;
   class Expression*          expression;
}

%token			END	     0	"end of file"

%token            _ALIGN
%token            _ASCII
%token            _BSS
%token <opcode>   _CALL_JMP
%token            _COMMENT
%token            _COMMON
%token            _DATA
%token            _DATA1
%token            _DATA2
%token            _DATA4
%token            _ENDP
%token            _ENTRY
%token            _EQU
%token            _IMPORT
%token            _PROC
%token            _REAL4
%token            _REAL8
%token            _RETURN
%token            _RTA
%token            _SECTION
%token            _SKIP
%token            _SVERSION
%token            _TEXT
%token            _TRACE
%token            _TYPE

%token            __PLUS
%token            __MINUS
%token            __NOT
%token            __COMMA
%token            __COLON
%token            __SEMICOLON
%token            __LPAREN
%token            __RPAREN
%token            __LBRACKET
%token            __RBRACKET
%token            __EQUAL
%token            __AT

%token <text>     CLUST
%token <text>     NAME
%token <value>    NUMBER
%token <opcode>   OPCODE
%token <opcode>   XNOP
%token <text>     QUOTE_STRING
%token <text>     REGNAME

%type   <text>    call_jmp_tgt
%type   <text>    name
%type   <text>    arg
%type   <text>    ret

%type   <value>   data_size
%type   <scope>   scope
%type   <value>   .dup

%type   <expression>            data_val
%type   <expression>            expr
%type   <expression>            mop_arg
%type   <arguments>             mop_arglist
%type   <syllableArguments>     .mop_arglist

%type   <function>     entry_dir

%left __PLUS __MINUS 
%left USIGN

%left INIT
%left _SKIP

%left ARGS
%left CLUST

/* dummy tokens, used outside yacc */
%token            BLOCK
%token            BUNDLE
%token            EQU
%token            LABEL


%destructor { delete $$; } CLUST 
%destructor { delete $$; } NAME 
%destructor { delete $$; } OPCODE 
%destructor { delete $$; } XNOP 
%destructor { delete $$; } QUOTE_STRING 
%destructor { delete $$; } _CALL_JMP

%destructor { delete $$; } call_jmp_tgt
%destructor { delete $$; } name
%destructor { delete $$; } arg
%destructor { delete $$; } ret
%destructor { delete $$; } data_val
%destructor { delete $$; } expr
%destructor { delete $$; } entry_dir

%destructor { delete $$; } mop_arg
%destructor { delete $$; } mop_arglist
%destructor { delete $$; } .mop_arglist

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN EXAMPLE - Change the example grammar rules below ***/

/********************************************************************************
 **     File structure
 ********************************************************************************/

asm_file        :       asm_section
                |       asm_file asm_section 
                ;

asm_section     :       _SECTION data_section
                |       _SECTION bss_section
                |       _SECTION text_section
                |       _COMMENT QUOTE_STRING // comment
                |       _SVERSION name
                |       _RTA NUMBER
                ;

        /*------------------------------------------------------*/
        /*              data section                            */
        /*------------------------------------------------------*/

data_section    :       _DATA .data_dir_list 
                ;


.data_dir_list  :       /* empty */
                |       data_dir_list
                ;

data_dir_list   :       data_dir
                |       data_dir_list data_dir
                ;


data_dir        :       _ALIGN NUMBER                   { } // data align
                |       _SKIP NUMBER                    { } // data skip
                |       name scope                      { } // data item
                        init_list %prec INIT            { }
                |       equ_dir                         { }
                |       common_dir                      { }
                |       data_global_dir                 { }
                |       type_dir                        { }
                ;

init_list       :       init_dir
                |       init_list init_dir
                ;

init_dir        :       data_size data_val .dup { } // init: size: INT dup INT
                |       _SKIP NUMBER { } // init skip
                |       _ASCII QUOTE_STRING { } // init string
                ;

data_val        :       expr               { $$ = $1; }
                |       NUMBER __COMMA NUMBER  { $$ = new Expression($1); } // $$ = build_numexp($1);

data_size       :       _DATA1          { $$ = 1; }
                |       _DATA2          { $$ = 2; }
                |       _DATA4          { $$ = 4; }
                |       _REAL4          { $$ = 4; }
                |       _REAL8          { $$ = 8; }
                ;

.dup            :       /* empty */     { $$ = 0;  }
                |       __COLON NUMBER      { $$ = $2; }
                ;


data_global_dir :       _IMPORT name    { } // data import
                ;

        /*------------------------------------------------------*/
        /*              bss section                             */
        /*------------------------------------------------------*/

bss_section     :       _BSS .bss_dir_list
                ;

.bss_dir_list   :       /* empty */
                |       bss_dir_list
                ;

bss_dir_list    :       bss_dir
                |       bss_dir_list bss_dir
                ;

bss_dir         :       bss_label_decl
                |       common_dir
                |       equ_dir
                |       _ALIGN NUMBER { } // bss align
                |       _SKIP NUMBER { } // bss skip
                ;

bss_label_decl  :       name scope { } // bss item
                ;

common_dir      :       _COMMON name __COMMA NUMBER __COMMA NUMBER 
                ;

        /*------------------------------------------------------*/
        /*              text section                            */
        /*------------------------------------------------------*/

text_section    :       _TEXT .text_inst_list
                ;

.text_inst_list :       /* empty */
                |       text_inst_list
                ;

text_inst_list  :       text_inst                   
                |       text_inst_list text_inst
                ;

text_inst       :       proc_inst     
                |       equ_dir
                |       text_global_dir
                |       type_dir
                |       label_decl
                |       _ALIGN NUMBER { }
                ;

proc_inst       :       proc entry_dir  { } // begin of function
                        code_list _ENDP { } // end of function
                |       proc name scope _ENDP { } // empty function
                |       proc _ENDP
                ;

proc            :       _PROC { }
                ;

code_list       :       code_item
                |       code_list code_item 
                ;

code_item       :       bundle 
                |       call_jmp_dir   
                |       equ_dir        
                |       label_decl     
                |       return_dir     
                |       trace_dir      
                ;

trace_dir       :       _TRACE NUMBER
                |       _TRACE NUMBER __COMMA NUMBER 
                ;

label_decl      :       name scope  { driver.context.setLabel(*$1, $2); }
                ;

call_jmp_dir    :       _CALL_JMP call_jmp_tgt __COMMA callc __COMMA { }
                        arg __LPAREN .arg_list __RPAREN __COMMA            { }
                        ret __LPAREN .arg_list __RPAREN                { }
                ;

call_jmp_tgt    :       name          { $$ = $1; }
                |       REGNAME       { $$ = $1; }
                |       /* empty */   { $$ = new std::string(""); }
                ;

entry_dir       :       _ENTRY callc __COMMA regloclist __COMMA arg __LPAREN .arg_list __RPAREN name scope { 
                            $$->str = $10;
                            $$->scope = $11;
                        }
                |       name scope  {
                            $$->str = $1;
                            $$->scope = $2;
                        }
                ;

callc           :       NAME  { }
                ;

return_dir      :       _RETURN  ret __LPAREN .arg_list __RPAREN  { }
                ;

arg             :       NAME  { $$ = $1; }
                ;

ret             :       NAME  { $$ = $1; }
                ;

text_global_dir :       _IMPORT name  { }
                ;

equ_dir         :       _EQU name __COMMA expr { }
                ;

scope           :       __COLON          { $$ = rVex::Label::LOCAL; }
                |       __COLON __COLON       { $$ = rVex::Label::GLOBAL; }
                ;

type_dir        :       _TYPE name __COMMA __AT NAME
                ;

/**********************************************************************************
 **     Pseudo-instruction argument list (call, return, entry)
 **********************************************************************************/

.arg_list       :       /* empty */
                |       arg_list 
                |       stackexp arg_list 
                ;

stackexp        :       expr __COMMA NUMBER __SEMICOLON  { }
                ;

arg_list        :       arg_desc              
                |       arg_list __COMMA arg_desc 
                ;

arg_desc        :       expr __COLON arg_type               { }
                |       expr __COLON expr __COLON arg_type      { }
                |       __COLON expr __COLON arg_type           { }
                ;

arg_type        :       name            { }
                |       __LBRACKET NUMBER __RBRACKET  { }
                ;

regloclist      :       regloc         
                |       regloclist __COMMA regloc 
                ;

regloc          :       NAME __EQUAL expr  { }
                ;

/**********************************************************************************
 **     BUNDLE structure and MOP opcodes
 **********************************************************************************/

bundle          :      .mop_list end_bundle { driver.context.endInstruction(); std::cout << ";;" << std::endl; }
                ;

end_bundle      :       __SEMICOLON __SEMICOLON 
                ;

.mop_list       :       /* empty */
                |       mop_list 
                ;

mop_list        :       mop         
                |       mop_list mop 
                ;

mop             :       normal_mop  
                |       xnop_mop
                |       asm_mop    
                ;

normal_mop      :       CLUST OPCODE .mop_arglist 
                        { 
                          driver.context.packSyllable( $2->syllableConstructor->create(), $3 ); 
                          
                          std::cout << " " << $2->as_op << " ";
                          
                          if ( $3->getDestinyArguments() )
                          {
                            $3->getDestinyArguments()->print(std::cout);
                            std::cout << " = ";
                          }
                          $3->getSourceArguments()->print(std::cout);
                          
                          std::cout << std::endl;
                        }
                ;

xnop_mop        :       XNOP NUMBER 
                        { 
                          Expression* ex = new Expression($2);
                          SyllableArguments* argument = new SyllableArguments(new Arguments(ex));
                          driver.context.packSyllable( $1->syllableConstructor->create(), argument ); 
                          
                          std::cout << " " << $1->as_op << " " << $2 << std::endl;
                        }
                ;

asm_mop         :       CLUST OPCODE __COMMA NUMBER { }
                        .mop_arglist { }
                ;

/**********************************************************************************
 **     MOP argument list
 **********************************************************************************/

.mop_arglist    :       /* empty */   %prec ARGS    { }
                |       mop_arglist __EQUAL mop_arglist       { $$ = new SyllableArguments($1, $3); }
                |       mop_arglist __EQUAL %prec ARGS        { $$ = new SyllableArguments($1); }
                |       mop_arglist                           { $$ = new SyllableArguments($1); }
                ;


mop_arglist     :       mop_arg                               { $$ = new Arguments($1); }
                |       mop_arglist __COMMA mop_arg           { $$ = new Arguments(*$1, $3); }
                ;

mop_arg         :       expr                                  { $$ = $1; }
                |       __LBRACKET REGNAME __RBRACKET         { $$ = new Expression(*$2); }
                |       expr __LBRACKET REGNAME __RBRACKET    { $$ = new Expression(*$1, *$3); }
                ;

/**********************************************************************************
 **     General add/sub arithmetic expression
 **********************************************************************************/

expr            :       __LPAREN expr __RPAREN    { $$ = $2; }
                |       expr __PLUS expr          { $$ = new Expression('+', *$1, *$3); } // $$ = build_binexp('+', $1, $3);
                |       expr __MINUS expr         { $$ = new Expression('-', *$1, *$3); } // $$ = build_binexp('-', $1, $3);
                |       __MINUS expr %prec USIGN  { $$ = new Expression('-', *$2); } // $$ = build_unexp('-', $2);
                |       __PLUS expr %prec USIGN   { $$ = new Expression('+', *$2); } // $$ = build_unexp('+', $2);
                |       __NOT expr %prec USIGN    { $$ = new Expression('~', *$2); } // $$ = build_unexp('~', $2);
                |       name                      { $$ = new Expression(*$1); } // $$ = build_strexp($1);
                |       REGNAME                   { $$ = new Expression(*$1); } // $$ = build_strexp($1);
                |       NUMBER                    { $$ = new Expression($1); } // $$ = build_numexp($1);
                ;

/**********************************************************************************
 **     Generic name (could be NAME or OPCODE)
 **********************************************************************************/
name            :       NAME                  { $$ = $1; }
                |       OPCODE                { $$ = new std::string($1->as_op); }
                |       CLUST                 { $$ = $1; }
                ;
/**********************************************************************************/
/**********************************************************************************/

 /*** END EXAMPLE - Change the example grammar rules above ***/

%% /*** Additional Code ***/

void VexParser::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
