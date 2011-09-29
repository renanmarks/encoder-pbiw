#include <memory>

#include "gtest/gtest.h"
#include "VexParser/Expressions/Expression.h"

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
    ASSERT_EQ(25, parseInfo.value); // FIXME
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
