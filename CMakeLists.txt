cmake_minimum_required(VERSION 3.20)
project(SDL2Game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

add_executable(SDL2Game main.cpp game.cpp player.cpp enemy.cpp render.cpp perlin.cpp)

target_link_libraries(SDL2Game SDL2::SDL2)

target_include_directories(SDL2Game PRIVATE ${SDL2_INCLUDE_DIRS})
