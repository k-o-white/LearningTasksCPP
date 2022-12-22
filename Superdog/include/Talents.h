//
// Created by teena on 22.12.2022.
//

#pragma once
#include <string>

class Talent
{
protected:
    std::string talent;
public:
    virtual std::string getTalent() = 0;

    virtual ~Talent();
};

class Swimming : virtual public Talent
{
public:
    Swimming();

    virtual std::string getTalent();
};

class Dancing : virtual public Talent
{
public:
    Dancing();

    virtual std::string getTalent();
};

class Counting : virtual public Talent
{
public:
    Counting();

    virtual std::string getTalent();
};
