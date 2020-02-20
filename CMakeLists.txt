cmake_minimum_required(VERSION 3.8)
project(GF-SC-Project3)
set(CMAKE_CXX_STANDARD 17)

add_executable(GF-SC-Project3-main battleship.cpp main.cpp destroyer.cpp destroyer.h torpedoes.cpp torpedoes.h)
add_executable(GF-SC-Project3-test battleship.cpp testing.cpp destroyer.cpp destroyer.h torpedoes.cpp torpedoes.h)