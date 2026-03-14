cmake_minimum_required(VERSION 3.27)
project(Goalkeeper)

set(CMAKE_CXX_STANDARD 17)

add_executable(Goalkeeper
        src/main.cpp
        src/goal.h
        src/goalmanager.cpp
)
