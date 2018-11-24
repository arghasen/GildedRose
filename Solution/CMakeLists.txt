cmake_minimum_required(VERSION 3.12)
project(GildedRose)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")

add_executable(GildedRose
        GildedRose.cpp
        GildedRose.h GildedRoseApp.cpp)

add_executable(GildedRoseExplore
        GildedRose.cpp
        GildedRose.h GildedRoseAppExplore.cpp)

add_executable(GildedRoseTests
        GildedRose.cpp
        GildedRose.h ext/catch.hpp GildedRoseTests.cpp GildedRoseTestImpl.cpp)