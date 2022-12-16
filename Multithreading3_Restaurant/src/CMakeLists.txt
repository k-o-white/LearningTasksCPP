cmake_minimum_required(VERSION 3.23)

add_executable(Restaurant main.cpp restaurant.cpp ${MY_INCLUDE_PATH}/restaurant.h)

target_include_directories(Restaurant PUBLIC ${MY_INCLUDE_PATH})