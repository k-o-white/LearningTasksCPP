#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Contact
{
private:
  std::string name;
  std::string number;
public:
  std::string getName()
  {
    return name;
  }

  void setName(const std::string &newName)
  {
    name = newName;
  }

  std::string getNumber()
  {
    return number;
  }

  void setNumber(const std::string &newNumber)
  {
    number = newNumber;
  }
};

class Phone
{
private:
  std::string number;
public:
  std::vector <Contact> phoneContacts;
  std::string getPhoneNumber()
  {
    return number;
  }

  void setPhoneNumber()
  {
    number += "+7";
    for(int i = 0; i < 10; ++i)
      number += std::to_string(std::rand() % 10);
  }

  void add()
  {
    std::system("clear");
    Contact newContact;
    std::string nName, nNumber;
    std::cout << "Input name: ";
    std::cin >> nName;
    newContact.setName(nName);
    std::cout << "Input number: ";
    std::cin >> nNumber;
    while (!checkNumberValidation(nNumber))
    {
      std::cout << "Number is incorrect. Try again." << std::endl;
      std::cout << "Input number: ";
      std::cin >> nNumber;
    }
    newContact.setNumber(nNumber);
    phoneContacts.push_back(newContact);
    std::cout << "Contact \"" << newContact.getName() << "\" is added.";
    std::cout << std::endl;
  }

  void call()
  {
    std::system("clear");
    std::string input;
    std::cout << "Input number or name of contact: ";
    std::cin >> input;
    Contact callingContact;
    bool found = false;
    for (int i = 0; i < phoneContacts.size() && !found; ++i)
    {
      if (input == phoneContacts[i].getName() || 
        input == phoneContacts[i].getNumber())
      {
        callingContact = phoneContacts[i];
        found = true;
      }
    }
    if (found)
    {
      std::cout << "Calling " << callingContact.getName() << "..."; 
      std::cout << std::endl;
    }
    else
    {
      std::cout << "Contact not found." << std::endl;
    }
  }

  void sms()
  {
    std::system("clear");
    std::string input;
    std::cout << "Input number or name of contact: ";
    std::cin >> input;
    Contact messageContact;
    bool found = false;
    for (int i = 0; i < phoneContacts.size() && !found; ++i)
    {
      if (input == phoneContacts[i].getName() || 
        input == phoneContacts[i].getNumber())
      {
        messageContact = phoneContacts[i];
        found = true;
      }
    }
    if (found)
    {
      std::string message;
      std::cin.ignore();
      std::cout << "Input message: " << std::endl;
      std::getline(std::cin, message);
      std::cout << "Message is sent to "; 
      std::cout << messageContact.getName() << "." << std::endl;
    }
    else
    {
      std::cout << "Contact not found." << std::endl;
    }
  }

  void displayContacts()
  {
    std::system("clear");
    if (phoneContacts.empty())
      std::cout << "You have no contacts on your phone." << std::endl;
    else
    {
      for (auto i: phoneContacts)
      {
        std::cout << "Name: " << i.getName() << std::endl;
        std::cout << "Number: " << i.getNumber() << std::endl;
        std::cout << std::endl;
      }
    }
  }

  static bool checkNumberValidation(const std::string &newNumber)
  {
    if (newNumber.length() != 12 || 
      (newNumber[0] != '+' && newNumber[1] != '7'))
      return false;
    for (int i = 2; i < newNumber.length(); ++i)
    {
      if (newNumber[i] < '0' || newNumber[i] > '9')
        return false;
    }
    return true;
  }
};


void instruction()
{
  std::cout << std::endl;
  std::cout << "-------------- How to use it --------------";
  std::cout << std::endl;
  std::cout << "add     - add new contact;" << std::endl;
  std::cout << "call    - make a phone call;" << std::endl;
  std::cout << "sms     - send sms-message;" << std::endl;
  std::cout << "list    - print your contacts list;" << std::endl;
  std::cout << "num     - display your phone number;" << std::endl;
  std::cout << "exit    - finish program." << std::endl;
  std::cout << "-------------------------------------------";
  std::cout << std::endl;
}

int main()
{
  std::srand(std::time(nullptr));
  std::cout << "Welcome to phone program!" << std::endl;
  Phone* myPhone = new Phone();
  myPhone->setPhoneNumber();
  instruction();
  std::string cmd;
  std::cout << "Input command: ";
  std::cin >> cmd;
  while (cmd != "exit")
  {
    if (cmd == "add")
      myPhone->add();
    else if (cmd == "call")
      myPhone->call();
    else if (cmd == "sms")
      myPhone->sms();
    else if (cmd == "list")
      myPhone->displayContacts();
    else if (cmd == "num")
    {
      std::system("clear");
      std::cout << "Your number is " << myPhone->getPhoneNumber();
      std::cout << "." << std::endl;
    }
    else
      std::cout << "Invalid command." << std::endl;
    
    instruction();
    std::cout << "Input command: ";
    std::cin >> cmd;
  }
  delete myPhone;
  myPhone = nullptr;
  return 0;
}
