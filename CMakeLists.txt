cmake_minimum_required(VERSION 3.27)
project(Goalkeeper)

set(CMAKE_CXX_STANDARD 17)

find_package(Slint REQUIRED)

add_executable(Goalkeeper
        src/main.cpp
        src/goal.h
        src/goalmanager.cpp
)

target_include_directories(Goalkeeper PRIVATE src)
slint_target_sources(Goalkeeper ui/app-window.slint)
target_link_libraries(Goalkeeper PRIVATE Slint::Slint)
