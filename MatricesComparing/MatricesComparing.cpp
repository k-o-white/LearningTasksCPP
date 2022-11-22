#include <iostream>

void input(int array[4][4]) 
{
  for (int i = 0; i < 4; i++) 
  {
    for (int j = 0; j < 4; j++) 
      std::cin >> array[i][j];
  }
}

bool equal(int a[4][4], int b[4][4]) 
{
  for (int i = 0; i < 4; i++) 
  {
    for (int j = 0; j < 4; j++) 
      if (a[i][j] != b[i][j]) return false; 
  }
  return true;
}

void dmatrix(int array[4][4]) 
{
  for (int i = 0; i < 4; i++) 
  {
    for (int j = 0; j < 4; j++) 
      if (i != j) array[i][j] = 0; 
  }

  for (int i = 0; i < 4; i++) 
  {
    for (int j = 0; j < 4; j++) 
      std::cout << array[i][j] << " "; 
    std::cout << std::endl;
  }
}

int main() 
{
  int a[4][4];
  int b[4][4];
  std::cout << "Input values of first matrix: ";
  input(a);
  std::cout << "Input values of second matrix: ";
  input(b);

  if (equal(a, b)) 
    dmatrix(a); 
  else 
    std::cout << "Matrices are not equal." << std::endl;
}
