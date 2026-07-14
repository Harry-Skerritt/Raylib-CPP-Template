cmake_minimum_required(VERSION 3.31)
project(Raylib_Template)

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
        src/main.cpp
        src/Game/Game.h
        src/Game/Game.cpp
        src/Managers/AudioManager/AudioManager.h
        src/Managers/AssetManager/AssetManager.h
        src/Managers/AssetManager/AssetManager.cpp
        src/Managers/SceneManager/Scene.h
        src/Managers/SceneManager/SceneManager.h
        src/Managers/SceneManager/SceneManager.cpp
        src/Managers/StorageManager/StorageManager.h
        src/Managers/GestureHandler/GestureHandler.h

        src/Scenes/Splash/Splash.h
        src/Scenes/Splash/Splash.cpp
        src/Scenes/GameScene/GameScene.h
        src/Scenes/GameScene/GameScene.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)