#include <iostream>
#include "Head.h"

int main()
{
    std::cout << "---------- Company simulator ----------" << std::endl;
    auto* company = createCompany();
    //
    deleteCompany(company);
    return 0;
}
