cmake_minimum_required(VERSION 3.10)
project(CPPToyExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(calculator_app
    src/main.cpp
)

# Unit tests
find_package(GTest REQUIRED)
enable_testing()

add_executable(calculator_test
    tests/calculator_test.cpp
)

target_link_libraries(calculator_test GTest::GTest GTest::Main)

add_test(NAME calculator_test COMMAND calculator_test)

# Run tests as part of the build
add_custom_command(TARGET calculator_test POST_BUILD
    COMMAND calculator_test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running unit tests..."
)
