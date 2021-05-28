cmake_minimum_required(VERSION 3.13.4)

project(src)

set(SRC roman.cpp)

include_directories(include)

add_library(src STATIC ${SRC})
