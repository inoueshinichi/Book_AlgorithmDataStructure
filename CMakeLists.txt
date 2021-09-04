cmake_minimum_required(VERSION 3.0.0)
project(AlgorithmDataStructure)

# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

add_subdirectory(practice)
add_subdirectory(ch2_order)
add_subdirectory(ch3_all_search)
add_subdirectory(ch4_recursion_and_divide_and_conquer_method)
add_subdirectory(ch5_dynamic_programming)
add_subdirectory(ch6_binary_search)
