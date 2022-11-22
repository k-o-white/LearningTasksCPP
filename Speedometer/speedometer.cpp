#include <iostream>
#include <cstdio>

bool speedCompare(float speed, float delta, const float epsilon = 0.01f)
{
  return (speed + delta >= epsilon);
}

int main()
{
  char speed_str[50];
  float speed = 0.f;
  float minSpeed = 0.f;
  float maxSpeed = 150.f;
  float delta;

  std::sprintf(speed_str, "Speed: %.1f", speed);
  std::cout << speed_str << std::endl;
  do
  {
    std::cout << "Input delta speed: ";
    std::cin >> delta;

    while (speed + delta < minSpeed || speed + delta > maxSpeed)
    {
      std::cout << "Input is invalid, try again." << std::endl;
      std::cout << "Input delta speed: ";
      std::cin >> delta;
    }
    
    speed += delta;
    std::sprintf(speed_str, "Speed: %.1f", speed);
    std::cout << speed_str << std::endl;
  } while (speedCompare(speed, delta));

  return 0;
}
