#include <iostream>

void show(char arr[10][10]) 
{
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) 
  {
    std::cout << "|";
    for (int j = 0; j < 10; j++) 
      std::cout << arr[i][j] << "|";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void addShip(const int player, bool arr[10][10], int size) 
{
  if (size == 1) 
  {
    int x, y;
    std::cin >> x >> y;

    // Проверяем, не выходят ли координаты за пределы поля
    while (x < 0 || x > 9 || y < 0 || y > 9) 
    {
      std::cout << "Error! Coordinates can't be more than 9 and less than 0. ";
      std::cout << "Try again: ";
      std::cin >> x >> y;
    }

    // Проверяем, не занято ли место другим кораблём
    while (arr[x][y] == true) 
    {
      std::cout << "Error! This place is already taken. ";
      std::cout << "Try again: ";
      std::cin >> x >> y;
    }
    
    arr[x][y] = true;
  } 
  else 
  {
    int startx, starty, endx, endy;
    std::cin >> startx >> starty >> endx >> endy;

    // Проверяем, не выходят ли координаты за пределы поля
    while (startx < 0 || startx > 9 || starty < 0 || starty > 9 || endx < 0 || 
      endx > 9 || endy < 0 || endy > 9) 
    {
      std::cout << "Error! Coordinates can't be more than 9 and less than 0. ";
      std::cout << "Try again: ";
      std::cin >> startx >> starty >> endx >> endy;
    }

    // Проверяем, не лежит ли корабль по диагонали
    while (startx != endx && starty != endy) 
    {
      std::cout << "Error! Coordinates must lie only horizontally or vertically. ";
      std::cout << "Try again: ";
      std::cin >> startx >> starty >> endx >> endy; 
    } 

    // Проверяем, соответствует ли размер корабля заявленному
    while (endx - startx != size - 1 && endy - starty != size - 1) 
    {
      std::cout << "Error! Wrong size of ship. ";
      std::cout << "Try again: ";
      std::cin >> startx >> starty >> endx >> endy;
    } 
    
    // Проверяем, нет ли других кораблей в пределах введёных коордиант 
    bool flag = false;

    while (!flag)
    {
      if (startx == endx) 
      {
        bool flag2 = true;
        for (int i = starty; i <= endy && flag2; i++)
        {
          if (arr[startx][i]) 
          {
            flag2 = false;
            std::cout << "Error! This place is already taken. ";
            std::cout << "Try again: ";
            std::cin >> startx >> starty >> endx >> endy; 
          }
        }
        if (!flag2) continue;
      } 
      else
      {
        bool flag2 = true;
        for (int i = startx; i <= endx && flag2; i++)
        {
          if (arr[i][starty])
          {
            flag2 = false;
            std::cout << "Error! This place is already taken. ";
            std::cout << "Try again: ";
            std::cin >> startx >> starty >> endx >> endy; 
          }
        }
        if (!flag2) continue;
      }
      flag = true;
    }

    // Если введённые координаты соответствуют всем условиям, располагаем корабль на поле
    if (startx == endx) 
    {
      for (int i = starty; i <= endy; i++)
        arr[startx][i] = true;
    } 
    else
    {
      for (int i = startx; i <= endx; i++)
        arr[i][starty] = true;
    }
  }
}

void addShips(const int player, bool arr[10][10])
{
  std::cout << "Player " << player << std::endl; 
  std::cout << "Input coordinates of one ship with four cells:" << std::endl;
  addShip(player, arr, 4);
  std::cout << "Input coordinates of two ships with three cells:" << std::endl; 
  for (int i = 0; i < 2; i++)
    addShip(player, arr, 3);
  std::cout << "Input coordinates of three ships with two cells:" << std::endl; 
  for (int i = 0; i < 3; i++)
    addShip(player, arr, 2);
  std::cout << "Input coordinates of four ships with one cells:" << std::endl; 
  for (int i = 0; i < 4; i++)
    addShip(player, arr, 1);
}

void shoot(const int player, bool arr[10][10], char field[10][10]) 
{
  int x, y;
  
  std::cout << "Player " << player << ", input coordinates: "; 
  std::cin >> x >> y;
  while (x < 0 || x > 9 || y < 0 || y > 9) 
  {
    std::cout << "Error! Wrong coordinates. Try again." << std::endl;
    std::cout << "Player " << player << ", input coordinates: "; 
    std::cin >> x >> y;
  }

  while (field[x][y] != '_') 
  {
    std::cout << "You've already shot this cell. Try again." << std::endl;
    std::cout << "Player " << player << ", input coordinates: "; 
    std::cin >> x >> y;
  }
  

  if (arr[x][y] == true) 
  {
    arr[x][y] = false;
    field[x][y] = 'X';
    show(field);
    std::cout << "Hit!\n" << std::endl;
  } 
  else 
  {
    field[x][y] = 'O';
    show(field);
    std::cout << "Missed!\n" << std::endl;
  }
}

bool isWon(const int player, bool arr[10][10]) 
{
  for (int i = 0; i < 10; i++) 
  {
    for (int j = 0; j < 10; j++) 
      if (arr[i][j]) return false;
  }
  return true;
}

int main() 
{
  // Массивы полей игроков для расстановки кораблей
  bool field1[10][10];
  bool field2[10][10];
  // Массивы полей для отметки ударов по вражеском полю
  char field_1[10][10];
  char field_2[10][10];
  
  for (int i = 0; i < 10; i++) 
  {
    for (int j = 0; j < 10; j++) 
    {
      field1[i][j] = false;
      field2[i][j] = false;
      field_1[i][j] = '_';
      field_2[i][j] = '_';
    }
  }

  addShips(1, field1);
  addShips(2, field2);

  while (true) 
  {
    shoot(1, field2, field_1);
    if (isWon(1, field2))
    {
      std::cout << "Player 1 won!" << std::endl;
      break;
    }
    shoot(2, field1, field_2);
    if (isWon(2, field1)) 
    {
      std::cout << "Player 2 won!" << std::endl;
      break;
    }    
  }
}
