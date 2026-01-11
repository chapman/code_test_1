#!/bin/bash
# Generate code coverage report locally
# Requires: lcov (install with: sudo apt-get install lcov)

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"

cd "$PROJECT_DIR"

echo "==> Cleaning build directory..."
rm -rf build

echo "==> Configuring with coverage enabled..."
cmake -S . -B build -DENABLE_COVERAGE=ON

echo "==> Building..."
cmake --build build

echo "==> Running tests..."
cd build && ctest --output-on-failure
cd "$PROJECT_DIR"

echo "==> Generating coverage report..."
lcov --capture --directory build --output-file coverage.info --ignore-errors mismatch
lcov --remove coverage.info '/usr/*' '*/googletest/*' '*/tests/*' --output-file coverage.info --ignore-errors mismatch --ignore-errors unused

echo ""
echo "==> Coverage Summary:"
lcov --summary coverage.info --ignore-errors mismatch

echo ""
echo "==> Generating HTML report..."
genhtml coverage.info --output-directory coverage_html

echo ""
echo "Coverage report generated at: coverage_html/index.html"
echo "Open with: xdg-open coverage_html/index.html"
