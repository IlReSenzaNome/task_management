#include <iostream>
#include <filesystem>
#include "../include/data.h"

int createProject(const std::string &path)
{
    std::string name;
    std::cout << "Enter project name: ";
    std::getline(std::cin, name);
    std::string path = relativepath();
    std::string folderproject = path + name;
    if (!std::filesystem::exists(folderproject))
    {
        std::filesystem::create_directory(folderproject);
    }
    else
    {
        return 1;
    }
    return 0;
}