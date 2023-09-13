#include <iostream>
#include <string>
#include "TaskManager.h"
#include "globals.h"
#define underline "\033[4m" 
#define stopUnderline "\033[0m"

void TaskManager::addTask() {
        
    std::string inName, inDesc, inDueDate;

    Task newTask;
    std::cout << "Task Name: ";
    std::cin >> inName;// std::ws consumes any leading whitespace
    newTask.setTitle(inName);

    std::cout << "Task Description: ";
    std::cin >> inDesc;
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
        std::cout << "-------------------------" << std::endl;
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
            std::cout << "-------------------------" << std::endl;
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
        std::cout << "Task " << ++x << ": " << task.getTitle() << std::endl;
        std::cout << "Description: " << task.getDescription() << std::endl;
        std::cout << "Due Date: " << task.getDueDate() << std::endl;
        std::cout << "Completed: " << (task.getIsComplete() ? "Yes" : "No") << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
    return;
}

Task newTask() {

    return Task();
}
