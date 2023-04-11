cmake_minimum_required(VERSION 3.10)
project(labyrinth_project)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)
include_directories(${SDL2_MIXER_INCLUDE_DIRS})

add_executable(labyrinth_project main.cpp Player.cpp Player.h Maze.cpp Maze.h MazeGenerator.cpp MazeGenerator.h)

target_link_libraries(labyrinth_project ${SDL2_LIBRARIES} ${SDL2_MIXER_LIBRARIES})
