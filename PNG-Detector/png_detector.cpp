#include <iostream>
#include <fstream>

bool isPNG(char* arr)
{
  return *arr == -119 && *(arr + 1) == 'P' && *(arr + 2) == 'N' && 
    *(arr + 3) == 'G';
}

int main()
{
  std::ifstream file;
  std::string path;
  std::cout << "Input path to file: " << std::endl;
  std::cin >> path;
  file.open(path, std::ios::binary);
  while(!file.is_open())
  {
    std::cerr << "Error! Path is invalid. Try again." << std::endl;
    std::cout << "Input path to file: " << std::endl;
    std::cin >> path;
    file.open(path, std::ios::binary);
  }

  char buffer[4];
  char png[] = {-119, 'P', 'N', 'G'};

  file.read(buffer, 4);
  
  if (std::__memcmp(png, buffer, 4) == 0)
    std::cout << "It's PNG-file." << std::endl;
  else
    std::cout << "It's not PNG-file." << std::endl;
  
  file.close();
  return 0;
}
