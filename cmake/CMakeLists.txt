cmake_minimum_required(VERSION 3.3)
set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-m64")
add_definitions("-Wall -std=c++11")

INCLUDE_DIRECTORIES(sharedLib src)
add_library(SharedClass SHARED sharedLib/SharedClass.cpp)
add_library(ClassA STATIC src/ClassA.cpp)

add_executable(Main main.cpp)
TARGET_LINK_LIBRARIES(Main ClassA SharedClass)

