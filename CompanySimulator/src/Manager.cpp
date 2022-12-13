//
// Created by teena on 08.12.2022.
//
#include <iostream>
#include "Manager.h"


Manager::Manager(const std::string &managerName, const int &employeesCount, const int &teamID)
{
    this->setEmployeeName(managerName);
    this->isTeamBusy = false;
    this->teamID = teamID;
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

void Manager::distributeTask(int &directive)
{
    if (!isTeamBusy)
    {
        std::srand(this->teamID + directive);
        int tasksCount = rand() % (this->team.size() + 1);
        std::cout << "Manager " << this->getEmployeeName() << " has got " << tasksCount << " tasks." << std::endl;
        for (int i = 0; i < team.size() && tasksCount > 0; ++i)
        {
            TaskType newTask = TaskType(rand() % AmountTask);
            if (newTask != None && !team[i]->isBusy())
            {
                team[i]->setTask(newTask);
                std::cout << team[i]->getEmployeeName() << " has got task " << team[i]->getTask() << ".";
                std::cout << std::endl;
                --tasksCount;
            }
        }
        isTeamBusy = this->checkBusyness();
        if (isTeamBusy)
            std::cout << "Team №" << this->teamID << " is busy now." << std::endl;
    }
    else
    {
        std::cout << "Team №" << this->teamID << " is busy now." << std::endl;
    }
}

bool Manager::checkBusyness()
{
    for (int i = 0; i < team.size(); ++i)
    {
        if (!team[i]->isBusy())
            return false;
    }
    return true;
}

bool Manager::getTeamBusyness()
{
    return this->isTeamBusy;
}
