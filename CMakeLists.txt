cmake_minimum_required(VERSION 3.29)
project(NewSeparate)

set(CMAKE_CXX_STANDARD 20)

add_executable(NewSeparate main.cpp
        monster.cpp
        monster.h
        player.cpp
        player.h
        room.cpp
        room.h)
