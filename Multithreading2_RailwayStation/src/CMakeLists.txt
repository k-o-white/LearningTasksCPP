cmake_minimum_required(VERSION 3.23)

add_executable(RailwayStation main.cpp Train.cpp ${MY_INCLUDE_PATH}/Train.h)

target_include_directories(RailwayStation PUBLIC ${MY_INCLUDE_PATH})