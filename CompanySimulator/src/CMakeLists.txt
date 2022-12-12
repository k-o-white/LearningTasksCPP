cmake_minimum_required(VERSION 3.23)

add_executable(CompanySimulator main.cpp Employee.cpp Manager.cpp Head.cpp
        ${MY_INCLUDE_PATH}/Employee.h ${MY_INCLUDE_PATH}/Manager.h ${MY_INCLUDE_PATH}/Head.h ${MY_INCLUDE_PATH}/TaskType.h)

target_include_directories(CompanySimulator PUBLIC ${MY_INCLUDE_PATH})