#include <gtest/gtest.h>
#include "calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

// Int tests
TEST_F(CalculatorTest, AddIntPositiveNumbers) {
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(0, 0), 0);
    EXPECT_EQ(calc.add(100, 200), 300);
}

TEST_F(CalculatorTest, AddIntNegativeNumbers) {
    EXPECT_EQ(calc.add(-2, -3), -5);
    EXPECT_EQ(calc.add(-10, 5), -5);
}

TEST_F(CalculatorTest, AddIntMixedPositiveNegative) {
    EXPECT_EQ(calc.add(10, -3), 7);
    EXPECT_EQ(calc.add(-7, 12), 5);
    EXPECT_EQ(calc.add(-5, 5), 0);
}

TEST_F(CalculatorTest, SubtractIntNumbers) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(3, 5), -2);
    EXPECT_EQ(calc.subtract(0, 0), 0);
}

TEST_F(CalculatorTest, MultiplyIntNumbers) {
    EXPECT_EQ(calc.multiply(2, 3), 6);
    EXPECT_EQ(calc.multiply(-2, 3), -6);
    EXPECT_EQ(calc.multiply(0, 100), 0);
}

TEST_F(CalculatorTest, DivideIntNumbers) {
    EXPECT_EQ(calc.divide(10, 2), 5);
    EXPECT_EQ(calc.divide(7, 2), 3);
    EXPECT_EQ(calc.divide(-10, 2), -5);
}

TEST_F(CalculatorTest, DivideIntZeroByPositive) {
    EXPECT_EQ(calc.divide(0, 5), 0);
    EXPECT_EQ(calc.divide(0, 100), 0);
}

TEST_F(CalculatorTest, DivideIntByZeroThrows) {
    EXPECT_THROW(static_cast<void>(calc.divide(10, 0)), std::runtime_error);
}

// Float tests
TEST_F(CalculatorTest, AddFloatNumbers) {
    EXPECT_FLOAT_EQ(calc.add(2.5f, 3.5f), 6.0f);
    EXPECT_FLOAT_EQ(calc.add(0.0f, 0.0f), 0.0f);
    EXPECT_FLOAT_EQ(calc.add(-1.5f, 2.5f), 1.0f);
}

TEST_F(CalculatorTest, SubtractFloatNumbers) {
    EXPECT_FLOAT_EQ(calc.subtract(5.5f, 3.0f), 2.5f);
    EXPECT_FLOAT_EQ(calc.subtract(3.0f, 5.5f), -2.5f);
}

TEST_F(CalculatorTest, MultiplyFloatNumbers) {
    EXPECT_FLOAT_EQ(calc.multiply(2.0f, 3.5f), 7.0f);
    EXPECT_FLOAT_EQ(calc.multiply(-2.0f, 3.0f), -6.0f);
    EXPECT_FLOAT_EQ(calc.multiply(0.0f, 100.0f), 0.0f);
}

TEST_F(CalculatorTest, DivideFloatNumbers) {
    EXPECT_FLOAT_EQ(calc.divide(10.0f, 2.0f), 5.0f);
    EXPECT_FLOAT_EQ(calc.divide(7.0f, 2.0f), 3.5f);
    EXPECT_FLOAT_EQ(calc.divide(-10.0f, 2.0f), -5.0f);
}

TEST_F(CalculatorTest, DivideFloatByZeroThrows) {
    EXPECT_THROW(static_cast<void>(calc.divide(10.0f, 0.0f)), std::runtime_error);
}

// Double tests
TEST_F(CalculatorTest, AddDoubleNumbers) {
    EXPECT_DOUBLE_EQ(calc.add(2.5, 3.5), 6.0);
    EXPECT_DOUBLE_EQ(calc.add(0.0, 0.0), 0.0);
    EXPECT_DOUBLE_EQ(calc.add(-1.5, 2.5), 1.0);
}

TEST_F(CalculatorTest, SubtractDoubleNumbers) {
    EXPECT_DOUBLE_EQ(calc.subtract(5.5, 3.0), 2.5);
    EXPECT_DOUBLE_EQ(calc.subtract(3.0, 5.5), -2.5);
}

TEST_F(CalculatorTest, MultiplyDoubleNumbers) {
    EXPECT_DOUBLE_EQ(calc.multiply(2.0, 3.5), 7.0);
    EXPECT_DOUBLE_EQ(calc.multiply(-2.0, 3.0), -6.0);
    EXPECT_DOUBLE_EQ(calc.multiply(0.0, 100.0), 0.0);
}

TEST_F(CalculatorTest, DivideDoubleNumbers) {
    EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
    EXPECT_DOUBLE_EQ(calc.divide(7.0, 2.0), 3.5);
    EXPECT_DOUBLE_EQ(calc.divide(-10.0, 2.0), -5.0);
}

TEST_F(CalculatorTest, DivideDoubleByZeroThrows) {
    EXPECT_THROW(static_cast<void>(calc.divide(10.0, 0.0)), std::runtime_error);
}
