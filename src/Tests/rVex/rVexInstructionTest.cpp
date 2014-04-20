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
#include <vector>

#include "rVex/rVex.h"
#include "gtest/gtest.h"

namespace InstructionTest
{
  TEST(InstructionTest, AddSyllable)
  {
    rVex::Base::Instruction instruction;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    rVex::Operations::ALU::ANDC ANDC;
    rVex::Operations::ALU::MAX MAX;
    rVex::Operations::ALU::MAXU MAXU;
    rVex::Operations::ALU::MIN MIN;
    rVex::Operations::ALU::MINU MINU;
    rVex::Operations::ALU::OR OR;
    rVex::Operations::ALU::ORC ORC;
    rVex::Operations::ALU::SH1ADD SH1ADD;
    rVex::Operations::ALU::SH2ADD SH2ADD;
    rVex::Operations::ALU::SH3ADD SH3ADD;
    rVex::Operations::ALU::SH4ADD SH4ADD;
    rVex::Operations::ALU::SHL SHL;
    rVex::Operations::ALU::SHR SHR;
    rVex::Operations::ALU::SHRU SHRU;
    rVex::Operations::ALU::SUB SUB;
    rVex::Operations::ALU::SXTB SXTB;
    rVex::Operations::ALU::SXTH SXTH;
    rVex::Operations::ALU::ZXTB ZXTB;
    rVex::Operations::ALU::ZXTH ZXTH;
    rVex::Operations::ALU::XOR XOR;
    rVex::Operations::ALU::MOV MOV;
    rVex::Operations::ALU::CMPEQ CMPEQ;
    rVex::Operations::ALU::CMPGE CMPGE;
    rVex::Operations::ALU::CMPGEU CMPGEU;
    rVex::Operations::ALU::CMPGT CMPGT;
    rVex::Operations::ALU::CMPGTU CMPGTU;
    rVex::Operations::ALU::CMPLE CMPLE;
    rVex::Operations::ALU::CMPLEU CMPLEU;
    rVex::Operations::ALU::CMPLT CMPLT;
    rVex::Operations::ALU::CMPLTU CMPLTU;
    rVex::Operations::ALU::CMPNE CMPNE;
    rVex::Operations::ALU::NANDL NANDL;
    rVex::Operations::ALU::NORL NORL;
    rVex::Operations::ALU::ORL ORL;
    rVex::Operations::ALU::MTB MTB;
    rVex::Operations::ALU::ANDL ANDL;
    rVex::Operations::ALU::ADDCG ADDCG;
    rVex::Operations::ALU::DIVS DIVS;
    rVex::Operations::ALU::SLCT SLCT;
    rVex::Operations::ALU::SLCTF SLCTF;

    ASSERT_EQ(0, instruction.getSyllables().size());

    instruction.addSyllable(ADD);

    ASSERT_EQ(1, instruction.getSyllables().size());

    instruction.addSyllable(AND);

    ASSERT_EQ(2, instruction.getSyllables().size());
    
    instruction.addSyllable(ANDC);

    ASSERT_EQ(3, instruction.getSyllables().size());
    
    instruction.addSyllable(MAX);

    ASSERT_EQ(4, instruction.getSyllables().size());
    
    instruction.addSyllable(MAXU);

    ASSERT_EQ(5, instruction.getSyllables().size());
    
    instruction.addSyllable(MIN);

    ASSERT_EQ(6, instruction.getSyllables().size());
    
    instruction.addSyllable(MINU);

    ASSERT_EQ(7, instruction.getSyllables().size());
    
    instruction.addSyllable(OR);

    ASSERT_EQ(8, instruction.getSyllables().size());
    
    instruction.addSyllable(ORC);

    ASSERT_EQ(9, instruction.getSyllables().size());
    
    instruction.addSyllable(SH1ADD);

    ASSERT_EQ(10, instruction.getSyllables().size());
    
    instruction.addSyllable(SH2ADD);

    ASSERT_EQ(11, instruction.getSyllables().size());
    
    instruction.addSyllable(SH3ADD);

    ASSERT_EQ(12, instruction.getSyllables().size());
    
    instruction.addSyllable(SH4ADD);

    ASSERT_EQ(13, instruction.getSyllables().size());
    
    instruction.addSyllable(SHL);

    ASSERT_EQ(14, instruction.getSyllables().size());
    
    instruction.addSyllable(SHR);

    ASSERT_EQ(15, instruction.getSyllables().size());
    
    instruction.addSyllable(SHRU);

    ASSERT_EQ(16, instruction.getSyllables().size());
    
    instruction.addSyllable(SUB);

    ASSERT_EQ(17, instruction.getSyllables().size());
    
    instruction.addSyllable(SXTB);

    ASSERT_EQ(18, instruction.getSyllables().size());
    
    instruction.addSyllable(SXTH);

    ASSERT_EQ(19, instruction.getSyllables().size());
    
    instruction.addSyllable(ZXTB);

    ASSERT_EQ(20, instruction.getSyllables().size());
    
    instruction.addSyllable(ZXTH);

    ASSERT_EQ(21, instruction.getSyllables().size());
    
    instruction.addSyllable(XOR);

    ASSERT_EQ(22, instruction.getSyllables().size());
    
    instruction.addSyllable(MOV);

    ASSERT_EQ(23, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPEQ);

    ASSERT_EQ(24, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPGE);

    ASSERT_EQ(25, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPGEU);

    ASSERT_EQ(26, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPGT);

    ASSERT_EQ(27, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPGTU);

    ASSERT_EQ(28, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPLE);

    ASSERT_EQ(29, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPLEU);

    ASSERT_EQ(30, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPLT);

    ASSERT_EQ(31, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPLTU);

    ASSERT_EQ(32, instruction.getSyllables().size());
    
    instruction.addSyllable(CMPNE);

    ASSERT_EQ(33, instruction.getSyllables().size());
    
    instruction.addSyllable(NANDL);

    ASSERT_EQ(34, instruction.getSyllables().size());
    
    instruction.addSyllable(NORL);

    ASSERT_EQ(35, instruction.getSyllables().size());
    
    instruction.addSyllable(ORL);

    ASSERT_EQ(36, instruction.getSyllables().size());
    
    instruction.addSyllable(MTB);

    ASSERT_EQ(37, instruction.getSyllables().size());
    
    instruction.addSyllable(ANDL);

    ASSERT_EQ(38, instruction.getSyllables().size());
    
    instruction.addSyllable(ADDCG);

    ASSERT_EQ(39, instruction.getSyllables().size());
    
    instruction.addSyllable(DIVS);

    ASSERT_EQ(40, instruction.getSyllables().size());
    
    instruction.addSyllable(SLCT);

    ASSERT_EQ(41, instruction.getSyllables().size());
    
    instruction.addSyllable(SLCTF);

    ASSERT_EQ(42, instruction.getSyllables().size());
  }

  TEST(InstructionTest, RemoveSyllable)
  {
    rVex::Base::Instruction instruction;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    rVex::Operations::ALU::ANDC ANDC;
    rVex::Operations::ALU::MAX MAX;
    rVex::Operations::ALU::MAXU MAXU;
    rVex::Operations::ALU::MIN MIN;
    rVex::Operations::ALU::MINU MINU;
    rVex::Operations::ALU::OR OR;
    rVex::Operations::ALU::ORC ORC;
    rVex::Operations::ALU::SH1ADD SH1ADD;
    rVex::Operations::ALU::SH2ADD SH2ADD;
    rVex::Operations::ALU::SH3ADD SH3ADD;
    rVex::Operations::ALU::SH4ADD SH4ADD;
    rVex::Operations::ALU::SHL SHL;
    rVex::Operations::ALU::SHR SHR;
    rVex::Operations::ALU::SHRU SHRU;
    rVex::Operations::ALU::SUB SUB;
    rVex::Operations::ALU::SXTB SXTB;
    rVex::Operations::ALU::SXTH SXTH;
    rVex::Operations::ALU::ZXTB ZXTB;
    rVex::Operations::ALU::ZXTH ZXTH;
    rVex::Operations::ALU::XOR XOR;
    rVex::Operations::ALU::MOV MOV;
    rVex::Operations::ALU::CMPEQ CMPEQ;
    rVex::Operations::ALU::CMPGE CMPGE;
    rVex::Operations::ALU::CMPGEU CMPGEU;
    rVex::Operations::ALU::CMPGT CMPGT;
    rVex::Operations::ALU::CMPGTU CMPGTU;
    rVex::Operations::ALU::CMPLE CMPLE;
    rVex::Operations::ALU::CMPLEU CMPLEU;
    rVex::Operations::ALU::CMPLT CMPLT;
    rVex::Operations::ALU::CMPLTU CMPLTU;
    rVex::Operations::ALU::CMPNE CMPNE;
    rVex::Operations::ALU::NANDL NANDL;
    rVex::Operations::ALU::NORL NORL;
    rVex::Operations::ALU::ORL ORL;
    rVex::Operations::ALU::MTB MTB;
    rVex::Operations::ALU::ANDL ANDL;
    rVex::Operations::ALU::ADDCG ADDCG;
    rVex::Operations::ALU::DIVS DIVS;
    rVex::Operations::ALU::SLCT SLCT;
    rVex::Operations::ALU::SLCTF SLCTF;

    instruction.addSyllable(ADD);
    instruction.addSyllable(AND);
    instruction.addSyllable(ANDC);
    instruction.addSyllable(MAX);
    instruction.addSyllable(MAXU);
    instruction.addSyllable(MIN);
    instruction.addSyllable(MINU);
    instruction.addSyllable(OR);
    instruction.addSyllable(ORC);
    instruction.addSyllable(SH1ADD);
    instruction.addSyllable(SH2ADD);
    instruction.addSyllable(SH3ADD);
    instruction.addSyllable(SH4ADD);
    instruction.addSyllable(SHL);
    instruction.addSyllable(SHR);
    instruction.addSyllable(SHRU);
    instruction.addSyllable(SUB);
    instruction.addSyllable(SXTB);
    instruction.addSyllable(SXTH);
    instruction.addSyllable(ZXTB);
    instruction.addSyllable(ZXTH);
    instruction.addSyllable(XOR);
    instruction.addSyllable(MOV);
    instruction.addSyllable(CMPEQ);
    instruction.addSyllable(CMPGE);
    instruction.addSyllable(CMPGEU);
    instruction.addSyllable(CMPGT);
    instruction.addSyllable(CMPGTU);
    instruction.addSyllable(CMPLE);
    instruction.addSyllable(CMPLEU);
    instruction.addSyllable(CMPLT);
    instruction.addSyllable(CMPLTU);
    instruction.addSyllable(CMPNE);
    instruction.addSyllable(NANDL);
    instruction.addSyllable(NORL);
    instruction.addSyllable(ORL);
    instruction.addSyllable(MTB);
    instruction.addSyllable(ANDL);
    instruction.addSyllable(ADDCG);
    instruction.addSyllable(DIVS);
    instruction.addSyllable(SLCT);
    instruction.addSyllable(SLCTF);

    ASSERT_EQ(42, instruction.getSyllables().size());

    instruction.removeSyllable(ADD);

    ASSERT_EQ(41, instruction.getSyllables().size());

    instruction.removeSyllable(AND);

    ASSERT_EQ(40, instruction.getSyllables().size());
    
    instruction.removeSyllable(ANDC);

    ASSERT_EQ(39, instruction.getSyllables().size());
    
    instruction.removeSyllable(MAX);

    ASSERT_EQ(38, instruction.getSyllables().size());
    
    instruction.removeSyllable(MAXU);

    ASSERT_EQ(37, instruction.getSyllables().size());
    
    instruction.removeSyllable(MIN);

    ASSERT_EQ(36, instruction.getSyllables().size());
    
    instruction.removeSyllable(MINU);

    ASSERT_EQ(35, instruction.getSyllables().size());
    
    instruction.removeSyllable(OR);

    ASSERT_EQ(34, instruction.getSyllables().size());
    
    instruction.removeSyllable(ORC);

    ASSERT_EQ(33, instruction.getSyllables().size());
    
    instruction.removeSyllable(SH1ADD);

    ASSERT_EQ(32, instruction.getSyllables().size());
    
    instruction.removeSyllable(SH2ADD);

    ASSERT_EQ(31, instruction.getSyllables().size());
    
    instruction.removeSyllable(SH3ADD);

    ASSERT_EQ(30, instruction.getSyllables().size());
    
    instruction.removeSyllable(SH4ADD);

    ASSERT_EQ(29, instruction.getSyllables().size());
    
    instruction.removeSyllable(SHL);

    ASSERT_EQ(28, instruction.getSyllables().size());
    
    instruction.removeSyllable(SHR);

    ASSERT_EQ(27, instruction.getSyllables().size());
    
    instruction.removeSyllable(SHRU);

    ASSERT_EQ(26, instruction.getSyllables().size());
    
    instruction.removeSyllable(SUB);

    ASSERT_EQ(25, instruction.getSyllables().size());
    
    instruction.removeSyllable(SXTB);

    ASSERT_EQ(24, instruction.getSyllables().size());
    
    instruction.removeSyllable(SXTH);

    ASSERT_EQ(23, instruction.getSyllables().size());
  
    instruction.removeSyllable(ZXTB);

    ASSERT_EQ(22, instruction.getSyllables().size());
    
    instruction.removeSyllable(ZXTH);

    ASSERT_EQ(21, instruction.getSyllables().size());
    
    instruction.removeSyllable(XOR);

    ASSERT_EQ(20, instruction.getSyllables().size());
    
    instruction.removeSyllable(MOV);

    ASSERT_EQ(19, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPEQ);

    ASSERT_EQ(18, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPGE);

    ASSERT_EQ(17, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPGEU);

    ASSERT_EQ(16, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPGT);

    ASSERT_EQ(15, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPGTU);

    ASSERT_EQ(14, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPLE);

    ASSERT_EQ(13, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPLEU);

    ASSERT_EQ(12, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPLT);

    ASSERT_EQ(11, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPLTU);

    ASSERT_EQ(10, instruction.getSyllables().size());
    
    instruction.removeSyllable(CMPNE);

    ASSERT_EQ(9, instruction.getSyllables().size());
    
    instruction.removeSyllable(NANDL);

    ASSERT_EQ(8, instruction.getSyllables().size());
    
    instruction.removeSyllable(NORL);

    ASSERT_EQ(7, instruction.getSyllables().size());
    
    instruction.removeSyllable(ORL);

    ASSERT_EQ(6, instruction.getSyllables().size());
    
    instruction.removeSyllable(MTB);

    ASSERT_EQ(5, instruction.getSyllables().size());
    
    instruction.removeSyllable(ANDL);

    ASSERT_EQ(4, instruction.getSyllables().size());
    
    instruction.removeSyllable(ADDCG);

    ASSERT_EQ(3, instruction.getSyllables().size());
    
    instruction.removeSyllable(DIVS);

    ASSERT_EQ(2, instruction.getSyllables().size());
    
    instruction.removeSyllable(SLCT);

    ASSERT_EQ(1, instruction.getSyllables().size());
    
    instruction.removeSyllable(SLCTF);

    ASSERT_EQ(0, instruction.getSyllables().size());
  }
  
  TEST(InstructionTest, GetSyllables)
  {
    rVex::Base::Instruction instruction;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    rVex::Operations::ALU::ANDC ANDC;
    rVex::Operations::ALU::MAX MAX;
    rVex::Operations::ALU::MAXU MAXU;
    rVex::Operations::ALU::MIN MIN;
    rVex::Operations::ALU::MINU MINU;
    rVex::Operations::ALU::OR OR;
    rVex::Operations::ALU::ORC ORC;
    rVex::Operations::ALU::SH1ADD SH1ADD;
    rVex::Operations::ALU::SH2ADD SH2ADD;
    rVex::Operations::ALU::SH3ADD SH3ADD;
    rVex::Operations::ALU::SH4ADD SH4ADD;
    rVex::Operations::ALU::SHL SHL;
    rVex::Operations::ALU::SHR SHR;
    rVex::Operations::ALU::SHRU SHRU;
    rVex::Operations::ALU::SUB SUB;
    rVex::Operations::ALU::SXTB SXTB;
    rVex::Operations::ALU::SXTH SXTH;
    rVex::Operations::ALU::ZXTB ZXTB;
    rVex::Operations::ALU::ZXTH ZXTH;
    rVex::Operations::ALU::XOR XOR;
    rVex::Operations::ALU::MOV MOV;
    rVex::Operations::ALU::CMPEQ CMPEQ;
    rVex::Operations::ALU::CMPGE CMPGE;
    rVex::Operations::ALU::CMPGEU CMPGEU;
    rVex::Operations::ALU::CMPGT CMPGT;
    rVex::Operations::ALU::CMPGTU CMPGTU;
    rVex::Operations::ALU::CMPLE CMPLE;
    rVex::Operations::ALU::CMPLEU CMPLEU;
    rVex::Operations::ALU::CMPLT CMPLT;
    rVex::Operations::ALU::CMPLTU CMPLTU;
    rVex::Operations::ALU::CMPNE CMPNE;
    rVex::Operations::ALU::NANDL NANDL;
    rVex::Operations::ALU::NORL NORL;
    rVex::Operations::ALU::ORL ORL;
    rVex::Operations::ALU::MTB MTB;
    rVex::Operations::ALU::ANDL ANDL;
    rVex::Operations::ALU::ADDCG ADDCG;
    rVex::Operations::ALU::DIVS DIVS;
    rVex::Operations::ALU::SLCT SLCT;
    rVex::Operations::ALU::SLCTF SLCTF;
    std::vector<rVex::Base::Syllable*> other;
    
    other.push_back(&ADD);
    other.push_back(&AND);
    other.push_back(&ANDC);
    other.push_back(&MAX);
    other.push_back(&MAXU);
    other.push_back(&MIN);
    other.push_back(&MINU);
    other.push_back(&OR);
    other.push_back(&ORC);
    other.push_back(&SH1ADD);
    other.push_back(&SH2ADD);
    other.push_back(&SH3ADD);
    other.push_back(&SH4ADD);
    other.push_back(&SHL);
    other.push_back(&SHR);
    other.push_back(&SHRU);
    other.push_back(&SUB);
    other.push_back(&SXTB);
    other.push_back(&SXTH);
    other.push_back(&ZXTB);
    other.push_back(&ZXTH);
    other.push_back(&XOR);
    other.push_back(&MOV);
    other.push_back(&CMPEQ);
    other.push_back(&CMPGE);
    other.push_back(&CMPGEU);
    other.push_back(&CMPGT);
    other.push_back(&CMPGTU);
    other.push_back(&CMPLE);
    other.push_back(&CMPLEU);
    other.push_back(&CMPLT);
    other.push_back(&CMPLTU);
    other.push_back(&CMPNE);
    other.push_back(&NANDL);
    other.push_back(&NORL);
    other.push_back(&ORL);
    other.push_back(&MTB);
    other.push_back(&ANDL);
    other.push_back(&ADDCG);
    other.push_back(&DIVS);
    other.push_back(&SLCT);
    other.push_back(&SLCTF);
    
    instruction.addSyllable(ADD);
    instruction.addSyllable(AND);
    instruction.addSyllable(ANDC);
    instruction.addSyllable(MAX);
    instruction.addSyllable(MAXU);
    instruction.addSyllable(MIN);
    instruction.addSyllable(MINU);
    instruction.addSyllable(OR);
    instruction.addSyllable(ORC);
    instruction.addSyllable(SH1ADD);
    instruction.addSyllable(SH2ADD);
    instruction.addSyllable(SH3ADD);
    instruction.addSyllable(SH4ADD);
    instruction.addSyllable(SHL);
    instruction.addSyllable(SHR);
    instruction.addSyllable(SHRU);
    instruction.addSyllable(SUB);
    instruction.addSyllable(SXTB);
    instruction.addSyllable(SXTH);
    instruction.addSyllable(ZXTB);
    instruction.addSyllable(ZXTH);
    instruction.addSyllable(XOR);
    instruction.addSyllable(MOV);
    instruction.addSyllable(CMPEQ);
    instruction.addSyllable(CMPGE);
    instruction.addSyllable(CMPGEU);
    instruction.addSyllable(CMPGT);
    instruction.addSyllable(CMPGTU);
    instruction.addSyllable(CMPLE);
    instruction.addSyllable(CMPLEU);
    instruction.addSyllable(CMPLT);
    instruction.addSyllable(CMPLTU);
    instruction.addSyllable(CMPNE);
    instruction.addSyllable(NANDL);
    instruction.addSyllable(NORL);
    instruction.addSyllable(ORL);
    instruction.addSyllable(MTB);
    instruction.addSyllable(ANDL);
    instruction.addSyllable(ADDCG);
    instruction.addSyllable(DIVS);
    instruction.addSyllable(SLCT);
    instruction.addSyllable(SLCTF);
    
    ASSERT_EQ(other, instruction.getSyllables());
  }
}