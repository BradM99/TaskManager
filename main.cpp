#include <iostream>
#include <string>
#include <vector>
#include "TaskManager.h"
#include "Task.h"

int main() {
    TaskManager taskManager;

    taskManager.addTask("Skate", "Skate at least 4 times a week", "Weekly", false);
    taskManager.addTask("Update CV", "Update CV with new technologies", "Monthly", false);
    taskManager.addTask("Buy Food", "Buy groceries for the week", "Weekly", false);
    taskManager.addTask("Study", "Learn CPP and OOP", "25/-9/2023", false);

    taskManager.removeTask();



    return 0;
}