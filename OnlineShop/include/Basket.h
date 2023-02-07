//
// Created by teena on 02.02.2023.
//

#pragma once
#include "Shop.h"

class Basket
{
private:
    std::map <std::string, int> goods;
public:
    Basket() = default;

    ~Basket() = default;

    void addGood(Shop &s, const std::string& code, int count);

    void removeGood(Shop &s, const std::string& code, int count);

    void displayGoods();
};