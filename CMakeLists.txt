cmake_minimum_required(VERSION 3.24)
project(Cosmic_Voyager)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(Cosmic_Voyager
        inc/EventHandler.h
        inc/FastShip.h
        inc/GameLoop.h
        inc/GameStateEnum.h
        inc/NormalShip.h
        inc/Printer.h
        inc/Ship.h
        inc/StrongShip.h
        src/EventHandler.cpp
        src/GameLoop.cpp
        src/Printer.cpp
        src/Ship.cpp
        main.cpp)
