cmake_minimum_required(VERSION 3.8)

project(SampleBenchmarks) 

set(CMAKE_BUILD_TYPE Release)
add_definitions(-Ofast)

set(CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(sample_bench main_sample.cpp)
