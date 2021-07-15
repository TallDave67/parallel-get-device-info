cmake_minimum_required(VERSION 3.16)
project(get-device-info)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(get-device-info
  get-device-info.cpp
)

target_compile_options(get-device-info PRIVATE 
  -std=c++20 -stdlib=libstdc++
)

