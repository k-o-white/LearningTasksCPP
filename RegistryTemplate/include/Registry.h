//
// Created by teena on 02.02.2023.
//

#pragma once
#include <map>
#include <vector>

template <typename T>
T input();

template <typename T1, typename T2>
class Registry
{
private:
    std::multimap<T1, T2> registry;
public:
    Registry() = default;

    ~Registry() = default;

    void add();

    void remove();

    void print();

    void find();
};
