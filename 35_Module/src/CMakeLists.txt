cmake_minimum_required(VERSION 3.23)

add_executable(35_Module main.cpp tasks.cpp ${MY_INCLUDE_PATH}/tasks.h)

target_include_directories(35_Module PUBLIC ${MY_INCLUDE_PATH})