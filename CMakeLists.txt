cmake_minimum_required(VERSION 3.22)
project(BattleField)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# Libraries
add_library(BATTLELIB STATIC 
        include/BattleField.h src/BattleField.cpp
        include/BattleShip.h)

# Enable Test Support
enable_testing()

# GTest Repo
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Compiler and Linker app
add_executable(BattleshipGame main.cpp)
target_link_libraries(BattleshipGame PUBLIC BATTLELIB)

# compiler and linker test
add_executable(Test test.cpp)
target_link_libraries(Test PUBLIC BATTLELIB gtest gtest_main)
