#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include "../include/interfaz.h"
#include "../include/data.h"

struct Data
{
  std::string nameTask, description, state;
  int dueDate;
} data;

int main(int argc, char const *argv[])
{
  relativepath();
  createDirectory();
  std::cout << "Type name file: " << std::endl;
  std::getline(std::cin, data.nameTask);

  return 0;
}
