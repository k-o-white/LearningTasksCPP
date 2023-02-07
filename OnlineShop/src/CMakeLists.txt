cmake_minimum_required(VERSION 3.23)

add_executable(OnlineShop
        main.cpp
        Shop.cpp
        Basket.cpp
        ${MY_INCLUDE_PATH}/Shop.h
        ${MY_INCLUDE_PATH}/Basket.h)

target_include_directories(OnlineShop PUBLIC ${MY_INCLUDE_PATH})