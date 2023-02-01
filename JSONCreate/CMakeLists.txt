cmake_minimum_required(VERSION 3.23)
project("CreateJSON")

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(CreateJSON main.cpp)

target_link_libraries(CreateJSON PRIVATE nlohmann_json::nlohmann_json)