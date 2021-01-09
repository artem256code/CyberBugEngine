
cmake_minimum_required(VERSION 3.5)


project(test LANGUAGES CXX)

add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT "/home/artem/C++/CyberBugEngine/googletest" STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR "/home/artem/C++/CyberBugEngine/googletest")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes})

find_library(SDL2_LIBRARY             SDL2)
find_library(SDL2_IMAGE_LIBRARY       SDL2_image)

add_executable(test     test.cpp
                        test_render.cpp
                        test_object.cpp
                        ../src/buffer.cpp
                        ../src/buffer.hpp
                        ../src/object.cpp
                        ../src/object.hpp
                        ../src/render.cpp
                        ../src/render.hpp
                        ${GTestFiles})

add_test(NAME test COMMAND test)
target_link_libraries(test PRIVATE Threads::Threads ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
