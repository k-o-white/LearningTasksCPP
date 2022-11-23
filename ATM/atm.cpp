#include <iostream>
#include <fstream>
#include <ctime>

void atmFilling(std::string& path, int* bills);
void withdrawMoney(std::string& path, int* bills);
void billsWitdrawal(int& sum, int *money, int bill);

int main()
{
  int bills[] = {100, 200, 500, 1000, 2000, 5000};
  char input;
  std::cout << "To fill ATM input '+'." << std::endl;
  std::cout << "To withdraw money input '-'." << std::endl;
  std::cin >> input;

  std::string path = "atm.bin";
  switch (input)
  {
    case '+':
      atmFilling(path, bills);
      break;
    case '-':
      withdrawMoney(path, bills);
      break;
    default:
      std::cout << "Input is invalid." << std::endl;
  }
  return 0;
}

void atmFilling(std::string& path, int* bills)
{
  int money[1000];
  std::ifstream atmCheck(path, std::ios::binary);
  if (atmCheck.is_open())
  {
    atmCheck.read((char*)money, sizeof(money));
    atmCheck.close();
  }
  else
  {
    for (int i = 0; i < 1000; ++i)
      money[i] = 0;
  }

  bool flag = false;

  for (int i = 0; i < 1000 && !flag; ++i)
  {
    if (money[i] == 0)
      flag = true;
  }


  if (!flag)
    std::cout << "ATM is already filled." << std::endl;
  else
  {
    std::srand(std::time(nullptr));
    for (int i = 0; i < 1000; ++i)
    {
      if (money[i] == 0)
        money[i] = bills[std::rand() % 6];
    }

    std::ofstream atmFill(path, std::ios::binary);
    atmFill.write((char*)money, sizeof(money));
    atmFill.close();
    std::cout << "ATM is filled now." << std::endl;
  }
}

void withdrawMoney(std::string& path, int* bills)
{
  int money[1000];
  std::ifstream atmCheck(path, std::ios::binary);
  if (atmCheck.is_open())
  {
    atmCheck.read((char*)money, sizeof(money));
    atmCheck.close();
  }
  else
  {
    std::cerr << "Error! File isn't open." << std::endl;
    return;
  }

  int total = 0;
  for (int i = 0; i < 1000; ++i)
  {
    total += money[i];
  }
  std::cout << "Money in ATM: " << total << "." << std::endl;

  int sum;
  std::cout << "Input sum: ";
  std::cin >> sum;

  while (sum % 100 != 0)
  {
    std::cerr << "Error. You must input sum with an accuracy of 100." 
      << std::endl;
    std::cout << "Input sum: ";
    std::cin >> sum;
  }

  for (int i = sizeof(bills) - 1; i >= 0; --i)
  {
    billsWitdrawal(sum, money, bills[i]);
  }

  if (sum == 0)
  {
    std::ofstream atmWithdraw(path, std::ios::binary);
    atmWithdraw.write((char*)money, sizeof(money));
    atmWithdraw.close();
    std::cout << "Money is withdrawn." << std::endl;
  }
  else
  {
    std::cout << "There is not enough money in the ATM." << std::endl;
  }
}

void billsWitdrawal(int& sum, int *money, int bill)
{
  for (int i = 0; i < 1000 && sum >= bill; ++i)
  {
    if (money[i] == bill)
    {
      sum -= bill;
      money[i] = 0;
    }
  }
}
