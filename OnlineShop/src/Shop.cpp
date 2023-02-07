//
// Created by teena on 02.02.2023.
//

#include <iostream>
#include "Shop.h"

Shop::Shop()
{
    int n;
    std::cout << "Input count of goods in the shop: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string code;
        std::cout << "Input code of good: ";
        std::cin >> code;
        int count;
        std::cout << "Input count of good: ";
        std::cin >> count;
        goods.insert({code, count});
    }
}

void Shop::displayGoods()
{
    std::cout << "Goods in the shop:" << std::endl;
    for (auto& it : goods)
        std::cout << it.first << ", count: " << it.second << "." << std::endl;
    std::cout << std::endl;
}