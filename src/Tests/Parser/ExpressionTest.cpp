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
#include "rVex/Parser/Expressions/Expression.h"

namespace ExpressionTest
{

  TEST( ExpressionTest, getParsedValueGR )
  {
    VexParser::Expression expr("$r0.30");
    VexParser::Expression::ParseInfo parseInfo=expr.getParsedValue();

    ASSERT_FALSE(parseInfo.isLabel);
    ASSERT_FALSE(parseInfo.isImmediate);
    ASSERT_FALSE(parseInfo.isBranchRegister);
    ASSERT_EQ(30, parseInfo.value);
  }

  TEST( ExpressionTest, getParsedValueLR )
  {
    VexParser::Expression expr("$l0.25");
    VexParser::Expression::ParseInfo parseInfo=expr.getParsedValue();

    ASSERT_FALSE(parseInfo.isLabel);
    ASSERT_FALSE(parseInfo.isImmediate);
    ASSERT_FALSE(parseInfo.isBranchRegister);
    ASSERT_EQ(31, parseInfo.value); // FIXME
  }

  TEST( ExpressionTest, getParsedValueBR )
  {
    VexParser::Expression expr("$b0.2");
    VexParser::Expression::ParseInfo parseInfo=expr.getParsedValue();

    ASSERT_FALSE(parseInfo.isLabel);
    ASSERT_FALSE(parseInfo.isImmediate);
    ASSERT_TRUE(parseInfo.isBranchRegister);
    ASSERT_EQ(2, parseInfo.value);
  }

  TEST( ExpressionTest, getParsedValueLabel )
  {
    VexParser::Expression expr("__LABELMALUCO");
    VexParser::Expression::ParseInfo parseInfo=expr.getParsedValue();

    ASSERT_TRUE(parseInfo.isLabel);
    ASSERT_FALSE(parseInfo.isImmediate);
    ASSERT_FALSE(parseInfo.isBranchRegister);
    ASSERT_EQ("__LABELMALUCO", parseInfo.label);
  }

  TEST( ExpressionTest, getParsedValueImm )
  {
    VexParser::Expression expr(1090);
    VexParser::Expression::ParseInfo parseInfo=expr.getParsedValue();

    ASSERT_FALSE(parseInfo.isLabel);
    ASSERT_TRUE(parseInfo.isImmediate);
    ASSERT_FALSE(parseInfo.isBranchRegister);
    ASSERT_EQ(1090, parseInfo.value);
  }
}
