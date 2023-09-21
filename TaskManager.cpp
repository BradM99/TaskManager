#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "TaskManager.h"
constexpr auto underline = "\033[4m";
constexpr auto stopUnderline = "\033[0m";

void TaskManager::updateFile() {

	// Creates or opens text file
	std::ofstream outFile("TaskManager.txt");
	if (outFile.is_open()) {
		// Loop through task array and write all information to text file
		for (const auto& task : tasks) {
			outFile << "Name: " << task.getTitle() << ", Description: " << task.getDescription() << ", Completed: " << (task.getIsComplete() ? "Yes" : "No") << std::endl;
		}
	}
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
}

void TaskManager::addTask() {

	std::string inName, inDesc, inDueDate;
	// Create new task object
	Task newTask;
	std::cout << "Task Name: ";
	// Consume the newline character left in the buffer
	std::cin.ignore();
	// Store entire line in string
	std::getline(std::cin, inName);
	// Set task title as captured string
	newTask.setTitle(inName);

	std::cout << "Task Description: ";
	// std::cin.ignore() was giving me bugs for description
	std::getline(std::cin, inDesc);
	newTask.setDescription(inDesc);

	std::cout << "Task Due Date: ";
	std::cin >> inDueDate;
	newTask.setDueDate(inDueDate);

	// Assuming newly added tasks are not completed by default
	newTask.setIsComplete(false);
	// Add task object to task array
	tasks.push_back(newTask);
}

void TaskManager::addTask(const std::string& title, const std::string& description, const std::string& dueDate, bool isComplete) {

	// Create task object with given details
	Task newTask(title, description, dueDate, isComplete);
	// Add the new task to the array of tasks
	tasks.push_back(newTask);
	std::cout << "Task added successfully" << std::endl;
	return;
}

void TaskManager::removeTask() {

	// Loop until the user provides valid input or cancels
	while (true) {
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << underline << "\nDelete Task: \n" << stopUnderline << std::endl;
		// Show user the list of tasks before giving the option to delete
		this->viewTasks();
		std::cout << "\nEnter the number of the task you want to delete \nAlternatively, Press 0 to cancel action: ";
		int taskNum{};
		std::cin >> taskNum;

		// Compare with integer 0, not character '0'
		if (taskNum == 0) {
			std::cout << std::endl;
			// Cancel action and return to the main loop
			return;
		}

		// Validate taskNum and perform task deletion if valid
		if (taskNum >= 1 && static_cast<size_t>(taskNum) <= tasks.size()) {
			// Delete the task at the specified index
			tasks.erase(tasks.begin() + taskNum - 1);
			std::cout << "\nTask " << taskNum << " deleted." << std::endl;
			// Small delay to present information clearer
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << "--------------------------------------------------" << std::endl;
			std::cout << underline << "\nUpdated task list:\n" << stopUnderline << std::endl;
			// Printing updated task list
			this->viewTasks();
			// Exit the loop and return to the main loop
			return;
		}
		else {
			// Error handling for incorrect input
			std::cout << "Invalid task. No task deleted." << std::endl;
		}
	}
}


void TaskManager::viewTasks() {

	char userIn{};
	// Task number (remember to alter 0 based array)
	int x{};
	std::cout << std::endl;
	// Loop through task array and print each task object's information
	for (const auto& task : tasks) {
		std::cout << "Task " << ++x << ": " << task.getTitle() << std::endl; //Loop through task array and print the task title along with index(+1)
	}

	// viewTasks displays a basic amount of information, with an option to expand on all information for all tasks
	std::cout << "More information? (y/n): ";
	std::cin >> userIn;
	if (userIn == 'y') {
		this->expandTasks();
	}
	return;
}

void TaskManager::expandTasks() {

	int x{};
	bool isComplete{};
	std::cout << std::endl;

	// Loop through task array and print all variables associated with the object
	for (const auto& task : tasks) {
		// Fix for spacing issues with terminal display of tasks (may be irrelevant now)
		std::cout << std::left << std::setw(20) << "Name:" << task.getTitle() << std::endl;
		std::cout << std::left << std::setw(20) << "Description:" << task.getDescription() << std::endl;
		std::cout << std::left << std::setw(20) << "Completed:" << (task.getIsComplete() ? "Yes" : "No") << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	}
	// 1s wait again for better presentation of information
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return;
}

void TaskManager::markComplete() {

	int taskNum{};
	std::cout << underline << "\nSelect a task to be marked as complete\n" << stopUnderline << std::endl;
	this->viewTasks();
	std::cout << "\nWhich task is complete: " << std::endl;
	std::cin >> taskNum;

	// Validate user input and perform task update if valid
	if (taskNum >= 1 && static_cast<size_t>(taskNum) <= tasks.size()) {
		// Update the task at the specified index
		tasks[static_cast<std::vector<Task, std::allocator<Task>>::size_type>(taskNum) - 1].setIsComplete(true);
		std::cout << "\nTask " << taskNum << " marked as complete." << std::endl;
		// 1s wait for better presentation of information
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "--------------------------------------------------" << std::endl;
		// Exit the loop and return to the main loop
	}
	else {
		// Invalid user input will be skipped
		std::cout << "Invalid task. No task updated." << std::endl;
	}
	return;
}

Task newTask() {

	return Task();
}

// On program start, pull all data currently saved to task file and store in array of tasks for use during runtime
void TaskManager::loadTasksFromFile(const std::string& filename) {


	std::string line;

	// Prevent tasks from duplicating in terminal
	tasks.clear();
	// Open Task file
	std::ifstream inFile("TaskManager.txt");

	if (!inFile.is_open()) {
		std::cerr << "Failed to open the file for reading." << std::endl;
		return;
	}

	// Loop until all data is retrieved from text document
	while (std::getline(inFile, line)) {
		Task newTask;

		// Use stringstream to extract task information from the line
		std::istringstream iss(line);
		std::string token;

		// Initialises a loop reading the Line using getline until it reaches a comma
		// Line information between commas is stored in token 
		// Loop continues until there are no more commas to read
		while (std::getline(iss, token, ',')) {
			// Look for colons that take place in stored tokens and stores their location
			size_t colonPos = token.find(':');
			// If a colon is found in the token, token is important
			if (colonPos != std::string::npos) {
				// Extracts from token pos 0, up to the position of the colon
				// Needed to locate different variable values
				std::string key = token.substr(0, colonPos);
				// Extracts from token 1 position after colon, to the end of the token, to hit target information
				std::string value = token.substr(colonPos + 1);

				// Method to trim white space surrounding targetted value strings
				whiteSpaceTrim(key, value);

				// If key contains any keyword, the value following from the colon is correct and is set accordingly
				if (key == "Name") {
					newTask.setTitle(value);
				}
				else if (key == "Description") {
					newTask.setDescription(value);
				}
				else if (key == " Completed") {
					newTask.setIsComplete(value.find("Yes") != std::string::npos);
				}
			}
		}
		// Add the parsed task to my tasks vector
		tasks.push_back(newTask);
	}
	inFile.close();
	return;
}

// Trim leading and trailing whitespace from key and value
void TaskManager::whiteSpaceTrim(std::string& key, std::string& value) {

	key.erase(0, key.find_first_not_of(' '));
	key.erase(key.find_last_not_of(' ') + 1);
	value.erase(0, value.find_first_not_of(' '));
	value.erase(value.find_last_not_of(' ') + 1);

	return;
}
