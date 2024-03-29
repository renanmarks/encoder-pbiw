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
#include <memory>

#include "gtest/gtest.h"
#include "rVex/Parser/VexContext.h"
#include "rVex/Printers/rVexPrinter.h"
#include "rVex/rVex.h"

namespace VexContextTest
{
  using namespace VexParser;
  
  class VexContextTest : public testing::Test {
    public:
    
    VexContextTest()
    : printer(std::cout), context(printer)
    { }
    
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.
    protected:  
     
    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the varibles.
    // Otherwise, this can be skipped.
    virtual void SetUp() 
    {
//      sourceRegs = new Arguments(new Expression("$r0.1"));
//      sourceRegs->addArgument(new Expression("$r0.2"));
//      destinyRegs = new Arguments(new Expression("$r0.3"));
//      
//      sourceImm = new Arguments(new Expression("8"));
//      sourceImm->addArgument(new Expression("$r0.2"));
//      
//      destinyImm = new Arguments(new Expression("16"));
//      destinyImm->addArgument(new Expression("$r0.3"));
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    //
//    virtual void TearDown() 
//    {
//
//    }

    // Init stuff
    rVex::Printers::rVexPrinter printer;
    VexContext context;
    
    Arguments* sourceRegs;
    Arguments* sourceImm;
    Arguments* destinyRegs;
    Arguments* destinyImm;
  };
  
  TEST_F(VexContextTest, OneInstruction)
  {
//    std::string compareStr;
//    
//    rVex::Base::Syllable* ADD = new rVex::Operations::ALU::ADD();
//    rVex::Base::Syllable* AND = new rVex::Operations::ALU::AND();
//    
//    context.newInstruction();
//    context.packSyllable(ADD, new SyllableArguments(sourceRegs, destinyRegs) );
//    context.endInstruction();
    
//    compareStr.append(ADD->print(true, false));
//    
//    ASSERT_EQ(compareStr, context.getInstruction(0).print());
  }
  
  TEST_F(VexContextTest, TwoInstruction)
  {
//    rVex::Printers::rVexPrinter printer(std::cout);
//    VexParser::VexContext context(printer);
//    rVex::Base::Syllable* ADD = new rVex::Operations::ALU::ADD();
//    rVex::Base::Syllable* AND = new rVex::Operations::ALU::AND();
//    std::string compareStr;
//    std::string compareStr2;
//    
//    context.newInstruction();
//    context.packSyllable(ADD);
//    context.packSyllable(AND);
//    context.endInstruction();
//    
//    rVex::Base::Syllable* ADDCG = new rVex::Operations::ALU::ADDCG();
//    rVex::Base::Syllable* ANDC = new rVex::Operations::ALU::ANDC();
//    rVex::Base::Syllable* ANDL = new rVex::Operations::ALU::ANDL();
//    
//    context.newInstruction();
//    context.packSyllable(ADDCG);
//    context.packSyllable(ANDC);
//    context.packSyllable(ANDL);
//    context.endInstruction();
//    
//    compareStr.append(ADD->print(true, false));
//    compareStr.append(AND->print(false, true));
//    
//    compareStr2.append(ADDCG->print(true, false));
//    compareStr2.append(ANDC->print(false, false));
//    compareStr2.append(ANDL->print(false, true));
//    
//    ASSERT_EQ(compareStr, context.getInstruction(0).print());
//    ASSERT_EQ(compareStr2, context.getInstruction(1).print());
  }
  
  TEST_F(VexContextTest, References)
  {
//    rVex::Printers::rVexPrinter printer(std::cout);
//    VexParser::VexContext context(printer);
//    std::string compareStr;
//    rVex::Base::Syllable* ADD = new rVex::Operations::ALU::ADD();
//    rVex::Base::Syllable* AND = new rVex::Operations::ALU::AND();
//    
//    context.newInstruction();
//    context.packSyllable(ADD);
//    context.packSyllable(AND);
//    context.endInstruction();
//    
//    compareStr.append(ADD->print(true, false));
//    compareStr.append(AND->print(false, true));
//    
//    rVex::Base::Instruction instruction = context.getInstruction(0);
//    
//    ASSERT_EQ(compareStr, instruction.print());
//    ASSERT_EQ(ADD, instruction.getSyllables()[0]);
//    ASSERT_EQ(AND, instruction.getSyllables()[1]);
  }
  
  TEST_F(VexContextTest, ScopeReference)
  {
//    rVex::Printers::rVexPrinter printer(std::cout);
//    VexParser::VexContext context(printer);
//    std::string compareStr;
//    rVex::Base::Syllable* ADDptr;
//    rVex::Base::Syllable* ANDptr;
//        
//    {
//      rVex::Base::Syllable* ADD = new rVex::Operations::ALU::ADD();
//      rVex::Base::Syllable* AND = new rVex::Operations::ALU::AND();
//      
//      ADDptr = ADD;
//      ANDptr = AND;
//      
//      context.newInstruction();
//      context.packSyllable(ADD);
//      context.packSyllable(AND);
//      context.endInstruction();
//
//      rVex::Base::Instruction instruction = context.getInstruction(0);
//      
//      compareStr.append(ADD->print(true, false));
//      compareStr.append(AND->print(false, true));
//      
//      ASSERT_EQ(compareStr, instruction.print());
//      ASSERT_EQ(ADD, instruction.getSyllables()[0]);
//      ASSERT_EQ(AND, instruction.getSyllables()[1]);
//    }
//    
//    {
//      rVex::Base::Instruction instruction = context.getInstruction(0);
//
//      ASSERT_EQ(compareStr, instruction.print());
//      ASSERT_EQ(ADDptr, instruction.getSyllables()[0]);
//      ASSERT_EQ(ANDptr, instruction.getSyllables()[1]);
//    }
  }
}
