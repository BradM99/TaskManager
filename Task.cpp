#include <iostream>
#include <string>
#include <vector>
#include "Task.h"


Task::Task() {
    Title = "";
    Description = "";
    DueDate = "";
    isComplete = false;
}


Task::Task(const std::string& title, const std::string& description, const std::string& dueDate, bool isComplete) {
    Title = title;
    Description = description;
    DueDate = dueDate;
    this->isComplete = isComplete;
}


const std::string& Task::getTitle() const {
    return Title;
}

void Task::setTitle(const std::string& title){
    Title = title;
}

const std::string& Task::getDescription() const{
    return Description;
}

void Task::setDescription(const std::string& description){
    Description = description;
}

const std::string& Task::getDueDate() const{
    return DueDate;
}

void Task::setDueDate(const std::string& dueDate){
    DueDate = dueDate;
}

bool Task::getIsComplete() const{
    return isComplete;
}

void Task::setIsComplete(bool newIsComplete){
    isComplete = newIsComplete;
}