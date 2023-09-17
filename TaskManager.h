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
    void removeTask();
    void viewTasks();
    void expandTasks();
    void markComplete();
    void updateFile();
    void loadTasksFromFile(const std::string& filename);
    void whiteSpaceTrim(std::string& key, std::string& value);

};

#endif // TASKMANAGER_H
