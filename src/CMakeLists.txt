cmake_minimum_required(VERSION 3.5)

project(CyberBugEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

find_library(SDL2_LIBRARY             SDL2)
find_library(SDL2_IMAGE_LIBRARY       SDL2_image)

add_executable(CyberBugEngine   main.cpp
                                buffer.cpp
                                buffer.hpp
                                object.cpp
                                object.hpp
                                render.cpp
                                render.hpp)

target_link_libraries(CyberBugEngine ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})


