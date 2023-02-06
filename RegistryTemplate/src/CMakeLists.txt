cmake_minimum_required(VERSION 3.23)

add_executable(Registry main.cpp Registry.cpp ${MY_INCLUDE_PATH}/Registry.h)

target_include_directories(Registry PUBLIC ${MY_INCLUDE_PATH})