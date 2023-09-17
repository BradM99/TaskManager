#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "TaskManager.h"
constexpr auto underline = "\033[4m";
constexpr auto stopUnderline = "\033[0m";

void TaskManager::updateFile() {
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

void TaskManager::addTask() {

    std::string inName, inDesc, inDueDate;
    Task newTask;
    std::cout << "Task Name: ";
    std::cin.ignore(); // Consume the newline character left in the buffer
    std::getline(std::cin, inName); // Read the entire line as the description
    newTask.setTitle(inName);

    std::cout << "Task Description: ";
    std::getline(std::cin, inDesc);
    newTask.setDescription(inDesc);

    std::cout << "Task Due Date: ";
    std::cin >> inDueDate;
    newTask.setDueDate(inDueDate);

    newTask.setIsComplete(false); //assuming newly added tasks are not completed by default
    tasks.push_back(newTask);
}

void TaskManager::addTask(const std::string& title, const std::string& description, const std::string& dueDate, bool isComplete) {

    Task newTask(title, description, dueDate, isComplete); //Create task object with given details
    tasks.push_back(newTask); //Add the new task to the array of tasks
    std::cout << "Task added successfully" << std::endl;
    return;
}

void TaskManager::removeTask() {

    while (true) { // Loop until the user provides valid input or cancels
        std::cout << "--------------------------------------------------" << std::endl;
        std::cout << underline << "\nDelete Task: \n" << stopUnderline << std::endl;
        this->viewTasks();
        std::cout << "\nEnter the number of the task you want to delete \nAlternatively, Press 0 to cancel action: ";
        int taskNum{};
        std::cin >> taskNum;

        if (taskNum == 0) { // Compare with integer 0, not character '0'
            std::cout << std::endl;
            return; // Cancel action and return to the main loop
        }

        // Validate taskNum and perform task deletion if valid
        if (taskNum >= 1 && static_cast<size_t>(taskNum) <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNum - 1); // Delete the task at the specified index
            std::cout << "\nTask " << taskNum << " deleted." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            std::cout << "--------------------------------------------------" << std::endl;
            std::cout << underline << "\nUpdated task list:\n" << stopUnderline << std::endl;
            this->viewTasks();
            return; // Exit the loop and return to the main loop
        }
        else {
            std::cout << "Invalid task. No task deleted." << std::endl;
        }
    }
}


void TaskManager::viewTasks() {

    char userIn{};
    int x{}; //Task number (remember to alter 0 based array)
    std::cout << std::endl;
    for (const auto& task : tasks) {
        std::cout << "Task " << ++x << ": " << task.getTitle() << std::endl; //Loop through task array and print the task title along with index(+1)
    }

    std::cout << "More information? (y/n): ";
    std::cin >> userIn;
    if (userIn == 'y') {
        this->expandTasks();
    }
    return;
}

void TaskManager::expandTasks() {

    int x{};
    bool isComplete{};

    std::cout << std::endl;

    for (const auto& task : tasks) {
        std::cout << std::left << std::setw(20) << "Name:" << task.getTitle() << std::endl;
        std::cout << std::left << std::setw(20) << "Description:" << task.getDescription() << std::endl;
        std::cout << std::left << std::setw(20) << "Completed:" << (task.getIsComplete() ? "Yes" : "No") << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return;
}

void TaskManager::markComplete() {

    int taskNum{};
    std::cout << underline << "\nSelect a task to be marked as complete\n" << stopUnderline << std::endl;
    this->viewTasks();
    std::cout << "\nWhich task is complete: " << std::endl;
    std::cin >> taskNum;

    // Validate taskNum and perform task update if valid
    if (taskNum >= 1 && static_cast<size_t>(taskNum) <= tasks.size()) {
        tasks[static_cast<std::vector<Task, std::allocator<Task>>::size_type>(taskNum) - 1].setIsComplete(true); // Update the task at the specified index
        std::cout << "\nTask " << taskNum << " marked as complete." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "--------------------------------------------------" << std::endl;
        return; // Exit the loop and return to the main loop
    }
    else {
        std::cout << "Invalid task. No task updated." << std::endl;
    }
    return;
}

Task newTask() {

    return Task();
}

void TaskManager::loadTasksFromFile(const std::string& filename) {
    tasks.clear(); // Clear existing tasks
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

    inFile.close();
    return;
}

void TaskManager::whiteSpaceTrim(std::string& key, std::string& value) {
    // Trim leading and trailing whitespace from key and value
    key.erase(0, key.find_first_not_of(' '));
    key.erase(key.find_last_not_of(' ') + 1);
    value.erase(0, value.find_first_not_of(' '));
    value.erase(value.find_last_not_of(' ') + 1);

    return;
}
