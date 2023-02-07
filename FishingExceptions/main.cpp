#include <iostream>
#include <vector>
#include <ctime>

enum Items {EMPTY = 0, FISH, BOOT};

enum Catched {Fish, Boot};

void placeItems(int* field, int size);
bool checkAttempts(std::vector<int>& vec, int num);

int main()
{
    const int field_size = 9;
    int field[field_size];

    for (int i = 0; i < field_size; ++i)
        field[i] = EMPTY;

    placeItems(field, field_size);
    int attemptCount = 0;
    std::vector<int> attempts;
    try
    {
        while (true)
        {
            int sector;
            Input:
            std::cout << "Input sector (1-9): ";
            std::cin >> sector;
            if (sector < 1 || sector > field_size)
            {
                std::cout << "Input is invalid. Try again." << std::endl;
                goto Input;
            }
            if (checkAttempts(attempts, sector))
            {
                std::cout << "You've already been here. Try again." << std::endl;
                goto Input;
            }

            --sector;
            ++attemptCount;
            if (field[sector] == FISH)
                throw Catched::Fish;
            else if (field[sector] == BOOT)
                throw Catched::Boot;
            else
            {
                attempts.push_back(++sector);
                std::cout << "It's empty." << std::endl;
            }
        }
    }
    catch (Catched c)
    {
        switch (c)
        {
            case Fish:
                std::cout << "You've catched a fish!" << std::endl;
                std::cout << "Attempt count: " << attemptCount << "." << std::endl;
                break;
            case Boot:
                std::cout << "You've catched a boot! You lose." << std::endl;
                break;
        }
    }
    return 0;
}

void placeItems(int* field, int size)
{
    std::srand(std::time(nullptr));
    field[std::rand() % size] = FISH;
    for (int bootsCount = 3; bootsCount > 0; --bootsCount)
    {
        int index = std::rand() % size;
        if (field[index] == EMPTY)
            field[index] = BOOT;
        else
            ++bootsCount;
    }
}

bool checkAttempts(std::vector<int>& vec, int num)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == num)
            return true;
    }
    return false;
}