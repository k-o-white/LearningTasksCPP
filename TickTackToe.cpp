#include <iostream>

void show(char arr[3][3]) 
{
  std::cout << std::endl;
  for (int i = 0; i < 3; i++) 
  {
    std::cout << "|";
    for (int j = 0; j < 3; j++) 
      std::cout << arr[i][j] << "|";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool isWon(char playingField[3][3], char symbol)
{
  for (int i = 0; i < 3; i++) 
  {
    int counter = 0;
    for (int j = 0; j < 3; j++) 
      if (playingField[i][j] == symbol) counter++;
    if (counter == 3) return true;
  }

  for (int i = 0; i < 3; i++) 
  {
    int counter = 0;
    for (int j = 0; j < 3; j++) 
      if (playingField[j][i] == symbol) counter++;
    if (counter == 3) return true;
  }
  
  if (playingField[0][0] == symbol && playingField[1][1] == symbol && 
    playingField[2][2] == symbol || playingField[0][2] == symbol && 
    playingField[1][1] == symbol && playingField[2][0] == symbol) return true;
  
  return false;
}

int main() 
{
  char playingfield[3][3] = {{'_', '_', '_'}, 
                             {'_', '_', '_'}, 
                             {'_', '_', '_'}};
  std::cout << "Welcome to tic-tac-toe game!" << std::endl;
  
  show(playingfield);
  
  char gamerSymbol = 'X';
  int player = 1, counter = 0, x, y;
  
  while (counter < 9) 
  {
    std::cout << "Player " << player << ", input coordinates: ";
    std::cin >> x >> y;

    while (x < 1 || x > 3 || y < 1 || y > 3 || playingfield[x - 1][y - 1] != '_') 
    {
      std::cout << std::endl;
      std::cout << "Error! Wrong coordinates.\n";
      std::cout << "Player " << player << ", input coordinates: ";
      std::cin >> x >> y;
    }
    
    playingfield[x - 1][y - 1] = gamerSymbol;
    show(playingfield);
    ++counter;
    
    if (counter >= 5) 
    {
      if (isWon(playingfield, gamerSymbol)) 
      {
        std::cout << "Player " << player << " won!" << std::endl;
        break;
      }
    }
    
    if (gamerSymbol == 'X' && player == 1) 
    {
      gamerSymbol = 'O';
      player = 2;
    } 
    else 
    {
      gamerSymbol = 'X';
      player = 1;
    }
  }

  if (!isWon(playingfield, 'X') && !isWon(playingfield, 'O')) 
    std::cout << "Draw!" << std::endl;
}
