cmake_minimum_required(VERSION 3.17)
project(tetris)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)


set(CMAKE_CXX_STANDARD 14)
add_subdirectory(common)

include_directories( SYSTEM  )

add_executable(tetris main.cpp Board.cpp Board.h Position.cpp Position.h Shape.cpp Shape.h test.cpp Game.cpp Game.h Models.h utils.h)
target_link_libraries(tetris glfw -lglut -lGL -lGLU GLEW common -ldl)
