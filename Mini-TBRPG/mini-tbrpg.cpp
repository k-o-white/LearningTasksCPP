#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <ctime>

enum Directions
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Position
{
  int x = -1;
  int y = -1;
};

struct Character
{
  std::string name = "unknown";
  int health = 0;
  int armor = 0;
  int damage = 0;
  Position pos;
};

void initializeCharacters(Character &player, Character* enemies);
bool checkPositions(Position &tempPos, 
                    std::vector <Position> &usedPos);
void displayField(char field[20][20], 
                  Character &player, 
                  Character* enemies);
void gameplay(Character &player, 
              Character* enemies, 
              const std::string &symbol);
void enemiesMoving(Character &enemy, Character* enemies);
void damage(Character &chrctr, int damage);
void saveGame(Character &player, Character* enemies);
bool loadGame(Character &player, Character* enemies);
bool gameOver(Character &player, Character* enemies);
void displayResults(Character &player, Character* enemies);

int main()
{
  char playingField[20][20];
  Character player;
  Character enemies[5];

  std::srand(std::time(nullptr));
  std::string start;
  do
  {
    std::cout << "To start new game input \"new\"." << std::endl;
    std::cout << "To load game input \"load\"." << std::endl;
    std::cin >> start;
  } while (start != "new" && start != "load");

  if (start == "load")
  {
    if (loadGame(player, enemies))
      std::cout << "Game loaded." << std::endl << std::endl;
    else
    {
      std::cout << "Save file isn't open. You'll start a new game." 
        << std::endl;
      goto new_game;
    }
  }
  else
  {
    new_game:
    initializeCharacters(player, enemies);
  }

  displayField(playingField, player, enemies);

  while (!gameOver(player, enemies))
  {
    std::string cmd;
    std::cout << "Input command: ";
    std::cin >> cmd;

    if (cmd == "w" || cmd == "a" || cmd == "s" || cmd == "d")
    {
      gameplay(player, enemies, cmd);
      displayField(playingField, player, enemies);
    }
    else if (cmd == "save")
    {
            saveGame(player, enemies);
            std::cout << "Game saved." << std::endl;
    }
    else if (cmd == "load")
    {
      if (loadGame(player, enemies))
      {
        std::cout << "Game loaded." << std::endl;
        displayField(playingField, player, enemies);
      }
      else
        std::cerr << "Save file isn't open. You'll continue current game." << std::endl;
    }
    else
      std::cerr << "Invalid command." << std::endl;
  }

  displayResults(player, enemies);
  return 0;
}

void initializeCharacters(Character &player, Character* enemies)
{
  std::cout << "Input character name: ";
  std::cin >> player.name;
  std::cout << "Input character health: ";
  std::cin >> player.health;
  std::cout << "Input character armor: ";
  std::cin >> player.armor;
  std::cout << "Input character damage: ";
  std::cin >> player.damage;

  std::vector <Position> usedPositions;
  player.pos.x = rand() % 20;
  player.pos.y = rand() % 20;
  usedPositions.push_back(player.pos);
  for (int i = 0; i < 5; ++i)
  {
    //min + rand() % (max - min);
    enemies[i].name = "Enemy #" + std::to_string(i + 1);
    enemies[i].health = 50 + rand() % 101;
    enemies[i].armor = rand() % 51;
    enemies[i].damage = 15 + rand() % 16;
    do
    {
      enemies[i].pos.x = rand() % 20;
      enemies[i].pos.y = rand() % 20;
    } while (checkPositions(enemies[i].pos, usedPositions));
    usedPositions.push_back(enemies[i].pos);
  }
}

bool checkPositions(Position &tempPos, std::vector <Position> &usedPos)
{
  for (int i = 0; i < usedPos.size(); ++i)
  {
    if (tempPos.x == usedPos[i].x && tempPos.y == usedPos[i].y)
      return true;
  }
  return false;
}

void displayField(char field[20][20], 
                  Character &player, 
                  Character* enemies)
{
  for (int i = 0; i < 20; ++i)
  {
    for (int j = 0; j < 20; ++j)
      field[i][j] = '.';
  }

  if (player.health > 0)
    field[player.pos.x][player.pos.y] = 'P';

  for (int i = 0; i < 5; ++i)
  {
    if (enemies[i].health > 0)
      field[enemies[i].pos.x][enemies[i].pos.y] = 'E';
  }

  std::cout << std::endl;
  for (int i = 0; i < 20; ++i)
  {
    for (int j = 0; j < 20; ++j)
      std::cout << std::setw(2) << field[i][j];
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void gameplay(Character &player, 
              Character* enemies, 
              const std::string &symbol)
{
  Position currentPlayerPos = player.pos;
  // player moving
  switch (symbol[0])
  {
    case 'w':
      if (player.pos.x > 0) --player.pos.x;
      break;
    case 's':
      if (player.pos.x < 19) ++player.pos.x;
      break;
    case 'a':
      if (player.pos.y > 0) --player.pos.y;
      break;
    case 'd':
      if (player.pos.y < 19) ++player.pos.y;
      break;
  }

  for (int i = 0; i < 5; ++i)
  {
    if (player.pos.x == enemies[i].pos.x 
        && player.pos.y == enemies[i].pos.y && enemies[i].health > 0)
    {
      damage(enemies[i], player.damage);
      player.pos = currentPlayerPos;
      break;
    }
  }

    // enemies moving

  for (int i = 0; i < 5; ++i)
  {
    Position currentEnemyPos = enemies[i].pos;
    enemiesMoving(enemies[i], enemies);

    if (player.pos.x == enemies[i].pos.x && 
        player.pos.y == enemies[i].pos.y && player.health > 0)
    {
      damage(player, enemies[i].damage);
      enemies[i].pos = currentEnemyPos;
      break;
    }
  }
}

void enemiesMoving(Character &enemy, Character* enemies)
{
  int possibleDirs[] = {UP, DOWN, LEFT, RIGHT};
  int dir = possibleDirs[rand() % 4];
  switch (dir)
  {
    case UP:
      if (enemy.pos.x > 0)
      {
        bool match = false;
        for (int i = 0; i < 5 && !match; ++i)
        {
          if (enemy.pos.x == enemies[i].pos.x && 
              enemy.pos.y == enemies[i].pos.y) continue;
          match = enemy.pos.x - 1 == enemies[i].pos.x && 
                  enemy.pos.y == enemies[i].pos.y;
        }
        if (!match) --enemy.pos.x;
      }
      break;
    case DOWN:
      if (enemy.pos.x < 19)
      {
        bool match = false;
        for (int i = 0; i < 5 && !match; ++i)
        {
          if (enemy.pos.x == enemies[i].pos.x && 
              enemy.pos.y == enemies[i].pos.y) continue;
          match = enemy.pos.x + 1 == enemies[i].pos.x && 
                  enemy.pos.y == enemies[i].pos.y;
        }
        if (!match) ++enemy.pos.x;
      }
      break;
    case LEFT:
      if (enemy.pos.y > 0)
      {
        bool match = false;
        for (int i = 0; i < 5 && !match; ++i)
        {
          if (enemy.pos.x == enemies[i].pos.x && 
              enemy.pos.y == enemies[i].pos.y) continue;
          match = enemy.pos.x == enemies[i].pos.x && 
                  enemy.pos.y - 1 == enemies[i].pos.y;
        }
        if (!match) --enemy.pos.y;
      }
      break;
    case RIGHT:
      if (enemy.pos.y < 19)
      {
        bool match = false;
        for (int i = 0; i < 5 && !match; ++i)
        {
          if (enemy.pos.x == enemies[i].pos.x && 
              enemy.pos.y == enemies[i].pos.y) continue;
          match = enemy.pos.x == enemies[i].pos.x && 
                  enemy.pos.y + 1 == enemies[i].pos.y;
        }
        if (!match) ++enemy.pos.y;
      }
      break;
    }
}

void damage(Character &chrctr, int damage)
{
  chrctr.armor -= damage;
  if (chrctr.armor < 0)
  {
    chrctr.health += chrctr.armor;
    chrctr.armor = 0;
  }
  std::cout << chrctr.name << " took damage " << damage << std::endl;
  if (chrctr.health <= 0)
  {
    chrctr.health = 0;
    chrctr.pos.x = -1;
    chrctr.pos.y = -1;
    std::cout << chrctr.name << " is dead." << std::endl;
  }
}

void saveGame(Character &player, Character* enemies)
{
  std::vector <Character> chars;
  chars.push_back(player);
  for (int i = 0; i < 5; ++i)
    chars.push_back(enemies[i]);
  std::ofstream save("save_file.bin", std::ios::binary);
  for (int i = 0; i < chars.size(); ++i)
  {
    int len = chars[i].name.length();
    save.write((char*)&len, sizeof(len));
    save.write(chars[i].name.c_str(), len);
    save.write((char*)&chars[i].health, sizeof(chars[i].health));
    save.write((char*)&chars[i].armor, sizeof(chars[i].armor));
    save.write((char*)&chars[i].damage, sizeof(chars[i].damage));
    save.write((char*)&chars[i].pos.x, sizeof(chars[i].pos.x));
    save.write((char*)&chars[i].pos.y, sizeof(chars[i].pos.y));
  }
  save.close();
}

bool loadGame(Character &player, Character* enemies)
{
  std::vector <Character> chars;
  std::ifstream load("save_file.bin", std::ios::binary);
  if (!load.is_open())
    return false;
  int len;
  while (load.read((char*)&len, sizeof(len)))
  {
    Character tempCh;
    tempCh.name.resize(len);
    load.read((char*)tempCh.name.c_str(), len);
    load.read((char*)&tempCh.health, sizeof(tempCh.health));
    load.read((char*)&tempCh.armor, sizeof(tempCh.armor));
    load.read((char*)&tempCh.damage, sizeof(tempCh.damage));
    load.read((char*)&tempCh.pos.x, sizeof(tempCh.pos.x));
    load.read((char*)&tempCh.pos.y, sizeof(tempCh.pos.y));
    chars.push_back(tempCh);
  }
  player = chars[0];
  for (int i = 0; i < 5; ++i)
    enemies[i] = chars[i + 1];
  load.close();
  return true;
}

bool gameOver(Character &player, Character* enemies)
{
  bool enemiesAlive = false;
  for (int i = 0; i < 5 && !enemiesAlive; ++i)
  {
    if (enemies[i].health > 0)
      enemiesAlive = true;
  }
  return player.health == 0 || !enemiesAlive;
}

void displayResults(Character &player, Character* enemies)
{
  std::cout << ((player.health == 0) ? "You lose." : "You win.") << std::endl;
}
