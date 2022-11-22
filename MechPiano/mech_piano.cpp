#include <iostream>
#include <string>

enum notes
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

bool isInputCorrect(int chord)
{
    std::string strChord = std::to_string(chord);
    for (int i = 0; i < strChord.length(); ++i)
    {
        if (strChord[i] < '1' || strChord[i] > '7')
            return false;
    }
    return true;
}

void printNotes(int notes)
{
    if (notes & DO)
        std::cout << "DO ";
    if (notes & RE)
        std::cout << "RE ";
    if (notes & MI)
        std::cout << "MI ";
    if (notes & FA)
        std::cout << "FA ";
    if (notes & SOL)
        std::cout << "SOL ";
    if (notes & LA)
        std::cout << "LA ";
    if (notes & SI)
        std::cout << "SI ";
}

int main()
{
    int melody[12];

    for (int i = 0; i < 12; ++i)
    {
        int chord;
        std::cout << "Input notes: ";
        std::cin >> chord;
        while (!isInputCorrect(chord))
        {
            std::cout << "Input is incorrect, notes must be from 1 to 7. ";
            std::cout << "Try again.\nInput notes: ";
            std::cin >> chord;
        }
        melody[i] = 0;
        while (chord > 0)
        {
            melody[i] |= 1 << ((chord % 10) - 1);
            chord /= 10;
        }
    }

    for (int i = 0; i < 12; ++i)
    {
        printNotes(melody[i]);
        std::cout << std::endl;
    }
    return 0;
}
