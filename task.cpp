#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>

int main(int argc, char**argv) {
    std::fstream taskFile;

    std::string relativePathToFile = std::string(std::getenv("HOME")) + "/.task";

    if(argc < 2) {
        if(!std::filesystem::exists(relativePathToFile)) {
            std::cout << "You don't have any task!\n";
        } else {
            taskFile.open(relativePathToFile, std::ios::in);

            std::cout << "\nCurrent Task: \e[0;92m" << taskFile.rdbuf() << "\n\n\e[0;39m";

            taskFile.close();
        }
        return 0;
    }

    if(std::strncmp(argv[1], "complete", 10) == 0) {
        remove(relativePathToFile.c_str());
        std::cout << "Task completed!\n";
        return 0;
    }

    taskFile.open(relativePathToFile, std::ios::out);

    taskFile << argv[1];

    std::cout << "Created!\n";

    taskFile.close();

    return 0;
}