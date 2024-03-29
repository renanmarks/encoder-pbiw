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
/* 
 * File:   Operations.h
 * Author: helix
 *
 * Created on August 21, 2011, 8:31 PM
 */

#ifndef RVEX_OPERATIONS_H
#define	RVEX_OPERATIONS_H

#include "ALU/ADD.h"
#include "ALU/AND.h"
#include "ALU/ANDC.h"
#include "ALU/MAX.h"
#include "ALU/MAXU.h"
#include "ALU/MIN.h"
#include "ALU/MINU.h"
#include "ALU/OR.h"
#include "ALU/ORC.h"
#include "ALU/SH1ADD.h"
#include "ALU/SH2ADD.h"
#include "ALU/SH3ADD.h"
#include "ALU/SH4ADD.h"
#include "ALU/SHL.h"
#include "ALU/SHR.h"
#include "ALU/SHRU.h"
#include "ALU/SUB.h"
#include "ALU/SXTB.h"
#include "ALU/SXTH.h"
#include "ALU/ZXTB.h"
#include "ALU/ZXTH.h"
#include "ALU/XOR.h"
#include "ALU/MOV.h"
#include "ALU/CMPEQ.h"
#include "ALU/CMPGE.h"
#include "ALU/CMPGEU.h"
#include "ALU/CMPGT.h"
#include "ALU/CMPGTU.h"
#include "ALU/CMPLE.h"
#include "ALU/CMPLEU.h"
#include "ALU/CMPLT.h"
#include "ALU/CMPLTU.h"
#include "ALU/CMPNE.h"
#include "ALU/NANDL.h"
#include "ALU/NORL.h"
#include "ALU/ORL.h"
#include "ALU/MTB.h"
#include "ALU/ANDL.h"
#include "ALU/ADDCG.h"
#include "ALU/DIVS.h"
#include "ALU/SLCT.h"
#include "ALU/SLCTF.h"

#include "MUL/MPYLL.h"
#include "MUL/MPYLLU.h"
#include "MUL/MPYLH.h"
#include "MUL/MPYLHU.h"
#include "MUL/MPYHH.h"
#include "MUL/MPYHHU.h"
#include "MUL/MPYL.h"
#include "MUL/MPYLU.h"
#include "MUL/MPYH.h"
#include "MUL/MPYHU.h"
#include "MUL/MPYHS.h"

#include "CTRL/GOTO.h"
#include "CTRL/IGOTO.h"
#include "CTRL/CALL.h"
#include "CTRL/ICALL.h"
#include "CTRL/BR.h"
#include "CTRL/BRF.h"
#include "CTRL/RETURN.h"
#include "CTRL/RFI.h"
#include "CTRL/XNOP.h"

#include "MEM/LDW.h"
#include "MEM/LDH.h"
#include "MEM/LDHU.h"
#include "MEM/LDB.h"
#include "MEM/LDBU.h"
#include "MEM/STW.h"
#include "MEM/STH.h"
#include "MEM/STB.h"
#include "MEM/PFT.h"

#include "MISC/STOP.h"
#include "MISC/NOP.h"
#include "MISC/SEND.h"
#include "MISC/RECV.h"

#endif	/* OPERATIONS_H */

