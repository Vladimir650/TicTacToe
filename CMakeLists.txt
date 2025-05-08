cmake_minimum_required(VERSION 3.10)
project(TicTacToePW8)

message("Project: ${PROJECT_NAME}")

option(BUILD_SHARED_LIBS "Build shared library" OFF)

add_library(game library/board.cpp library/check.cpp)

target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/library)

add_executable(tic_tac_toe main.cpp)
target_link_libraries(tic_tac_toe game)