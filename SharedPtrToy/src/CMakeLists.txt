cmake_minimum_required(VERSION 3.23)

add_executable(SharedPtrToy
        main.cpp
        shared_ptr_toy.cpp
        ${MY_INCLUDE_PATH}/Toy.h
        ${MY_INCLUDE_PATH}/shared_ptr_toy.h)

target_include_directories(SharedPtrToy PUBLIC ${MY_INCLUDE_PATH})