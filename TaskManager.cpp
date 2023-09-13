#include <iostream>
#include <string>
#include "TaskManager.h"
#include "globals.h"
#define underline "\033[4m" 
#define stopUnderline "\033[0m"


void TaskManager::addTask(const std::string& title, const std::string& description, const std::string& dueDate, bool isComplete) {
        
    //Create task object with given details
    Task newTask(title, description, dueDate, isComplete);
    //Add the new task to the array of tasks
    tasks.push_back(newTask);
    std::cout << "Task added successfully" << std::endl;
    return;
}

void TaskManager::removeTask() {
    int taskNum{};
    char userIn{};
    std::cout << "-------------------------" << std::endl;
    std::cout << underline << "Delete Task: \n" << stopUnderline << std::endl;
    calledByRemoveTask = true;
    this->viewTasks();
    std::cout << "\nMore information? (y/n): ";
    std::cin >> userIn;
    if(userIn == 'y') {
        calledByRemoveTask = true;
        this->expandTasks();
    }
    std::cout << "Enter the number of the task you want to delete \nAlternatively, Press X to cancel action: " ;
    std::cin >> taskNum;
    
    if (taskNum >= 0 && static_cast<size_t>(taskNum) < tasks.size()) {
        // Delete the task at the specified index
        tasks.erase(tasks.begin() + taskNum-1);
        std::cout << "Task at index " << taskNum << " deleted." << std::endl;
        std::cout << "-------------------------" << std::endl;
        std::cout << "Updated task list: " << std::endl;
        this->viewTasks();
    }
    else {
        std::cout << "Invalid task. No task deleted." << std::endl;
    }
    return;
}


void TaskManager::viewTasks() {
    
    if (calledByRemoveTask == true) {
        //Task number (remember to alter 0 based array)
        int x{};
        //Loop through task array and print the task title along with index(+1)
        for (const auto& task : tasks) {
            std::cout << "Task " << ++x << ": " << task.getTitle() << std::endl;
        }
        calledByRemoveTask == false;
    }
    else {
        char userIn{};
        //Task number (remember to alter 0 based array)
        int x{};
        //Loop through task array and print the task title along with index(+1)
        for (const auto& task : tasks) {
            std::cout << "Task " << ++x << ": " << task.getTitle() << std::endl;
        }

        std::cout << "More information? (y/n): ";
        std::cin >> userIn;
        if (userIn == 'y') {
            this->expandTasks();
        }
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