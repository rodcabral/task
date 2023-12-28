cmake_minimum_required(VERSION 3.15)
project(task)
set(CMAKE_CXX_STANDARD 17)

add_executable(task task.cpp)

install(
    TARGETS
    task
)