#include <iostream>
#include <string>
#include <sstream>

enum switches
{
  TOTAL_POWER     = 1,
  SOCKET_POWER    = 2,
  LIGHT_IN_HOUSE  = 4,
  LIGHT_ON_GARDEN = 8,
  HOUSE_HEATING   = 16,
  WATER_HEATING   = 32,
  CONDITIONER     = 64
};

int switches_state = 0;

void displayTime(int value);
bool convertStrToBool(std::string text);
void checkWaterHeating(float t);
void checkLightsOutside(int time, bool mov);
void checkHouseHeating(float t);
void checkConditioner(float t);
void checkLightInHouse(bool light);
void colorTemperature(int time);

int main()
{
  float tInside, tOutside;
  bool movementOut, lightsIn;

  for (int day = 1; day <= 2; ++day)
  {
    std::cout << "Day " << day << std::endl;
    for (int time = 0; time < 24; ++time)
    {
      displayTime(time);
      std::string text;
      std::cout << "Input home condition with a space (temperature inside, temperature outside, ";
      std::cout << "is there any movement outside, is the light on in the house)." << std::endl;
      if (day == 1 && time == 0)
      {
        std::cout << "For example: 10 25 no yes." << std::endl;
      }
      std::getline(std::cin, text);

      std::stringstream home_condition(text);
      std::string space, movOutStr, lightsInStr;
      home_condition >> tInside >> tOutside >> movOutStr >> lightsInStr;
      movementOut = convertStrToBool(movOutStr);
      lightsIn = convertStrToBool(lightsInStr);

      checkWaterHeating(tOutside);
      checkLightsOutside(time, movementOut);
      checkHouseHeating(tInside);
      checkConditioner(tInside);
      checkLightInHouse(lightsIn);
      if (lightsIn)
        colorTemperature(time);
    }
  }
  return 0;
}

void displayTime(int value)
{
  std::stringstream text;
  if (value <= 9)
    text << "0" << value << ":00";
  else if (value <= 23)
    text << value << ":00";

  std::cout << "Current time: " << text.str() << std::endl;
}

bool convertStrToBool(std::string text)
{
  return (text == "yes");
}

void checkWaterHeating(float t)
{
  if (t < 0 && ((switches_state & WATER_HEATING) != WATER_HEATING))
  {
    switches_state |= WATER_HEATING;
    std::cout << "Water heating is on." << std::endl;
  }
  if (t > 5 && ((switches_state & WATER_HEATING) == WATER_HEATING))
  {
    switches_state &= ~WATER_HEATING;
    std::cout << "Water heating is off." << std::endl;
  }
}

void checkLightsOutside(int time, bool mov)
{
  if (((time > 16 || time < 5) && mov) && ((switches_state & LIGHT_ON_GARDEN) != LIGHT_ON_GARDEN))
  {
    switches_state |= LIGHT_ON_GARDEN;
    std::cout << "Light on garden is on";
  }
  if (((time >= 5 && time <= 16) || !mov) && ((switches_state & LIGHT_ON_GARDEN) == LIGHT_ON_GARDEN))
  {
    switches_state &= ~LIGHT_ON_GARDEN;
    std::cout << "Light on garden is off";
  }
}

void checkHouseHeating(float t)
{
  if (t < 22 && ((switches_state & HOUSE_HEATING) != HOUSE_HEATING))
  {
    switches_state |= HOUSE_HEATING;
    std::cout << "House heating is on." << std::endl;
  }
  if (t > 25 && ((switches_state & HOUSE_HEATING) == HOUSE_HEATING))
  {
    switches_state &= ~HOUSE_HEATING;
    std::cout << "House heating is off." << std::endl;
  }
}

void checkConditioner(float t)
{
  if (t >= 30 && ((switches_state & CONDITIONER) != CONDITIONER))
  {
    switches_state |= CONDITIONER;
    std::cout << "Conditioner is on." << std::endl;
  }
  if (t <= 25 && ((switches_state & CONDITIONER) == CONDITIONER))
  {
    switches_state &= ~CONDITIONER;
    std::cout << "Conditioner is off." << std::endl;
  }
}

void checkLightInHouse(bool light)
{
  if (light && ((switches_state & LIGHT_IN_HOUSE) != LIGHT_IN_HOUSE))
  {
    switches_state |= LIGHT_IN_HOUSE;
    std::cout << "Light in house is on." << std::endl;
  }
  if (!light && ((switches_state & LIGHT_IN_HOUSE) == LIGHT_IN_HOUSE))
  {
    switches_state &= ~LIGHT_IN_HOUSE;
    std::cout << "Light in house is off." << std::endl;
  }
}

void colorTemperature(int time)
{
  int colorTemp;
  if (time < 16)
    colorTemp = 5000;
  else if (time <= 20)
    colorTemp = 5000 - (time - 16) * ((5000 - 2700) / (20 - 16));
  else
    colorTemp = 2700;
  std::cout << "Color temperature: " << colorTemp << "K" << std::endl;
}
