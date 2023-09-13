#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    std::string Title;
    std::string Description;
    std::string DueDate;
    bool isComplete;

public:
    Task();  // Default constructor
    Task(const std::string& title, const std::string& description, const std::string& dueDate, bool isComplete);  // Parameterized constructor

    const std::string& getTitle() const;
    void setTitle(const std::string& title);

    const std::string& getDescription() const;
    void setDescription(const std::string& description);

    const std::string& getDueDate() const;
    void setDueDate(const std::string& dueDate);

    bool getIsComplete() const;
    void setIsComplete(bool newIsComplete);
};

#endif // TASK_H