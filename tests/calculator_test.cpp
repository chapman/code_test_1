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
    EXPECT_DOUBLE_EQ(calc.divide(10, 2), 5.0);
    EXPECT_DOUBLE_EQ(calc.divide(7, 2), 3.5);
    EXPECT_DOUBLE_EQ(calc.divide(-10, 2), -5.0);
}

TEST_F(CalculatorTest, DivideZeroByPositive) {
    EXPECT_DOUBLE_EQ(calc.divide(0, 5), 0.0);
    EXPECT_DOUBLE_EQ(calc.divide(0, 100), 0.0);
}

TEST_F(CalculatorTest, DivideByZeroThrows) {
    // Cast to void to suppress [[nodiscard]] warning when testing exception
    EXPECT_THROW(static_cast<void>(calc.divide(10, 0)), std::runtime_error);
}
