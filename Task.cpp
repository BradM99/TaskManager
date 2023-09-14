#include <iostream>
#include <string>
#include <vector>
#include "Task.h"

// Default constructor
Task::Task() : 
    Title(""), 
    Description(""),
    DueDate(date::year{1970}/date::January/1),  // Set a default date using the date library
    isComplete(false)
{}

// Parameterized constructor
Task::Task(const std::string& title, 
           const std::string& description, 
           const date::year_month_day& dueDate, 
           bool isComplete) : 
    Title(title), 
    Description(description), 
    DueDate(dueDate), 
    isComplete(isComplete)
{}

const std::string& Task::getTitle() const {
    return Title;
}

void Task::setTitle(const std::string& title) {
    Title = title;
}

const std::string& Task::getDescription() const {
    return Description;
}

void Task::setDescription(const std::string& description) {
    Description = description;
}

date::year_month_day Task::getDueDate() const {
    return DueDate;
}

void Task::setDueDate(const date::year_month_day& dueDate) {
    DueDate = dueDate;
}

bool Task::getIsComplete() const {
    return isComplete;
}

void Task::setIsComplete(bool newIsComplete) {
    isComplete = newIsComplete;
}
