cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b73f27fd164456fea9aba56163f5511355a03272.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(This MiniRT)

project(${This} C CXX)

# GoogleTest requires C++
set(CMAKE_CXX_STANDARD 14)

enable_testing()

set(Headers
	../headers/mini_rt.h
)

set(Sources
	../sources/validation/arg_validator.c)

add_library(${This} ${Sources} ${Headers})

# this will add all the subdirectories with unit tests
add_subdirectory(InputTests)
