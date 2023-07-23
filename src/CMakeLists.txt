cmake_minimum_required (VERSION 3.8)

project ("28-1-swim-100-meters")

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(28-1-swim-100-meters "main.cpp" ${MY_INCLUDE_DIR}/functions.h "functions.cpp" ${MY_INCLUDE_DIR}/swimmer.h "swimmer.cpp")

target_include_directories(28-1-swim-100-meters PUBLIC ${CMAKE_SOURCE_DIR}/include)