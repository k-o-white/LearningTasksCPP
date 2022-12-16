cmake_minimum_required(VERSION 3.23)

add_executable(Swimmers main.cpp Swimmer.cpp ${MY_INCLUDE_PATH}/Swimmer.h)

target_include_directories(Swimmers PUBLIC ${MY_INCLUDE_PATH})