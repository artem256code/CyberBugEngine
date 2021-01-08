cmake_minimum_required(VERSION 3.5)

project(CyberBugEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src bin)
add_subdirectory(tests)






