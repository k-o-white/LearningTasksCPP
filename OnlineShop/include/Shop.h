//
// Created by teena on 02.02.2023.
//

#pragma once
#include <map>
#include <string>

class Basket;

class Shop
{
private:
    std::map <std::string, int> goods;
public:
    friend Basket;

    Shop();

    ~Shop() = default;

    void displayGoods();
};