#include <iostream>
#include <string>
#include <vector>
#include "TaskManager.h"
#include "Task.h"
#define underline "\033[4m" 
#define stopUnderline "\033[0m"
using namespace std;

int main() {
    //TODO - Program should be able to open, read, write, and save to a text document


    TaskManager taskManager;

    //example tasks to test methods for now
    taskManager.addTask("Skate", "Skate at least 4 times a week", "Weekly", false);
    taskManager.addTask("Update CV", "Update CV with new technologies", "Monthly", false);
    taskManager.addTask("Buy Food", "Buy groceries for the week", "Weekly", false);
    taskManager.addTask("Study", "Learn CPP and OOP", "25/09/2023", false);
    cout << "-------------------------" << endl;

    while (true) {
        char UserIn{};

        cout << underline << "\nWhat would you like to do?\n" << stopUnderline << endl;
        cout << "View all tasks - V" << endl;
        cout << "Add a task - A" << endl;
        cout << "Remove a task - R" << endl;
        cout << "Exit Program - D" << endl;
        cin >> UserIn;

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
            break;
        }
        else {
            cout << "Please enter a valid command" << endl;
        }
        continue;
    }

    //#002 main needs to be reworked into a while loop to keep the program active until manually closed
    //13/09/23 program has started to be reworked into responsive infinite loop

    cout << "Program exiting" << endl;


    return 0;
}
