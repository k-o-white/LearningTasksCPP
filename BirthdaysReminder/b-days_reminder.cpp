#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

struct PersonBDay
{
  std::string name = "unknown";
  std::tm date;
};

void inputNames();
void addBirthday(std::string &name);
void calculateNearestBDay();
bool isNearest(PersonBDay &birthday, 
               std::tm &currentTime, 
               std::tm &nearestTime);
int daysCount(std::tm &date);
void printBDays();

std::vector <PersonBDay> personsBDays;
std::vector <PersonBDay> todayBDays;
std::vector <PersonBDay> nearestBDays;

std::time_t t = std::time(nullptr);
std::tm local = *std::localtime(&t);

int main()
{
  inputNames();
  calculateNearestBDay();
  printBDays();
  return 0;
}

void inputNames()
{
  std::string tempName;
  std::cout << "Input name or \"end\" to finish names input: ";
  std::cin >> tempName;
  while (tempName != "end")
  {
    addBirthday(tempName);
    std::cout << "Input name or \"end\" to finish names input: ";
    std::cin >> tempName;
  }
}

void addBirthday(std::string &name)
{
  PersonBDay tempPerson;
  tempPerson.name = name;
  tempPerson.date = local;
  std::cout << "Input birthday on format YYYY/MM/DD: ";
  std::cin >> std::get_time(&tempPerson.date, "%Y/%m/%d");
  personsBDays.push_back(tempPerson);
}

void calculateNearestBDay()
{
  std::tm curTime = local;
  std::tm nearestBDayTime;
  for (int i = 0; i < personsBDays.size(); ++i)
  {
    if (daysCount(personsBDays[i].date) == daysCount(curTime))
      todayBDays.push_back(personsBDays[i]);
    else
    {
      if (nearestBDays.empty())
      {
        nearestBDays.push_back(personsBDays[i]);
        nearestBDayTime = personsBDays[i].date;
      }
      else
      {
        if (daysCount(personsBDays[i].date) == 
          daysCount(nearestBDayTime))
        {
          nearestBDays.push_back(personsBDays[i]);
        }
        else
        {
          if (isNearest(personsBDays[i], curTime, nearestBDayTime))
          {
            nearestBDays.clear();
            nearestBDays.push_back(personsBDays[i]);
            nearestBDayTime = personsBDays[i].date;
          }
        }
      }
    }
  }
}

bool isNearest(PersonBDay &birthday, 
               std::tm &currentTime, 
               std::tm &nearestTime)
{
  if (daysCount(nearestTime) < daysCount(currentTime))
  {
    if (daysCount(birthday.date) < daysCount(nearestTime) ||
        daysCount(birthday.date) > daysCount(currentTime))
      return true;
  }
  else
  {
    if (daysCount(birthday.date) > daysCount(currentTime) &&
        daysCount(birthday.date) < daysCount(nearestTime))
      return true;
  }
  return false;
}

int daysCount(std::tm &date)
{
  int totalDays = 0;
  int day = date.tm_mday;
  int mon = date.tm_mon;
  int year = date.tm_year;

  for (int i = 0; i < mon; ++i)
  {
    if (i == 3 || i == 5 || i == 8 || i == 10)
      totalDays += 30;
    else
    {
      if (i == 2)
      {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
          totalDays += 29;
        else
          totalDays += 28;
      }
      else
        totalDays += 31;
      }
  }
  totalDays += day;

  return totalDays;
}

void printBDays()
{
  if (!todayBDays.empty())
  {
    std::cout << std::endl << "Today (" 
      << std::put_time(&local, "%m/%d") << ") birthdays:" << std::endl;
    for (auto person: todayBDays)
      std::cout << person.name << std::endl;
  }

  if (!nearestBDays.empty())
  {
    if (nearestBDays.size() > 1)
    {
      std::cout << std::endl << "Nearest birthdays:" << std::endl;
      for (auto person: nearestBDays)
      {
        std::cout << person.name << ": " 
          << std::put_time(&person.date, "%m/%d") << std::endl;
      }
    }
    else
    {
      std::cout << std::endl << "Nearest birthday:" << std::endl;
      std::cout << nearestBDays[0].name << ": " 
        << std::put_time(&nearestBDays[0].date, "%m/%d");
      std::cout << std::endl;
    }
  }
}
