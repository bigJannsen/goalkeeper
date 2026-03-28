cmake_minimum_required(VERSION 3.27)
project(Goalkeeper LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        Slint
        GIT_REPOSITORY https://github.com/slint-ui/slint.git
        GIT_TAG release/1
        SOURCE_SUBDIR api/cpp
)

FetchContent_MakeAvailable(Slint)

add_executable(Goalkeeper
        src/main.cpp
        src/goalmanager.cpp
)

target_include_directories(Goalkeeper PRIVATE src)

slint_target_sources(Goalkeeper ui/app-window.slint)

target_link_libraries(Goalkeeper PRIVATE Slint::Slint)

if (WIN32)
    add_custom_command(TARGET Goalkeeper POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            $<TARGET_RUNTIME_DLLS:Goalkeeper>
            $<TARGET_FILE_DIR:Goalkeeper>
            COMMAND_EXPAND_LISTS
    )
endif()