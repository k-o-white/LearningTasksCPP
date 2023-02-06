//
// Created by teena on 02.02.2023.
//

#include <iostream>
#include "Registry.h"

template <typename T>
T input()
{
    T value;
    std::cin >> value;
    return value;
}

template<typename T1, typename T2>
void Registry<T1, T2>::add()
{
    std::cout << "Input key: ";
    T1 key = input<T1>();
    std::cout << "Input value: ";
    T2 value = input<T2>();
    registry.insert(std::pair<T1, T2>{key, value});
}

template<typename T1, typename T2>
void Registry<T1, T2>::remove()
{
    std::cout << "Input key: ";
    T1 key = input<T1>();

    auto find = registry.find(key);
    if (find != registry.end())
        registry.erase(key);
    else
        std::cout << "Not found." << std::endl;
}

template<typename T1, typename T2>
void Registry<T1, T2>::print()
{
    for (auto& it : registry)
        std::cout << it.first << " : " << it.second << "." << std::endl;
    std::cout << std::endl;
}

template<typename T1, typename T2>
void Registry<T1, T2>::find()
{
    std::cout << "Input key: ";
    T1 key = input<T1>();
    std::vector<T2> values;
    for (auto it = registry.begin(); it != registry.end(); ++it)
    {
        if (it->first == key)
            values.push_back(it->second);
    }
    if (values.empty())
        std::cout << "Not found." << std::endl;
    else
    {
        for (auto i : values)
            std::cout << i << " ";
    }
}

