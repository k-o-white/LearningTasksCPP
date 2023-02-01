cmake_minimum_required(VERSION 3.23)
project("AnalyseJSON")

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(AnalyseJSON main.cpp)

target_link_libraries(AnalyseJSON PRIVATE nlohmann_json::nlohmann_json)