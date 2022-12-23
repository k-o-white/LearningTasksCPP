cmake_minimum_required(VERSION 3.23)

add_executable(SuperDog main.cpp Talents.cpp Dog.cpp ${MY_INCLUDE_PATH}/Talents.h ${MY_INCLUDE_PATH}/Dog.h)

target_include_directories(SuperDog PUBLIC ${MY_INCLUDE_PATH})