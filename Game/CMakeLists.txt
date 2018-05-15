# Project : Game/Game.vcxproj
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

##################### Variables ############################
############################################################

# Project
set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_NAME Game)

# Dependencies
set(0ENGINE_DIR ../0Engine)

################# CMake Project ############################
# The main options of project                              #
############################################################

project(${PROJECT_NAME} CXX)

# Define Release by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
  message(STATUS "Build type not specified: Use Release by default.")
endif(NOT CMAKE_BUILD_TYPE)

############## Artefacts Output ############################
# Defines outputs , depending BUILD TYPE                   #
############################################################

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DEBUG}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DEBUG}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${OUTPUT_DEBUG}")
  set(EXECUTABLE_OUTPUT_PATH "${OUTPUT_DEBUG}")
else()
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_RELEASE}")
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_RELEASE}")
  set(CMAKE_EXECUTABLE_OUTPUT_DIRECTORY "${OUTPUT_RELEASE}")
  set(EXECUTABLE_OUTPUT_PATH "${OUTPUT_RELEASE}")
endif()

# Messages
message("${PROJECT_NAME}: MAIN PROJECT: ${CMAKE_PROJECT_NAME}")
message("${PROJECT_NAME}: CURR PROJECT: ${CMAKE_CURRENT_SOURCE_DIR}")
message("${PROJECT_NAME}: CURR BIN DIR: ${CMAKE_CURRENT_BINARY_DIR}")

###################### Includes ############################
# Include files and directories                            #
############################################################

# Include directories 
include_directories(${0ENGINE_DIR}/Headers)

################## Dependencies ############################
# Add Dependencies to project                              #
############################################################

# Dependencies: disable BUILD_DEPENDS to link with libraries already built
option(BUILD_DEPENDS "Build other CMake project." ON)

if(BUILD_DEPENDS)
  if(NOT TARGET 0Engine)
    add_subdirectory("${0ENGINE_DIR}" ${CMAKE_BINARY_DIR}/0Engine)
  endif()
else()
   link_directories(${CMAKE_BINARY_DIR}/0Engine)
endif()




############################################################
############################################################
############### Files & Targets ############################
# Files of project and target to build                     #
############################################################
############################################################

# Source Files
set(SRC_FILES
    Source/main.cpp
)
source_group("Sources" FILES ${SRC_FILES})

# Header Files
set(HEADERS_FILES
)
source_group("Headers" FILES ${HEADERS_FILES})




# Add executable to build.
add_executable(${PROJECT_NAME} 
   ${SRC_FILES} ${HEADERS_FILES}
)

######################### Flags ############################
# Defines Flags for Windows and Linux                      #
############################################################

if(NOT MSVC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
   if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
   endif()
endif(NOT MSVC)

# Preprocessor definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE 
    )
    if(MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE  /W3 /MD /Od /EHsc)
    endif()
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_definitions(${PROJECT_NAME} PRIVATE 
    )
    if(MSVC)
        target_compile_options(${PROJECT_NAME} PRIVATE  /W3 /GL /Oi /Gy /EHsc)
    endif()
endif()

########### Link & Dependencies ############################
# Add project dependencies and Link to project             #
############################################################

# Project dependencies
add_dependencies(${PROJECT_NAME} 0Engine)

# Link with other dependencies.
target_link_libraries(${PROJECT_NAME} 0Engine GLEW )
if(MSVC)
   target_link_libraries(${PROJECT_NAME} Opengl32.lib )
endif(MSVC)

if(NOT MSVC)
   target_link_libraries(${PROJECT_NAME} OpenGL32)
endif(NOT MSVC)