cmake_minimum_required(VERSION 3.10)

# Project name
project(BinarySearchTreeKthLargest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(code main.cpp)

# Optional: Set compiler flags for better warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
