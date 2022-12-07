cmake_minimum_required(VERSION 3.23)

add_executable(ElfVillage main.cpp Branch.cpp Village.cpp ${MY_INCLUDE_PATH}/Branch.h ${MY_INCLUDE_PATH}/Village.h)

target_include_directories(ElfVillage PUBLIC ${MY_INCLUDE_PATH})