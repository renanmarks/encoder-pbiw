/************************************************************************
 * PBIW Software Insfrastructure
 * Copyright (C) 2013 Renan Albuquerque Marks
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************/
/**
*** Copyright (C) 1994 - 2002 Hewlett-Packard Company.
***
*** The information and source code contained herein is the exclusive
*** property of Hewlett-Packard Company and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
**/

/**
*** Author: Paolo Faraboschi
**/

/**
*** static char sccs_id[] = "$Id: vextypes.h,v 1.2 2002/08/06 18:45:05 frb Exp $";
**/

/**
*** Definition of VEX Opcodes
**/

#ifndef __MACHINE_INCLUDED__
#define __MACHINE_INCLUDED__

#include <string>
#include <vector>

#include "parser.tab.hh"
#include "rVex/Syllable.h"

typedef VexParser::Parser::token token;
typedef VexParser::Parser::token_type token_type;

/**
 * Custom structs that are used in VexParser (C++ Version)
 */
namespace VexParser 
{
  /**
   * Types of tokens. Originally by HP
   */
  typedef enum {
    opASM, 
    opADD,
    opADDCG, 
    opAND, 
    opANDC, 
    opANDL, 
    opASMDIR,
    opBRANCH,  
    opBRANCHF,  
    opCALL, 
    opCALLDIR, 
    opCMPEQ, 
    opCMPGE, 
    opCMPGEU, 
    opCMPGT,
    opCMPGTU, 
    opCMPLE, 
    opCMPLEU, 
    opCMPLT, 
    opCMPLTU, 
    opCMPNE, 
    opDIVS,
    opGOTO, 
    opLDB, 
    opLDBU, 
    opLDH, 
    opLDHU, 
    opLDW, 
    opLONGJMPDIR,
    opMAX , 
    opMAXU ,
    opMFB, 
    opMFL, 
    opMIN, 
    opMINU, 
    opMOV, 
    opMTB, 
    opMTBINV, 
    opMTL, 
    opMUL,
    opMULL,
    opMULLU,
    opMULH,
    opMULHU,
    opMULHS,
    opMULLL,
    opMULLLU,
    opMULLH,
    opMULLHU,
    opMULHH,
    opMULHHU,
    opNANDL, 
    opNOP,
    opNORL,
    opOR,
    opORC,
    opORL,
    opPFT,
    opRETURN,
    opSBIT,
    opSBITF,
    opSETJMPDIR,
    opSH1ADD,
    opSH2ADD,
    opSH3ADD,
    opSH4ADD,
    opSHL,
    opSHR,
    opSHRU,
    opSLCT,
    opSLCTF,
    opSTB,
    opSTH,
    opSTW,
    opSUB,
    opSXTB,
    opSXTH,
    opTBIT,
    opTBITF,
    opXNOP,
    opXOR,
    opZXTB,
    opZXTH,
    opNONE = 0
  } VEX_tok;

  /**
   * Types of operation's flags. Originally by HP
   */
  typedef enum {
         NONE = 0,
         SPEC = 1,
         LOCK = 2,
         STREAM = 4,
         CTLFLOW = 8,
         SSPEC = (SPEC | STREAM),
         LSPEC = (SPEC | LOCK),
  } VEX_flags;
  
  /**
   * Pure base class used to construct Vex syllables at parsing.
   */
  struct OperationConstructor {
    virtual ~OperationConstructor() {}
    
    virtual rVex::Syllable* create( void ) const = 0;
    
    virtual rVex::Syllable* operator()( void ) const {
      return create();
    }
  };
  
  /**
   * Generic class used to create Vex syllables to populate the auxiliary
   * parse table.
   */
  template < class T >
  struct SyllableConstructor : public OperationConstructor
  {
    virtual ~SyllableConstructor() { }
    
    virtual rVex::Syllable* create( void ) const {
      return ( new T () );
    }  
  };
  
  /**
   * Vex Opcode table item
   */
  struct VexOpcode
  {
      std::string as_op;                 /* opcode string      */
      token_type tok;                    /* yacc token         */
      VEX_flags flags;                   /* flags (e.g. SPEC)  */
      VEX_tok op;                        /* operation type     */
      OperationConstructor* syllableConstructor;  /* constructor of syllables */
  };

  /**
   * Vex function definition
   */
  struct VexFunction 
  {
      std::string str;
      int scope;
  };
}

/* Operation table used in parsing of asm file */
extern std::vector<VexParser::VexOpcode> operationTable;

#endif

