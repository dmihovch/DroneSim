cmake_minimum_required(VERSION 3.16)
project(sim-enviro LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(sim-enviro ${SRC_FILES})

target_include_directories(sim-enviro PRIVATE
    ${RAYLIB_INCLUDE_DIRS}
)

target_link_libraries(sim-enviro PRIVATE
    ${RAYLIB_LIBRARIES}
)
