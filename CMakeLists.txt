cmake_minimum_required(VERSION 3.2)

project(lab2)

add_executable(lab2
        main.cpp
        Money.cpp
        )

set_property(TARGET lab2 PROPERTY CXX_STANDART 17)
