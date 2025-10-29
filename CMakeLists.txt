
cmake_minimum_required(VERSION 3.5)

project(DM_Linux_Drive LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(motordriver
               src/multicontrol.cpp
)