cmake_minimum_required(VERSION 3.20)

project(
    ColdCoffeeEngine
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# --------------------------------------------------
# SDL3
# --------------------------------------------------

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.0
)

set(SDLIMAGE_AVIF OFF CACHE BOOL "Disable AVIF support" FORCE)
set(SDLIMAGE_VENDORED_DAV1D OFF CACHE BOOL "Disable vendored dav1d" FORCE)

FetchContent_MakeAvailable(SDL3)

# --------------------------------------------------
# SDL3_image
# --------------------------------------------------

FetchContent_Declare(
    SDL3_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-3.4.4
)

FetchContent_MakeAvailable(SDL3_image)

# --------------------------------------------------
# Cold Coffee Engine
# --------------------------------------------------

add_executable(
    ColdCoffeeEngine

    Engine/Core/main.cpp
    Engine/Core/Application.cpp
    Engine/Core/Renderer.cpp
    Engine/Core/Input.cpp
    Engine/Core/Time.cpp
    Engine/Core/Transform.cpp
    Engine/Core/GameObject.cpp
    Engine/Core/Scene.cpp
    Engine/Core/SpriteRenderer.cpp
    Engine/Core/Texture.cpp
    Engine/Core/AssetManager.cpp
)

target_link_libraries(
    ColdCoffeeEngine
    PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
)

# --------------------------------------------------
# Copy SDL3 DLL beside our executable
# --------------------------------------------------

add_custom_command(
    TARGET ColdCoffeeEngine POST_BUILD

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SDL3::SDL3>"
        "$<TARGET_FILE_DIR:ColdCoffeeEngine>"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SDL3_image::SDL3_image>"
        "$<TARGET_FILE_DIR:ColdCoffeeEngine>"
)