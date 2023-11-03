#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include "../include/task.h"

int menu();
int selection();

struct Data
{
  std::string nameTask, viewTask;
  int dueDate;
} data;

int main(int argc, char const *argv[])
{
  selection();
  while (getchar() != '\n')
    ;
  return 0;
}

int menu()
{
  int option;
  rlutil::cls();
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << "|                     Menu                          |" << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << "|> 1. Create Task:                                  |" << std::endl;
  std::cout << "|> 2. Delete Task:                                  |" << std::endl;
  std::cout << "|> 3. Show Task:                                    |" << std::endl;
  std::cout << "|> 4. Exit:                                         |" << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
  std::cout << "|> Enter your option:                               |" << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;
  rlutil::locate(23, 9);
  std::cin >> option;
  std::cin.ignore();
  return option;
}

int selection()
{
  int option;
  do
  {
    option = menu();
    switch (option)
    {
    case 1:
      rlutil::cls();
      std::cout << "Type name file: " << std::endl;
      std::getline(std::cin, data.nameTask);
      createTask(data.nameTask);
      break;
    case 2:
      std::cout << "Name Task: " << std::endl;
      std::getline(std::cin, data.viewTask);
      viewTask(data.viewTask);
      break;
    case 4:
      std::cout << "Error" << std::endl;
      while (getchar() != '\n')
        ;
      exit(0);
      break;
    default:

      break;
    }
  } while (option != 4);
  return 0;
}