#include <iostream>
#include <string>
#include <sstream>

bool isNumberCorrect(std::string expression, int start, int end)
{
  bool dot = false;
  for (int i = start; i < end; ++i)
  {
    if (expression[i] == '.')
    {
      if (!dot)
        dot = true;
      else
        return false;
    }
    else if (expression[i] < '0' || expression[i] > '9') 
      return false;
  }
  return true;
}

bool isExpressionCorrect(std::string expression)
{
  int operationInd = -1;
  for (int i = 0; i < expression.length(); ++i)
  {
    if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
    {
      operationInd = i;
    }  
  }
  
  if (operationInd == -1 || !isNumberCorrect(expression, 0, operationInd) || !isNumberCorrect(expression, operationInd + 1, expression.length()))
  {
    return false;
  }
  return true;
}

int main()
{
  std::string expression;
  std::cout << "Input expression: " << std::endl;
  std::getline(std::cin, expression);

  while (!isExpressionCorrect(expression))
  {
    expression = "";
    std::cerr << "Expression is invalid. Try again." << std::endl;
    std::cout << "Input expression: " << std::endl;
    std::getline(std::cin, expression);
  }

  double a, b;
  char operation;
  std::stringstream buffer_stream(expression);
  buffer_stream >> a >> operation >> b;

  switch (operation)
  {
    case '+':
      std::cout << "Result: " << a + b << std::endl;
      break;
    case '-':
      std::cout << "Result: " << a - b << std::endl;
      break;
    case '*':
      std::cout << "Result: " << a * b << std::endl;
      break;
    case '/':
      if (b != 0)
        std::cout << "Result: " << a * b << std::endl;
      else
        std::cout << "Division by 0 is not allowed." << std::endl;
        break;
    default:
      std::cerr << "Error!" << std::endl;
  }
  return 0;
}
