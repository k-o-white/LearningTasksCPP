//
// Created by teena on 08.12.2022.
//

#include "Manager.h"

Manager::Manager(const std::string &managerName, const int &employeesCount)
{
    this->setEmployeeName(managerName);
    for (int i = 0; i < employeesCount; ++i)
    {
        auto* newEmployee = new Employee;
        this->team.push_back(newEmployee);
    }
}

int Manager::getEmployeesCount()
{
    return this->team.size();
}

Employee* Manager::getEmployee(int &num)
{
    if (num < 0) return nullptr;
    if (num >= this->team.size()) return nullptr;
    return this->team[num];
}