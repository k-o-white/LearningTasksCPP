#include <iostream>

#define MON "Monday"
#define TUE "Tuesday"
#define WED "Wednesday"
#define THU "Thursday"
#define FRI "Friday"
#define SAT "Saturday"
#define SUN "Sunday"

#define DAY_OF_WEEK(n) \
((n == (1)) ? MON : (n == (2)) ? TUE : (n == (3)) ? WED : (n == (4)) ? THU : (n == (5)) ? FRI : (n == (6)) ? SAT : SUN)

int main()
{
    int number;
    do
    {
        std::cout << "Input number from 1 to 7: " << std::endl;
        std::cin >> number;
    } while (number < 1 || number > 7);

    std::cout << DAY_OF_WEEK(number) << std::endl;
    return 0;
}
