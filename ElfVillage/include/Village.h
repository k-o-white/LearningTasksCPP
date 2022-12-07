//
// Created by teena on 07.12.2022.
//
#pragma once
#include <vector>
#include "Branch.h"

class Village
{
private:
    const int countOfTrees = 5;
    std::vector <Branch*> trees;
public:
    Village();

    ~Village();

    void findTree(const std::string &searchName);
};
