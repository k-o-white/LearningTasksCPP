#include <iostream>
#include <cmath>

struct vector
{
  double x = 0;
  double y = 0;
};

void add(vector& a, vector& b, vector& sum);
void subtract(vector& a, vector& b, vector& difference);
void scale(vector& a, int& multiplier);
double length(vector& a);
void normalize(vector& a);

int main()
{
  std::string cmd;
  std::cout << "Input command: " << std::endl;
  std::cin >> cmd;

  if (cmd == "add")
  {
    vector a;
    vector b;
    std::cout << "Input first vector value: ";
    std::cin >> a.x >> a.y;
    std::cout << "Input second vector value: ";
    std::cin >> b.x >> b.y;
    vector sum;
    add(a, b, sum);
  }
  else if (cmd == "subtract")
  {
    vector a;
    vector b;
    std::cout << "Input first vector value: ";
    std::cin >> a.x >> a.y;
    std::cout << "Input second vector value: ";
    std::cin >> b.x >> b.y;
    vector difference;
    subtract(a, b, difference);
  }
  else if (cmd == "scale")
  {
    vector a;
    int multiplier;
    std::cout << "Input vector value: ";
    std::cin >> a.x >> a.y;
    std::cout << "Input multiplier: ";
    std::cin >> multiplier;
    scale(a, multiplier);
  }
  else if (cmd == "length")
  { 
    vector a;
    std::cout << "Input vector value: ";
    std::cin >> a.x >> a.y;
    std::cout << length(a) << std::endl;
  }
  else if (cmd == "normalize")
  {
    vector a;
    std::cout << "Input vector value: ";
    std::cin >> a.x >> a.y;
    normalize(a);
  }
  else
  {
    std::cerr << "Wrong command!" << std::endl;
    return 1;
  }
  return 0;
}

void add(vector& a, vector& b, vector& sum)
{
  sum.x = a.x + b.x;
  sum.y = a.y + b.y;
  std::cout << "{" << sum.x << "; " << sum.y << "}" << std::endl;
}

void subtract(vector& a, vector& b, vector& difference)
{
  difference.x = a.x - b.x;
  difference.y = a.y - b.y;
  std::cout << "{" << difference.x << "; " << difference.y << "}";
  std::cout << std::endl;
}

void scale(vector& a, int& multiplier)
{
  a.x *= multiplier;
  a.y *= multiplier;
  std::cout << "{" << a.x << "; " << a.y << "}" << std::endl;
}

double length(vector& a)
{
  return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

void normalize(vector& a)
{
  double invLength = (1 / length(a));
  a.x *= invLength;
  a.y *= invLength;
  std::cout << "{" << a.x << "; " << a.y << "}" << std::endl;
}
