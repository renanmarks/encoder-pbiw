/**
*** Copyright (C) 1994 - 2002 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** Author:  Geoffrey Brown 
***     based upon previous work by Paolo Faraboschi and Bill Ackerman
**/

/**
*** static char sccs_id[] = "$Id: vexopc.h,v 1.3 2003/02/19 16:18:57 frb Exp $";
**/

/**
*** Definition of VEX Opcodes
**/

#ifndef __VEX_INCLUDED__
#define __VEX_INCLUDED__

#include <vector>

#include "vextypes.h"
#include "parser.tab.hh"

typedef VexParser::Parser::token token;
typedef VexParser::Parser::token_type token_type;

const VexParser::VexOpcode _optab[] = {
/*----------------------------------------------*/
/*  as_opc            tok     flags     opctype */
/*----------------------------------------------*/
/* MEM */
   {"ldb",         token::OPCODE,   NONE,         opLDB},
   {"ldb.d",       token::OPCODE,   SPEC,      opLDB},
   {"ldbu",        token::OPCODE,   NONE,        opLDBU},
   {"ldbu.d",      token::OPCODE,   SPEC,     opLDBU},
   {"ldh",         token::OPCODE,   NONE,         opLDH},
   {"ldh.d",       token::OPCODE,   SPEC,      opLDH},
   {"ldhu",        token::OPCODE,   NONE,        opLDHU},
   {"ldhu.d",      token::OPCODE,   SPEC,     opLDHU},
   {"ldw",         token::OPCODE,   NONE,         opLDW},
   {"ldw.d",       token::OPCODE,   SPEC,      opLDW},
   {"pft",         token::OPCODE,   NONE,         opPFT},
   {"stb",         token::OPCODE,   NONE,         opSTB},
   {"sth",         token::OPCODE,   NONE,         opSTH},
   {"stw",         token::OPCODE,   NONE,         opSTW},

/* STREAM  */
   {"ldb.s",       token::OPCODE,   STREAM,    opLDB},
   {"ldb.s.d",     token::OPCODE,   SSPEC,     opLDB},
   {"ldbu.s",      token::OPCODE,   STREAM,    opLDBU},
   {"ldbu.s.d",    token::OPCODE,   SSPEC,     opLDBU},
   {"ldh.s",       token::OPCODE,   STREAM,    opLDH},
   {"ldh.s.d",     token::OPCODE,   SSPEC,     opLDH},
   {"ldhu.s",      token::OPCODE,   STREAM,    opLDHU},
   {"ldhu.s.d",    token::OPCODE,   SSPEC,     opLDHU},
   {"ldw.s",       token::OPCODE,   STREAM,    opLDW},
   {"ldw.s.d",     token::OPCODE,   SSPEC,     opLDW},
   {"pft.s",       token::OPCODE,   STREAM,    opPFT},
   {"stb.s",       token::OPCODE,   STREAM,    opSTB},
   {"sth.s",       token::OPCODE,   STREAM,    opSTH},
   {"stw.s",       token::OPCODE,   STREAM,    opSTW},

/* LOCK */
   {"ldb.l",       token::OPCODE,   LOCK,      opLDB},
   {"ldb.l.d",     token::OPCODE,   LSPEC,     opLDB},
   {"ldbu.l",      token::OPCODE,   LOCK,      opLDBU},
   {"ldbu.l.d",    token::OPCODE,   LSPEC,     opLDBU},
   {"ldh.l",       token::OPCODE,   LOCK,      opLDH},
   {"ldh.l.d",     token::OPCODE,   LSPEC,     opLDH},
   {"ldhu.l",      token::OPCODE,   LOCK,      opLDHU},
   {"ldhu.l.d",    token::OPCODE,   LSPEC,     opLDHU},
   {"ldw.l",       token::OPCODE,   LOCK,      opLDW},
   {"ldw.l.d",     token::OPCODE,   LSPEC,     opLDW},
   {"pft.l",       token::OPCODE,   LOCK,      opPFT},
   {"stb.l",       token::OPCODE,   LOCK,      opSTB},
   {"sth.l",       token::OPCODE,   LOCK,      opSTH},
   {"stw.l",       token::OPCODE,   LOCK,      opSTW},

/* ALU */
   {"add",        token::OPCODE,    NONE,         opADD},
   {"and",        token::OPCODE,    NONE,         opAND},
   {"andc",       token::OPCODE,    NONE,         opANDC},
   {"andl",       token::OPCODE,    NONE,         opANDL},
   {"cmpeq",      token::OPCODE,    NONE,         opCMPEQ},
   {"cmpge",      token::OPCODE,    NONE,         opCMPGE},
   {"cmpgeu",     token::OPCODE,    NONE,         opCMPGEU},
   {"cmpgt",      token::OPCODE,    NONE,         opCMPGT},
   {"cmpgtu",     token::OPCODE,    NONE,         opCMPGTU},
   {"cmple",      token::OPCODE,    NONE,         opCMPLE},
   {"cmpleu",     token::OPCODE,    NONE,         opCMPLEU},
   {"cmplt",      token::OPCODE,    NONE,         opCMPLT},
   {"cmpltu",     token::OPCODE,    NONE,         opCMPLTU},
   {"cmpne",      token::OPCODE,    NONE,         opCMPNE},
   {"max",        token::OPCODE,    NONE,         opMAX },
   {"maxu",       token::OPCODE,    NONE,         opMAXU },
   {"min",        token::OPCODE,    NONE,         opMIN},
   {"minu",       token::OPCODE,    NONE,         opMINU},
   {"mpy",        token::OPCODE,    NONE,         opMUL},
   {"mpyl",       token::OPCODE,    NONE,         opMULL},
   {"mpylu",      token::OPCODE,    NONE,         opMULLU},
   {"mpyh",       token::OPCODE,    NONE,         opMULH},
   {"mpyhu",      token::OPCODE,    NONE,         opMULHU},
   {"mpyhs",      token::OPCODE,    NONE,         opMULHS},
   {"mpyll",      token::OPCODE,    NONE,         opMULLL},
   {"mpyllu",     token::OPCODE,    NONE,         opMULLLU},
   {"mpylh",      token::OPCODE,    NONE,         opMULLH},
   {"mpylhu",     token::OPCODE,    NONE,         opMULLHU},
   {"mpyhh",      token::OPCODE,    NONE,         opMULHH},
   {"mpyhhu",     token::OPCODE,    NONE,         opMULHHU},
   {"nandl",      token::OPCODE,    NONE,         opNANDL},
   {"nop",        token::OPCODE,    NONE,         opNOP},
   {"norl",       token::OPCODE,    NONE,         opNORL},
   {"or",         token::OPCODE,    NONE,         opOR},
   {"orc",        token::OPCODE,    NONE,         opORC},
   {"orl",        token::OPCODE,    NONE,         opORL},
   {"sbit",       token::OPCODE,    NONE,         opSBIT},
   {"sbitf",      token::OPCODE,    NONE,         opSBITF},
   {"sh1add",     token::OPCODE,    NONE,         opSH1ADD},
   {"sh2add",     token::OPCODE,    NONE,         opSH2ADD},
   {"sh3add",     token::OPCODE,    NONE,         opSH3ADD},
   {"sh4add",     token::OPCODE,    NONE,         opSH4ADD},
   {"shl",        token::OPCODE,    NONE,         opSHL},
   {"shr",        token::OPCODE,    NONE,         opSHR},
   {"shru",       token::OPCODE,    NONE,         opSHRU},
   {"slct",       token::OPCODE,    NONE,         opSLCT},
   {"slctf",      token::OPCODE,    NONE,         opSLCTF},
   {"sub",        token::OPCODE,    NONE,         opSUB},
   {"sxtb",       token::OPCODE,    NONE,         opSXTB},
   {"sxth",       token::OPCODE,    NONE,         opSXTH},
   {"tbit",       token::OPCODE,    NONE,         opTBIT},
   {"tbitf",      token::OPCODE,    NONE,         opTBITF},
   {"xor",        token::OPCODE,    NONE,         opXOR},
   {"zxtb",       token::OPCODE,    NONE,         opZXTB},
   {"zxth",       token::OPCODE,    NONE,         opZXTH},

/* DIV/CARRY */
   {"divs",	  token::OPCODE,    NONE,         opDIVS},
   {"addcg",      token::OPCODE,    NONE,         opADDCG},

/* MOV */
   {"mov",	  token::OPCODE,    NONE,         opMOV},
   {"mfl",	  token::OPCODE,    NONE,         opMFL},
   {"mtl",	  token::OPCODE,    NONE,         opMTL},
   {"mfb",	  token::OPCODE,    NONE,         opMFB},
   {"mtb",	  token::OPCODE,    NONE,         opMTB},
   {"mtbf",	  token::OPCODE,    NONE,         opMTBINV},

/* BRANCH */
   {"goto",       token::OPCODE,    CTLFLOW,   opGOTO},
   {"call",       token::OPCODE,    CTLFLOW,   opCALL},
   {"return",     token::OPCODE,    CTLFLOW,   opRETURN},
   {"br",         token::OPCODE,    CTLFLOW,   opBRANCH},
   {"brf",        token::OPCODE,    CTLFLOW,   opBRANCHF},

/* ASM */
   {"asm",        token::OPCODE,    NONE,         opASM},

/* XNOP */
   {"xnop",       token::XNOP,      NONE,         opXNOP},

/**************** PSEUDO  OPCODES *************************/

   {".call",      token::_CALL_JMP,  NONE,        opCALLDIR},
   {".longjmp",   token::_CALL_JMP,  NONE,        opLONGJMPDIR},
   {"._longjmp",  token::_CALL_JMP,  NONE,        opLONGJMPDIR},
   {".__longjmp", token::_CALL_JMP,  NONE,        opLONGJMPDIR},
   {".setjmp",    token::_CALL_JMP,  NONE,        opSETJMPDIR},
   {"._setjmp",   token::_CALL_JMP,  NONE,        opSETJMPDIR},
   {".__setjmp",  token::_CALL_JMP,  NONE,        opSETJMPDIR},

/*************  ASSEMBLER DIRECTIVES **********************/

   {".align",      token::_ALIGN,    NONE,         opASMDIR},
   {".ascii",      token::_ASCII,    NONE,         opASMDIR},
   {".bss",        token::_BSS,      NONE,         opASMDIR},
   {".section",    token::_SECTION,  NONE,         opASMDIR},
   {".comment",    token::_COMMENT,  NONE,         opASMDIR},
   {".comm",       token::_COMMON,   NONE,         opASMDIR},
   {".data",       token::_DATA,     NONE,         opASMDIR},
   {".data1",      token::_DATA1,    NONE,         opASMDIR},
   {".data2",      token::_DATA2,    NONE,         opASMDIR},
   {".data4",      token::_DATA4,    NONE,         opASMDIR},
   {".endp",       token::_ENDP,     NONE,         opASMDIR},
   {".entry",      token::_ENTRY,    NONE,         opASMDIR},
   {".equ",        token::_EQU,      NONE,         opASMDIR},
   {".import",     token::_IMPORT,   NONE,         opASMDIR},
   {".proc",       token::_PROC,     NONE,         opASMDIR},
   {".real4",      token::_REAL4,    NONE,         opASMDIR},
   {".real8",      token::_REAL8,    NONE,         opASMDIR},
   {".return",     token::_RETURN,   NONE,         opASMDIR},
   {".rta",        token::_RTA,      NONE,         opASMDIR},
   {".skip",       token::_SKIP,     NONE,         opASMDIR},
   {".sversion",   token::_SVERSION, NONE,         opASMDIR},
   {".text",       token::_TEXT,     NONE,         opASMDIR},
   {".trace",      token::_TRACE,    NONE,         opASMDIR},
   {".type",       token::_TYPE,     NONE,         opASMDIR},
   
/*************  Operators **********************/

   {"+",       token::__PLUS,       NONE,         opNONE},
   {"-",       token::__MINUS,      NONE,         opNONE},
   {"~",       token::__NOT,        NONE,         opNONE},
   {",",       token::__COMMA,      NONE,         opNONE},
   {":",       token::__COLON,      NONE,         opNONE},
   {";",       token::__SEMICOLON,  NONE,         opNONE},
   {"(",       token::__LPAREN,     NONE,         opNONE},
   {")",       token::__RPAREN,     NONE,         opNONE},
   {"[",       token::__LBRACKET,   NONE,         opNONE},
   {"]",       token::__RBRACKET,   NONE,         opNONE},
   {"=",       token::__EQUAL,      NONE,         opNONE},
   {"@",       token::__AT,         NONE,         opNONE}
};

std::vector<VexParser::VexOpcode> 
  optab (_optab, _optab + sizeof(_optab) / sizeof(_optab[0]));

#endif
