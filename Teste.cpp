#include "gtest/gtest.h"
#include "IVLIWOperation.h"
#include "rVexSyllable.h"

TEST(CalculadoraTestes, Soma) {
  Base::IVLIWOperation* op = new rVex::rVexSyllable();
  
  
  std::vector<int> regs;
  
  regs.push_back(10);
  regs.push_back(20);
  regs.push_back(30);
  
  op->setOpcode(10);
  op->setReadRegisters(regs);
  
  ASSERT_EQ(10, op->getOpcode());
  
  ASSERT_EQ(regs[0], op->getReadRegisters()[0]);
  ASSERT_EQ(regs[1], op->getReadRegisters()[1]);
  ASSERT_EQ(regs[2], op->getReadRegisters()[2]);
  
  delete op;
}