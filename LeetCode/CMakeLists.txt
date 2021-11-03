# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCode")

# Include sub-projects.
add_subdirectory ("Median of two sorted array")
add_subdirectory("5.longest-palindromic-substring")
add_subdirectory("17.letter-combinations-of-a-phone-number")
add_subdirectory("20.valid-parentheses")
add_subdirectory("23.merge-k-sorted-lists")
add_subdirectory("42.trapping-rain-water")
add_subdirectory("53.maximum-subarray")
add_subdirectory("62.unique-paths")
add_subdirectory("70_climbing_stairs")
add_subdirectory("108.Convert-Sorted-Array-to-Binary-Search-Tree")
add_subdirectory("212.word-search-ii")
add_subdirectory("127.word-ladder")
add_subdirectory("221.Maximal-Square")
add_subdirectory("227.basic-calculator-ii")
add_subdirectory("230.kth-smallest-element-in-a-bst")
add_subdirectory("415.add-strings")