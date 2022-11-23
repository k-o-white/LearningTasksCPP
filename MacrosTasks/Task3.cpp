#include <iostream>

#define MAX_PASSENGERS_COUNT 20
#define CHECK_WAGONS(array, func, result) for(const auto& value: array) { (result) += ((func(value)) ? (1) : (0)); }
#define COUNT_TOTAL(array, result) for(const auto& value: array) { (result) += (value); }

void fillTrain(int* train, int wagCount);
bool overcrowdedWagon(int count);
bool notFilledWagon(int count);

int main()
{
  int train[10];
  fillTrain(train, 10);

  int overcrowdedWagonsCount = 0;
  int notFilledWagonsCount = 0;
  int passengersCount = 0;

  CHECK_WAGONS(train, overcrowdedWagon, overcrowdedWagonsCount);
  CHECK_WAGONS(train, notFilledWagon, notFilledWagonsCount);
  COUNT_TOTAL(train, passengersCount);

  std::cout << "Total passengers count:      " << passengersCount;
  std::cout << std::endl;
  std::cout << "Overcrowded wagons count:    " << overcrowdedWagonsCount;
  std::cout << std::endl;
  std::cout << "Not fullfilled wagons count: " << notFilledWagonsCount; 
  std::cout << std::endl;
  return 0;
}

void fillTrain(int* train, int wagCount)
{
  if (wagCount > 1)
    fillTrain(train, wagCount - 1);

  std::cout << "Enter count of passengers on " << wagCount << " wagon: ";
  std::cin >> train[wagCount - 1];
}

bool overcrowdedWagon(int count)
{
  return count > MAX_PASSENGERS_COUNT;
}

bool notFilledWagon(int count)
{
  return count < MAX_PASSENGERS_COUNT;
}
