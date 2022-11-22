#include <iostream>
#include <vector>

int main() 
{
  std::vector <int> a = {2, 7, 11, 15};
  int result = 9;

  for (int i = 0; i < a.size() - 1; i++) 
  {
    for (int j = i + 1; j < a.size(); j++)
    {
      if (a[i] + a[j] == result)
      {
        std::cout << a[i] << " " << a[j] << std::endl;
        return 0;
      }
    }
  }
}
