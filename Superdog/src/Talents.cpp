//
// Created by teena on 22.12.2022.
//

#include "Talents.h"

Talent::~Talent() = default;

Swimming::Swimming()
{
    talent = "Swim";
}

std::string Swimming::getTalent()
{
    return talent;
}

Dancing::Dancing()
{
    talent = "Dance";
}

std::string Dancing::getTalent()
{
    return talent;
}

Counting::Counting()
{
    talent = "Count";
}

std::string Counting::getTalent()
{
    return talent;
}