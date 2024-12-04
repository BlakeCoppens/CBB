cmake_minimum_required(VERSION 3.28)
project(CBB)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CBB
        credits.cpp
        credits.h
        creditswindow.cpp
        creditswindow.h
        main.cpp
        mainwindow.cpp
        mainwindow.h
        MovieClass.h
        MovieMaxHeap.h
        MovieTree.h)
