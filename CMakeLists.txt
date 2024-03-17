cmake_minimum_required(VERSION 3.24)
project(CosmicVoyager)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
include_directories(src)

add_executable(CosmicVoyager main.cpp
        src/EventHandler.cpp
        src/Printer.cpp
        src/Ship.cpp
        src/GameLoop.cpp
        inc/EventHandler.h
        inc/FastShip.h
        inc/GameLoop.h
        inc/GameStateEnum.h
        inc/NormalShip.h
        inc/Printer.h
        inc/Ship.h
        inc/StrongShip.h)
