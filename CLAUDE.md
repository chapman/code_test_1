# Claude Code Guidelines

## C++ Coding Style

- Declare one variable per line, never multiple variables on the same line
- Use `const` for variables that don't change
- Use `const` member functions for methods that don't modify state
- Use `[[nodiscard]]` for functions whose return values should not be ignored
- No `const` on pass-by-value parameters in function signatures
- Use `constexpr` and `noexcept` where appropriate
- Use `#pragma once` instead of include guards
- Use `'\n'` instead of `std::endl` to avoid unnecessary buffer flushing

## Build

- Build and test under WSL2 using CMake
- Project path in WSL: `/mnt/c/temp/claude/code_test_1`
- Tests run automatically as part of the build and must pass
