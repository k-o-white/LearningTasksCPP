cmake_minimum_required(VERSION 3.23)

add_executable(Shape main.cpp Circle.cpp Rectangle.cpp Triangle.cpp
        ${MY_INCLUDE_PATH}/Shape.h ${MY_INCLUDE_PATH}/Circle.h ${MY_INCLUDE_PATH}/Rectangle.h
        ${MY_INCLUDE_PATH}/Triangle.h)

target_include_directories(Shape PUBLIC ${MY_INCLUDE_PATH})