cmake_minimum_required(VERSION 3.23)

add_executable(GeometricFigures main.cpp Figures.cpp ${MY_INCLUDE_PATH}/Figures.h)

target_include_directories(GeometricFigures PUBLIC ${MY_INCLUDE_PATH})