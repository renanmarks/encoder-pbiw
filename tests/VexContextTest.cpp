#include "gtest/gtest.h"
#include "VexParser/VexContext.h"
#include "rVex/rVex.h"

#include <memory>

namespace VexContextTest
{
  TEST(VexContextTest, OneInstruction)
  {
    VexParser::VexContext context;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    std::string compareStr;
    
    context.newInstruction();
    context.packSyllable(ADD);
    context.packSyllable(AND);
    context.endInstruction();
    
    compareStr.append(ADD.print(true, false));
    compareStr.append(AND.print(false, true));
    
    ASSERT_EQ(compareStr, context.getInstruction(0).print());
  }
  
  TEST(VexContextTest, TwoInstruction)
  {
    VexParser::VexContext context;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    std::string compareStr;
    std::string compareStr2;
    
    context.newInstruction();
    context.packSyllable(ADD);
    context.packSyllable(AND);
    context.endInstruction();
    
    context.newInstruction();
    context.packSyllable(AND);
    context.packSyllable(ADD);
    context.packSyllable(AND);
    context.endInstruction();
    
    compareStr.append(ADD.print(true, false));
    compareStr.append(AND.print(false, true));
    
    compareStr2.append(AND.print(true, false));
    compareStr2.append(ADD.print(false, false));
    compareStr2.append(AND.print(false, true));
    
    ASSERT_EQ(compareStr, context.getInstruction(0).print());
    ASSERT_EQ(compareStr2, context.getInstruction(1).print());
  }
  
  TEST(VexContextTest, References)
  {
    VexParser::VexContext context;
    std::string compareStr;
    rVex::Operations::ALU::ADD ADD;
    rVex::Operations::ALU::AND AND;
    
    context.newInstruction();
    context.packSyllable(ADD);
    context.packSyllable(AND);
    context.endInstruction();
    
    compareStr.append(ADD.print(true, false));
    compareStr.append(AND.print(false, true));
    
    rVex::Instruction instruction = context.getInstruction(0);
    
    ASSERT_EQ(compareStr, instruction.print());
    ASSERT_EQ(&ADD, instruction.getSyllables()[0]);
    ASSERT_EQ(&AND, instruction.getSyllables()[1]);
  }
  
  TEST(VexContextTest, ScopeReference)
  {
    VexParser::VexContext context;
    std::string compareStr;
    rVex::Syllable* ADDptr;
    rVex::Syllable* ANDptr;
        
    {
      rVex::Syllable* ADD = new rVex::Operations::ALU::ADD();
      rVex::Syllable* AND = new rVex::Operations::ALU::AND();
      
      ADDptr = ADD;
      ANDptr = AND;
      
      context.newInstruction();
      context.packSyllable(*ADD);
      context.packSyllable(*AND);
      context.endInstruction();

      compareStr.append(ADD->print(true, false));
      compareStr.append(AND->print(false, true));
      
      rVex::Instruction instruction = context.getInstruction(0);
      
      ASSERT_EQ(compareStr, instruction.print());
      ASSERT_EQ(ADD, instruction.getSyllables()[0]);
      ASSERT_EQ(AND, instruction.getSyllables()[1]);
    }
    
    {
      rVex::Instruction instruction = context.getInstruction(0);

      ASSERT_EQ(compareStr, instruction.print());
      ASSERT_EQ(ADDptr, instruction.getSyllables()[0]);
      ASSERT_EQ(ANDptr, instruction.getSyllables()[1]);
    }
    
    delete ADDptr, ANDptr;
  }
}
