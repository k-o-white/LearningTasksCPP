//
// Created by teena on 22.12.2022.
//

#include <iostream>
#include "Dog.h"

bool isalpha(std::string &str)
{
    for (char i : str)
    {
        if (i < 'A' || (i > 'Z' && i < 'a') || i > 'z')
            return false;
    }
    return true;
}

enum Talents
{
    SWIMMING = 1, DANCING, COUNTING
};


Dog::Dog()
{
    std::cout << "Input dog's name: ";
    std::cin >> name;
    while (!isalpha(name))
    {
        std::cout << "Error! Name must contain only letters. Try again." << std::endl;
        std::cout << "Input dog's name: ";
        std::cin >> name;
    }
}

void Dog::addTalent(const int &talentNum)
{
    Talent* newTalent = nullptr;
    switch (talentNum)
    {
        case SWIMMING:
            newTalent = new Swimming();
            break;
        case DANCING:
            newTalent = new Dancing();
            break;
        case COUNTING:
            newTalent = new Counting();
            break;
        default:
            std::cout << "Error! Number is invalid." << std::endl;
            return;
    }

    for (auto & talent : talents)
    {
        if (newTalent->getTalent() == talent->getTalent())
        {
            std::cout << this->name << " already has this talent." << std::endl;
            return;
        }
    }
    talents.push_back(newTalent);
}

void Dog::showTalents()
{
    if (!talents.empty())
    {
        std::cout << "This is " << this->name << " and it has some talents:" << std::endl;
        for (auto & t : talents)
            std::cout << "It can \"" << t->getTalent() << "\"" << std::endl;
    }
    else
        std::cout << "This is " << this->name << " and it has no talents." << std::endl;
}

Dog::~Dog()
{
    for (auto & talent : talents)
    {
        delete talent;
        talent = nullptr;
    }
}