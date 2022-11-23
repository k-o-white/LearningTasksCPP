#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct Task
{
  std::string name = "unknown";
  std::time_t startTime = 0;
  std::time_t finishTime = 0;
  bool finish = false;
};

void instruction();
void startTask(std::vector <Task> &tasksList);
void finishTask(std::vector <Task> &tasksList);
void printTasksList(std::vector <Task> &tasksList);
void calculateTime(Task &endedTask);

int main()
{
  instruction();
  std::vector <Task> tasks;
  std::string cmd;
  std::cout << "Input cmd: ";
  std::cin >> cmd;

  while (cmd != "exit")
  {
    if (cmd == "begin")
      startTask(tasks);
    else if (cmd == "end")
      finishTask(tasks);
    else if (cmd == "status")
      printTasksList(tasks);
    else
      std::cout << "Invalid command!" << std::endl;

    instruction();
    std::cout << "Input cmd: ";
    std::cin >> cmd;
  }
  return 0;
}

void instruction()
{
  std::cout << "Command \"begin\"  - input new task." << std::endl;
  std::cout << "Command \"end\"    - finish task in process." << std::endl;
  std::cout << "Command \"status\" - display all tasks." << std::endl;
  std::cout << "Command \"exit\"   - finish program." << std::endl;
  std::cout << std::endl;
}

void startTask(std::vector <Task> &tasksList)
{
  std::system("clear");
  if (!tasksList.empty() && !tasksList[tasksList.size() - 1].finish)
  {
    tasksList[tasksList.size() - 1].finish = true;
    tasksList[tasksList.size() - 1].finishTime = std::time(nullptr);
    std::cout << "Task \"" << tasksList[tasksList.size() - 1].name 
      << "\" is finished." << std::endl << std::endl;
  }
  Task tempTask;
  std::cin.ignore();
  std::cout << "Input task name: ";
  std::getline(std::cin, tempTask.name);
  tempTask.startTime = std::time(nullptr);
  tasksList.push_back(tempTask);
  std::cout << "Task \"" << tempTask.name << "\" is started." << std::endl;
  std::cout << std::endl;
}

void finishTask(std::vector <Task> &tasksList)
{
  std::system("clear");
  if (!tasksList.empty() && !tasksList[tasksList.size() - 1].finish)
  {
    tasksList[tasksList.size() - 1].finish = true;
    tasksList[tasksList.size() - 1].finishTime = std::time(nullptr);
    std::cout << "Task \"" << tasksList[tasksList.size() - 1].name 
      << "\" is finished." << std::endl << std::endl;
  }
  else
    std::cout << "All tasks is finished by now." << std::endl << std::endl;
}

void printTasksList(std::vector <Task> &tasksList)
{
  std::system("clear");
  std::cout << std::endl;
  for (int i = 0; i < tasksList.size(); ++i)
  {
    std::cout << "Task " << i + 1 << ":" << std::endl;
    std::cout << tasksList[i].name << std::endl;
    std::cout << "Status: " << 
      ((tasksList[i].finish) ? "Finished." : "In process.") << std::endl;
    if (tasksList[i].finish)
      calculateTime(tasksList[i]);
  }
  std::cout << std::endl;
}

void calculateTime(Task &endedTask)
{
  int delta = endedTask.finishTime - endedTask.startTime;
  int hours = delta / 3600;
  delta %= 3600;
  int minutes = delta / 60;
  delta %= 60;
  int seconds = delta;
  std::cout << "Task finished in " << hours << " hours, " 
    << minutes << " minutes, " << seconds << " seconds.";
  std::cout << std::endl;
}
