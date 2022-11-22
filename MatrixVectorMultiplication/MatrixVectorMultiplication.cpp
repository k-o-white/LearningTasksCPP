#include <iostream>
#include <vector>

int main() 
{
  float a[4][4];
  std::vector <float> b(4);
  std::vector <float> c;

  std::cout << "Input values of 4x4 matrix:\n";
  for (int i = 0; i < 4; i++) 
  {
    for (int j = 0; j < 4; j++) 
      std::cin >> a[i][j];
  }
  
  std::cout << "Input 4 values of vector:\n";
  for (int i = 0; i < 4; i++) 
    std::cin >> b[i];
  
  for (int i = 0; i < 4; i++) 
  {
    float accum = 0;
    for (int j = 0; j < 4; j++) 
      accum += a[i][j] * b[j];
    c.push_back(accum);
  }

  for (int i = 0; i < c.size(); i++) 
    std::cout << c[i] << " ";
}
