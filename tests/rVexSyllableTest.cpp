#include "gtest/gtest.h"
#include "rVex/rVex.h"

using namespace std;
using namespace rVex;

TEST(SyllableTest, PrintBinaryADD)
{
  rVex::Operations::ALU::ADD add;
  
  add.addReadRegister(10);
  add.addReadRegister(63);
  add.setGrDestiny(1);
  
  ASSERT_EQ("10000010000000100101011111100001", add.print(true, false));
  ASSERT_EQ("10000010000000100101011111100010", add.print(false, true));
  ASSERT_EQ("10000010000000100101011111100011", add.print(true, true));
  ASSERT_EQ("10000010000000100101011111100000", add.print(false, false));
}

TEST(SyllableTest, PrintBinaryAND)
{
  rVex::Operations::ALU::AND AND;
  
  AND.addReadRegister(10);
  AND.addReadRegister(63);
  AND.setGrDestiny(1);
  
  ASSERT_EQ("10000110000000100101011111100001", AND.print(true, false));
  ASSERT_EQ("10000110000000100101011111100010", AND.print(false, true));
  ASSERT_EQ("10000110000000100101011111100011", AND.print(true, true));
  ASSERT_EQ("10000110000000100101011111100000", AND.print(false, false));
}