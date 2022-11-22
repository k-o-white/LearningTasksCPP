#include <iostream>
#include <vector>

int main() 
{
  std::vector <int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  int startInd = 0, endInd = 0, maxSum = 0, currentSum = 0;

  for (int i = 1; i < numbers.size(); i++) 
  {
    currentSum += numbers[i];
    if (currentSum > maxSum)
    {
      maxSum = currentSum;
      endInd = i;
    }
    if (currentSum < 0 && i < numbers.size() - 1)
    {
      currentSum = 0;
      startInd = i + 1;
    }
  }

  std::cout << startInd << " " << endInd << std::endl;
}
