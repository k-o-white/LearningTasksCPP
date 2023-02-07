//
// Created by teena on 02.02.2023.
//

#include <iostream>
#include "Basket.h"

void Basket::addGood(Shop &s, const std::string &code, int count)
{
    bool found = false;
    for (auto it = s.goods.begin(); it != s.goods.end() && !found; ++it)
    {
        if (it->first == code)
        {
            found = true;
            if (it->second < count)
                throw std::invalid_argument(reinterpret_cast<const char *>(count));
            else
            {
                it->second -= count;
                this->goods.insert(std::pair{code, count});
                std::cout << "Good with code " << code << " added to basket." << std::endl;
                std::cout << "Count: " << count << "." << std::endl;
            }
        }
    }
    if (!found)
        throw std::invalid_argument(code);
}

void Basket::removeGood(Shop &s, const std::string &code, int count)
{
    bool found = false;
    for (auto it = this->goods.begin(); it != this->goods.end() && !found; ++it)
    {
        if (it->first == code)
        {
            found = true;
            if (it->second < count)
                throw std::invalid_argument(reinterpret_cast<const char *>(count));
            it->second -= count;
            s.goods[code] += count;
            this->goods.erase(code);
            std::cout << "Good with code " << code << " removed from basket." << std::endl;
        }
    }
    if (!found)
        throw std::invalid_argument(code);
}

void Basket::displayGoods()
{
    std::cout << "Goods in the basket:" << std::endl;
    for (auto& it : goods)
        std::cout << it.first << ", count: " << it.second << "." << std::endl;
    std::cout << std::endl;
}