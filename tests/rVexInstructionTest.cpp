#include <vector>

#include "rVex/Instruction.h"
#include "rVex/Operations/Operations.h"
#include "gtest/gtest.h"

namespace InstructionTest
{
  TEST(InstructionTest, AddSyllable)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD aluOp;

    ASSERT_EQ(0, instruction.getSyllables().size());

    instruction.addSyllable(aluOp);

    ASSERT_EQ(1, instruction.getSyllables().size());

    instruction.addSyllable(aluOp);

    ASSERT_EQ(2, instruction.getSyllables().size());
  }

  TEST(InstructionTest, RemoveSyllable)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD aluOp;

    instruction.addSyllable(aluOp);
    instruction.addSyllable(aluOp);

    ASSERT_EQ(2, instruction.getSyllables().size());

    instruction.removeSyllable(aluOp);

    ASSERT_EQ(1, instruction.getSyllables().size());

    instruction.removeSyllable(aluOp);

    ASSERT_EQ(0, instruction.getSyllables().size());
  }

  TEST(InstructionTest, GetSyllables)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD aluOp;
    std::vector<rVex::Syllable*> other;
    
    other.push_back(&aluOp);
    other.push_back(&aluOp);
    
    instruction.addSyllable(aluOp);
    instruction.addSyllable(aluOp);
    
    ASSERT_EQ(other, instruction.getSyllables());
  }
  
  TEST(InstructionTest, PrintInstruction)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD aluOp;
    std::string compareStr;
    
    instruction.addSyllable(aluOp);
    instruction.addSyllable(aluOp);
    
    compareStr.append(aluOp.print());
    compareStr.append(aluOp.print());
    
    ASSERT_EQ(compareStr, instruction.print());
  }
}