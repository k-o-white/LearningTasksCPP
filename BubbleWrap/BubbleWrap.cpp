#include <iostream>
#include <iomanip>

void show(bool arr[12][12]) 
{
  for (int i = 0; i < 12; i++) 
  {
    for (int j = 0; j < 12; j++) 
    {
      (arr[i][j]) ? std::cout << std::setw(2) << "o" : std::cout << std::setw(2) << "x";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool validationCheck(int x, int y) 
{
  if (x < 0 || x >= 12 || y < 0 || y >= 12) return false;
  else return true;
}

bool bubblesCheck(bool arr[12][12]) 
{
  for (int i = 0; i < 12; i++) 
  {
    for (int j = 0; j < 12; j++) 
      if (arr[i][j]) return false;
  }
  return true;
}

int main() {
  bool popIt[12][12];

  for (int i = 0; i < 12; i++) 
  {
    for (int j = 0; j < 12; j++) 
      popIt[i][j] = true;
  }

  while (!bubblesCheck(popIt)) 
  {
    show(popIt);
    int startX, startY, endX, endY;
    
    std::cout << "Input coordinates of start: ";
    std::cin >> startX >> startY;
    while (!validationCheck(startX, startY)) 
    {
      std::cout << "Error! Coordinates are invalid. Try again.\n";
      std::cout << "Input coordinates of start: ";
      std::cin >> startX >> startY;
    }
    
    std::cout << "Input coordinates of end: ";
    std::cin >> endX >> endY;
    while (!validationCheck(endX, endY) || endX < startX || endY < startY) 
    {
      std::cout << "Error! Coordinates are invalid. Try again.\n";
      std::cout << "Input coordinates of end: ";
      std::cin >> endX >> endY;
    }
    
    std::cout << std::endl;
    for (int i = startX; i <= endX; i++) 
    {
      for (int j = startY; j <= endY; j++) 
      {
        if (popIt[i][j]) 
        {
          std::cout << "Pop!" << std::endl;
          popIt[i][j] = false;
        }
      }
    }
  }

  show(popIt);
  std::cout << "\nAll the bubbles burst!" << std::endl;
}
