cmake_minimum_required(VERSION 3.23)

add_executable(Graph
        main.cpp
        ListGraph.cpp
        MatrixGraph.cpp
        ${MY_INCLUDE_PATH}/IGraph.h
        ${MY_INCLUDE_PATH}/ListGraph.h
        ${MY_INCLUDE_PATH}/MatrixGraph.h)

target_include_directories(Graph PUBLIC ${MY_INCLUDE_PATH})