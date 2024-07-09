cmake_minimum_required(VERSION 3.18)
project(
    car_lorry_project
    VERSION 0.0.0
    DESCRIPTION "Car and Lorry classes"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(car_lorry_project main.cpp Car.cpp Lorry.cpp)
