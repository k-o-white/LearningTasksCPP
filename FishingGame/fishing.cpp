#include <iostream>
#include <fstream>

int main()
{
  std::string neededFish;
  std::cout << "Input fish you want to catch: ";
  std::cin >> neededFish;

  std::ifstream river("river.txt");
  if(!river.is_open())
  {
    std::ofstream riverTemp("river.txt");
    riverTemp << "sunfish" << std::endl;
    riverTemp << "shad" << std::endl;
    riverTemp << "carp" << std::endl;
    riverTemp << "bass" << std::endl;
    riverTemp << "bullhead" << std::endl;
    riverTemp << "carp" << std::endl;
    riverTemp << "walleye" << std::endl;
    riverTemp << "catfish" << std::endl;
    riverTemp << "carp" << std::endl;
    riverTemp.close();
    river.open("river.txt");
  }
  std::ofstream basket("basket.txt", std::ios::app);

  int counter = 0;
  while(!river.eof())
  {
    std::string fish;
    river >> fish;
    if (fish == neededFish)
    {
      basket << fish << std::endl;
      ++counter;
    }
  }

  river.close();
  basket.close();
  std::cout << "Number of fish caught: " << counter << std::endl;
  return 0;
}
