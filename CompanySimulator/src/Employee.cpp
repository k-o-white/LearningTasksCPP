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

TaskType Employee::getTask()
{
    return task;
}

void Employee::getTask(const TaskType &task)
{
    this->task = task;
}
