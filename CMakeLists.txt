cmake_minimum_required(VERSION 3.13.4)

project(lab3)

set(SOURSE_NAME main.cpp)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)


add_executable(main ${SOURSE_NAME})

target_link_libraries(main src)