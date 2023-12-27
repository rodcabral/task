#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>

int main(int argc, char**argv) {
    std::fstream taskFile;

    if(argc < 2) {
        if(!std::filesystem::exists(".task")) {
            std::cout << "You don't have any task!\n";
            return 0;
        }

        taskFile.open(".task", std::ios::in);

        std::cout << "\nCurrent Task: \e[0;92m" << taskFile.rdbuf() << "\n\n\e[0;39m";

        taskFile.close();
        return 0;
    }

    if(std::strncmp(argv[1], "complete", 10) == 0) {
        remove(".task");
        std::cout << "Task completed!\n";
        return 0;
    }

    taskFile.open(".task", std::ios::out);

    taskFile << argv[1];

    std::cout << "Created!\n";

    taskFile.close();

    return 0;
}