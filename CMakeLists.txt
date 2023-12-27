cmake_minimum_required(VERSION 3.15)
project(task)

add_executable(task task.cpp)

install(
    TARGETS
    task
)