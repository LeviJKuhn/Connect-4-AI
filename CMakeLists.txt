cmake_minimum_required(VERSION 4.2)
project(Connect_4_AI)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        Connect_4_AI
        main.cpp
        Board.cpp
        Board.h
        Machine.cpp
        Machine.h

)
