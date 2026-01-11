#include <gtest/gtest.h>
#include "calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calc;
};

TEST_F(CalculatorTest, AddPositiveNumbers) {
    EXPECT_EQ(calc.add(2, 3), 5);
    EXPECT_EQ(calc.add(0, 0), 0);
    EXPECT_EQ(calc.add(100, 200), 300);
}

TEST_F(CalculatorTest, AddNegativeNumbers) {
    EXPECT_EQ(calc.add(-2, -3), -5);
    EXPECT_EQ(calc.add(-10, 5), -5);
}

TEST_F(CalculatorTest, AddMixedPositiveNegative) {
    EXPECT_EQ(calc.add(10, -3), 7);
    EXPECT_EQ(calc.add(-7, 12), 5);
    EXPECT_EQ(calc.add(-5, 5), 0);
}

TEST_F(CalculatorTest, SubtractNumbers) {
    EXPECT_EQ(calc.subtract(5, 3), 2);
    EXPECT_EQ(calc.subtract(3, 5), -2);
    EXPECT_EQ(calc.subtract(0, 0), 0);
}

TEST_F(CalculatorTest, MultiplyNumbers) {
    EXPECT_EQ(calc.multiply(2, 3), 6);
    EXPECT_EQ(calc.multiply(-2, 3), -6);
    EXPECT_EQ(calc.multiply(0, 100), 0);
}

TEST_F(CalculatorTest, DivideNumbers) {
    EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
    EXPECT_DOUBLE_EQ(calc.divide(7.0, 2.0), 3.5);
    EXPECT_DOUBLE_EQ(calc.divide(-10.0, 2.0), -5.0);
}

TEST_F(CalculatorTest, DivideZeroByPositive) {
    EXPECT_DOUBLE_EQ(calc.divide(0.0, 5.0), 0.0);
    EXPECT_DOUBLE_EQ(calc.divide(0.0, 100.0), 0.0);
}

TEST_F(CalculatorTest, DivideByZeroThrows) {
    // Cast to void to suppress [[nodiscard]] warning when testing exception
    EXPECT_THROW(static_cast<void>(calc.divide(10, 0)), std::runtime_error);
}

// Tests for int types
TEST_F(CalculatorTest, IntOperations) {
    EXPECT_EQ(calc.add<int>(2, 3), 5);
    EXPECT_EQ(calc.subtract<int>(5, 3), 2);
    EXPECT_EQ(calc.multiply<int>(2, 3), 6);
    EXPECT_EQ(calc.divide<int>(10, 2), 5);
}

// Tests for float types
TEST_F(CalculatorTest, FloatOperations) {
    EXPECT_FLOAT_EQ(calc.add<float>(2.5f, 3.5f), 6.0f);
    EXPECT_FLOAT_EQ(calc.subtract<float>(5.5f, 3.0f), 2.5f);
    EXPECT_FLOAT_EQ(calc.multiply<float>(2.5f, 4.0f), 10.0f);
    EXPECT_FLOAT_EQ(calc.divide<float>(7.0f, 2.0f), 3.5f);
}

// Tests for double types
TEST_F(CalculatorTest, DoubleOperations) {
    EXPECT_DOUBLE_EQ(calc.add<double>(2.5, 3.5), 6.0);
    EXPECT_DOUBLE_EQ(calc.subtract<double>(5.5, 3.0), 2.5);
    EXPECT_DOUBLE_EQ(calc.multiply<double>(2.5, 4.0), 10.0);
    EXPECT_DOUBLE_EQ(calc.divide<double>(7.0, 2.0), 3.5);
}
