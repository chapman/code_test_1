# C++ Toy Example - Simple Calculator

[![CI](https://github.com/chapman/code_test_1/actions/workflows/ci.yml/badge.svg)](https://github.com/chapman/code_test_1/actions/workflows/ci.yml)
![coverage](https://img.shields.io/endpoint?url=https://gist.githubusercontent.com/<USERNAME>/<GIST_ID>/raw/coverage-badge.json)

A simple C++ project demonstrating basic project structure with CMake.

## Project Structure

```
.
├── CMakeLists.txt          # Build configuration
├── include/                # Header files
│   └── calculator.h        # Calculator class (header-only)
├── src/                    # Source files
│   └── main.cpp
├── tests/                  # Unit tests
│   └── calculator_test.cpp
└── build/                  # Build output directory
```

## Building the Project

### Prerequisites
- CMake (version 3.10 or higher)
- C++ compiler with C++17 support (g++, clang++, MSVC)
- Google Test (for unit tests)

### Build Instructions

#### On Windows
```bash
cd build
cmake ..
cmake --build .
```

#### On Linux/macOS
```bash
cd build
cmake ..
make
```

## Running the Application

After building, run the executable:

#### On Windows
```bash
build\Debug\calculator_app.exe
```

#### On Linux/macOS
```bash
./build/calculator_app
```

## Unit Tests

Unit tests run automatically as part of the build. If any test fails, the build will fail.

To run tests manually:
```bash
cd build
ctest --output-on-failure
```

## Code Coverage

To generate a coverage report locally:

```bash
# Install lcov if not already installed
sudo apt-get install lcov

# Run the coverage script
./scripts/coverage.sh
```

This will:
1. Build with coverage instrumentation
2. Run all tests
3. Generate an HTML report at `coverage_html/index.html`

CI requires >80% line coverage for PRs to pass.

## What This Project Does

This simple calculator demonstrates:
- Basic C++ class structure
- Header-only implementation
- CMake build system
- Simple arithmetic operations with error handling
- Unit testing with Google Test
