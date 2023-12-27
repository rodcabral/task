cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(task)

add_executable(task task.cpp)

install(
    TARGETS
    task
)