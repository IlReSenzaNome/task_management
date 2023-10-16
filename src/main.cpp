#include <iostream>
#include <stdlib.h>
#include "../include/interfaz.h"

struct Data
{
  std::string nameTask;
  int dueDate;
}data;

int main(int argc, char const *argv[])
{
  std::cout << "Type a task: ";
  std::getline(std::cin,data.nameTask);
  taskInterfaz(data.nameTask);

  
  return 0;
}
