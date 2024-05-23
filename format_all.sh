#!/bin/bash

# Find all .cpp, .hpp, and .h files and format them using clang-format
find . -name "*.cpp" -o -name "*.hpp" -o -name "*.h" | xargs clang-format -i
