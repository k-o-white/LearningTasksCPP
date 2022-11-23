#include <iostream>
#include <iomanip>
#include <ctime>

int main() 
{
  std::tm timer;
  std::cout << "Input time in format MM:SS: ";
  std::cin >> std::get_time(&timer, "%M:%S");

  std::time_t timeStop = 
    std::time(nullptr) + timer.tm_min * 60 + timer.tm_sec;
  bool stop = false;
  while (!stop)
  {
    std::system("clear");
    std::time_t delta = timeStop - std::time(nullptr);
    std::tm* leftTime = std::localtime(&delta);
    std::cout << std::put_time(leftTime, "%M:%S") << std::endl;
    stop = delta == 0;
  }
  std::cout << "DING! DING! DING!" << std::endl;
  return 0;
}
