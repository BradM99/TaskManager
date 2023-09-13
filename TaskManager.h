#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "Task.h"

class TaskManager {
private:
    //Array of tasks
    std::vector<Task> tasks;

public:
    //Methods for task class
    TaskManager() {};
    void addTask();
    void addTask(const std::string& title, const std::string& description, const std::string& dueDate, bool isComplete);
    void TaskManager::removeTask();
    void viewTasks();
    void expandTasks();

};

#endif // TASKMANAGER_H
