# Minimum version recommended for modern C++ features
cmake_minimum_required(VERSION 3.10)

project(Unit_Tests_Sample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

aux_source_directory(src SOURCES)

add_executable(Unit_Tests_Sample ${SOURCES})

set(INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include)

target_include_directories(Unit_Tests_Sample PRIVATE ${INCLUDE_DIRS})