//
// Created by teena on 22.12.2022.
//

#pragma once
#include <string>
#include <vector>
#include "Talents.h"

class Dog
{
private:
    std::string name;
    std::vector <Talent*> talents;
public:
    Dog();

    ~Dog();

    void addTalent(const int &talentNum);

    void showTalents();
};
