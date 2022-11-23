#include <iostream>
#include <fstream>

int main()
{
  std::ifstream file;
  std::string path;
  std::cout << "Input path to .txt file: " << std::endl;
  std::cin >> path;
  file.open(path);
  while(!file.is_open())
  {
    std::cerr << "Error! Path is invalid. Try again." << std::endl;
    std::cout << "Input path to .txt file: " << std::endl;
    std::cin >> path;
    file.open(path);
  }

  std::string searchWord;
  std::cout << "Input word to search: ";
  std::cin >> searchWord;
  int counter = 0;
  while(!file.eof())
  {
    std::string word;
    file >> word;
    if(word == searchWord) ++counter;
  }
  file.close();
  std::cout << counter << std::endl;
  return 0;
}
