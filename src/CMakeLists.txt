cmake_minimum_required(VERSION 3.13.4)

project(src)

set(LIST list.cpp)

include_directories(include)

add_library(list STATIC ${LIST})