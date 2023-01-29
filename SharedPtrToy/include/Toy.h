//
// Created by teena on 25.01.2023.
//

#pragma once
#include <string>

class Toy
{
private:
    std::string name;
public:
    Toy() : name("SomeToy") {}

    explicit Toy(std::string _name) : name(std::move(_name)) {}

    std::string getName()
    {
        return this->name;
    }
};
