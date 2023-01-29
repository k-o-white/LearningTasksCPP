//
// Created by teena on 25.01.2023.
//

#pragma once
#include "Toy.h"

class shared_ptr_toy
{
private:
    Toy* obj = nullptr;
    int* linkCount = nullptr;
public:
    shared_ptr_toy();

    explicit shared_ptr_toy(std::string name);

    shared_ptr_toy(const shared_ptr_toy& oth);

    shared_ptr_toy& operator=(const shared_ptr_toy& oth);

    ~shared_ptr_toy();

    std::string getToyName();
};

shared_ptr_toy make_shared_toy();

shared_ptr_toy make_shared_toy(const std::string &name);

shared_ptr_toy make_shared_toy(const shared_ptr_toy& oth);
