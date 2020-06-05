cmake_minimum_required(VERSION 3.16)

project(Matrix)

include_directories(Matrix-linux/)

add_executable(Matrix Matrix-linux/Matrix.cpp Matrix-linux/run-linux.cpp)

