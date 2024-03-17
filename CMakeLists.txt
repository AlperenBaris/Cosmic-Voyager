cmake_minimum_required(VERSION 3.24)
project(CosmicVoyager)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

set(SOURCE_FILES src/EventHandler.cpp
        src/GameLoop.cpp
        src/Printer.cpp
        src/Ship.cpp)

add_executable(CosmicVoyager main.cpp ${SOURCE_FILES})
