#include "FileManager.h"
#include "TaskManager.h"
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <iomanip>
#include <sstream>


/*
FileManager::FileManager(const std::string& filename) : filename(filename) {
    // Attempt to open the file
    file.open(filename, std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        // Optionally, you might throw an exception or handle the error in some way
    }
}

void FileManager::updateFile(std::vector<Task> tasks)
{
    std::ofstream outFile("TaskManager.txt"); //Creates/opens txt file
    if (outFile.is_open()) {
        for (const auto& task : tasks) {
            outFile << "Name: " << task.getTitle() << ", Description: " << task.getDescription() << ", Completed: " << (task.getIsComplete() ? "Yes" : "No") << std::endl;
        }
    }
    else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}

std::vector<Task> FileManager::loadTasksFromFile(const std::string & filename)
{
    std::vector<Task> tasks;
    //tasks.clear(); // Clear existing tasks
    std::ifstream inFile("TaskManager.txt");

    if (!inFile.is_open()) {
        std::cerr << "Failed to open the file for reading." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        Task newTask;

        // Use stringstream to extract task information from the line
        std::istringstream iss(line);
        std::string token;

        while (std::getline(iss, token, ',')) {
            size_t colonPos = token.find(':');
            if (colonPos != std::string::npos) {
                std::string key = token.substr(0, colonPos);
                std::string value = token.substr(colonPos + 1);

                whiteSpaceTrim(key, value);

                if (key == "Name") {
                    newTask.setTitle(value);
                }
                else if (key == "Description") {
                    newTask.setDescription(value);
                }
                else if (key == " Completed") {
                    newTask.setIsComplete(value.find("Yes") != std::string::npos);
                }
            }
        }
        // Add the parsed task to your tasks vector
        tasks.push_back(newTask);
    }
    return;
}

void FileManager::whiteSpaceTrim(std::string& key, std::string& value) {
    // Trim leading and trailing whitespace from key and value
    key.erase(0, key.find_first_not_of(' '));
    key.erase(key.find_last_not_of(' ') + 1);
    value.erase(0, value.find_first_not_of(' '));
    value.erase(value.find_last_not_of(' ') + 1);

    return;
}
*/
