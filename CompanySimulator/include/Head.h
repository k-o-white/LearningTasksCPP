//
// Created by teena on 08.12.2022.
//

#pragma once
#include "Manager.h"


class Head : public Employee
{
private:
    std::vector <Manager*> teams;
public:
    explicit Head(const std::string &name);

    ~Head();

    void addTeam(Manager* newTeam);

    void setDirective();

    bool isAllTeamsBusy();
};

Head* createCompany();

void deleteCompany(Head* companyHead);