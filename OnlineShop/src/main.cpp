#include <iostream>
#include "Shop.h"
#include "Basket.h"

enum actions {ADD = 1, REMOVE, DISPLAY_SHOP, DISPLAY_BASKET};

void instruction()
{
    std::cout << "1 - add;" << std::endl;
    std::cout << "2 - remove;" << std::endl;
    std::cout << "3 - display goods in the shop;" << std::endl;
    std::cout << "4 - display goods in your basket." << std::endl;
}

int main()
{
    Shop shop;
    Basket basket;
    while (true)
    {
        std::system("cls");
        int input;
        instruction();
        std::cout << "Input command: ";
        std::cin >> input;

        try
        {
            std::string code;
            int count;
            if (input == ADD || input == REMOVE)
            {
                std::cout << "Input code: ";
                std::cin >> code;
                std::cout << "Input count: ";
                std::cin >> count;
            }
            switch (input)
            {
                case ADD:
                    basket.addGood(shop, code, count);
                    break;
                case REMOVE:
                    basket.removeGood(shop, code, count);
                    break;
                case DISPLAY_SHOP:
                    shop.displayGoods();
                    break;
                case DISPLAY_BASKET:
                    basket.displayGoods();
                    break;
                default:
                    std::cout << "Incorrect command." << std::endl;
            }
        }
        catch (const std::invalid_argument &error)
        {
            std::cout << "Invalid argument: " << error.what() << std::endl;
        }

        char answer = '\0';
        while (answer != 'y' && answer != 'n')
        {
            std::cout << "Continue? (y/n): ";
            std::cin >> answer;
        }
        if (answer == 'n') break;
    }
    return 0;
}
