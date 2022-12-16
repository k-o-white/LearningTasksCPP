//
// Created by teena on 16.12.2022.
//
#pragma once
#include <mutex>
#include <vector>

enum dishes
{
    NONE = 0, PIZZA, SOUP, STEAK, SALAD, SUSHI
};

std::string getDish(const dishes &dish);

void newOrder(std::vector <dishes> *orders);

void kitchenWork(std::vector <dishes> *orders, std::vector <dishes> *ready);

void deliveryWork(std::vector <dishes> *ready);