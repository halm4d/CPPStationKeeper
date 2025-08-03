cmake_minimum_required(VERSION 3.31)
project(CPPRayStationKeeper)

set(CMAKE_CXX_STANDARD 26)

# Find required packages
find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(imgui CONFIG REQUIRED)

# Recursively find all .cpp and .h files
file(GLOB_RECURSE PROJECT_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)
file(GLOB_RECURSE PROJECT_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

# Add the executable target
add_executable(CPPRayStationKeeper ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# Link libraries
target_link_libraries(CPPRayStationKeeper PRIVATE
        fmt::fmt
        glfw
        OpenGL::GL
        imgui::imgui
)