#include <memory>

#include "gtest/gtest.h"
#include "VexParser/VexContext.h"
#include "rVex/rVex.h"

namespace VexContextTest
{
  TEST(VexContextTest, OneInstruction)
  {
    VexParser::VexContext context;
    std::string compareStr;
    rVex::Syllable* ADD = new rVex::Operations::ALU::ADD();
    rVex::Syllable* AND = new rVex::Operations::ALU::AND();
    
    context.newInstruction();
    context.packSyllable(ADD);
    context.packSyllable(AND);
    context.endInstruction();
    
    compareStr.append(ADD->print(true, false));
    compareStr.append(AND->print(false, true));
    
    ASSERT_EQ(compareStr, context.getInstruction(0).print());
  }
  
  TEST(VexContextTest, TwoInstruction)
  {
    VexParser::VexContext context;
    rVex::Syllable* ADD = new rVex::Operations::ALU::ADD();
    rVex::Syllable* AND = new rVex::Operations::ALU::AND();
    std::string compareStr;
    std::string compareStr2;
    
    context.newInstruction();
    context.packSyllable(ADD);
    context.packSyllable(AND);
    context.endInstruction();
    
    rVex::Syllable* ADDCG = new rVex::Operations::ALU::ADDCG();
    rVex::Syllable* ANDC = new rVex::Operations::ALU::ANDC();
    rVex::Syllable* ANDL = new rVex::Operations::ALU::ANDL();
    
    context.newInstruction();
    context.packSyllable(ADDCG);
    context.packSyllable(ANDC);
    context.packSyllable(ANDL);
    context.endInstruction();
    
    compareStr.append(ADD->print(true, false));
    compareStr.append(AND->print(false, true));
    
    compareStr2.append(ADDCG->print(true, false));
    compareStr2.append(ANDC->print(false, false));
    compareStr2.append(ANDL->print(false, true));
    
    ASSERT_EQ(compareStr, context.getInstruction(0).print());
    ASSERT_EQ(compareStr2, context.getInstruction(1).print());
  }
  
  TEST(VexContextTest, References)
  {
    VexParser::VexContext context;
    std::string compareStr;
    rVex::Syllable* ADD = new rVex::Operations::ALU::ADD();
    rVex::Syllable* AND = new rVex::Operations::ALU::AND();
    
    context.newInstruction();
    context.packSyllable(ADD);
    context.packSyllable(AND);
    context.endInstruction();
    
    compareStr.append(ADD->print(true, false));
    compareStr.append(AND->print(false, true));
    
    rVex::Instruction instruction = context.getInstruction(0);
    
    ASSERT_EQ(compareStr, instruction.print());
    ASSERT_EQ(ADD, instruction.getSyllables()[0]);
    ASSERT_EQ(AND, instruction.getSyllables()[1]);
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
      context.packSyllable(ADD);
      context.packSyllable(AND);
      context.endInstruction();

      rVex::Instruction instruction = context.getInstruction(0);
      
      compareStr.append(ADD->print(true, false));
      compareStr.append(AND->print(false, true));
      
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
  }
}
