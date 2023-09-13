#include <iostream>
#include <string>
#include <vector>
#include "TaskManager.h"
#include "Task.h"

int main() {
    TaskManager taskManager;

    //#002 main needs to be reworked into a while loop to keep the program active until manually closed

    //example tasks to test methods for now
    taskManager.addTask("Skate", "Skate at least 4 times a week", "Weekly", false);
    taskManager.addTask("Update CV", "Update CV with new technologies", "Monthly", false);
    taskManager.addTask("Buy Food", "Buy groceries for the week", "Weekly", false);
    taskManager.addTask("Study", "Learn CPP and OOP", "25/09/2023", false);

    taskManager.removeTask();



    return 0;
}
