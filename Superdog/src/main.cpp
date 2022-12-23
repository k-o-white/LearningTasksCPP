#include <iostream>
#include <vector>
#include <Dog.h>

void instruction()
{
    std::cout << "-------------" << std::endl;
    std::cout << "1 - swimming;" << std::endl;
    std::cout << "2 - dancing;" << std::endl;
    std::cout << "3 - counting." << std::endl;
    std::cout << "-------------" << std::endl;
}

int main()
{
    Dog* newDog = new Dog();
    int numTalent;
    while (true)
    {
        instruction();
        std::cout << "Input new talent or 0 to finish: ";
        std::cin >> numTalent;
        if (numTalent == 0) break;
        newDog->addTalent(numTalent);
    }
    newDog->showTalents();
    delete newDog;
    newDog = nullptr;
    return 0;
}
