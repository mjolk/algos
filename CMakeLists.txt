cmake_minimum_required(VERSION 3.16)
project(algos)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
add_subdirectory(src)

enable_testing()
add_subdirectory(test)
