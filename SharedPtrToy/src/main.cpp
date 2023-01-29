#include <iostream>
#include <vector>
#include "shared_ptr_toy.h"

int main()
{
    std::vector <shared_ptr_toy> toys = {make_shared_toy("Car"), make_shared_toy("Doll")};
    toys[0] = toys[1];
    toys.push_back(make_shared_toy(toys[0]));
    toys.push_back(make_shared_toy());
    for (auto toy : toys)
        std::cout << toy.getToyName() << std::endl;
    return 0;
}
