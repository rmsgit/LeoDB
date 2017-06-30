cmake_minimum_required(VERSION 3.7)
project(LoeDB_project)

set(CMAKE_CXX_STANDARD 11)
link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp file_handle.c lang/lang.cpp lib/Graph.cpp lib/Axis.cpp)
add_executable(LoeDB_project ${SOURCE_FILES})