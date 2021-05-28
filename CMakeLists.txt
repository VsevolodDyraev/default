cmake_minimum_required(VERSION 3.13.4)

project(lab5_text)

set(SOURSE_NAME main.cpp)

include_directories(include)

add_subdirectory(test)


add_executable(main ${SOURSE_NAME})
