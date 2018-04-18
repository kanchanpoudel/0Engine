include_directories(
        ${dependencies_include}
        Headers
)

file(GLOB DEBUGGER Debugger/*.cpp)
file(GLOB GAME Game/*.cpp)
file(GLOB GRAPHICS Graphics/*.cpp)
file(GLOB INPUT Input/*.cpp)
file(GLOB MATHS Maths/*.cpp)

add_library(Lie STATIC
    ${DEBUGGER}
    ${GAME}
    ${GRAPHICS}
    ${INPUT}
    ${MATHS}
)

target_link_libraries(Lie
    opengl
    glew
    glfw
)

