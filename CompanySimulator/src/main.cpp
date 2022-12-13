#include <iostream>
#include "Head.h"

int main()
{
    std::cout << "---------- Company simulator ----------" << std::endl;
    auto* company = createCompany();

    while (!company->isAllTeamsBusy())
        company->setDirective();

    deleteCompany(company);
    return 0;
}
