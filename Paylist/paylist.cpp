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

  int maxMoney = 0;
  int sum = 0;
  std::string maxMoneyName;
  while(!file.eof())
  {
    int money;
    std::string name, surname, date;
    file >> name >> surname >> money >> date;
    sum += money;
    if (money > maxMoney)
    {
      maxMoney = money;
      maxMoneyName = name + " " + surname;
    }
  }

  std::cout << sum << std::endl;
  std::cout << maxMoneyName << std::endl;
  file.close();
  return 0;
}
