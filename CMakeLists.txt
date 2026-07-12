cmake_minimum_required(VERSION 3.31)
project(2048)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        master
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME}
        main.cpp
        Game/Game.h
        Game/Game.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
