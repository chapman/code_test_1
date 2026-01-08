#include <iostream>
#include "calculator.h"

int main() {
    std::cout << "C++ Toy Example - Simple Calculator\n";
    std::cout << "====================================\n";

    const Calculator calc;

    const int a = 50;
    const int b = 5;

    std::cout << "a = "     << a << ", b = " << b  << '\n';
    std::cout << "a + b = " << calc.add(a, b)      << '\n';
    std::cout << "a - b = " << calc.subtract(a, b) << '\n';
    std::cout << "a * b = " << calc.multiply(a, b) << '\n';
    std::cout << "a / b = " << calc.divide(a, b)   << '\n';

    return 0;
}
