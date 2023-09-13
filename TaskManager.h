#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "Task.h"

class TaskManager {
private:
    //Array of tasks
    std::vector<Task> tasks;
    // Flag to indicate if viewTasks was called by removeTask
    bool calledByRemoveTask;

public:
    //Methods for task class
    TaskManager() : calledByRemoveTask(false) {}
    void addTask(const std::string& title, const std::string& description, const std::string& dueDate, bool isComplete);
    void TaskManager::removeTask();
    void viewTasks();
    void expandTasks();

};

#endif // TASKMANAGER_H