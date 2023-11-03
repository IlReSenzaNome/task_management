#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include "../include/data.h"

int error()
{
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "|                   Error                     |" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    return 0;
}

void success()
{
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "|                    Success                        |" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
}

std::string path = relativepath();

// The `createTask` function is responsible for creating a new task. It takes a `fileName` parameter, which is the name of the file where the task will be stored.
void createTask(const std::string &fileName)
{
    createDirectory(path);
    rlutil::cls();
    std::string taskName, description, dueDate, status;
    std::string path = relativepath();
    std::ofstream file;
    file.open((path + "/" + fileName + ".txt").c_str(), std::ios::out);
    if (file.fail())
    {
        error();
        exit(1);
    }
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "|                    Create Task                    |" << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    file << "-----------------------------------------------------" << std::endl;
    file << "|                    Task                           |" << std::endl;
    file << "-----------------------------------------------------" << std::endl;
    std::cout << "|Enter task name:                                   |" << std::endl;
    rlutil::locate(19, 4);
    std::getline(std::cin, taskName);
    file << "|Task name: ";
    file << taskName;
    file << "\t\t\t\t\t    |" << std::endl;
    std::cout << "|Enter description:                                 |" << std::endl;
    rlutil::locate(21, 5);
    std::getline(std::cin, description);
    file << "|Description: ";
    file << description;
    file << "\t\t\t\t    |" << std::endl;
    std::cout << "|Due Date:                                          |" << std::endl;
    rlutil::locate(12, 6);
    std::getline(std::cin, dueDate);
    file << "|DueDate: ";
    file << dueDate;
    file << "\t\t\t\t\t    |" << std::endl;
    std::cout << "|Status:                                            |" << std::endl;
    rlutil::locate(10, 7);
    std::getline(std::cin, status);
    file << "|Status: ";
    file << status;
    file << "\t\t\t\t\t    |" << std::endl;
    file << "-----------------------------------------------------" << std::endl;
    success();
    while (getchar() != '\n')
        ;
    file.close();
}

// The `viewTask` function is responsible for displaying the contents of a task file. It takes a `fileName` parameter, which is the name of the file to be viewed.
void viewTask(const std::string &fileName)
{
    rlutil::cls();
    std::string path = relativepath();
    std::ifstream file;
    std::string line;
    file.open((path + "/" + fileName + ".txt").c_str(), std::ios::in);
    if (file.fail())
    {
        error();
        exit(1);
    }
    while (!file.eof())
    {
        getline(file, line);
        std::cout << line << std::endl;
    }
    file.close();
    while (getchar() != '\n')
        ;
}

void taskList()
{
    rlutil::cls();
    std::string path = relativepath();
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
    {
        for (const auto &file : std::filesystem::directory_iterator(path))
        {
            if (std::filesystem::is_regular_file(file))
            {
                std::cout << "List Task: " << file.path().filename() << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Directory not found" << std::endl;
    }
    while (getchar() != '\n')
        ;
}

#endif // TASK_H