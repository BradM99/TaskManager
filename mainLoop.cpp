#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TaskManager.h"
#include "mainLoop.h"
#include "Task.h"
#define underline "\033[4m" 
#define stopUnderline "\033[0m"

void MainLoop::run() {
    //TODO - Program should be able to open, read, write, and save to a text document

    //-----ISSUES-----//
    //#002 main needs to be reworked into a while loop to keep the program active until manually closed

    //-----TIMELINE-----//
    //13/09/23 program has started to be reworked into responsive infinite loop
    //17/09/23 Work started on text document parsing

    TaskManager taskManager;

    //example tasks to test methods for now
    /*taskManager.addTask("Skate", "Skate at least 4 times a week", "Weekly", false);
    taskManager.addTask("Update CV", "Update CV with new technologies", "Monthly", false);
    taskManager.addTask("Buy Food", "Buy groceries for the week", "Weekly", false);
    taskManager.addTask("Study", "Learn CPP and OOP", "25/09/2023", false);
    cout << "-------------------------" << endl;*/

    while (true) {
        char UserIn{};
        taskManager.loadTasksFromFile("TaskManager.txt");


        std::cout << underline << "\nWhat would you like to do?\n" << stopUnderline << std::endl;
        std::cout << "V | View all tasks" << std::endl;
        std::cout << "A | Add a task" << std::endl;
        std::cout << "R | Remove a task " << std::endl;
        std::cout << "M | Mark a task as complete " << std::endl;
        std::cout << "D | Exit Program " << std::endl;
        std::cin >> UserIn;

        if (UserIn == 'V') {
            taskManager.viewTasks();
        }
        else if (UserIn == 'A') {
            taskManager.addTask();
        }
        else if (UserIn == 'R') {
            taskManager.removeTask();
        }
        else if (UserIn == 'D') {
            taskManager.updateFile();
            break; //Program end
        }
        else if (UserIn == 'M') {
            taskManager.markComplete();
        }
        else {
            std::cout << "Please enter a valid command" << std::endl;
        }
        taskManager.updateFile();
    }
    std::cout << "Program exiting" << std::endl;
    return;
}