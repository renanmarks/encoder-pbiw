//#include "gtest/gtest.h"
//#include "rVexSyllable.h"
//
//using namespace rVex;
//using namespace std;
//
//TEST(rVexSyllableTest, Opcode)
//{
//  rVexSyllable op;
//  op.setOpcode(10);
//  ASSERT_EQ(10, op.getOpcode());
//}
//
//TEST(rVexSyllableTest, ReadRegs) 
//{
//  rVexSyllable op;
//  vector<int> regs;
//  
//  regs.push_back(10);
//  regs.push_back(20);
//  regs.push_back(30);
//  
//  op.setReadRegisters(regs);
//  
//  ASSERT_EQ(regs[0], op.getReadRegisters()[0]);
//  ASSERT_EQ(regs[1], op.getReadRegisters()[1]);
//  ASSERT_EQ(regs[2], op.getReadRegisters()[2]);
//}
//
//TEST(rVexSyllableTest, WriteRegs)
//{
//  rVexSyllable op;
//  vector<int> regs;
//  
//  regs.push_back(10);
//  regs.push_back(20);
//  regs.push_back(30);
//  
//  op.setWriteRegisters(regs);
//  
//  ASSERT_EQ(regs[0], op.getWriteRegisters()[0]);
//  ASSERT_EQ(regs[1], op.getWriteRegisters()[1]);
//  ASSERT_EQ(regs[2], op.getWriteRegisters()[2]);
//}
//
//TEST(rVexSyllableTest, TestEqualityOperators)
//{
//  // We set the data from source syllable
//  rVexSyllable source;
//  vector<int> regsSource;
//  
//  regsSource.push_back(10);
//  regsSource.push_back(20);
//  regsSource.push_back(30);
//  
//  source.setOpcode(10);
//  source.setWriteRegisters(regsSource);
//  source.setReadRegisters(regsSource);
//  
//  // We set the data from destiny syllable
//  rVexSyllable destiny;
//  vector<int> regsDestiny;
//  
//  regsDestiny.push_back(5);
//  regsDestiny.push_back(15);
//  regsDestiny.push_back(25);
//  
//  destiny.setOpcode(5);
//  destiny.setWriteRegisters(regsDestiny);
//  destiny.setReadRegisters(regsDestiny);
//  
//  // Point from one to other
//  source.setBranchDestiny(destiny);
//  
//  ASSERT_NE(source, destiny);
//  ASSERT_EQ(*(source.getBranchDestiny()), destiny);
//  ASSERT_EQ(*(destiny.getBranchSource()), source);
//  ASSERT_EQ(NULL, source.getBranchSource());
//  ASSERT_EQ(NULL, destiny.getBranchDestiny());
//}
//
//TEST(rVexSyllableTest, TestBranchPointers)
//{
//  // We set the data from syllables
//  rVexSyllable source;
//  rVexSyllable middle;
//  rVexSyllable destiny;
//  
//  // Point from one to other
//  source.setBranchDestiny(destiny);
//  destiny.setBranchDestiny(middle);
//  
//  ASSERT_EQ(*(source.getBranchDestiny()), destiny);
//  ASSERT_EQ(*(destiny.getBranchSource()), source);
//  ASSERT_EQ(NULL, source.getBranchSource());
//  
//  ASSERT_EQ(*(destiny.getBranchDestiny()), middle);
//  ASSERT_EQ(*(middle.getBranchSource()), destiny);
//}