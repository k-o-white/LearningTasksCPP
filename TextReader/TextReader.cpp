#include <iostream>
#include <fstream>

int main()
{
  std::ifstream file;
  std::string path;
  std::cout << "Input path to .txt file: " << std::endl;
  std::cin >> path;
  file.open(path, std::ios::binary);
  while(!file.is_open())
  {
    std::cerr << "Error! Path is invalid. Try again." << std::endl;
    std::cout << "Input path to .txt file: " << std::endl;
    std::cin >> path;
    file.open(path, std::ios::binary);
  }

  while(!file.eof())
  {
    char output[21];
    file.read(output, sizeof(output) - 1);
    if(file.gcount() < sizeof(output) - 1)
      output[file.gcount()] = 0;
    else
      output[sizeof(output) - 1] = 0;
    
    for(int i = 0; output[i] != '\0'; ++i)
    {
      if (output[i] != '\n')
        std::cout << output[i];
    }
  }
  file.close();
  return 0;
}
