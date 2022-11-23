#include <iostream>
#include <string>
#include <vector>
#include <map>

void instruction();
void addNumber(std::map <std::string, std::string> &phonebook);
bool numberValidation(std::string &number);
void findNumber(std::map <std::string, std::string> &phonebook);
void findSurname(std::map <std::string, std::string> &phonebook);

int main()
{
  std::map <std::string, std::string> phonebook;
  phonebook.insert(std::pair<std::string, std::string>("70-70-70", "Sidorov"));
  phonebook.insert(std::pair<std::string, std::string>("48-15-16", "Ivanov"));
  phonebook.insert(std::pair<std::string, std::string>("16-23-42", "Petrov"));
  phonebook.insert(std::pair<std::string, std::string>("55-35-35", "Ivanov"));
  std::string cmd;
  std::cout << "--- Phonebook ---" << std::endl;
  instruction();
  std::cout << "Input command: ";
  std::cin >> cmd;
    
  while (cmd != "exit")
  {
    if (cmd == "add")
      addNumber(phonebook);
    else if (cmd == "number")
      findNumber(phonebook);
    else if (cmd == "surname")
      findSurname(phonebook);
    else
      std::cout << "Invalid command." << std::endl;

    instruction();
    std::cout << "Input command: ";
    std::cin >> cmd;
  }

  return 0;
}

void instruction()
{
  std::cout << std::endl << "To add number to phonebook input \"add\"." << std::endl;
  std::cout << "To find number by surname in phonebook input \"number\"." << std::endl;
  std::cout << "To find surname by number in phonebook input \"surname\"." << std::endl;
  std::cout << "To finish program input \"exit\"." << std::endl;
}

void addNumber(std::map <std::string, std::string> &phonebook)
{
  std::cout << "Input number and surname: " << std::endl;
  std::string line;
  std::cin.ignore();
  std::getline(std::cin, line);
  if(line.length() < 11 || line[8] != ' ')
  /*длина номера - строго 8 символов, плюс пробел, плюс хотя бы два символа в фамилии, итого 11, если в строке меньше символов, то функция закончит работу. 
  Так же функция прекратит работу если между номером и фамилией нет пробела.*/
  {
    std::cerr << "Input is invalid." << std::endl;
    return;
  }
  std::string number = line.substr(0, 8);
  if (!numberValidation(number))
  {
    std::cerr << "Number is invalid." << std::endl;
    return;
  }
  std::string surname = line.substr(9, line.length());
  phonebook.insert(std::pair<std::string, std::string>(number, surname));
  std::cout << "Number is added to phonebook." << std::endl;
}

bool numberValidation(std::string &number)
{
  for (int i = 0; i < number.length(); ++i)
  {
    if (((i == 2 || i == 5) && number[i] != '-') || 
      (((i != 2 && i != 5)) && number[i] < '0' || number[i] > '9'))
      return false;
  }
  return true;
}

void findNumber(std::map <std::string, std::string> &phonebook)
{
  std::cout << "Input surname: ";
  std::string surname;
  std::cin >> surname;

  bool found = false;
  std::vector <std::string> fNumbers;
  for (auto it = phonebook.begin(); 
    it != phonebook.end() && !found; ++it)
  {
    found = it->second == surname;
    if (found)
    {
      while (it->second == surname)
      {
        fNumbers.push_back(it->first);
        ++it;
      }
    }
  }

  if (!fNumbers.empty())
  {
    std::cout << "Found numbers:" << std::endl;
    for (int i = 0; i < fNumbers.size(); ++i)
      std::cout << fNumbers[i] << std::endl;
  }
  else
  {
    std::cout << "No numbers found." << std::endl;
  }
}

void findSurname(std::map <std::string, std::string> &phonebook)
{
  std::cout << "Input number: ";
  std::string number;
  std::cin >> number;
  bool found = false;
  std::string answer;
  for (auto it = phonebook.begin(); 
    it != phonebook.end() && !found; ++it)
  {
    found = it->first == number;
    if (found) answer = it->second;
  }

  std::cout << ((found) ? answer : "No surname found.") << std::endl;
}
