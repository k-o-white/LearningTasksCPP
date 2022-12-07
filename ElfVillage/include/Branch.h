//
// Created by teena on 07.12.2022.
//

#pragma once
#include <string>
#include <vector>

class Branch
{
private:
    std::string name = "None";
    Branch* parent = nullptr;
    std::vector <Branch*> childrens;
public:

    void setName(std::string &name);

    std::string getName();

    void addChildren(Branch* newChildren);

    int getChildrensCount();

    Branch* getChildren(int &num);

    void settleElves();

    void findElf(const std::string &searchName, int treeNum, bool &found);

    int countOfNeighbours(const std::string &searchName);
};

