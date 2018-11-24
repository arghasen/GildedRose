cmake_minimum_required(VERSION 3.12)
project(GildedRose)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GildedRose
        GildedRose.cpp
        GildedRose.h GildedRoseApp.cpp)

add_executable(GildedRoseExplore
        GildedRose.cpp
        GildedRose.h GildedRoseAppExplore.cpp)

add_executable(GildedRoseTests
        GildedRose.cpp
        GildedRose.h ext/catch.hpp GildedRoseTests.cpp GildedRoseTestImpl.cpp)