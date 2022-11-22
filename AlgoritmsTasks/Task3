#include <iostream>
#include <vector>

std::vector <int> bubbleSort(std::vector <int> numbers)
{
  for (int i = 0; i < numbers.size(); i++) 
  {
    for (int j = 1; j < numbers.size() - i; j++)
    {
      if (numbers[j] < numbers[j - 1])
        std::swap(numbers[j], numbers[j - 1]);
    }
  }
  return numbers;
}

int main() 
{
  std::vector <int> numbers;
  int n;
  
  std::cout << "Input numbers: ";
  std::cin >> n;
  
  while (n != -2) 
  {
    if (n == -1)
    {
      if (numbers.size() < 5) 
      {
        std::cout << "You've entered less than five numbers." << std::endl;
      }
      else
      {
        numbers = bubbleSort(numbers);
        std::cout << numbers[4] << std::endl;
      }
      std::cout << "Input numbers: ";
    }
    else
    {
      numbers.push_back(n);
    }
    std::cin >> n;
  }
}
