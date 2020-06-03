cmake_minimum_required(VERSION 3.16)

project(Matrix)

include_directories(Matrix/)

add_executable(Matrix Matrix/Matrix.cpp Matrix/run.cpp)

