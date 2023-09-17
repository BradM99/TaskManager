#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <vector>
#include "Task.h"

class FileManager {
public:
    FileManager(const std::string& filename);
    void updateFile(std::vector<Task>);
    void whiteSpaceTrim(std::string& key, std::string& value);
    std::vector<Task> loadTasksFromFile(const std::string& filename);

private:
    std::string filename;
    std::fstream file;
};

#endif // FILEMANAGER_H