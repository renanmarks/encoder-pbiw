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

#include "VexTypes.h"
#include "parser.tab.hh"
#include "../rVex/Operations/Operations.h"

typedef VexParser::Parser::token token;
typedef VexParser::Parser::token_type token_type;

using namespace VexParser;
using namespace rVex::Operations;

/**
 * Auxiliary declaration of table.
 * All the opcodes and its respectives constructors are placed here to
 * make easy the extensibility of Vex ISA.
 */
const VexOpcode _optab[] = {
/*----------------------------------------------------------------------------*/
/*  as_opc                   tok   flags   opctype    SyllableConstructor     */
/*----------------------------------------------------------------------------*/
/* MEM */
   {"ldb",         token::OPCODE,   NONE,    opLDB  , new SyllableConstructor<MEM::LDB>() },
   {"ldb.d",       token::OPCODE,   SPEC,    opLDB  , new SyllableConstructor<MEM::LDB>() },
   {"ldbu",        token::OPCODE,   NONE,    opLDBU , new SyllableConstructor<MEM::LDBU>() },
   {"ldbu.d",      token::OPCODE,   SPEC,    opLDBU , new SyllableConstructor<MEM::LDBU>() },
   {"ldh",         token::OPCODE,   NONE,    opLDH  , new SyllableConstructor<MEM::LDH>() },
   {"ldh.d",       token::OPCODE,   SPEC,    opLDH  , new SyllableConstructor<MEM::LDH>() },
   {"ldhu",        token::OPCODE,   NONE,    opLDHU , new SyllableConstructor<MEM::LDHU>() },
   {"ldhu.d",      token::OPCODE,   SPEC,    opLDHU , new SyllableConstructor<MEM::LDHU>() },
   {"ldw",         token::OPCODE,   NONE,    opLDW  , new SyllableConstructor<MEM::LDW>() },
   {"ldw.d",       token::OPCODE,   SPEC,    opLDW  , new SyllableConstructor<MEM::LDW>() },
   {"pft",         token::OPCODE,   NONE,    opPFT  , new SyllableConstructor<MEM::PFT>() },
   {"stb",         token::OPCODE,   NONE,    opSTB  , new SyllableConstructor<MEM::STB>() },
   {"sth",         token::OPCODE,   NONE,    opSTH  , new SyllableConstructor<MEM::STH>() },
   {"stw",         token::OPCODE,   NONE,    opSTW  , new SyllableConstructor<MEM::STW>() },

/* STREAM  */
   {"ldb.s",       token::OPCODE,   STREAM,    opLDB   , new SyllableConstructor<MEM::LDB>() },
   {"ldb.s.d",     token::OPCODE,   SSPEC,     opLDB   , new SyllableConstructor<MEM::LDB>() },
   {"ldbu.s",      token::OPCODE,   STREAM,    opLDBU  , new SyllableConstructor<MEM::LDBU>() },
   {"ldbu.s.d",    token::OPCODE,   SSPEC,     opLDBU  , new SyllableConstructor<MEM::LDBU>() },
   {"ldh.s",       token::OPCODE,   STREAM,    opLDH   , new SyllableConstructor<MEM::LDH>() },
   {"ldh.s.d",     token::OPCODE,   SSPEC,     opLDH   , new SyllableConstructor<MEM::LDH>() },
   {"ldhu.s",      token::OPCODE,   STREAM,    opLDHU  , new SyllableConstructor<MEM::LDHU>() },
   {"ldhu.s.d",    token::OPCODE,   SSPEC,     opLDHU  , new SyllableConstructor<MEM::LDHU>() },
   {"ldw.s",       token::OPCODE,   STREAM,    opLDW   , new SyllableConstructor<MEM::LDW>() },
   {"ldw.s.d",     token::OPCODE,   SSPEC,     opLDW   , new SyllableConstructor<MEM::LDW>() },
   {"pft.s",       token::OPCODE,   STREAM,    opPFT   , new SyllableConstructor<MEM::PFT>() },
   {"stb.s",       token::OPCODE,   STREAM,    opSTB   , new SyllableConstructor<MEM::STB>() },
   {"sth.s",       token::OPCODE,   STREAM,    opSTH   , new SyllableConstructor<MEM::STH>() },
   {"stw.s",       token::OPCODE,   STREAM,    opSTW   , new SyllableConstructor<MEM::STW>() },

/* LOCK */
   {"ldb.l",       token::OPCODE,   LOCK,      opLDB   , new SyllableConstructor<MEM::LDB>() },
   {"ldb.l.d",     token::OPCODE,   LSPEC,     opLDB   , new SyllableConstructor<MEM::LDB>() },
   {"ldbu.l",      token::OPCODE,   LOCK,      opLDBU  , new SyllableConstructor<MEM::LDBU>() },
   {"ldbu.l.d",    token::OPCODE,   LSPEC,     opLDBU  , new SyllableConstructor<MEM::LDBU>() },
   {"ldh.l",       token::OPCODE,   LOCK,      opLDH   , new SyllableConstructor<MEM::LDH>() },
   {"ldh.l.d",     token::OPCODE,   LSPEC,     opLDH   , new SyllableConstructor<MEM::LDH>() },
   {"ldhu.l",      token::OPCODE,   LOCK,      opLDHU  , new SyllableConstructor<MEM::LDHU>() },
   {"ldhu.l.d",    token::OPCODE,   LSPEC,     opLDHU  , new SyllableConstructor<MEM::LDHU>() },
   {"ldw.l",       token::OPCODE,   LOCK,      opLDW   , new SyllableConstructor<MEM::LDW>() },
   {"ldw.l.d",     token::OPCODE,   LSPEC,     opLDW   , new SyllableConstructor<MEM::LDW>() },
   {"pft.l",       token::OPCODE,   LOCK,      opPFT   , new SyllableConstructor<MEM::PFT>() },
   {"stb.l",       token::OPCODE,   LOCK,      opSTB   , new SyllableConstructor<MEM::STB>() },
   {"sth.l",       token::OPCODE,   LOCK,      opSTH   , new SyllableConstructor<MEM::STH>() },
   {"stw.l",       token::OPCODE,   LOCK,      opSTW   , new SyllableConstructor<MEM::STW>() },

/* ALU */
   {"add",        token::OPCODE,    NONE,      opADD    , new SyllableConstructor<ALU::ADD>() },
   {"and",        token::OPCODE,    NONE,      opAND    , new SyllableConstructor<ALU::AND>() },
   {"andc",       token::OPCODE,    NONE,      opANDC   , new SyllableConstructor<ALU::ANDC>() },
   {"andl",       token::OPCODE,    NONE,      opANDL   , new SyllableConstructor<ALU::ANDL>() },
   {"cmpeq",      token::OPCODE,    NONE,      opCMPEQ  , new SyllableConstructor<ALU::CMPEQ>() },
   {"cmpge",      token::OPCODE,    NONE,      opCMPGE  , new SyllableConstructor<ALU::CMPGE>() },
   {"cmpgeu",     token::OPCODE,    NONE,      opCMPGEU , new SyllableConstructor<ALU::CMPGEU>() },
   {"cmpgt",      token::OPCODE,    NONE,      opCMPGT  , new SyllableConstructor<ALU::CMPGT>() },
   {"cmpgtu",     token::OPCODE,    NONE,      opCMPGTU , new SyllableConstructor<ALU::CMPGTU>() },
   {"cmple",      token::OPCODE,    NONE,      opCMPLE  , new SyllableConstructor<ALU::CMPLE>() },
   {"cmpleu",     token::OPCODE,    NONE,      opCMPLEU , new SyllableConstructor<ALU::CMPLEU>() },
   {"cmplt",      token::OPCODE,    NONE,      opCMPLT  , new SyllableConstructor<ALU::CMPLT>() },
   {"cmpltu",     token::OPCODE,    NONE,      opCMPLTU , new SyllableConstructor<ALU::CMPLTU>() },
   {"cmpne",      token::OPCODE,    NONE,      opCMPNE  , new SyllableConstructor<ALU::CMPNE>() },
   {"max",        token::OPCODE,    NONE,      opMAX    , new SyllableConstructor<ALU::MAX>() },
   {"maxu",       token::OPCODE,    NONE,      opMAXU   , new SyllableConstructor<ALU::MAXU>() },
   {"min",        token::OPCODE,    NONE,      opMIN    , new SyllableConstructor<ALU::MIN>() },
   {"minu",       token::OPCODE,    NONE,      opMINU   , new SyllableConstructor<ALU::MIN>() },
   {"mpy",        token::OPCODE,    NONE,      opMUL    , new SyllableConstructor<MISC::NOP>() }, // checar se existe MUL/MPY
   {"mpyl",       token::OPCODE,    NONE,      opMULL   , new SyllableConstructor<MUL::MPYL>() },
   {"mpylu",      token::OPCODE,    NONE,      opMULLU  , new SyllableConstructor<MUL::MPYLU>() },
   {"mpyh",       token::OPCODE,    NONE,      opMULH   , new SyllableConstructor<MUL::MPYH>() },
   {"mpyhu",      token::OPCODE,    NONE,      opMULHU  , new SyllableConstructor<MUL::MPYHU>() },
   {"mpyhs",      token::OPCODE,    NONE,      opMULHS  , new SyllableConstructor<MUL::MPYHS>() },
   {"mpyll",      token::OPCODE,    NONE,      opMULLL  , new SyllableConstructor<MUL::MPYLL>() },
   {"mpyllu",     token::OPCODE,    NONE,      opMULLLU , new SyllableConstructor<MUL::MPYLLU>() },
   {"mpylh",      token::OPCODE,    NONE,      opMULLH  , new SyllableConstructor<MUL::MPYLH>() },
   {"mpylhu",     token::OPCODE,    NONE,      opMULLHU , new SyllableConstructor<MUL::MPYLHU>() },
   {"mpyhh",      token::OPCODE,    NONE,      opMULHH  , new SyllableConstructor<MUL::MPYHH>() },
   {"mpyhhu",     token::OPCODE,    NONE,      opMULHHU , new SyllableConstructor<MUL::MPYHHU>() },
   {"nandl",      token::OPCODE,    NONE,      opNANDL  , new SyllableConstructor<ALU::NANDL>() },
   {"nop",        token::OPCODE,    NONE,      opNOP    , new SyllableConstructor<MISC::NOP>() },
   {"norl",       token::OPCODE,    NONE,      opNORL   , new SyllableConstructor<ALU::NORL>() },
   {"or",         token::OPCODE,    NONE,      opOR     , new SyllableConstructor<ALU::OR>() },
   {"orc",        token::OPCODE,    NONE,      opORC    , new SyllableConstructor<ALU::ORC>() },
   {"orl",        token::OPCODE,    NONE,      opORL    , new SyllableConstructor<ALU::ORL>() },
   {"sbit",       token::OPCODE,    NONE,      opSBIT   , new SyllableConstructor<MISC::NOP>() }, // Checar
   {"sbitf",      token::OPCODE,    NONE,      opSBITF  , new SyllableConstructor<MISC::NOP>() }, // Checar
   {"sh1add",     token::OPCODE,    NONE,      opSH1ADD , new SyllableConstructor<ALU::SH1ADD>() },
   {"sh2add",     token::OPCODE,    NONE,      opSH2ADD , new SyllableConstructor<ALU::SH2ADD>() },
   {"sh3add",     token::OPCODE,    NONE,      opSH3ADD , new SyllableConstructor<ALU::SH3ADD>() },
   {"sh4add",     token::OPCODE,    NONE,      opSH4ADD , new SyllableConstructor<ALU::SH4ADD>() },
   {"shl",        token::OPCODE,    NONE,      opSHL    , new SyllableConstructor<ALU::SHL>() },
   {"shr",        token::OPCODE,    NONE,      opSHR    , new SyllableConstructor<ALU::SHR>() },
   {"shru",       token::OPCODE,    NONE,      opSHRU   , new SyllableConstructor<ALU::SHRU>() },
   {"slct",       token::OPCODE,    NONE,      opSLCT   , new SyllableConstructor<ALU::SLCT>() },
   {"slctf",      token::OPCODE,    NONE,      opSLCTF  , new SyllableConstructor<ALU::SLCTF>() },
   {"sub",        token::OPCODE,    NONE,      opSUB    , new SyllableConstructor<ALU::SUB>() },
   {"sxtb",       token::OPCODE,    NONE,      opSXTB   , new SyllableConstructor<ALU::SXTB>() },
   {"sxth",       token::OPCODE,    NONE,      opSXTH   , new SyllableConstructor<ALU::SXTH>() },
   {"tbit",       token::OPCODE,    NONE,      opTBIT   , new SyllableConstructor<MISC::NOP>() }, // Checar
   {"tbitf",      token::OPCODE,    NONE,      opTBITF  , new SyllableConstructor<MISC::NOP>() }, // Checar
   {"xor",        token::OPCODE,    NONE,      opXOR    , new SyllableConstructor<ALU::XOR>() },
   {"zxtb",       token::OPCODE,    NONE,      opZXTB   , new SyllableConstructor<ALU::ZXTB>() },
   {"zxth",       token::OPCODE,    NONE,      opZXTH   , new SyllableConstructor<ALU::ZXTH>() },

/* DIV/CARRY */
   {"divs",       token::OPCODE,    NONE,      opDIVS   , new SyllableConstructor<ALU::DIVS>() },
   {"addcg",      token::OPCODE,    NONE,      opADDCG  , new SyllableConstructor<ALU::ADDCG>() },

/* MOV */
   {"mov",	  token::OPCODE,    NONE,         opMOV        , new SyllableConstructor<ALU::MOV>()  },
   {"mfl",	  token::OPCODE,    NONE,         opMFL        , new SyllableConstructor<MISC::NOP>()  },
   {"mtl",	  token::OPCODE,    NONE,         opMTL        , new SyllableConstructor<MISC::NOP>()  },
   {"mfb",	  token::OPCODE,    NONE,         opMFB        , new SyllableConstructor<MISC::NOP>()  },
   {"mtb",	  token::OPCODE,    NONE,         opMTB        , new SyllableConstructor<ALU::MTB>()  },
   {"mtbf",	  token::OPCODE,    NONE,         opMTBINV     , new SyllableConstructor<MISC::NOP>()  },

/* BRANCH */
   {"goto",       token::OPCODE,    CTLFLOW,   opGOTO      , new SyllableConstructor<CTRL::GOTO>()  },
   {"call",       token::OPCODE,    CTLFLOW,   opCALL      , new SyllableConstructor<CTRL::CALL>()  },
   {"return",     token::OPCODE,    CTLFLOW,   opRETURN    , new SyllableConstructor<CTRL::RETURN>()  },
   {"br",         token::OPCODE,    CTLFLOW,   opBRANCH    , new SyllableConstructor<CTRL::BR>()  },
   {"brf",        token::OPCODE,    CTLFLOW,   opBRANCHF   , new SyllableConstructor<CTRL::BRF>()  },

/* ASM */
   {"asm",        token::OPCODE,    NONE,         opASM    , new SyllableConstructor<MISC::NOP>()  },

/* XNOP */
   {"xnop",       token::XNOP,      NONE,         opXNOP   , new SyllableConstructor<CTRL::XNOP>()  },

/**************** PSEUDO  OPCODES *************************/

   {".call",      token::_CALL_JMP,  NONE,        opCALLDIR },
   {".longjmp",   token::_CALL_JMP,  NONE,        opLONGJMPDIR },
   {"._longjmp",  token::_CALL_JMP,  NONE,        opLONGJMPDIR },
   {".__longjmp", token::_CALL_JMP,  NONE,        opLONGJMPDIR },
   {".setjmp",    token::_CALL_JMP,  NONE,        opSETJMPDIR },
   {"._setjmp",   token::_CALL_JMP,  NONE,        opSETJMPDIR },
   {".__setjmp",  token::_CALL_JMP,  NONE,        opSETJMPDIR },

/*************  ASSEMBLER DIRECTIVES **********************/

   {".align",      token::_ALIGN,    NONE,         opASMDIR },
   {".ascii",      token::_ASCII,    NONE,         opASMDIR },
   {".bss",        token::_BSS,      NONE,         opASMDIR },
   {".section",    token::_SECTION,  NONE,         opASMDIR },
   {".comment",    token::_COMMENT,  NONE,         opASMDIR },
   {".comm",       token::_COMMON,   NONE,         opASMDIR },
   {".data",       token::_DATA,     NONE,         opASMDIR },
   {".data1",      token::_DATA1,    NONE,         opASMDIR },
   {".data2",      token::_DATA2,    NONE,         opASMDIR },
   {".data4",      token::_DATA4,    NONE,         opASMDIR },
   {".endp",       token::_ENDP,     NONE,         opASMDIR },
   {".entry",      token::_ENTRY,    NONE,         opASMDIR },
   {".equ",        token::_EQU,      NONE,         opASMDIR },
   {".import",     token::_IMPORT,   NONE,         opASMDIR },
   {".proc",       token::_PROC,     NONE,         opASMDIR },
   {".real4",      token::_REAL4,    NONE,         opASMDIR },
   {".real8",      token::_REAL8,    NONE,         opASMDIR },
   {".return",     token::_RETURN,   NONE,         opASMDIR },
   {".rta",        token::_RTA,      NONE,         opASMDIR },
   {".skip",       token::_SKIP,     NONE,         opASMDIR },
   {".sversion",   token::_SVERSION, NONE,         opASMDIR },
   {".text",       token::_TEXT,     NONE,         opASMDIR },
   {".trace",      token::_TRACE,    NONE,         opASMDIR },
   {".type",       token::_TYPE,     NONE,         opASMDIR },
   
/*************  Operators **********************/

   {"+",       token::__PLUS,       NONE,         opNONE },
   {"-",       token::__MINUS,      NONE,         opNONE },
   {"~",       token::__NOT,        NONE,         opNONE },
   {",",       token::__COMMA,      NONE,         opNONE },
   {":",       token::__COLON,      NONE,         opNONE },
   {";",       token::__SEMICOLON,  NONE,         opNONE },
   {"(",       token::__LPAREN,     NONE,         opNONE },
   {")",       token::__RPAREN,     NONE,         opNONE },
   {"[",       token::__LBRACKET,   NONE,         opNONE },
   {"]",       token::__RBRACKET,   NONE,         opNONE },
   {"=",       token::__EQUAL,      NONE,         opNONE },
   {"@",       token::__AT,         NONE,         opNONE }
};

/* Operation table used in parsing of asm file */
std::vector<VexOpcode> 
  operationTable (_optab, _optab + sizeof(_optab) / sizeof(_optab[0]));

#endif
