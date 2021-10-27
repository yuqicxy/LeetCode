# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCode")

# Include sub-projects.
add_subdirectory ("Median of two sorted array")
add_subdirectory ("70_climbing_stairs")
add_subdirectory("5.longest-palindromic-substring")