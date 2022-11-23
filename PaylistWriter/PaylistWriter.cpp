#include <iostream>
#include <fstream>

bool dateValidation(std::string date)
{
  int day = std::stoi(date.substr(0, 2));
  int month = std::stoi(date.substr(3, 2));
  int year = std::stoi(date.substr(6, 4));
  if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 
    || month == 10 || month == 12) && (day >= 1 && day <= 31)) || ((month == 4 
    || month == 6 || month == 9 || month == 11) && (day >= 1 && day <= 31)) ||
    (month == 2 && (day >= 1 && day <= 29) && (year % 4 == 0 && year % 100 == 0 
    && year % 400 == 0)) || (month == 2 && (day >= 1 && day <= 28)))
    return true;
  return false;
}

int main()
{
  std::ofstream file("accounting_record.txt", std::ios::app);
  bool flag = true;
  while (flag)
  {
    std::string name, surname, date;
    int money;
    std::cout << "Input name: ";
    std::cin >> name;
    std::cout << "Input surname: ";
    std::cin >> surname;
    std::cout << "Input sum: ";
    std::cin >> money;
    std::cout << "Input date(DD.MM.YYYY): ";
    std::cin >> date;
    
    if(!dateValidation(date))
    {
      std::cout << "Wrong date! Try again." << std::endl;
      continue;
    }
    
    file << name << " " << surname << " " << money << " " << date << std::endl;
    char userAnswer = 0;
    while (userAnswer != 'y' && userAnswer != 'n')
    {
      std::cout << "Do you want to make a new record? (y - yes, n - no) ";
      std::cin >> userAnswer;
    }
    flag = userAnswer == 'y';
  }
  file.close();
  return 0;
}
