# Project : Dependencies/GLFW/GLFW.vcxproj
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

##################### Variables ############################
############################################################

# Project
get_filename_component(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
set(PROJECT_NAME GLFW)

################# CMake Project ############################
# The main options of project                              #
############################################################

project(${PROJECT_NAME} C)

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




############################################################
############################################################
############### Files & Targets ############################
# Files of project and target to build                     #
############################################################
############################################################

# Source Files
set(SRC_FILES
    src/cocoa_time.c
    src/context.c
    src/egl_context.c
    src/glx_context.c
    src/init.c
    src/input.c
    src/linux_joystick.c
    src/mir_init.c
    src/mir_monitor.c
    src/mir_window.c
    src/monitor.c
    src/posix_time.c
    src/posix_tls.c
    src/vulkan.c
    src/wgl_context.c
    src/win32_init.c
    src/win32_joystick.c
    src/win32_monitor.c
    src/win32_time.c
    src/win32_tls.c
    src/win32_window.c
    src/window.c
    src/wl_init.c
    src/wl_monitor.c
    src/wl_window.c
    src/x11_init.c
    src/x11_monitor.c
    src/x11_window.c
    src/xkb_unicode.c
)
source_group("Sources" FILES ${SRC_FILES})

# Header Files
set(HEADERS_FILES
    include/GLFW/glfw3.h
    include/GLFW/glfw3native.h
    src/cocoa_joystick.h
    src/cocoa_platform.h
    src/egl_context.h
    src/glfw_config.h
    src/glx_context.h
    src/internal.h
    src/linux_joystick.h
    src/mir_platform.h
    src/nsgl_context.h
    src/posix_time.h
    src/posix_tls.h
    src/wgl_context.h
    src/win32_joystick.h
    src/win32_platform.h
    src/wl_platform.h
    src/x11_platform.h
    src/xkb_unicode.h
)
source_group("Headers" FILES ${HEADERS_FILES})




# Add library to build.
add_library(${PROJECT_NAME} STATIC
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
