#include <vector>

#include "rVex/rVex.h"
#include "gtest/gtest.h"

namespace InstructionTest
{
  TEST(InstructionTest, AddSyllable)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;

    ASSERT_EQ(0, instruction.getSyllables().size());

    instruction.addSyllable(ADD);

    ASSERT_EQ(1, instruction.getSyllables().size());

    instruction.addSyllable(AND);

    ASSERT_EQ(2, instruction.getSyllables().size());
  }

  TEST(InstructionTest, RemoveSyllable)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;

    instruction.addSyllable(ADD);
    instruction.addSyllable(AND);

    ASSERT_EQ(2, instruction.getSyllables().size());

    instruction.removeSyllable(ADD);

    ASSERT_EQ(1, instruction.getSyllables().size());

    instruction.removeSyllable(AND);

    ASSERT_EQ(0, instruction.getSyllables().size());
  }

  TEST(InstructionTest, GetSyllables)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    std::vector<rVex::Syllable*> other;
    
    other.push_back(&ADD);
    other.push_back(&AND);
    
    instruction.addSyllable(ADD);
    instruction.addSyllable(AND);
    
    ASSERT_EQ(other, instruction.getSyllables());
  }
  
  TEST(InstructionTest, PrintInstruction)
  {
    rVex::Instruction instruction;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    std::string compareStr;
    
    instruction.addSyllable(ADD);
    instruction.addSyllable(AND);
    instruction.addSyllable(ADD);
    
    compareStr.append(ADD.print(true, false));
    compareStr.append(AND.print(false, false));
    compareStr.append(ADD.print(false, true));
    
    ASSERT_EQ(compareStr, instruction.print());
  }
}