#include <iostream>
#include <string>
#include <map>

bool isalpha(std::string &line);
bool isupper(char &letter);

int main()
{
  std::map <std::string, int> queue;
  queue["Ivanov"] = 1;
  std::string cmd;

  while (!queue.empty())
  {
    std::cout << "Input surname or command \"Next\": ";
    std::cin >> cmd;
    while(!isalpha(cmd))
    {
      std::cout << "You must input only only alphabetic characters!" << std::endl;
      std::cout << "Input surname or command \"Next\": ";
      std::cin >> cmd;
    }
    while(!isupper(cmd[0]))
    {
      std::cout << "First letter must be upper-case!" << std::endl;
      std::cout << "Input surname or command \"Next\": ";
      std::cin >> cmd;
    }
    if (cmd == "Next")
    {
      std::map <std::string, int>::iterator next = queue.begin();
      std::cout << "Calling " << next->first << "." << std::endl;
      if (next->second > 1)
        --next->second;
      else
        queue.erase(next);
    }
    else
    {
      queue[cmd] += 1;
      std::cout << cmd << " is queued up." << std::endl;
    }
  }

  return 0;
}

bool isalpha(std::string &line)
{
  for (char i : line)
  {
    if (i < 'A' || (i > 'Z' && i < 'a') || i > 'z')
      return false;
  }
  return true;
}

bool isupper(char &letter)
{
  return letter >= 'A' && letter <= 'Z';
}
