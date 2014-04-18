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
#include "gtest/gtest.h"
#include "rVex/rVex.h"

using namespace std;
using namespace rVex;

TEST(SyllableTest, PrintBinaryMPYLL)      // Test 1
{
  rVex::Operations::MUL::MPYLL MPYLL;
  
  MPYLL.addReadRegister(10);
  MPYLL.addReadRegister(63);
  MPYLL.setGrDestiny(1);
  
  ASSERT_EQ("00000010000000100101011111100001", MPYLL.print(true, false));
  ASSERT_EQ("00000010000000100101011111100010", MPYLL.print(false, true));
  ASSERT_EQ("00000010000000100101011111100011", MPYLL.print(true, true));
  ASSERT_EQ("00000010000000100101011111100000", MPYLL.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYLLU)      // Test 2
{
  rVex::Operations::MUL::MPYLLU MPYLLU;
  
  MPYLLU.addReadRegister(10);
  MPYLLU.addReadRegister(63);
  MPYLLU.setGrDestiny(1);
  
  ASSERT_EQ("00000100000000100101011111100001", MPYLLU.print(true, false));
  ASSERT_EQ("00000100000000100101011111100010", MPYLLU.print(false, true));
  ASSERT_EQ("00000100000000100101011111100011", MPYLLU.print(true, true));
  ASSERT_EQ("00000100000000100101011111100000", MPYLLU.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYLH)     // Test 3
{
  rVex::Operations::MUL::MPYLH MPYLH;
  
  MPYLH.addReadRegister(10);
  MPYLH.addReadRegister(63);
  MPYLH.setGrDestiny(1);
  
  ASSERT_EQ("00000110000000100101011111100001", MPYLH.print(true, false));
  ASSERT_EQ("00000110000000100101011111100010", MPYLH.print(false, true));
  ASSERT_EQ("00000110000000100101011111100011", MPYLH.print(true, true));
  ASSERT_EQ("00000110000000100101011111100000", MPYLH.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYLHU)      // Test 4
{
  rVex::Operations::MUL::MPYLHU MPYLHU;
  
  MPYLHU.addReadRegister(10);
  MPYLHU.addReadRegister(63);
  MPYLHU.setGrDestiny(1);
  
  ASSERT_EQ("00001000000000100101011111100001", MPYLHU.print(true, false));
  ASSERT_EQ("00001000000000100101011111100010", MPYLHU.print(false, true));
  ASSERT_EQ("00001000000000100101011111100011", MPYLHU.print(true, true));
  ASSERT_EQ("00001000000000100101011111100000", MPYLHU.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYHH)      // Test 5
{
  rVex::Operations::MUL::MPYHH MPYHH;
  
  MPYHH.addReadRegister(10);
  MPYHH.addReadRegister(63);
  MPYHH.setGrDestiny(1);
  
  ASSERT_EQ("00001010000000100101011111100001", MPYHH.print(true, false));
  ASSERT_EQ("00001010000000100101011111100010", MPYHH.print(false, true));
  ASSERT_EQ("00001010000000100101011111100011", MPYHH.print(true, true));
  ASSERT_EQ("00001010000000100101011111100000", MPYHH.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYHHU)      // Test 6
{
  rVex::Operations::MUL::MPYHHU MPYHHU;
  
  MPYHHU.addReadRegister(10);
  MPYHHU.addReadRegister(63);
  MPYHHU.setGrDestiny(1);
  
  ASSERT_EQ("00001100000000100101011111100001", MPYHHU.print(true, false));
  ASSERT_EQ("00001100000000100101011111100010", MPYHHU.print(false, true));
  ASSERT_EQ("00001100000000100101011111100011", MPYHHU.print(true, true));
  ASSERT_EQ("00001100000000100101011111100000", MPYHHU.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYL)      // Test 7
{
  rVex::Operations::MUL::MPYL MPYL;
  
  MPYL.addReadRegister(10);
  MPYL.addReadRegister(63);
  MPYL.setGrDestiny(1);
  
  ASSERT_EQ("00001110000000100101011111100001", MPYL.print(true, false));
  ASSERT_EQ("00001110000000100101011111100010", MPYL.print(false, true));
  ASSERT_EQ("00001110000000100101011111100011", MPYL.print(true, true));
  ASSERT_EQ("00001110000000100101011111100000", MPYL.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYLU)      // Test 8
{
  rVex::Operations::MUL::MPYLU MPYLU;
  
  MPYLU.addReadRegister(10);
  MPYLU.addReadRegister(63);
  MPYLU.setGrDestiny(1);
  
  ASSERT_EQ("00010000000000100101011111100001", MPYLU.print(true, false));
  ASSERT_EQ("00010000000000100101011111100010", MPYLU.print(false, true));
  ASSERT_EQ("00010000000000100101011111100011", MPYLU.print(true, true));
  ASSERT_EQ("00010000000000100101011111100000", MPYLU.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYH)      // Test 9
{
  rVex::Operations::MUL::MPYH MPYH;
  
  MPYH.addReadRegister(10);
  MPYH.addReadRegister(63);
  MPYH.setGrDestiny(1);
  
  ASSERT_EQ("00010010000000100101011111100001", MPYH.print(true, false));
  ASSERT_EQ("00010010000000100101011111100010", MPYH.print(false, true));
  ASSERT_EQ("00010010000000100101011111100011", MPYH.print(true, true));
  ASSERT_EQ("00010010000000100101011111100000", MPYH.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYHU)      // Test 10
{
  rVex::Operations::MUL::MPYHU MPYHU;
  
  MPYHU.addReadRegister(10);
  MPYHU.addReadRegister(63);
  MPYHU.setGrDestiny(1);
  
  ASSERT_EQ("00010100000000100101011111100001", MPYHU.print(true, false));
  ASSERT_EQ("00010100000000100101011111100010", MPYHU.print(false, true));
  ASSERT_EQ("00010100000000100101011111100011", MPYHU.print(true, true));
  ASSERT_EQ("00010100000000100101011111100000", MPYHU.print(false, false));
}

TEST(SyllableTest, PrintBinaryMPYHS)      // Test 11
{
  rVex::Operations::MUL::MPYHS MPYHS;
  
  MPYHS.addReadRegister(10);
  MPYHS.addReadRegister(63);
  MPYHS.setGrDestiny(1);
  
  ASSERT_EQ("00010110000000100101011111100001", MPYHS.print(true, false));
  ASSERT_EQ("00010110000000100101011111100010", MPYHS.print(false, true));
  ASSERT_EQ("00010110000000100101011111100011", MPYHS.print(true, true));
  ASSERT_EQ("00010110000000100101011111100000", MPYHS.print(false, false));
}

