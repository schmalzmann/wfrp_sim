cmake_minimum_required( VERSION 3.21 )
project( WFRP_Simulator LANGUAGES CXX )


set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include" )
set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/source" )

file( GLOB_RECURSE HEADERS "${INCLUDE_PATH}/*.hpp" )
file( GLOB_RECURSE SOURCES "${SOURCE_PATH}/*.cpp" )

add_executable( WFRP_Simulator wfrp_simulator.cpp ${HEADERS} ${SOURCES})

target_include_directories( WFRP_Simulator PUBLIC ${INCLUDE_PATH} ${SOURCE_PATH} )

add_subdirectory( tests )