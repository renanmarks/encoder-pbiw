#include "gtest/gtest.h"
#include "IVLIWOperation.h"
#include "rVexSyllable.h"

TEST(rVexSyllableTest, Opcode)
{
  Base::IVLIWOperation* op = new rVex::rVexSyllable();
  op->setOpcode(10);
  ASSERT_EQ(10, op->getOpcode());
  delete op;
}

TEST(rVexSyllableTest, ReadRegs) 
{
  Base::IVLIWOperation* op = new rVex::rVexSyllable();
  std::vector<int> regs;
  
  regs.push_back(10);
  regs.push_back(20);
  regs.push_back(30);
  
  op->setReadRegisters(regs);
  
  ASSERT_EQ(regs[0], op->getReadRegisters()[0]);
  ASSERT_EQ(regs[1], op->getReadRegisters()[1]);
  ASSERT_EQ(regs[2], op->getReadRegisters()[2]);
  
  delete op;
}

TEST(rVexSyllableTest, WriteRegs)
{
  Base::IVLIWOperation* op = new rVex::rVexSyllable();
  std::vector<int> regs;
  
  regs.push_back(10);
  regs.push_back(20);
  regs.push_back(30);
  
  op->setWriteRegisters(regs);
  
  ASSERT_EQ(regs[0], op->getWriteRegisters()[0]);
  ASSERT_EQ(regs[1], op->getWriteRegisters()[1]);
  ASSERT_EQ(regs[2], op->getWriteRegisters()[2]);
  
  delete op;
}