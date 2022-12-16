//
// Created by teena on 16.12.2022.
//
#include <vector>
#include <thread>
#include <iostream>
#include "restaurant.h"

std::mutex restaurant_access;
std::mutex delivery_access;

std::string getDish(const dishes &dish)
{
    std::string result;
    switch (dish)
    {
        case NONE:
            result = "none";
            break;
        case PIZZA:
            result = "pizza";
            break;
        case SOUP:
            result = "soup";
            break;
        case STEAK:
            result = "steak";
            break;
        case SALAD:
            result = "salad";
            break;
        case SUSHI:
            result = "sushi";
            break;
    }
    return result;
}

void newOrder(std::vector <dishes> *orders)
{
    std::srand(std::time(nullptr));
    while (true)
    {
        int time = rand() % 6 + 5;
        std::this_thread::sleep_for(std::chrono::seconds(time));
        dishes newOrder = dishes(rand() % 5 + 1);
        restaurant_access.lock();
        orders->push_back(newOrder);
        restaurant_access.unlock();
        std::cout << "New order: " << getDish(newOrder) << "." << std::endl;
    }
}

void kitchenWork(std::vector <dishes> *orders, std::vector <dishes> *ready)
{
    std::srand(std::time(nullptr));
    while (true)
    {
        if(!orders->empty())
        {
            restaurant_access.lock();
            dishes cookingDish = orders->at(0);
            orders->erase(orders->begin());
            restaurant_access.unlock();
            std::cout << "Cooking: " << getDish(cookingDish) << "." << std::endl;
            int time = rand() % 11 + 5;
            std::this_thread::sleep_for(std::chrono::seconds(time));
            restaurant_access.lock();
            std::cout << "Ready: " << getDish(cookingDish) << "." << std::endl;
            ready->push_back(cookingDish);
            restaurant_access.unlock();
        }
    }
}

void deliveryWork(std::vector <dishes> *ready)
{
    int deliveryCount = 0;
    while (deliveryCount < 10)
    {
        if(!ready->empty())
        {
            std::this_thread::sleep_for(std::chrono::seconds(30));
            delivery_access.lock();
            std::vector <dishes> deliveryDishes;
            while (!ready->empty())
            {
                dishes dish = ready->at(0);
                ready->erase(ready->begin());
                deliveryDishes.push_back(dish);
            }
            std::cout << "The courier took the following dishes for delivery:\n";
            for (auto i : deliveryDishes)
            {
                std::cout << getDish(i) << "\n";
                ++deliveryCount;
            }
            delivery_access.unlock();
        }
    }
}