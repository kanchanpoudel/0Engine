
include_directories(
        ${engine_header}
)

file(GLOB SOURCES Source/*.cpp)

add_executable(Game ${SOURCES})

target_link_libraries(Game
        Lie
)