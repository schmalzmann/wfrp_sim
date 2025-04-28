cmake_minimum_required(VERSION 3.21)
project( die_tests LANGUAGES CXX )

enable_testing()

set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/../include" )
set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/../source" )

file( GLOB_RECURSE HEADERS "${INCLUDE_PATH}/*.hpp" )
file( GLOB_RECURSE SOURCES "${SOURCE_PATH}/*.cpp" )

# Fetch GoogleTest
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

# Create the test executable
add_executable(
  die_tests
  ../source/die.cpp         # relative path to your source file
  test_die_roll.cpp
)

target_include_directories(die_tests PRIVATE ${CMAKE_SOURCE_DIR} ${INCLUDE_PATH} ${SOURCE_PATH})

target_link_libraries(
  die_tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(die_tests)

add_test(NAME die_tests COMMAND die_tests)