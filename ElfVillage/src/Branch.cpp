//
// Created by teena on 07.12.2022.
//
#include <iostream>
#include "Branch.h"

void Branch::setName(std::string &name)
{
    this->name = name;
}

std::string Branch::getName()
{
    return this->name;
}

void Branch::addChildren(Branch* newChildren)
{
    this->childrens.push_back(newChildren);
}

int Branch::getChildrensCount()
{
    return this->childrens.size();
}

Branch* Branch::getChildren(int &num)
{
    return this->childrens[num];
}

void Branch::settleElves()
{
    int bigBranchesCount = this->getChildrensCount();
    for (int i = 0; i < bigBranchesCount; ++i)
    {
        std::cout << "Big branch №" << i + 1 << " of " << bigBranchesCount << "." << std::endl;
        Branch* bigBranch = this->getChildren(i);
        int middleBranchesCount = bigBranch->getChildrensCount();
        for (int j = 0; j < middleBranchesCount; ++j)
        {
            std::cout << "Middle branch №" << j + 1 << " of " << middleBranchesCount << "." << std::endl;
            Branch* middleBranch = bigBranch->getChildren(j);
            char answer = '\0';
            do {
                std::cout << "Is somebody living here? (y/n): ";
                std::cin >> answer;
            } while (answer != 'y' && answer != 'n');
            if (answer == 'y')
            {
                std::string inputName;
                std::cout << "Input name of elf, living here: ";
                std::cin >> middleBranch->name;
            }
        }
    }
}

void Branch::findElf(const std::string &searchName, int treeNum, bool &found)
{
    int bigBranchesCount = this->getChildrensCount();
    for (int i = 0; i < bigBranchesCount && !found; ++i)
    {
        Branch* bigBranch = this->getChildren(i);
        int middleBranchesCount = bigBranch->getChildrensCount();
        for (int j = 0; j < middleBranchesCount && !found; ++j)
        {
            Branch* middleBranch = bigBranch->getChildren(j);
            if (middleBranch->name == searchName)
            {
                found = true;
                std::cout << searchName << " is living on a " << j + 1 << " middle branch of ";
                std::cout << i + 1 << " big branch of " << treeNum << " tree." << std::endl;
                std::cout << "Count of neighbours: " << bigBranch->countOfNeighbours(searchName) << "." << std::endl;
            }
        }
    }
}

int Branch::countOfNeighbours(const std::string &searchName)
{
    int neighboursCount = 0;
    int middleBranchesCount = this->getChildrensCount();
    for (int i = 0; i < middleBranchesCount; ++i)
    {
        Branch* middleBranch = this->getChildren(i);
        if (middleBranch->name != "None" && middleBranch->name != searchName)
            ++neighboursCount;
    }
    return neighboursCount;
}
