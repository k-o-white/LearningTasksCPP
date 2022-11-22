#include <iostream>
#include <iomanip>

int main() 
{
  int n = 5;
  int nums[n][n];
  int number = 0, dir = 1, start = 0, end = n - 1;

  for (int i = 0; i < n; i++) 
  {
    for(int j = start; j != end + dir; j += dir)
      nums[i][j] = number++;
    dir = -dir;
    std::swap(start, end);
  }

  for (int i = 0; i < n; ++i) 
  { 
    for (int j = 0; j < n; ++j) 
      std::cout << std::setw(3) << nums[i][j];
    std::cout << std::endl;
  }
}
