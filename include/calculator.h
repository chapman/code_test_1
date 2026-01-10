#pragma once

#include <stdexcept>

class Calculator {
public:
    template <typename T>
    [[nodiscard]] constexpr T add(T a, T b) const noexcept {
        return a + b;
    }

    template <typename T>
    [[nodiscard]] constexpr T subtract(T a, T b) const noexcept {
        return a - b;
    }

    template <typename T>
    [[nodiscard]] constexpr T multiply(T a, T b) const noexcept {
        return a * b;
    }

    template <typename T>
    [[nodiscard]] T divide(T a, T b) const {
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        return a / b;
    }
};
