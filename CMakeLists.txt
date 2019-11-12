cmake_minimum_required(VERSION 3.14)
project(PVZ)
include_directories(include)

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES "src/*.cpp")

add_executable(PVZ ${SOURCES})