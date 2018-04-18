cmake_minimum_required(VERSION 3.2  FATAL_ERROR)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(GameProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(dependencies_include ./../Dependencies/include)
set(engine_header ./../Lie/Headers)

find_package(OpenGL REQUIRED)
add_library(opengl INTERFACE IMPORTED)
set_property(TARGET opengl PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${OpenGL_INCLUDE_DIR})

add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES STATIC_IMPORT_DIRECTORY Dependencies/lib/glew32)

add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES STATIC_IMPORT_DIRECTORY Dependencies/lib/glfw3)

enable_testing()
add_subdirectory(Lie)
add_subdirectory(Game)
add_dependencies(Game Lie)