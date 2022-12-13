//
// Created by teena on 08.12.2022.
//

#pragma once
#include "Employee.h"
#include <vector>

class Manager : public Employee
{
private:
    int teamID;
    bool isTeamBusy;
    std::vector <Employee*> team;
public:
    Manager(const std::string &managerName, const int &employeesCount, const int &teamID);

    int getEmployeesCount();

    Employee* getEmployee(int &num);

    void distributeTask(int &directive);

    bool checkBusyness();

    bool getTeamBusyness();
};