//
// Created by teena on 07.12.2022.
//
#include <iostream>
#include <ctime>
#include "Village.h"

Village::Village()
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < countOfTrees; ++i)
    {
        Branch* tree = new Branch;
        std::cout << "Tree №" << i + 1 << "." << std::endl;
        int bigBranchesCount = std::rand() % 3 + 3;
        for (int j = 0; j < bigBranchesCount; ++j)
        {
            Branch* bigBranch = new Branch;
            int middleBranchesCount = std::rand() % 2 + 2;
            for (int k = 0; k < middleBranchesCount; ++k)
            {
                Branch* middleBranch = new Branch;
                bigBranch->addChildren(middleBranch);
            }
            tree->addChildren(bigBranch);
        }
        tree->settleElves();
        trees.push_back(tree);
    }
}

Village::~Village()
{
    for (int i = 0; i < countOfTrees; ++i)
    {
        Branch* tree = trees[i];
        int bigBranchesCount = tree->getChildrensCount();
        for (int j = 0; j < bigBranchesCount; ++j)
        {
            Branch* bigBranch = tree->getChildren(j);
            int middleBranchesCount = bigBranch->getChildrensCount();
            for (int k = 0; k < middleBranchesCount; ++k)
            {
                Branch* middleBranch = bigBranch->getChildren(k);
                delete middleBranch;
            }
            delete bigBranch;
        }
        delete tree;
        tree = nullptr;
    }
}

void Village::findTree(const std::string &searchName)
{
    bool found = false;
    for (int i = 0; i < countOfTrees && !found; ++i)
        trees[i]->findElf(searchName, i + 1, found);
    if (!found)
        std::cout << "Elf not found." << std::endl;
}