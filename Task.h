#ifndef TASK_H
#define TASK_H

#include <string>
#include <date/date.h>  // include the date library

class Task {
private:
    std::string Title;
    std::string Description;
    date::year_month_day DueDate;  // Use the date library's year_month_day type
    bool isComplete;

public:
    Task();  // Default constructor
    Task(const std::string& title, 
         const std::string& description, 
         const date::year_month_day& dueDate,  // Accept year_month_day directly
         bool isComplete);

    const std::string& getTitle() const;
    void setTitle(const std::string& title);

    const std::string& getDescription() const;
    void setDescription(const std::string& description);

    date::year_month_day getDueDate() const;
    void setDueDate(const date::year_month_day& dueDate);  // Accept year_month_day directly

    bool getIsComplete() const;
    void setIsComplete(bool newIsComplete);
};

#endif // TASK_H
