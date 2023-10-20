#include <iostream>
#include <filesystem>
#include <fstream>

std::string verifySystem(const std::string &users)
{
#ifdef _WIN32
    return "C:\\Users\\" + users + "\\Documents\\Data";
#elif __unix
    return "/home/" + users + "/Documents/Data";
#else
    return "Error";
#endif
}

std::string getUserInput()
{
    std::string user;
    std::cout << "Type your username: ";
    std::getline(std::cin, user);
    return user;
}

std::string relativepath()
{
    std::string user = getUserInput();
    std::string path = verifySystem(user);
    return path;
}

int createDirectory()
{
    std::string path = relativepath();
    if (!std::filesystem::exists(path))
    {
        try
        {
            std::filesystem::create_directories(path);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        return 1;
    }
    return 0;
}

void createFile(const std::string &fileName)
{
    std::string path = relativepath();
    std::ofstream file;
    std::string phrase;
    file.open((path + "/" + fileName).c_str(), std::ios::out);
    if (file.fail())
    {
        error();
        exit(1);
    }
    std::cout << "Type a phrase: ";
    getline(std::cin, phrase);
    file << phrase;
    file.close();
}