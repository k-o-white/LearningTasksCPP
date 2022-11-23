#include <iostream>
#include <string>
#include <map>

bool isAnagram(std::string sFirst, std::string sSecond);

int main()
{
  std::cout << "Input first string: " << std::endl;
  std::string firstStr;
  std::getline(std::cin, firstStr);

  std::cin.clear();
  std::cout << "Input second string: " << std::endl;
  std::string secondStr;
  std::getline(std::cin, secondStr);

  std::cout << (isAnagram(firstStr, secondStr) ? "It's anagram" 
    : "It's not anagram") << std::endl;
  return 0;
}

bool isAnagram(std::string sFirst, std::string sSecond)
{
  if (sFirst.length() != sSecond.length()) return false;
  int len = sFirst.length();
  std::map <char, int> letters1;
  std::map <char, int> letters2;
  for (int i = 0; i < len; ++i)
  {
    sFirst[i] = toupper(sFirst[i]);
    letters1[sFirst[i]] += 1;
    sSecond[i] = toupper(sSecond[i]);
    letters2[sSecond[i]] += 1;
  }

  return letters1 == letters2;
}
