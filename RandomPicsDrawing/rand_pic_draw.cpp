#include <iostream>
#include <fstream>
#include <ctime>

int main() 
{
  std::srand(std::time(nullptr));
  int height, width;
  std::cout << "Input width and height: " ;
  std::cin >> height >> width;

  int pic[height][width];
  std::ofstream file("pic.txt", std::ios::app);
  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width; ++j)
    {
      pic[i][j] = std::rand() % 2;
      file << pic[i][j];
    }
    file << std::endl;
  }

  file.close();
  return 0;
}
