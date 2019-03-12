cmake_minimum_required(VERSION 3.5)
SET( CMAKE_CXX_FLAGS "-std=c++11 -O3")

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

 
add_executable(LoggingTest LoggingTest.cpp)
target_link_libraries(LoggingTest libserver_base)
