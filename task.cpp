#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstring>

int main(int argc, char**argv) {
    std::fstream taskFile;

    std::string relativePath = std::string(std::getenv("HOME"));
    std::string task = relativePath + "/.task";
    std::string taskHistory = relativePath + "/.taskHistory";

    if(argc < 2) {
        if(!std::filesystem::exists(task)) {
            std::cout << "You don't have any task!\n";
        } else {
            taskFile.open(task, std::ios::in);

            std::cout << "\nCurrent Task: \e[0;92m" << taskFile.rdbuf() << "\n\n\e[0;39m";

            taskFile.close();
        }
        return 0;
    }

    if(std::strncmp(argv[1], "complete", 10) == 0) {

        if(!std::filesystem::exists(task)) {
            std::cout << "You don't have any task!\n";
            return 0;
        }

        taskFile.open(task, std::ios::in);

        std::string taskContent;

        std::getline(taskFile, taskContent);

        taskFile.close();

        taskFile.open(taskHistory, std::ios::app);

        taskFile << "\n" << taskContent << "\e[0;92m\t[Completed]\e[0;39m\n\n";

        taskFile.close();

        remove(task.c_str());
        std::cout << "Task completed!\n";
        return 0;
    }

    if(std::strncmp(argv[1], "history", 9) == 0) {
        if(!std::filesystem::exists(taskHistory)) {
            std::cout << "You have not created any tasks!\n";
            return 0;
        }
 
        taskFile.open(taskHistory, std::ios::in);

        std::cout << taskFile.rdbuf();

        taskFile.close();

        return 0;
    }

    taskFile.open(task, std::ios::out);

    taskFile << argv[1];

    std::cout << "Created!\n";

    taskFile.close();

    return 0;
}