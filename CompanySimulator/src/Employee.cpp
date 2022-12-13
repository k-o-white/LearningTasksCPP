//
// Created by teena on 08.12.2022.
//

#include "Employee.h"

std::string Employee::getEmployeeName()
{
    return this->name;
}

void Employee::setEmployeeName(const std::string &name)
{
    this->name = name;
}

std::string Employee::getTask()
{
    std::string result;
    switch (this->task)
    {
        case None:
            result = "None";
            break;
        case A:
            result = "A";
            break;
        case B:
            result = "B";
            break;
        case C:
            result = "C";
            break;
    }
    return result;
}

void Employee::setTask(const TaskType &task)
{
    this->task = task;
}

bool Employee::isBusy()
{
    return this->task != None;
}
