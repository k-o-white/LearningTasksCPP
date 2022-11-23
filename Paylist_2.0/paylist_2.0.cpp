#include <iostream>
#include <fstream>
#include <vector>

struct record
{
  std::string name = "";
  std::string surname = "";
  int sum = 0;
  std::string date = "";
};

void addRecord();
void printList();

int main()
{
  std::string command;
  std::cout << "Input command ('list' or 'add'): " << std::endl;
  std::cin >> command;

  if (command == "add")
    addRecord();
  else if (command == "list")
    printList();
  else
  {
    std::cerr << "Wrong command." << std::endl;
    return 1;
  }  
  return 0;
}

void addRecord()
{
  std::ofstream file("according_record.txt", std::ios::app);
  record person;
  std::cout << "Input name: ";
  std::cin >> person.name;
  std::cout << "Input surname: ";
  std::cin >> person.surname;
  std::cout << "Input sum: ";
  std::cin >> person.sum;
  std::cout << "Input date(DD.MM.YYYY): ";
  std::cin >> person.date;
  file << person.name << " " << person.surname << " ";
  file << person.sum << " " << person.date << std::endl;
  std::cout << "Record is added." << std::endl;
  file.close();
}

void printList()
{
  std::ifstream file("according_record.txt");
  std::vector <record> persons;
  while (!file.eof())
  {
    record person;
    file >> person.name;
    if (person.name.empty()) break;
    file >> person.surname >> person.sum >> person.date;
    persons.push_back(person);
  }

  for (int i = 0; i < persons.size() - 1; ++i)
  {
    std::cout << persons[i].name << " " << persons[i].surname << " ";
    std::cout << persons[i].sum << " " << persons[i].date;
    std::cout << std::endl;
  }
  file.close();
}
