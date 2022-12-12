//
// Created by teena on 08.12.2022.
//

#pragma once
#include "Employee.h"
#include <vector>

class Manager : public Employee
{
private:
    std::vector <Employee*> team;
public:
    Manager(const std::string &managerName, const int &employeesCount);

    int getEmployeesCount();

    Employee* getEmployee(int &num);
};