#include <iostream>
#include <string>

bool isIntPartCorrect(std::string num)
{
  for (int i = 0; i < num.length(); ++i)
  {
    if (i == 0 && num[i] == '-') 
      continue;
    if (num[i] < '0' || num[i] > '9')
      return false;
  }
  return true;
}

bool isFrPartCorrect(std::string num)
{
  for (int i = 0; i < num.length(); ++i)
  {
    if (num[i] < '0' || num[i] > '9')
      return false;
  }
  return true;
}

int main()
{
  std::string intPart, frPart;
  std::cout << "Input integer part of number: ";
  std::cin >> intPart;

  while (!isIntPartCorrect(intPart))  
  {
    std::cerr << "Input is incorrect. Try again." << std::endl;
    std::cout << "Input fractional part of a number: ";
    std::cin >> intPart;
  }
  
  std::cout << "Input fractional part of a number: ";
  std::cin >> frPart;
  
  while (!isFrPartCorrect(frPart))  
  {
    std::cerr << "Input is incorrect. Try again." << std::endl;
    std::cout << "Input fractional part of a number: ";
    std::cin >> frPart;
  }
  
  double number = std::stod(intPart + "." + frPart);
  std::cout << "Your number: " << number << std::endl;
  return 0;
}
