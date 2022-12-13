//
// Created by teena on 08.12.2022.
//
#include <iostream>
#include "Head.h"

Head::Head(const std::string &name)
{
    this->setEmployeeName(name);
}

Head::~Head()
{
    int teamsCount = this->teams.size();
    for (int i = 0; i < teamsCount; ++i)
    {
        Manager* team = teams[i];
        int employeesCount = team->getEmployeesCount();
        for (int j = 0; j < employeesCount; ++j)
        {
            Employee* employee = team->getEmployee(j);
            delete employee;
        }
        delete team;
    }
}

void Head::addTeam(Manager *newTeam)
{
    this->teams.push_back(newTeam);
}

void Head::setDirective()
{
    int headDirective;
    std::cout << "Input number of head's direction: ";
    std::cin >> headDirective;
    std::system("clear");
    for (int i = 0; i < teams.size(); ++i)
    {
        teams[i]->distributeTask(headDirective);
    }
}

bool Head::isAllTeamsBusy()
{
    for (int i = 0; i < teams.size(); ++i)
    {
        if (!teams[i]->getTeamBusyness())
            return false;
    }
    return true;
}

Head* createCompany()
{
    std::cout << "Input name of company head: ";
    std::string inputName;
    std::cin >> inputName;
    Head* companyHead = new Head(inputName);
    int teamsCount;
    std::cout << "Input count of teams: ";
    std::cin >> teamsCount;
    for (int id = 1; id <= teamsCount; ++id)
    {
        std::string managerName;
        std::cout << "Input manager name of team №" << id << ": ";
        std::cin >> managerName;
        int employeesCount;
        std::cout << "Input count of employees: ";
        std::cin >> employeesCount;
        auto* newTeam = new Manager(managerName, employeesCount, id);
        for (int j = 0; j < employeesCount; ++j)
        {
            std::string employeeName;
            std::cout << "Input name of employee №" << j + 1 << " of team №" << id << ": ";
            std::cin >> employeeName;
            Employee* employee = newTeam->getEmployee(j);
            employee->setEmployeeName(employeeName);
        }
        companyHead->addTeam(newTeam);
    }
    return companyHead;
}

void deleteCompany(Head* companyHead)
{
    delete companyHead;
    companyHead = nullptr;
}