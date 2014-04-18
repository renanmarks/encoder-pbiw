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

namespace InstructionMulTest
{
  TEST(InstructionMulTest, AddSyllable)
  {
    rVex::Instruction instruction;
    rVex::Operations::MUL::MPYLL MPYLL;
    rVex::Operations::MUL::MPYLLU MPYLLU;
    rVex::Operations::MUL::MPYLH MPYLH;
    rVex::Operations::MUL::MPYLHU MPYLHU;
    rVex::Operations::MUL::MPYHH MPYHH;
    rVex::Operations::MUL::MPYHHU MPYHHU;
    rVex::Operations::MUL::MPYL MPYL;
    rVex::Operations::MUL::MPYLU MPYLU;
    rVex::Operations::MUL::MPYH MPYH;
    rVex::Operations::MUL::MPYHU MPYHU;
    rVex::Operations::MUL::MPYHS MPYHS;

    ASSERT_EQ(0, instruction.getSyllables().size());

    instruction.addSyllable(MPYLL);

    ASSERT_EQ(1, instruction.getSyllables().size());

    instruction.addSyllable(MPYLLU);

    ASSERT_EQ(2, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYLH);

    ASSERT_EQ(3, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYLHU);

    ASSERT_EQ(4, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYHH);

    ASSERT_EQ(5, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYHHU);

    ASSERT_EQ(6, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYL);

    ASSERT_EQ(7, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYLU);

    ASSERT_EQ(8, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYH);

    ASSERT_EQ(9, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYHU);

    ASSERT_EQ(10, instruction.getSyllables().size());
    
    instruction.addSyllable(MPYHS);

    ASSERT_EQ(11, instruction.getSyllables().size());

  }

  TEST(InstructionMulTest, RemoveSyllable)
  {
    rVex::Instruction instruction;
    rVex::Operations::MUL::MPYLL MPYLL;
    rVex::Operations::MUL::MPYLLU MPYLLU;
    rVex::Operations::MUL::MPYLH MPYLH;
    rVex::Operations::MUL::MPYLHU MPYLHU;
    rVex::Operations::MUL::MPYHH MPYHH;
    rVex::Operations::MUL::MPYHHU MPYHHU;
    rVex::Operations::MUL::MPYL MPYL;
    rVex::Operations::MUL::MPYLU MPYLU;
    rVex::Operations::MUL::MPYH MPYH;
    rVex::Operations::MUL::MPYHU MPYHU;
    rVex::Operations::MUL::MPYHS MPYHS;

    instruction.addSyllable(MPYLL);
    instruction.addSyllable(MPYLLU);
    instruction.addSyllable(MPYLH);
    instruction.addSyllable(MPYLHU);
    instruction.addSyllable(MPYHH);
    instruction.addSyllable(MPYHHU);
    instruction.addSyllable(MPYL);
    instruction.addSyllable(MPYLU);
    instruction.addSyllable(MPYH);
    instruction.addSyllable(MPYHU);
    instruction.addSyllable(MPYHS);


    ASSERT_EQ(11, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYLL);

    ASSERT_EQ(10, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYLLU);

    ASSERT_EQ(9, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYLH);

    ASSERT_EQ(8, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYLHU);

    ASSERT_EQ(7, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYHH);

    ASSERT_EQ(6, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYHHU);

    ASSERT_EQ(5, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYL);

    ASSERT_EQ(4, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYLU);

    ASSERT_EQ(3, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYH);

    ASSERT_EQ(2, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYHU);

    ASSERT_EQ(1, instruction.getSyllables().size());
    
    instruction.removeSyllable(MPYHS);

    ASSERT_EQ(0, instruction.getSyllables().size());
  }
  
  TEST(InstructionMulTest, GetSyllables)
  {
    rVex::Instruction instruction;
    rVex::Operations::MUL::MPYLL MPYLL;
    rVex::Operations::MUL::MPYLLU MPYLLU;
    rVex::Operations::MUL::MPYLH MPYLH;
    rVex::Operations::MUL::MPYLHU MPYLHU;
    rVex::Operations::MUL::MPYHH MPYHH;
    rVex::Operations::MUL::MPYHHU MPYHHU;
    rVex::Operations::MUL::MPYL MPYL;
    rVex::Operations::MUL::MPYLU MPYLU;
    rVex::Operations::MUL::MPYH MPYH;
    rVex::Operations::MUL::MPYHU MPYHU;
    rVex::Operations::MUL::MPYHS MPYHS;

    std::vector<rVex::Syllable*> other;
    
    other.push_back(&MPYLL);
    other.push_back(&MPYLLU);
    other.push_back(&MPYLH);
    other.push_back(&MPYLHU);
    other.push_back(&MPYHH);
    other.push_back(&MPYHHU);
    other.push_back(&MPYL);
    other.push_back(&MPYLU);
    other.push_back(&MPYH);
    other.push_back(&MPYHU);
    other.push_back(&MPYHS);
    
    instruction.addSyllable(MPYLL);
    instruction.addSyllable(MPYLLU);
    instruction.addSyllable(MPYLH);
    instruction.addSyllable(MPYLHU);
    instruction.addSyllable(MPYHH);
    instruction.addSyllable(MPYHHU);
    instruction.addSyllable(MPYL);
    instruction.addSyllable(MPYLU);
    instruction.addSyllable(MPYH);
    instruction.addSyllable(MPYHU);
    instruction.addSyllable(MPYHS);
        
    ASSERT_EQ(other, instruction.getSyllables());
  }
  
  TEST(InstructionMulTest, PrintInstruction)
  {
    rVex::Instruction instruction;
    rVex::Operations::MUL::MPYLL MPYLL;
    rVex::Operations::MUL::MPYLLU MPYLLU;
    rVex::Operations::MUL::MPYLH MPYLH;
    rVex::Operations::MUL::MPYLHU MPYLHU;
    rVex::Operations::MUL::MPYHH MPYHH;
    rVex::Operations::MUL::MPYHHU MPYHHU;
    rVex::Operations::MUL::MPYL MPYL;
    rVex::Operations::MUL::MPYLU MPYLU;
    rVex::Operations::MUL::MPYH MPYH;
    rVex::Operations::MUL::MPYHU MPYHU;
    rVex::Operations::MUL::MPYHS MPYHS;
    
    std::string compareStr;
    
    instruction.addSyllable(MPYLL);
    instruction.addSyllable(MPYLLU);
    instruction.addSyllable(MPYLH);
    instruction.addSyllable(MPYLHU);
    instruction.addSyllable(MPYHH);
    instruction.addSyllable(MPYHHU);
    instruction.addSyllable(MPYL);
    instruction.addSyllable(MPYLU);
    instruction.addSyllable(MPYH);
    instruction.addSyllable(MPYHU);
    instruction.addSyllable(MPYHS);
    
    
    compareStr.append(MPYLL.print(true, false));
    compareStr.append(MPYLLU.print(false, false));
    compareStr.append(MPYLH.print(false, false));
    compareStr.append(MPYLHU.print(false, false));
    
    compareStr.append(MPYHH.print(false, false));
    compareStr.append(MPYHHU.print(false, false));
    compareStr.append(MPYL.print(false, false));
    compareStr.append(MPYLU.print(false, false));
    
    compareStr.append(MPYH.print(false, false));
    compareStr.append(MPYHU.print(false, false));
    compareStr.append(MPYHS.print(false, true));
       
    ASSERT_EQ(compareStr, instruction.print());
  }
}