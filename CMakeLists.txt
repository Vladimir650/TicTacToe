cmake_minimum_required(VERSION 3.10)
project(TicTacToePW8 VERSION 1.0 LANGUAGES CXX)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries instead of static ones")

message(STATUS "=== Building project: ${PROJECT_NAME} ===")
message(STATUS "Library type: ${BUILD_SHARED_LIBS}")

set(GAME_SOURCES library/board.cpp library/check.cpp)
set(GAME_HEADERS library/board.hpp library/check.hpp)

add_library(game ${GAME_SOURCES} ${GAME_HEADERS})

target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/library)
target_compile_features(game PUBLIC cxx_std_17)

add_executable(tic_tac_toe main.cpp)
target_link_libraries(tic_tac_toe PRIVATE game)