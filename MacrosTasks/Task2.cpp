#include <iostream>

#define WINTER 0
#define SPRING 1
#define SUMMER 2
#define AUTUMN 3

#define SEASON SUMMER

#define PRINT_SEASON(n) ((n == 0) ? "Winter" : (n == 1) ? "Spring" : (n == 2) ? "Summer" : "Autumn")

int main()
{
#if SEASON >= 0 && SEASON <= 3
    std::cout << PRINT_SEASON(SEASON) << std::endl;
#else
    std::cout << "Wrong code." << std::endl;
#endif
    return 0;
}
