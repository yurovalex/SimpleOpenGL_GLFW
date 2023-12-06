cmake_minimum_required(VERSION 3.20)

project(GLFW_IMGUI_SPDLOG
    VERSION 0.0.1
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

set(CMAKE_BUILD_PARALLEL_LEVEL 40)

add_subdirectory(external)
add_subdirectory(sources)


