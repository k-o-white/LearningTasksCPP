#include <iostream>
#include <vector>
#include <cmath>

enum room_type
{
  bedroom = 1,
  kitchen,
  bathroom,
  children,
  living
};

enum buliding_type
{
  BARN = 1,
  GARAGE,
  BATH
};

struct room
{
  std::string roomType = "";
  int square = 0;
};

struct floorStruct
{
  int floorHeight = 0;
  std::vector <room> roomsAmount;
};

struct sector
{
  int number = 0;
  int square = 0;

  struct houseStruct
  {
    int square = 0;
    std::vector <floorStruct> floors;
    bool chimney = false;
  } livingHouse;

  struct barnStruct
  {
    bool enable = false;
    int square = 0;
  } barn;

  struct garageStruct
  {
    bool enable = false;
    int square = 0;
  } garage;

  struct bathStruct
  {
    bool enable = false;
    int square = 0;
    bool chimney = false;
  } bathHouse;
};

sector createSector(int &num);
void createHouse(sector &temp, int &sectorSquare);
room createRoom(int &floorSquare);
int inputSquare(int &emptySquare);
void createBarn(sector &temp, int &sectorSquare);
void createGarage(sector &temp, int &sectorSquare);
void createBathhouse(sector &temp, int &sectorSquare);
char answer();

int totalSquare(std::vector <sector> &village);
int buildingsCount(std::vector <sector> &village);
int bulidingSquare(std::vector <sector> &village);
double buildSquarePercent(std::vector <sector> &village);
void displayResult(std::vector <sector> &village);

int main()
{
  std::vector <sector> village;
  int sectorsCount;
  std::cout << "Input count of sectors: ";
  std::cin >> sectorsCount;
  for (int i = 1; i <= sectorsCount; ++i)
  {
    village.push_back(createSector(i));
  }
  displayResult(village);
  return 0;
}

sector createSector(int &num)
{
  sector tempSector;
  tempSector.number = num;
  std::cout << "Sector " << tempSector.number << "." << std::endl;
  do
  {
    std::cout << "Input sector square: ";
    std::cin >> tempSector.square;
  } while (tempSector.square <= 0);
  
  int emptySquare = tempSector.square;
  createHouse(tempSector, emptySquare);

  int bulidsCount;
  std::cout << "How many bulidings on the sector except the house? ";
  std::cin >> bulidsCount;
    
  std::vector <int> usedNumbers;
  while (bulidsCount > 0 && emptySquare > 0)
  {
    int bulidCode;
    std::cout << "1 - barn;" << std::endl;
    std::cout << "2 - garage;" << std::endl;
    std::cout << "3 - bathhouse." << std::endl;
    std::cout << "Input buliding code: ";
    std::cin >> bulidCode;
        
    bool foundNumber = false;
    for (int i = 0; i < usedNumbers.size() && !foundNumber; ++i)
    {
      if (bulidCode == usedNumbers[i])
        foundNumber = true;
    }
        
    if (foundNumber)
    {
      std::cerr << "This buliding is already placed on the territory. ";
      std::cerr << "Input another number." << std::endl;
      continue;
    }
    else
    {
      switch (bulidCode)
      {
        case BARN:
          usedNumbers.push_back(bulidCode);
          createBarn(tempSector, emptySquare);
          --bulidsCount;
          break;
        case GARAGE:
          usedNumbers.push_back(bulidCode);
          createGarage(tempSector, emptySquare);
          --bulidsCount;
          break;
        case BATH:
          usedNumbers.push_back(bulidCode);
          createBathhouse(tempSector, emptySquare);
          --bulidsCount;
          break;
        default:
          std::cerr << "You need to input number from 1 to 3.";
          std::cerr << std::endl;
      }
    }
  }
  return tempSector;
}


void createHouse(sector &temp, int &sectorSquare)
{
  std::cout << "Input square of house: ";
  temp.livingHouse.square = inputSquare(sectorSquare);
  sectorSquare -= temp.livingHouse.square;
  int floorsCount;
  std::cout << "Input count of floors in living house: ";
  std::cin >> floorsCount;

  while (floorsCount < 1 || floorsCount > 3)
  {
    std::cerr << "Wrong count. Try again." << std::endl;
    std::cout << "Input count of floors in living house: ";
    std::cin >> floorsCount;
  }

  for (int i = 1; i <= floorsCount; ++i)
  {
    int tempSquare = temp.livingHouse.square;
    floorStruct tempFloor;
    std::cout << "Floor " << i << "." << std::endl;
    std::cout << "Input height of the floor: ";
    std::cin >> tempFloor.floorHeight;
    int roomsCounter;
    std::cout << "Input count of rooms on the floor: ";
    std::cin >> roomsCounter;

    while (roomsCounter < 2 || roomsCounter > 4)
    {
      std::cerr << "Wrong count. Try again." << std::endl;
      std::cout << "Input count of rooms on the floor: ";
      std::cin >> roomsCounter;
    }

    while (roomsCounter > 0)
    {
      tempFloor.roomsAmount.push_back(createRoom(tempSquare));
      --roomsCounter;
    }

    temp.livingHouse.floors.push_back(tempFloor);
  }

  std::cout << "Is there chimney on the living house";
  std::cout << "('+' - yes; '-' - no): ";
  char answerChimneyHouse = answer();
  if (answerChimneyHouse == '+')
    temp.livingHouse.chimney = true;
}

room createRoom(int &floorSquare)
{
  room tempRoom;
  int roomCode = 0;
  std::cout << "1 - bedroom;" << std::endl;
  std::cout << "2 - kitchen;" << std::endl;
  std::cout << "3 - bathroom;" << std::endl;
  std::cout << "4 - children room;" << std::endl;
  std::cout << "5 - living room." << std::endl;

  std::vector <int> usedNumbers;
    
  while (roomCode <= 0 || roomCode > 5)
  {
    std::cout << "Input room code: ";
    std::cin >> roomCode;

    bool foundNumber = false;
    for (int i = 0; i < usedNumbers.size() && !foundNumber; ++i)
    {
      if (roomCode == usedNumbers[i])
        foundNumber = true;
    }

    if (foundNumber)
    {
      std::cerr << "This buliding is already placed on the territory.";
      std::cerr << std::endl << "Input another number." << std::endl;
      continue;
    }
    else
    {
      switch (roomCode)
      {
        case bedroom:
          usedNumbers.push_back(roomCode);
          tempRoom.roomType = "Bedroom";
          break;
        case kitchen:
          usedNumbers.push_back(roomCode);
          tempRoom.roomType = "Kitchen";
          break;
        case bathroom:
          usedNumbers.push_back(roomCode);
          tempRoom.roomType = "Bathroom";
          break;
        case children:
          usedNumbers.push_back(roomCode);
          tempRoom.roomType = "Children room";
          break;
        case living:
          usedNumbers.push_back(roomCode);
          tempRoom.roomType = "Living room";
          break;
        default:
          std::cerr << "You need to input number from 1 to 5.";
          std::cerr << std::endl;
      }
    }
  }

  std::cout << "Input room square: ";
  tempRoom.square = inputSquare(floorSquare);
  floorSquare -= tempRoom.square;
  return tempRoom;
}

int inputSquare(int &emptySquare)
{
  int square;
  std::cin >> square;
  while (square <= 0 || square >= emptySquare)
  {
    std::cerr << "Input another value: ";
    std::cin >> square;
  }
  return square;
}

void createBarn(sector &temp, int &sectorSquare)
{
  temp.barn.enable = true;
  std::cout << "Input barn square: ";
  temp.barn.square = inputSquare(sectorSquare);
  sectorSquare -= temp.barn.square;
}

void createGarage(sector &temp, int &sectorSquare)
{
  temp.garage.enable = true;
  std::cout << "Input garage square: ";
  temp.garage.square = inputSquare(sectorSquare);
  sectorSquare -= temp.garage.square;
}

void createBathhouse(sector &temp, int &sectorSquare)
{
  temp.bathHouse.enable = true;
  std::cout << "Input bathhouse square: ";
  temp.bathHouse.square = inputSquare(sectorSquare);
  sectorSquare -= temp.bathHouse.square;

  std::cout << "Is there chimney on the bathouse ('+' - yes; '-' - no): ";
  char answerChimneyBath = answer();
  if (answerChimneyBath == '+')
    temp.bathHouse.chimney = true;
}

char answer()
{
  char answer;
  std::cin >> answer;
  while (answer != '+' && answer != '-')
  {
    std::cerr << "Input is invalid. Try again: ";
    std::cin >> answer;
  }
  return answer;
}

int totalSquare(std::vector <sector> &village)
{
  int total = 0;
  for (int i = 0; i < village.size(); ++i)
  {
    total += village[i].square;
  }
  return total;
}

int buildingsCount(std::vector <sector> &village)
{
  int count = village.size();
  for (int i = 0; i < village.size(); ++i)
  {
    if (village[i].barn.enable) ++count;
    if (village[i].garage.enable) ++count;
    if (village[i].bathHouse.enable) ++count;
  }
  return count;
}

int bulidingSquare(std::vector <sector> &village)
{
  int square = 0;
  for (int i = 0; i < village.size(); ++i)
  {
    square += village[i].livingHouse.square;
    if (village[i].barn.enable)
      square += village[i].barn.square;
    if (village[i].garage.enable)
      square += village[i].garage.square;
      if (village[i].bathHouse.enable)
      square += village[i].bathHouse.square;
  }
  return square;
}

double buildSquarePercent(std::vector <sector> &village)
{
  double percent = ((double)bulidingSquare(village) / (double) totalSquare(village)) * 100;
  percent = round(percent * 10) / 10;
  return percent;
}

void displayResult(std::vector <sector> &village)
{
  std::cout << std::endl;
  std::cout << "Total count of sectors: " << village.size() << ".";
  std::cout << std::endl;
  std::cout << "Total square of the village: " << totalSquare(village);
  std::cout << "." << std::endl;
  std::cout << "Total count of bulidings of the village: ";
  std::cout << buildingsCount(village) << "." << std::endl;
  std::cout << "Total square of bulidings of the village: "; 
  std::cout << bulidingSquare(village) << "." << std::endl;
  std::cout << "Percentage of the square of buildings from the square of the village: ";
  std::cout << buildSquarePercent(village) << "." << std::endl;
}
