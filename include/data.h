#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <stdlib.h>
#include <filesystem>
#include <fstream>
#include "../lib/rlutil.h"
#include <cstdlib>

// The `verifySystem` function is used to determine the appropriate file path based on the operating system. It takes a `users` parameter, which is the username of the current user.
std::string verifySystem(const std::string &users)
{
#ifdef _WIN32
    return "C:\\Users\\" + users + "\\Documents\\Data";
#elif __unix
    return "/home/" + users + "/Documents/Data";
#else
    return "error";
#endif
}

// The `getUserInput()` function is used to retrieve the username from a configuration file called "config.txt".
std::string getUsername()
{
    const char *username = std::getenv("USER");
    if (username)
    {
        return username;
    }
    return "unknown";
}

// global var user
std::string user = getUsername();

// The `relativepath()` function is used to determine the file path based on the operating system. It calls the `verifySystem()` function to get the appropriate file path based on the current user's username. The file path is then returned as a `std::string`.
std::string relativepath()
{
    std::string path = verifySystem(user);
    return path;
}

// The `createDirectory` function is responsible for creating a directory at the specified path if it does not already exist.
void createDirectory(const std::string path)
{
    if (!std::filesystem::exists(path))
    {
        try
        {
            std::filesystem::create_directories(path);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error creating directory: " << e.what() << '\n';
        }
    }
}

/*void updateTask(const std::string &fileName) {

}*/

#endif