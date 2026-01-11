#pragma once

#include <stdexcept>

class Calculator {
public:
    [[nodiscard]] constexpr int add(int a, int b) const noexcept {
        return a + b;
    }

    [[nodiscard]] constexpr int subtract(int a, int b) const noexcept {
        return a - b;
    }

    [[nodiscard]] constexpr int multiply(int a, int b) const noexcept {
        return a * b;
    }

    [[nodiscard]] double divide(int a, int b) const {
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        return static_cast<double>(a) / b;
    }
};
