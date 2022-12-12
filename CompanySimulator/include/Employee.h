//
// Created by teena on 08.12.2022.
//

#pragma once
#include <string>
#include "TaskType.h"



class Employee
{
private:
    std::string name = "unknown";
    TaskType task = None;
public:

    std::string getEmployeeName();

    void setEmployeeName(const std::string &name);

    TaskType getTask();

    void getTask(const TaskType &task);
};
