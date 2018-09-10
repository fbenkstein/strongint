cmake_minimum_required(VERSION 3.10)
project(strongint)

find_package(GTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT GTEST_FOUND)
    set(GTEST_SOURCE_DIR "/usr/src/googletest" CACHE PATH "Google Test source directory")

    if (IS_DIRECTORY "${GTEST_SOURCE_DIR}")
        add_subdirectory("${GTEST_SOURCE_DIR}" gtest EXCLUDE_FROM_ALL)
        add_library(GTest::GTest ALIAS gtest)
        add_library(GTest::Main ALIAS gtest_main)
    endif()
endif()

if (NOT TARGET GTest::GTest)
    return()
endif()

enable_testing()

add_executable(strongint_test test/strongint_test.cc)
if (CMAKE_CXX_COMPILER_ID STREQUAL GNU OR CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    target_compile_options(strongint_test PRIVATE -W -Wall -pedantic)
endif()
target_include_directories(strongint_test PRIVATE include)
target_link_libraries(strongint_test PRIVATE GTest::GTest GTest::Main)
gtest_discover_tests(strongint_test)
