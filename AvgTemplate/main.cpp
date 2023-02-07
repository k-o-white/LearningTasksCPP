#include <iostream>
#include <exception>

class TypesException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid type of array.";
    }
};

template <typename T>
bool isNumber(T var)
{
    if (sizeof(var) != sizeof(int) && sizeof(var) != sizeof(long) && sizeof(var) != sizeof(long long) &&
        sizeof(var) != sizeof(float) && sizeof(var) != sizeof(double) && sizeof(var) != sizeof(long double))
        return false;
    return true;
}

template <typename T>
void input(T *array, unsigned int size)
{
    std::cout << "Fill the array (" << size << "): ";
    for (int i = 0; i < size; ++i)
        std::cin >> array[i];
}

template <typename T>
T avg(T *array, unsigned int size)
{
    if (!isNumber(array[0]))
        throw TypesException();

    T sum = 0;

    for (int i = 0; i < size; ++i)
        sum += array[i];

    return (sum / (T)size);
}

int main()
{
    try
    {
        int size = 3;
        int intArr[size];
        float floatArr[size];
        char charArr[size];
        input(intArr, size);
        std::cout << avg(intArr, size) << std::endl;
        input(floatArr, size);
        std::cout << avg(floatArr, size) << std::endl;
        input(charArr, size);
        std::cout << avg(charArr, size) << std::endl;
    }
    catch (const TypesException &error)
    {
        std::cerr << "Error! " << error.what() << std::endl;
    }
    return 0;
}