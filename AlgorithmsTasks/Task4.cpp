#include <iostream>
#include <vector>
#include <cmath>

int main()
{
  std::vector <int> numbers = {-100, -50, -1, 1, 2, 3, 4};

  int posInd = 0;
  while (posInd < numbers.size() && numbers[posInd] < 0)
    ++posInd; 
  int negInd = posInd - 1;

  while (negInd >= 0 || posInd < numbers.size()) 
  {
    if (negInd >= 0 && (posInd == numbers.size() || numbers[posInd] > -numbers[negInd]))
      std::cout << numbers[negInd--] << " ";
    else 
      std::cout << numbers[posInd++] << " ";
  }
  std::cout << std::endl;
}
