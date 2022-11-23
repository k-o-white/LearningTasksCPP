#include <iostream>
#include <fstream>

void displayQuestion(std::ifstream& text);
void answerTheQuestion(std::ifstream& questions, 
                       std::ifstream& answers, 
                       const std::string& qPath,
                       const std::string& aPath, bool& result);
bool game(int number);

int main()
{
  std::cout << "Welcome to \"What? Where? When?\" game!" << std::endl;
  int expertScore = 0, viewersScore = 0;
  bool question[13];
  for (int i = 0; i < sizeof(question); ++i)
    question[i] = true;

  int sector = 1;
  while (expertScore < 6 && viewersScore < 6)
  {
    std::cout << "Expert: " << expertScore << ", Viewers: " 
      << viewersScore << "." << std::endl;
    int offset;
    std::cout << "Input offset: ";
    std::cin >> offset;
    sector += offset;
    if (sector > 13) sector %= 13;
    while (!question[sector - 1])
    {
      ++sector;
      if (sector > 13) sector = 1;
    }

    std::cout << "Question " << sector << "." << std::endl;
    if (game(sector)) ++expertScore;
    else ++viewersScore;
    question[sector - 1] = false;
  }

  std::cout << "Expert: " << expertScore << ", Viewers: " << viewersScore << "." << std::endl;
  std::cout << ((expertScore == 6) ? "Expert won" : "Viewers won") << std::endl;
  return 0;
}

void displayQuestion(std::ifstream& text)
{
  while(!text.eof())
  {
    char output[21];
    text.read(output, sizeof(output) - 1);
    if(text.gcount() < sizeof(output) - 1)
      output[text.gcount()] = 0;
    else
      output[sizeof(output) - 1] = 0;
    
    for(int i = 0; output[i] != '\0'; ++i)
    {
      if (output[i] != '\n')
        std::cout << output[i];
    }
  }
  std::cout << std::endl;
}

void answerTheQuestion(std::ifstream& questions, 
                       std::ifstream& answers, 
                       const std::string& qPath,
                       const std::string& aPath, bool& result)
{
  questions.open(qPath, std::ios::binary);
  displayQuestion(questions);
  questions.close();
  std::string answer;
  std::cout << "Input answer: ";
  std::cin >> answer;
  answers.open(aPath);
  std::string rightAnswer;
  answers >> rightAnswer;
  if (answer == rightAnswer)
  {
    result = true;
    std::cout << "This is the right answer!" << std::endl;
  }
  else
  {
    result = false;
    std::cout << "This is the wrong answer, right answer is " 
      << rightAnswer << "." << std::endl;
  }
  answers.close();
}

bool game(int number)
{
  std::ifstream question;
  std::ifstream rightAnswer;
  std::string qPath;
  std::string aPath;
  bool result;
  switch (number)
  {
    case 1:
      qPath = "./Questions/1.txt";
      aPath = "./Answers/1.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 2:
      qPath = "./Questions/2.txt";
      aPath = "./Answers/2.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 3:
      qPath = "./Questions/3.txt";
      aPath = "./Answers/3.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 4:
      qPath = "./Questions/4.txt";
      aPath = "./Answers/4.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 5:
      qPath = "./Questions/5.txt";
      aPath = "./Answers/5.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 6:
      qPath = "./Questions/6.txt";
      aPath = "./Answers/6.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 7:
      qPath = "./Questions/7.txt";
      aPath = "./Answers/7.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 8:
      qPath = "./Questions/8.txt";
      aPath = "./Answers/8.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 9:
      qPath = "./Questions/9.txt";
      aPath = "./Answers/9.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 10:
      qPath = "./Questions/10.txt";
      aPath = "./Answers/10.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 11:
      qPath = "./Questions/11.txt";
      aPath = "./Answers/11.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 12:
      qPath = "./Questions/12.txt";
      aPath = "./Answers/12.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
    case 13:
      qPath = "./Questions/13.txt";
      aPath = "./Answers/13.txt";
      answerTheQuestion(question, rightAnswer, qPath, aPath, result);
      break;
  }
  return result;
}
